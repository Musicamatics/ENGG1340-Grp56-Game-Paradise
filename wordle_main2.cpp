#include "wordle.h"
#include <unistd.h>

void gameInstructions(){
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
}

void wordOverlap(bool & overlapWord, const char & randletter, const string & word){
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
void triggerLandmine(const char & randletter){
    cout << "Oops! You used the letter " << B_MAGENTA << randletter << RESET << " which triggered the wordle landmine!" << endl;
    sleep(1);
    cout << "You've lost!" << endl;
}
void endgame(const int & currentTry){
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
}                   

void earlyEndgame(const int & currentTry, const string & input2, const bool & present, const string & word, const bool & match){
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
}

void continuegame(int & currentTry,vector<string> & tries, vector<vector<bool>> & found, vector<vector<char>> & charr, int & num_of_games, bool & match, int & score){
    currentTry = 0;
    tries.clear();
    found.clear();
    charr.clear();
    num_of_games += 1;
    if(match == 1){
        score += 1;
        match = false;
    }
}
void final(const int & score){
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
}
