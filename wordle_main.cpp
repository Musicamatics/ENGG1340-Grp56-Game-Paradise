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
    int len_of_words = 5;
    int num_of_tries = 6;
    int currentTry = 0;
    int num_of_games = 0, score = 0;

    vector <vector<char>> charr;
    vector <vector<bool>> found;

    vector <string> tries;
    string input1, input2, word;
    map<dictPair, string> mydict;
    string filepath = "/usr/share/dict/words"; /*access system dictionary*/
    bool b = loaddict(filepath, mydict), present = false;
    char randletter;

    /*Game instructions*/
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
    cout << "But this wordle is different because there are " << B_MAGENTA << " LANDMINES!" << RESET << endl;
    cout << "There will be 1 letter out of the 27 letters that is RANDOMIZED to be the " << B_MAGENTA << "landmine" << RESET << " in the beginning!" << endl;
    cout << "If you used the " << B_MAGENTA << "landmine letter" << RESET << " in your guess, you will lose immediately!" << endl;
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
                dictPair word_int = generateword(mydict); /*randomly generate word for guessing*/
                word = word_int.dictword;
                toLowerCase(word); /*convert word to lowercase*/
                bool overlapWord = false; /*generate letter landmine*/
                do{
                    overlapWord = false; 
                    randletter = generateChar();
                    int count = 0;
                    for(int i=0; i < word.length(); i++){
                        if(randletter == word[i]){
                            count ++;
                        }
                    }
                    if(count != 0){
                        overlapWord = true;
                    }
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
                        cout << "Oops! You used the letter " << B_MAGENTA << randletter << RESET << " which triggered the wordle landmine!" << endl;
                        sleep(1);
                        cout << "You've lost!" << endl;
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
                    };
                }while(!isValid(input2) || input2 == "Q");
                if(present || input2 == "Q"){
                    break;}
                
                match = testingdoWordsMatch(word, input2); /*check whether user input matches guessed word*/
                playwordle(word, input2, charr, found, currentTry, tries); /*start wordle game*/
                printResults(charr, found, tries); /*print display of previous attempts*/
                currentTry++;
                if(currentTry != 6){cout << "You have " << 6-currentTry << " tries left!" << endl;}
                if(match == 1){
                    if(currentTry == 1){    
                        cout << "You got the answer with only " << currentTry << " try !" << endl;
                    }
                    cout << "You got the answer in " << currentTry << " tries !" << endl;
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
            if(input2 == "Q" && currentTry < 6){
                cout << "It's sad you gave up trying!" << endl;
            }
            else if(present){
                cout << "You're too unlucky!" << endl; 
            }
            else if(currentTry == 6 && match != 1){
                cout << "The 6 chances to guess the answer have been used up!" << endl;
            }
            sleep(1);
            cout << "The correct answer is " << word << "." << endl;
            string input3;
            do{
                sleep (1);
                cout << "Would you like to play again? Enter Y for yes and Q for no: " << endl;
                getline(cin, input3);
            }while(input1 != "Y" && input1 != "Q");
            if(input3 == "Y"){
                currentTry = 0;
                tries.clear();
                found.clear();
                charr.clear();
                num_of_games += 1;
                if(match == 1){
                    score += 1;
                }
                continue;
            }
            else if(input3 == "Q"){
                break;
            }

        }
    };
    if (score > 1){
        cout << "You've played really well! You've won " << score << " games in total!" << endl;
    }
    else if(score == 1){
        cout << "You've played well! You've won 1 game in total!" << endl;
    }
    else{
        cout << "Great try! You'll do better next time!" << endl;
    }
    sleep(1);
    cout << "Bye!" << endl;
    return 0;
}
