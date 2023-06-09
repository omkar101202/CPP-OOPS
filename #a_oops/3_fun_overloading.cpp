#include<bits/stdc++.h>
using namespace std;

float area(float);
int area(int);
int area(int ,int);

int main()
{
    float r;
    int a,b;
    char c;
    cout<<"enter radius of circle:";
    cin>>r;
    cout<<"area of circle is:"<<area(r)<<endl;
    cout<<"enter length and breadth if rectangle:";
    cin>>a>>b;
    cout<<"area of rectangle is:"<<area(a,b)<<endl;
    cout<<"enter character:";
    cin>>c;
    cout<<"output is:"<<area(c);// type promotion........1)char to int and 2)float to double.............**

    /* whenever a func. is called it searches for func. by its name. if it found multiple func. 
    with same name then it picks all function they all are "candidates".
    >>in order to select appropriate candidate it does 3 steps--
    1)exact match
    2)type promotion..........**
    3)type conversion
    
    */

    return 0;
}

float area(float r)
{
    return 3.14*r*r;
}

int area(int a,int b)
{
    return a*b;
}

int area(int x)
{
    return x;
}