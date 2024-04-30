#include "wordle.h"

playWordle() {
    bool match;
    int num_of_tries = 6;
    int currentTry = 0;
    int num_of_games = 0;

    std::vector<std::vector<char>> charr;
    std::vector<std::vector<bool>> found;

    std::vector <std::string> tries;
    std::string input1, input2, input3, word;
    std::map<dictPair, std::string> mydict;
    std::string filepath = "/usr/share/dict/words"; /*access system dictionary*/
    bool b = loaddict(filepath, mydict);
    char randletter;

    gameInstructions();
    while(input1 != "Q"){
        do{
            if(num_of_games > 0){
                input1 = "Y";
                continue;
            }
            std::cout << "Would you like to start playing Wordle? Type Y to start or Q to quit: ";
            std::getline(std::cin, input1);
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
            int present = -1;
            while(currentTry < num_of_tries){
                do{
                    std::cout << "Please enter your guess (word length must be 5) or type Q to quit: ";
                    std::getline(std::cin, input2);
                    if(input2 == "Q"){
                        break;
                    }
                    toLowerCase(input2);
                    
                    while(!dictword(input2, mydict)){ /*check whether user input word is valid*/
                        if(input2 == "Q"){
                            break;
                        }
                        if(input2.length() != 5){
                            std::cout << "Please enter a word that has 5 letters: " ;
                        }
                        else{
                            std::cout << "Please enter a valid word found in the dictionary: " ;
                        }
                        getline(std::cin, input2);
                    }
                }while(!isValid(input2) || input2 == "Q");
                if(input2 == "Q"){
                    break;}
                present = wordpresent(randletter, input2); 
                match = testingdoWordsMatch(word, input2); /*check whether user input matches guessed word*/
                playwordle(word, input2, charr, found, currentTry, tries); /*start wordle game*/
                printResults(charr, found, tries, present); /*print display of previous attempts*/
                /*detect whether user input includes landmine letter*/
                if(present != -1){
                    triggerLandmine(randletter);
                    break;
                    }
                currentTry++;
                if(match == 1){
                    endgame(currentTry);
                    break;
                }
                if(currentTry != 6){
                    std::cout << "You have " << 6-currentTry << " tries left!\n";}
            }
            earlyEndgame(currentTry, input2, present, word, match);
            do{
                sleep (1);
                std::cout << "Would you like to play again? Enter Y for yes and Q for no: ";
                getline(std::cin, input3);
            }while(input1 != "Y" && input1 != "Q");
            num_of_games ++; 
            writefile(num_of_games, match, currentTry, word, present);
            continuegame(currentTry,tries, found, charr, match);
            if(input3 == "Y"){
                continue;
            }
            else if(input3 == "Q"){
                break;
            }
        }
    };
    outfile();
    return 0;
}
