#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
char window[25][75];
int snake_x[100], snake_y[100], dir_x=1, dir_y=0;
// length of snake is 100, storing the corresponding snake
int fruit_x=12, fruit_y=32, length=1, score=0, speed=200;

void getkey()
{
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

void printing()
{
    for(int i=0; i<25; i++)
    {
        for(int j=0; j<75; j++)
        {
          cout<<window[i][j];
        }
        cout<<endl;
    }
}

void fruit()
{
}

int main()
{
    setwindow();
    printing();
    return 0;
}
