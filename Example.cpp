#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

using namespace std;

char window[25][75], inputting;
int snake_x[100], snake_y[100], dir_x = 1, dir_y = 0;
int fruit_x, fruit_y, length = 1, score = 0;
bool contin = true;

void getkey()
{
    if (_kbhit())
    {
        inputting = getch();
    }

    switch (inputting)
    {
    case 'w':
    case 'W':
        if (dir_x == 0)
        {
            dir_x = -1;
            dir_y = 0;
        }
        break;
    case 'A':
    case 'a':
        if (dir_y == 0)
        {
            dir_x = 0;
            dir_y = -1;
        }
        break;
    case 'S':
    case 's':
        if (dir_x == 0)
        {
            dir_x = 1;
            dir_y = 0;
        }
        break;
    case 'D':
    case 'd':
        if (dir_y == 0)
        {
            dir_x = 0;
            dir_y = 1;
        }
        break;
    }
}

void setwindow()
{
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 75; j++)
        {
            if (i == 0 || i == 24 || j == 0 || j == 74)
            {
                window[i][j] = '#';
            }
            else
            {
                window[i][j] = ' ';
            }
        }
    }
}

void printing(string user)
{
    system("CLS");
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 75; j++)
        {
            cout << window[i][j];
        }
        cout << endl;
    }
    cout << endl;
    cout << user << "'s score: " << score;
}

void fruit()
{
    if (snake_x[0]==fruit_x && snake_y[0]==fruit_y)
    {
        fruit_x=rand()%23+1;
        fruit_y=rand()%23+1;
        score+=1;
        length+=1;
    }
    window[fruit_x][fruit_y]='@';
}

void snake(char skin)
{
    for (int i = length; i > 0; i--)
    {
        snake_x[i] = snake_x[i - 1];
        snake_y[i] = snake_y[i - 1];
    }

    snake_x[0] += dir_x;
    snake_y[0] += dir_y;
    window[snake_x[0]][snake_y[0]] = skin;
    window[snake_x[length]][snake_y[length]] = ' ';
}

void crash()
{
    if (snake_x[0] == 0 || snake_x[0] == 24 || snake_y[0] == 0 || snake_y[0] == 74)
    {
        contin = false;
    }
    if (length > 1)
    {
        for (int i = 1; i < length; i++)
        {
            if (snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i])
            {
                contin = false;
            }
        }
    }
}

void play(char skin, string user, int speed)
{
    setwindow();
    length = 1;
    score = 0;
    snake_x[0] = 12;
    snake_y[0] = 32;
    window[fruit_x][fruit_y]=' ';
    fruit_x = rand() % 23 + 1;
    fruit_y = rand() % 73 + 1;
    contin=true
    printing(user);
    while (contin)
    {
        getkey();
        snake(skin);
        fruit();
        printing(user);
        Sleep(speed);
        crash();
    }
}

int main()
{
    char skin;
    string user, sure, wait_to_start;
    int speed;
    bool makesure = true;

    while (makesure)
    {
        cout << "Please enter a name for your snake: " << endl;
        getline(cin, user);
        cout << "Do you sure that the name of your snake is " << user << endl;
        cout << "Please enter (Yes: y | No: Any Key):" << endl;
        getline(cin, sure);
        if (sure == "y" or sure == "Y")
        {
            makesure = false;
        }
    }

    cout << "Choose your skin: ( O / X / H )" << endl;
    cout << "skin O:  OOOOOOOO" << endl;
    cout << "skin X:  XXXXXXXX" << endl;
    cout << "skin H:  HHHHHHHH" << endl;
    cin >> skin;
    while (skin != 'O' && skin != 'X' && skin != 'H')
    {
        cout << "Invalid Input!!! Only available to enter O, X or H" << endl;
        cin >> skin;
    }

    char difficulty, again;
    bool check_input=true;
    bool check_again=true;
    while (check_again)
    {   
        check_input=true;
        while (check_input)
        {
            cout<<"Choose a difficulty level: (1/2/3)"<<endl;
            cin>>difficulty;
            if (difficulty=='1' || difficulty=='2' || difficulty=='3')
            {
                check_input=false;
            }
            else
            {
                cout<<"Invalid Input!! Please enter again..."<<endl;
            }
        }

        switch (difficulty)
        {
            case '1':
                speed=250;
                break;
            case '2':
                speed=200;
                break;
            case '3':
                speed=120;
                break;
        }

        cout<<"Press any key to start..."<<endl;
        cin>>wait_to_start;
        
        play(skin, user, speed);
            
        check_input = true;
        while(check_input)
        {
            cout<<endl;
            cout<< "Play again? (Yes: Y, No: N)"<<endl;
            cin>>again;
            if (again!='y' && again!='Y' && again!='n' && again!='N')
            {
                cout<<"Invalid Input!! Please enter again!"<<endl;
            }
            else
            {
                check_input=false;
            }
        }

        switch(again)
        {
            case 'Y':
            case 'y':
                check_again=true;     
                break;
            case 'N':
            case 'n':
                check_again=false;
                cout<<"Bye Bye~"<<endl;
                break;
        }
    }
    return 0;
}
