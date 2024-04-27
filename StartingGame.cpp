#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;


void print(const string& str)
{
    cout << str << endl;
}

int main()
{
    bool input_check = true;
    string user, makesure;
    print("#######################################");
    print("#                                 十  #");
    print("#      ######     ######        %%%%%%#");
    print("#     #           #     #      %   %  #");
    print("#     #    ##     ######      %%%%%%%%#");
    print("#     #     #     #            %      #");
    print("#     #######     #           ［      #");
    print("#                            %%%%%%%%%#");
    print("#######################################");
    print("Welcome to GameParadise!");
    print("Please enter your name:");
    while (input_check)
    {
        getline(cin, user);
        if (!user.empty())
        {
            cout<<"Do you sure your name is "<<user<<"?  (Yes: Y/ N: Any other key)"<<endl;
            getline(cin, makesure);
            if (makesure=="y" || makesure=="Y")
            {
                input_check=false;
            }
        }
    }
    cout << "Welcome, " << user << " !" << endl;

    bool choose = true;
    string chosen;
    while (choose)
    {
        print("Please choose a game to play:");
        print(" 一一一一一一一一一一一一一一一一一");
        print("| 1) Snake Game    (Enter 1) |");
        print("|                            |");
        print("| 2) Wordle        (Enter 2) |");
        print(" 一一一一一一一一一一一一一一一一一");
        getline(cin, chosen);
        if (chosen != "1" && chosen != "2")
        {
            print("Invalid Input!!");
            print("Please try again!");
            print("");
            print("");
        }
        else
        {
            choose = false;
        }
    }

    if (chosen == "1")
    {
        print("Loading Snake Game...");
        system("g++ -Wall -Wextra -pedantic -std=c++11 -o snake main.cpp snake.cpp userinput.cpp -lncurses");
        system("./snake");
    }
    else if (chosen == "2")
    {
        print("Loading Wordle...");
        system("g++ -Wall -Wextra -pedantic -std=c++11 -o wordle wordle_main.cpp wordle.cpp");
        system("./wordle");
    }

    return 0;
}
