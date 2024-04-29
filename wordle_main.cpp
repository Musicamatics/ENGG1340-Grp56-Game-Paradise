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
#include <unistd.h>
using namespace std;

void playWordle() {
    bool match;
    int len_of_words = 5;
    int num_of_tries = 6;
    int currentTry = 0;
    int num_of_games = 0;

    vector <vector<char>> charr;
    vector <vector<bool>> found;

    vector <string> tries;
    string input1, input2, word;
    map<dictPair, string> mydict;
    string filepath = "/usr/share/dict/words";
    bool b = loaddict(filepath, mydict);

    cout << "Welcome to WORDLE!" << endl << "These are the rules of the game! " << endl << endl;
    sleep(1);
    cout << "Wordle is a simple game in which you have to guess a five-letter word." << endl;
    cout << "You have 6 tries only. Each 5-word guess must be a valid word." << endl << endl;
    sleep(1);
    cout << "The colour of the tile will change to show you how close your guess was." << endl;
    cout << "A " << BLACK << B_GREEN << "GREEN" << RESET << " tile means that the letter is in the word AND in the right spot." << endl;
    cout << "A "  << BLACK << B_YELLOW << "YELLOW" << RESET << " tile means that the letter is in the word BUT NOT in the right spot." << endl;
    cout << "A " << BLACK << B_GRAY << "GRAY" << RESET << " tile means that the letter is NOT in the word." << endl << endl;
    sleep(1);
    cout << "Good luck with your guesses!" << endl;
    
    while(input1 != "Q"){
        do{
            if(num_of_games > 0){
                input1 = "Y";
                continue;
            }
            cout << "Would you like to start playing Wordle? Type Y to start or Q to quit: ";
            getline(cin, input1);
        }while(input1 != "Y" && input1 != "Q");
        if(input1 == "Q"){
            break;
        }
        if(input1 == "Y"){
            if(b){
                dictPair word_int = generateword(mydict);
                word = word_int.dictword;
                toLowerCase(word);
            }
            currentTry = 0;
            while(currentTry < num_of_tries){
                do{
                    cout << "Please enter your guess (word length must be 5) or type Q to quit: ";
                    getline(cin, input2);
                    if(input2 == "Q"){
                        break;
                    }
                    toLowerCase(input2);
                    while(!dictword(input2, mydict)){
                        cout << "Please enter a valid word found in the dictionary: " ;
                        getline(cin, input2);
                    };
                }while(!isValid(input2));
                if(input2 == "Q"){
                    break;
                }
                match = testingdoWordsMatch(word, input2);
                playwordle(word, input2, charr, found, currentTry, tries);
                printResults(charr, found, tries);
                currentTry++;
                if(match == 1){
                    if(currentTry == 1){    
                        cout << "You got the answer with only " << currentTry << "try !" << endl;
                    }
                    cout << "You got the answer in " << currentTry << "tries !" << endl;
                    switch(currentTry){
                        case 1: cout << "Genius!"; break;
                        case 2: cout << "Magnificent!"; break;
                        case 3: cout << "Impressive!"; break;
                        case 4: cout << "Splendid!"; break;
                        case 5: cout << "Great!"; break;
                        case 6: cout << "Phew!"; break;
                    }
                    cout << endl;
                    break;
                }
            }
            if(input2 == "Q"){
                break;
            }
            if(match == 1){
                string input3;
                do{
                    cout << "Would you like to play again? Enter Y for yes and Q for no: " << endl;
                    getline(cin, input3);
                }while(input1 != "Y" && input1 != "Q");
                if(input3 == "Y"){
                    currentTry = 0;
                    tries.clear();
                    found.clear();
                    charr.clear();
                    num_of_games += 1;
                    continue;
                }
                else if(input3 == "Q"){
                    break;
                }
            }
        }
    cout << "Bye!" << endl;
    };
}