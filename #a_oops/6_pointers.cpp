#include<iostream>
using namespace std;

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
   c1.showdata();
    return 0;
}

