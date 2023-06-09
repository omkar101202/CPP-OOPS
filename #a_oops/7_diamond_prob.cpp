#include<iostream>
using namespace std;

class A
{  
    public:
        A()
        {
            cout<<"A called."<<endl;
        }

};

class B:virtual public A
{
    public:
        B()
        {
            cout<<"b called."<<endl;
        }

};

class C:virtual public A
{
    public:
        C()
        {
            cout<<"c called"<<endl;
        }

};

class D:public B,public C
{
    public:
        D()
        {
            cout<<"d called."<<endl;
        }

};

int main()
{
    D d;

    return 0;
}

/*
here A is created two times but A of both B and C is same so each obj must be created only once ,
so to avoide this problem just add virtual key word while inheriting the class A 
*/