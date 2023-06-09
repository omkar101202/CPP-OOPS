#include<iostream>
using namespace std;
//operator can also be defined as friend functinn.
class complex
{
    private:
        int a,b;
    public:
        void setdata(int x,int y)
        { a=x; b=y;}

        void showdata()
        { cout<<a<<"+"<<b<<"i"<<endl;}

        friend complex operator+(complex,complex);
        friend complex operator-(complex);    

        complex operator+(int k)
        {
            complex temp;
            temp.a=a+k;
            temp.b=b;
            return temp;
        } 

        friend complex operator+(int,complex);
};

complex operator+(complex x, complex y)    
    {   
        complex temp;
        temp.a=x.a+y.a;
        temp.b=x.b+y.b;
        return temp;
    }

complex operator+(int k,complex x)
    {
        complex temp;
        temp.a=k+x.a;
        temp.b=x.b;
        return temp;
    }

complex operator-(complex x)
    {
        complex temp;
        temp.a=-x.a;
        temp.b=-x.b;
        return temp;
    }

int main()
{
    complex c1,c2,c3,c4;
   c1.setdata(3,4);
   c2.setdata(5,6);
   
   c3=c1+c2;  //c3=operator+(c1,c2)   -->now here c1 is not caller obj. 
   // it can read as "+" operator is called by c1 & C2 IS passed as argument and value returned by + operator is stored in c3.
   c1.showdata();
   c2.showdata();
   c3.showdata();
   c4=-c3;   
   c4.showdata();

   //now
   c3=c1+10;
   //but if we write,
   c3=10+c1; //so for this defining a operator is not possible as always left operand is caller obj. but "5" is not an obj so it cant be caller to operator
   //but we can define it as a friend function.
   c3.showdata();
    return 0;
}

