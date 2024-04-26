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