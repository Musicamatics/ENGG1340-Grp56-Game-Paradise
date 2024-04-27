#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
char window[25][75], inputting;
int snake_x[100], snake_y[100], dir_x=1, dir_y=0;
// length of snake is 100, storing the corresponding snake
// dir_x is up and down, -1 for up and 1 for down
// dir_y is left and right, -1 for left and 1 for right
int fruit_x=12, fruit_y=32, length=1, score=0, speed=200;
bool contin=true;

void getkey()
{
    if(_kbhit())
    {
        inputting=getch();
    }

    switch(inputting)   
    {
        case 'w':
        case 'W':
            if (dir_x==0) // check no hitting its body
            {
                dir_x=-1;
                dir_y=0;
            }
            break;
        case 'A':
        case 'a':
            if (dir_y==0)
            {
                dir_x=0;
                dir_y=-1;
            }
            break;
        case 'S':
        case 's':
            if (dir_x==0)
            {
                dir_x=1;
                dir_y=0;
            }
            break;
        case 'D':
        case 'd':
            if (dir_y==0)
            {
                dir_x=0;
                dir_y=1;
            }
            break;
}

void setwindow()
{
    for(int i=0; i<25; i++)
    {
        for(int j=0; j<75; j++)
        {
            if(i==0 || i==24 || j==0 || j==74)
            {
                window[i][j]='#';
            }
            else
            {
                window[i][j]=' ';
            }
        }
    }
}

void printing(user)
{
    system("CLS");
    for(int i=0; i<25; i++)
    {
        for(int j=0; j<75; j++)
        {
          cout<<window[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<user<<"'s score: "<<score;
}

void fruit()
{
    if (snake_x[0]==fruit_x && snake_y[0]==fruit_y)
    {
        fruit_x=rand()%23+1; // 0 and 24 is a wall
        // remainder of 23={0,1,2,...,22}
        // generate a fruit in {1,2,...,23}
        fruit_y=rand()%73+1; // 0 and 74 is a wall
        score+=1;
        length+=1;
    }
        window[fruit_x][fruit_y]='A';
}

void snake()
{
}

void crash()
{
}

int main()
{
    setwindow();
    printing();
    while (contin)
    {
        getkey();
        cout << dir_x << " " << dir_y << endl;
        Sleep(speed);
    }
    return 0;
}
