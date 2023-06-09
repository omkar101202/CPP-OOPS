//some more deep in operator overload
#include<iostream>
using namespace std;

class person
{
    int age;
    int rank;

    public:

     person(int a,int r)
    {
        cout<<"parameter constructor"<<endl;
        age=a;
        rank=r;
    }
    //copy constructor
    person(const person &p)       {
        // p.age=50;
        cout<<"copy constructor"<<endl;
        age=p.age;
        rank=p.rank;
    }

    person()   //default constructor
    {
        cout<<"default constructor"<<endl;    
    }

    person operator+(person p)
    {
        cout<<"operator +"<<endl;
        person temp;
        temp.age=age+p.age;
        temp.rank=rank+rank;
        return temp;
    }
    void display()
    {
        cout<<"person age-"<<age;
        cout<<"person rank-"<<rank<<endl;
    }


    void operator<<(ostream &os)
    {
        os<<"person age-"<<age;
        os<<"person rank-"<<rank<<endl;
    }

    // friend ostream &operator<<(ostream &os, person p);
};

// ostream &operator<<(ostream &os , person p)
// {
//     cout<<"<< overloaded"<<endl;
//     os<<"person age-"<<p.age;
//     os<<"person rank-"<<p.rank<<endl;
// }

int main()
{
    person p1(20,23);
    person p2=p1;
    person p3=p1+p2;    
    cout<<endl;  
    
    p2.display();
    cout<<endl;

    p3<<cout;  //


    

}

