#include<iostream>
using namespace std;

class flight
{
    public:
        void search()
        {
            cout<<"search flight."<<endl;
        }

        virtual void book()
        {
            cout<<"flight booked."<<endl;
        }

};

class airindia:public flight
{
    void book()
        {
            cout<<"air india flight booked."<<endl;
        }
};

class spicejet:public flight
{
    void book()
        {
            cout<<"spicejet flight booked."<<endl;
        }
};
int main()
{
    flight *fli1;
    flight *fli2;
    airindia ai;
    spicejet sj;

    fli1=&ai;
    fli1->search();
    fli1->book();

    fli2=&sj;
    fli2->search();
    fli2->book();

    return 0;
}

//## in normal function which one will be called depends on the pointer type.
//this is decided at compile time so it is early binding(compile time binding.)

//## in virtual function which function will be called depends on object type.
//this is decided at runtime [the type of object we assign to the pointer] so it is late binding(runtime time binding)