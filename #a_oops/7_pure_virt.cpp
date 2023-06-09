#include<iostream>
using namespace std;

class shape 
{
    public:
        virtual void area()=0;  //pure virtual function
};

class rectangle:public shape
{
    public:
        void area()
        {
            cout<<"area of rectangle"<<endl;
        }

};

class triangle:public shape
{
    public:
        void area()
        {
            cout<<"area of triangle"<<endl;
        }

};

int main()
{
    // shape s;  // you cannot create object of pure virtual function.
    //if you have not completed the pvf in derived class then you cannot create object of derived class also.
    rectangle r;
    r.area();

    triangle t;
    t.area();
    return 0;
}

//pvf-pure virtual function