// gcd.h
#ifndef WORDLE_H
#define WORDLE_H
#include <string>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <ctime>
#include <map>
#include <list>
#include <random>

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

#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */
#define DIMBLACK "\033[2m\033[30m"    /* Dim Black */
#define DIMRED "\033[2m\033[31m"      /* Dim Red */
#define DIMGREEN "\033[2m\033[32m"    /* Dim Green */
#define DIMYELLOW "\033[2m\033[33m"   /* Dim Yellow */
#define DIMBLUE "\033[2m\033[34m"     /* Dim Blue */
#define DIMMAGENTA "\033[2m\033[35m"  /* Dim Magenta */
#define DIMCYAN "\033[2m\033[36m"     /* Dim Cyan */
#define DIMWHITE "\033[2m\033[37m"    /* Dim White */
#define MOVEUP "\033["                /* add integer, and add F */
#define ERASELINE "\033[2K"           /* erase current line */

using namespace std;

struct dictPair{
    string dictword;
    int wordInt;
};
bool operator<(const dictPair& a, const dictPair& b);
bool loaddict(const string & file, map<dictPair, string> & mydict);
void toLowerCase(string & input);
dictPair generateword(map<dictPair, string> & mapdict);
bool isValid(string input);
bool testingdoWordsMatch(string s1, string s2);
void testingfindGs(string s1,string s2, vector<char> & charword, vector<bool> & found);
void charprinting(vector<char> & charr);
void boolprinting(vector<bool> & found);
void wordprinting( string line);
void testingfindYs(string s1,string s2, vector<char> & charr, vector<bool> & found);
void playwordle(string word, string input, vector<vector<char>> & charr, vector<vector<bool>> & found, int currentTry, vector<string> & tries);
void printResults(vector<vector<char>> & charr, vector<vector<bool>> & found, vector<string> & tries);
bool dictword(string curr_word, map<dictPair, string> & mapdict);

#endif
