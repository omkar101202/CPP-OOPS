#include<iostream>
using namespace std;

class A
{
    private:
        void privatefuncA()
        {
            cout<<"this is private of A"<<endl;
        }
    protected:
        void protectedfuncA()
        {
            cout<<"this is protected of A"<<endl;
        }
    public:
        void publicfuncA()
        {
            cout<<"this is public of A"<<endl;
        }

    //constructor
    A()
    {
        cout<<"parent constructor"<<endl;
    }

    ~A()
    {
        cout<<"parent destructor"<<endl;
    }

};

class Av2:public A
{
    private:
        
        void privatefunc()
        {
            cout<<"this is private of Av2"<<endl;
        }
    protected:
        void protectedfunc()
        {
            cout<<"this is protected of Av2"<<endl;
        }
    public:
        void publicfunc()
        {
            cout<<"this is public of Av2"<<endl;
            
            protectedfuncA();
            publicfuncA();
        }

    //constructor in child 
    Av2():A()  //default constru. of derived class.{writing ':A()' is optional but we can if necessary }
    {
        cout<<"child constructor"<<endl;
    }

    //destructor
    ~Av2()
    {
        cout<<"child destructor"<<endl;
    }

};

int main()
{
    Av2 a;

   
    a.publicfunc();
    return 0;
}
