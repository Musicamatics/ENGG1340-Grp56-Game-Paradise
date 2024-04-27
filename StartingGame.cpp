#include <iostream>
#include <string>
using namespace std;

void print(string str)
{
    cout << str << endl;
}

int main()
{
    bool input_check=true;
    string user;
    print("Welcome to GameParadise!");
    print("Please enter your name:");
    while (input_check)
    {
        getline(cin,user);
        if (user!="")
        {
            input_check=false;
        }
    }

    bool choose=true;
    string chosen;
    while (choose)
    {
        print("Please choose a game to play:");
        print("1) Snake Game (Enter 1)");
        print("2) Wordle     (Enter 2)");
        getline(cin, chosen);
        if (chosen!="1" && chosen!="2")
        {
            print("Invalid Input!!");
            print("Please try again!");
        }
        else if (chosen=="1")
        {
            print("Loading Snake Game...");
            choose=false;
        }
        else
        {
            print("Loading Wordle")
            choose=false;
        }
        
    return 0;
}
      

