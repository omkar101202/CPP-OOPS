#include<iostream>
using namespace std;

class item
{
    private:
        int a,b;
    public:
        friend void f1(item);
        void setdata(int x, int y){ a=x; b=y;}
};

// class A
// {
//     public:
//         void f1;
// }

void f1(item i)
{
    cout<<"sum is"<<i.a+i.b;
}

int main()
{
    item i1;
    i1.setdata(10,20);
    f1(i1);
    // f1(); //it is a non member func. so it should not call by i1. or something
    // A obj;
    /* but now f1 is member of class A now membership label is require so it should be written as-*/
    // obj.f1();
    cout<<endl;
    return 0;
}