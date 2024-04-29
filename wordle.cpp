#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <ctime>
#include <map>
#include <list>
#include <random>
#include "wordle.h"
using namespace std;

bool operator<(const dictPair& a, const dictPair& b) { /*for correcting iteration of map<dictPair, string> mapdict*/
    return a.dictword < b.dictword;
}
bool loaddict(const string & file, map<dictPair, string> & mydict){ /*for generating dictionary with 5 letter words only and non-specific terms only*/
    string word;
    ifstream filed{file};
    if (!filed.is_open()) {
        cout << "Error in file opening!" << endl;
        exit(1);
        return false;
    }
    
    int num=0;
    dictPair d;
    if(filed.is_open()){
        while (getline(filed, word)){
            if((word.length() == 5) && !isupper(word[0])){
                d.wordInt = num;
                d.dictword = word;
                mydict[d] = d.wordInt;
                num++;
            }
        }
    }

    //cout << num << endl;
    filed.close();
    return true;
}
void toLowerCase(string & input){
    for (int i=0; i<5; i++){
        if (input[i] < 97){
            input[i] = input[i]+32;
        }
    }
}

dictPair generateword(map<dictPair, string> & mapdict){ /*generate random word*/
    dictPair d;
    int N = mapdict.size()-1;
    int num = 0;
    random_device rd;
    mt19937 e2(rd());
    uniform_int_distribution<int> dist(1,N);
    num = dist(e2); /*generate random integer*/
    d.wordInt = num; /*search for word in dictionary key using random int*/
    for(std::map<dictPair, string>::iterator iter = mapdict.begin(); iter != mapdict.end(); ++iter){ /*iterate through key of dictionary only to find word*/
        dictPair k =  iter->first;
        if(k.wordInt == num){
            string word = k.dictword;
            d.dictword = word;
        }
        //ignore value
        //Value v = iter->second;
    }
    return d;
}

bool isValid(string input){
    if((input.length() > 5) || (input.length() < 5)){   /*invalid if user input word length > 5 or < 5*/
        return false;
    }
    for (int i=0;i<5;i++){  /*invalid if user input word that contains non-letters*/
        if ((input[i]<97) || (input[i]>122)){
            return false;
        }
    }
    return true;
}

bool testingdoWordsMatch(string s1, string s2){ /*if user input and guess word match return true*/
    if (s1 == s2){
        return true;
    }
    return false;
};
void testingfindGs(string s1,string s2, vector<char> & charword, vector<bool> & found){ /*creating matrix indicating matching char in user input and guess word*/
    for (int i=0; i<5; i++){
        if (s1[i] == s2[i]){       /*if user input char is present in word and appear in same position as word */
            charword[i] = 'G';  /*store as 'G' to indicate green colour*/
            found[i] = true;    /*store as 1 to indicate presence of matching char*/
        }
        else{
            charword[i] = ' ';
            found[i] = false;
        }
    }
};
void charprinting(vector<char> & charr){    /*for printing out char array*/
    for (int i=0; i<5; i++){
        cout << charr[i] << " ";
    }
    cout << endl;
}

void boolprinting(vector<bool> & found){    /*for printing out bool array*/
    for (int i=0; i<5; i++){
        cout << found[i] << " ";
    }
    cout << endl;
}
void wordprinting( string line){    /*for printing out word*/
    for (int i=0; i<5; i++){
        cout << line[i] << " ";
    }
    cout << endl;
}
void testingfindYs(string s1,string s2, vector<char> & charr, vector<bool> & found){    /*for finding user input chars which appear in guess word but not in correct position*/
    for(int i=0; i<5; i++){
        for(int a=0; a<5; a++){
            if((s1[i] == s2[a]) && (charr[i] != 'G')){  /*if user char appears in word but not in correct position*/
                charr[i] = 'Y'; /*store value as 'Y' for yellow colour*/
                found[a] = true;         /*indicate user input char is correct*/
            }
        }
    }
}
/*if 'Y' indicating presence of user char in wrong position overlaps with 'G' in another position 
indicating correct position char match, remove 'Y' of a lower priority*/
void testingfindYys(string s1,string s2, vector<char> & charr, vector<bool> & found){   /*removing extra Ys in char array*/
    for(int s=0; s<5; s++){
        for (int g=0; g<5; g++){
            if (((s1[s] == s1[g]) && (s!=g)) && ((charr[s] == 'Y') && (charr[g] == 'G'))){ 
                charr[s] = ' ';
            }
        }
    }
};

void playwordle(string word, string input, vector<vector<char>> & charr, vector<vector<bool>> & found, int currentTry, vector<string> & tries){
    for(int i=0; i<6; i++){
        if(i == currentTry){
            int bsize = charr.size(), asize = 0;    /*generate char vector and bool vector for each word in vector of words*/
            vector<char> charrword;
            vector<bool> foundword;
            for (int s=0; s<5; s++){
                charrword.push_back('\0');  /*initializing char and bool vector*/
                foundword.push_back(0);
            }
            charr.push_back(charrword); /*store initialized char and bool vector for each word in larger vecttor for whole game*/
            found.push_back(foundword);
            asize = charr.size();
            tries.push_back(input);
            testingfindGs(word, input, charr[i], found[i]); /*storing values of 'G' and 1/0*/
            testingfindYs(word, input, charr[i], found[i]); /*storing values of 'Y' and 1/0*/
            testingfindYys(word, input, charr[i], found[i]); /*removing extra 'Y'*/
        }
    }
};

void printResults(vector<vector<char>> & charr, vector<vector<bool>> & found, vector<string> & tries){ /*printing out user input of tries*/
    cout << "*****************" << endl;
    for (int i=0; i<charr.size(); i++){
        cout << "| ";
        for(int s=0; s<charr[i].size(); s++){
            
            if((charr[i][s] == 'G') && (found[i][s] == 1)){ /*correct char and correct pos*/
                cout << BLACK << B_GREEN;
            }
            else if((charr[i][s] != 'G') && (found[i][s] == 1)){    /*user input char correct but wrong pos*/
                cout << BLACK << B_YELLOW;
            }
            else{   
                cout << BLACK << B_GRAY;    /*user input char incorrect*/
            }
            cout << tries[i][s] << RESET << " |" ;
        }
        cout << endl << "*****************" << endl;
    }
    
};
bool dictword(string curr_word, map<dictPair, string> & mapdict){   /*check if user input word is a valid word*/
    std::map<dictPair,string>::iterator it; /*initialize map iterator*/
    dictPair d;
    for(std::map<dictPair, string>::iterator iter = mapdict.begin(); iter != mapdict.end(); ++iter){
        dictPair k =  iter->first;
        if(k.dictword == curr_word){    /*if user input word matches word string stored in key dictPair of dictionary*/
            d.wordInt = k.wordInt;
            d.dictword = curr_word;
        }
        //ignore value
        //Value v = iter->second;
    }
    return mapdict.count(d);
};

char generateChar(){    /*generate random letter landmine*/
    int N = 26, n = 0;
    char num = 'a';
    random_device rd;
    mt19937 e2(rd());
    uniform_int_distribution<int> dist(1,N);
    n = dist(e2);   /*generate random integer*/
    num += n;   /*create random char letter*/
    return num;
}

bool wordpresent(char letter, string input){    /*check if landmine letter is present in word*/
    for(int i=0; i<input.length(); i++){
        if (input[i] == letter){    /*if landmine matches char in user input word*/
            return true;
        }
    }
    return false;
};
