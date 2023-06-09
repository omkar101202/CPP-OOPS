#include<iostream>
using namespace std;

/*
'this" pointer is local object pointer in every instance member function contain address of current obj.
##it can't be modified.
*/

class complex
{
    private:
        int a,b;
    public:
    //1)-used to avoide name conflict between instance member variable and local variable.
        void setdata(int a,int b)
        { this->a=a; this->b=b;}

        void showdata()
        { cout<<a<<"+"<<b<<"i"<<endl;}

    //2)whenever it is required to represent current(caller) object in instance member function.
        complex sumgreater(complex c)
        {
            if( (a+b) > (c.a+c.b) )
                return *this;
            else
                return c;
        }

        complex operator+(int k)
        {
            complex temp;
            temp.a=a+k;
            temp.b=b;
            return temp;
        } 

       
};


void inputdata(complex *p)
{
        int x,y;
        cout<<"enter real and img part -";
        cin>>x>>y;
        p->setdata(x,y);
}

int main()
{
    complex c1,c2,c3,c4;
   inputdata(&c1);
   c2.setdata(4,5);
   c3=c1.sumgreater(c2);
    return 0;
}

