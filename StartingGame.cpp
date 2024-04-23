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
    print("Welcome to Snake Game!");
    print("Please enter your name:");
    while (input_check)
    {
        getline(cin,user);
        if (user!="")
        {
            input_check=false;
        }
    }
    return 0;
}
      

