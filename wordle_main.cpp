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

int main() {
    bool match;
    int len_of_words = 5; num_of_tries = 6; currentTry = 0; num_of_games = 0, score = 0;

    vector <vector<char>> charr; vector <vector<bool>> found; vector <string> tries;
    string input1, input2, input3, word;
    map<dictPair, string> mydict;
    string filepath = "/usr/share/dict/words"; /*access system dictionary*/
    bool b = loaddict(filepath, mydict), present = false;
    char randletter;

    gameInstructions();
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
                dictPair word_int = generateword(mydict); /*randomly generate word for guessing*/
                word = word_int.dictword;
                toLowerCase(word); /*convert word to lowercase*/
                bool overlapWord = false; /*generate letter landmine*/
                do{
                    randletter = generateChar();
                    wordOverlap(overlapWord, randletter, word);
                }while(overlapWord); /*if landmine appears in guessing word, the landmine letter is regenerated until it is not in the word*/
            }
            currentTry = 0;
            bool present = false;
            while(currentTry < num_of_tries){
                do{
                    cout << "Please enter your guess (word length must be 5) or type Q to quit: ";
                    getline(cin, input2);
                    if(input2 == "Q"){
                        break;
                    }
                    toLowerCase(input2);
                    
                    present = wordpresent(randletter, input2); /*detect whether user input includes landmine letter*/
                    if(present){
                        triggerLandmine(randletter);
                        break;
                    }
                    
                    while(!dictword(input2, mydict)){ /*check whether user input word is valid*/
                        if(input2.length() != 5){
                            cout << "Please enter a word that has 5 letters: " ;
                        }
                        else{
                            cout << "Please enter a valid word found in the dictionary: " ;
                        }
                        getline(cin, input2);
                    }
                }while(!isValid(input2) || input2 == "Q");
                if(present || input2 == "Q"){
                    break;}
                
                match = testingdoWordsMatch(word, input2); /*check whether user input matches guessed word*/
                playwordle(word, input2, charr, found, currentTry, tries); /*start wordle game*/
                printResults(charr, found, tries); /*print display of previous attempts*/
                currentTry++;
                if(match == 1){
                    endgame(currentTry);
                    break;
                }
                if(currentTry != 6){cout << "You have " << 6-currentTry << " tries left!" << endl;}
            }
            earlyEndgame(currentTry, input2, present, word, match);
            do{
                sleep (1);
                cout << "Would you like to play again? Enter Y for yes and Q for no: " << endl;
                getline(cin, input3);
            }while(input1 != "Y" && input1 != "Q");
            if(input3 == "Y"){
                continuegame(currentTry,tries, found, charr, num_of_games, match, score);
                continue;
            }
            else if(input3 == "Q"){
                break;
            }

        }
    };
    final(score);
    return 0;
}
