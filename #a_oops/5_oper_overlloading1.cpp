#include<iostream>
using namespace std;
//the operator which are present in c lang. only that primitive operator can be overloaded in c++
class complex
{
    private:
        int a,b;
    public:
        void setdata(int x,int y)
        { a=x; b=y;}

        void showdata()
        { cout<<a<<"+"<<b<<"i"<<endl;}

        // complex add(complex c) ..............
        complex operator+(complex c)    //operator overload.
        {   
            complex temp;
            temp.a=a+c.a;
            temp.b=b+c.b;
            return temp;
        }

        //unary operov
        complex operator-()
        {
            complex temp;
            temp.a=-a;
            temp.b=-b;
            return temp;
        }
};

int main()
{
    complex c1,c2,c3,c4;
   c1.setdata(3,4);
   c2.setdata(5,6);
   //c3=c1.add(c2);  ...............
   c3=c1+c2;  //here c1 is caller obj. and c2 is passed as argument.
   //c3=c1.operator+(c2); same as c3=c1+c2;

   c1.showdata();
   c2.showdata();
   c3.showdata();
   c4=-c3;   //c3 is a caller obj. called '-' operator then value returned by "-" is assigned in c4.
   c4.showdata();

    return 0;
}

/*  why sizeof () operator cant be overloaded?
    -->>  function of sizeof () operator is to give size of any data type so there are no any other possibilities to define its meaning.
*/