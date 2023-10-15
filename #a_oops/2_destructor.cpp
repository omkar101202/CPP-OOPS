#include<iostream>
using namespace std;
class complex
{
    private:
        int a,b;
    public:
        complex()  { a=0; b=0;}
        complex(int p, int q) { a=p; b=q;}
        complex(int x){ a=x; b=0;}
        complex(complex &c) { a=c.a; b=c.b;}

        //destructor...
        ~complex()  //default destructor with empty body.
        {
            cout<<"bye";
        }

        void setdata(int x,int y)
        { a=x; b=y;}
        
        void showdata()
        { cout<<a<<"+"<<b<<"i"<<endl;}
        complex add(complex c)  
        {   
            complex temp;
            temp.a=a+c.a;
            temp.b=b+c.b;
            return temp;
        }
};

int main()
{
    complex c1(5,6),c2(2,1),c3(2),c4;
    complex c5=c1;

   
   c1.showdata();
   c2.showdata();
   c3.showdata();
   c5.showdata();

    return 0;
}

/*
constructor can be overlosded similar to function overloading.
but
destructor cannot be overloaded.
*/