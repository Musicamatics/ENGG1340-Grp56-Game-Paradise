#include "wordle.h"

bool operator<(const dictPair& a, const dictPair& b) { /*for correcting iteration of map<dictPair, string> mapdict*/
    return a.dictword < b.dictword;
}
bool loaddict(const std::string & file, std::map<dictPair, std::string> & mydict){ /*for generating dictionary with 5 letter words only and non-specific terms only*/
    std::string word;
    std::ifstream filed{file};
    if (!filed.is_open()) {
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
    filed.close();
    return true;
}
void toLowerCase(std::string & input){
    for (int i=0; i<5; i++){
        if (input[i] < 97){
            input[i] = input[i]+32;
        }
    }
}

dictPair generateword(std::map<dictPair, std::string> & mapdict){ /*generate random word*/
    dictPair d;
    int N = mapdict.size()-1;
    int num = 0;
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_int_distribution<int> dist(1,N);
    num = dist(e2); /*generate random integer*/
    d.wordInt = num; /*search for word in dictionary key using random int*/
    for(std::map<dictPair, std::string>::iterator iter = mapdict.begin(); iter != mapdict.end(); ++iter){ /*iterate through key of dictionary only to find word*/
        dictPair k =  iter->first;
        if(k.wordInt == num){
            std::string word = k.dictword;
            d.dictword = word;
        }
        //ignore value
        //Value v = iter->second;
    }
    return d;
}

bool isValid(std::string input){
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

bool testingdoWordsMatch(std::string s1, std::string s2){ /*if user input and guess word match return true*/
    if (s1 == s2){
        return true;
    }
    return false;
};
void testingfindGs(std::string s1, std::string s2, std::vector<char> & charword, std::vector<bool> & found){ /*creating matrix indicating matching char in user input and guess word*/
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

void testingfindYs(std::string s1,std::string s2, std::vector<char> & charr, std::vector<bool> & found){    /*for finding user input chars which appear in guess word but not in correct position*/
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
void testingfindYys(std::string s1, std::string s2, std::vector<char> & charr, std::vector<bool> & found){   /*removing extra Ys in char array*/
    for(int s=0; s<5; s++){
        for (int g=0; g<5; g++){
            if (((s1[s] == s1[g]) && (s!=g)) && ((charr[s] == 'Y') && (charr[g] == 'G'))){ 
                charr[s] = ' ';
            }
        }
    }
};

void playwordle(std::string word, std::string input, std::vector<std::vector<char>> & charr, std::vector<std::vector<bool>> & found, int currentTry, std::vector<std::string> & tries){
    for(int i=0; i<6; i++){
        if(i == currentTry){
            int bsize = charr.size(), asize = 0;    /*generate char vector and bool vector for each word in vector of words*/
            std::vector<char> charrword;
            std::vector<bool> foundword;
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


bool dictword(std::string curr_word, std::map<dictPair, std::string> & mapdict){   /*check if user input word is a valid word*/
    std::map<dictPair, std::string>::iterator it; /*initialize map iterator*/
    dictPair d;
    for(std::map<dictPair, std::string>::iterator iter = mapdict.begin(); iter != mapdict.end(); ++iter){
        dictPair k =  iter->first;
        if(k.dictword == curr_word){    /*if user input word matches word string stored in key dictPair of dictionary*/
            d.wordInt = k.wordInt;
            d.dictword = curr_word;
        }
    }
    return mapdict.count(d);
};

char generateChar(){    /*generate random letter landmine*/
    int N = 26, n = 0;
    char num = 'a';
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_int_distribution<int> dist(1,N);
    n = dist(e2);   /*generate random integer*/
    num += n;   /*create random char letter*/
    return num;
}

int wordpresent(char letter, std::string input){    /*check if landmine letter is present in word*/
    for(int i=0; i<input.length(); i++){
        if (input[i] == letter){    /*if landmine matches char in user input word*/
            return i;
        }
    }
    return -1;
};

void wordOverlap(bool & overlapWord, const char & randletter, const std::string & word){
    overlapWord = false; 
    int count = 0;
    for(int i=0; i < word.length(); i++){
        if(randletter == word[i]){
        count ++;
        }
    }
    if(count != 0){
        overlapWord = true;
    }
}
void continuegame(int & currentTry,std::vector<std::string> & tries, std::vector<std::vector<bool>> & found, std::vector<std::vector<char>> & charr,bool & match){
    currentTry = 0;
    tries.clear();
    found.clear();
    charr.clear();
    if(match == 1){
        match = false;
    }
}

void writefile(const int & numGame, const bool & match, const int & currentTry, const std::string & word, const int & present){    
    std::ofstream fout;
    if(numGame == 1){
        fout.open("result.txt");
    }
    else{
        fout.open("result.txt", std::ios::app);
    }
    if(fout.fail()){
        exit(1);
    }
    bool complete = ((match == 1) || (currentTry == 6));
    fout << numGame << " " << currentTry << " " << word << " " << match << " "  << complete << " " << present << "\n";
    fout.close();
}

void outfile(){
    std::ifstream fin;
    int numGame=1, currentTry, gamesComplete=0, landmine=0, gamesWon=0, present=-1;
    bool match, complete;
    std::string line, word;
    
    char filename[80] = "result.txt";
    fin.open(filename);
    if(fin.fail()){
        exit(1);
    }
    while(getline(fin, line)){
        std::istringstream iss(line);
        iss >> numGame >> currentTry >> word >> match >> complete >> present;
        std::cout << complete << " " << present << "\n";
        if(complete==1){
            gamesComplete ++;
        }
        if(present != -1){
            landmine++;
        }
        if(match){
            gamesWon ++;
        }
    }
    fin.close();
    if(gamesComplete > 0){
        std::cout << "You've completed " << gamesComplete << " wordle puzzles! ";
        if(numGame - gamesComplete - landmine > 0){
            std::cout << "But you've given up on " << numGame - gamesComplete - landmine << " wordle puzzles! ";
        }
        if(landmine > 0){
            std::cout << "You've stepped on " << landmine << " landmines!";
        }
        std::cout << "\n";
    }
    else{
        std::cout << "Although you didn't try until the end, you can do better next time!\n";
        std::cout<< "Great job!\n";
    }
    if(gamesWon > 0){
        std::cout << "You've got " << gamesWon << " wordle puzzles correct! You have solved" << gamesWon/gamesComplete*100 << "%% of puzzles!\n";
    }
    else{
        if(gamesComplete > 0){
            std::cout << "Although you couldn't solve any wordle puzzles, you can do better next time!\n";
        }
    }
    std::cout << "Bye~\n";
    remove("result.txt");

    
}
