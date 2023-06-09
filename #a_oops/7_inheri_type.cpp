#include<iostream>
using namespace std;

class A
{
    public:
        void fun1()
        {
            cout<<"function 1 of A."<<endl;
        }
    protected:
        void fun2()
        {
            cout<<"function 2 of A."<<endl;
        }
    private:
        void fun3()
        {
            cout<<"function 3 of A."<<endl;
        }

};

class B:public A
{   //only protected and public are accessible in derived class.
    public:
        void checkprotected()
        {
            fun1();  //protected
            fun2();  //protected
        }


};

class C:public B
{
    // fun1();  ==protected
    // // fun2(); ==protected
    public:
        void checkprotected()
        {
            fun1();  //protected
            fun2();  //protected
        }

};

int main()
{
    A a;
    //protected and private cannot be accessed directly from main function.(USER 2)
    // a.fun1();

    B b;
    // b.fun1();
    // b.checkprotected();
    
    C c;
    c.checkprotected();

}