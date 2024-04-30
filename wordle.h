#ifndef WORDLE_H
#define WORDLE_H
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <ctime>
#include <map>
#include <list>
#include <random>
#include <unistd.h>

#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */

#define B_BLACK   "\033[40m"    /* Black */
#define B_RED     "\033[41m"    /* Red */
#define B_GREEN   "\033[42m"    /* Green */
#define B_YELLOW  "\033[43m"    /* Yellow */
#define B_BLUE    "\033[44m"    /* Blue */
#define B_MAGENTA "\033[45m"    /* Magenta */
#define B_CYAN    "\033[46m"    /* Cyan */
#define B_WHITE   "\033[47m"    /* White */
#define B_GRAY "\033[47m"      /* Gray */

struct dictPair{
    std::string dictword;
    int wordInt;
};

void gameInstructions();
void wordOverlap(bool & overlapWord, const char & randletter, const std::string & word);
void triggerLandmine(const char & randletter);
void endgame(const int & currentTry);
void earlyEndgame(const int & currentTry, const std::string & input2, const int & present, const std::string & word, const bool & match);
void continuegame(int & currentTry,std::vector<std::string> & tries, std::vector<std::vector<bool>> & found, std::vector<std::vector<char>> & charr, bool & match);
void final(const int & score);
bool operator<(const dictPair& a, const dictPair& b);
bool loaddict(const std::string & file, std::map<dictPair, std::string> & mydict);
void toLowerCase(std::string & input);
dictPair generateword(std::map<dictPair, std::string> & mapdict);
bool isValid(std::string input);
bool testingdoWordsMatch(std::string s1, std::string s2);
void testingfindGs(std::string s1, std::string s2, std::vector<char> & charword, std::vector<bool> & found);
void charprinting(std::vector<char> & charr);
void boolprinting(std::vector<bool> & found);
void wordprinting(std::string line);
void testingfindYs(std::string s1, std::vector<char> & charr);
void playwordle(std::string word, std::string input, std::vector<std::vector<char>> & charr, std::vector<std::vector<bool>> & found, int currentTry, std::vector<std::string> & tries);
void printResults(std::vector<std::vector<char>> & charr, std::vector<std::vector<bool>> & found, std::vector<std::string> & tries, const int & present);
bool dictword(std::string curr_word, std::map<dictPair, std::string> & mapdict);
char generateChar();
int wordpresent(char letter, std::string input);
void writefile(const int & numGame, const bool & match, const int & currentTry, const std::string & word, const int & present);
void outfile();
void playWordle();
#endif
