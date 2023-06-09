//some more deep in operator overload
#include<iostream>
using namespace std;

class person
{
    int age;
    int rank;

    public:
    int getage()
    {
        return age;
    }
    int getrank()
    {
        return rank;
    }

    person(int a,int r)
    {
        cout<<"parameter constructor"<<endl;
        age=a;
        rank=r;
    }
    //copy constructor
    person(const person &p)   
    //if we dont write const keyword then  can be execute but to prevent that no one should change our values we should use 'const'
    {
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

    person operator++()       //pre increment
    {
        person temp;
        temp.age=++age;
        temp.rank=++rank;
        return temp;
    }

    person operator++(int useless)       //post increment--->>##pass int      (passing  int tells compiler that the "++" called is post increment)
    {
        person temp;
        temp.age=age++;
        temp.rank=rank++;
        return temp;
    }

    void display()
    {
        cout<<"person age-"<<age;
        cout<<"person rank-"<<rank<<endl;
    }

    friend ostream &operator<<(ostream &os, person p);
    // friend operator<<(istream , person );

};

ostream &operator<<(ostream &os , person p)
{
    cout<<"<< overloaded"<<endl;
    os<<"person age-"<<p.age;
    os<<"person rank-"<<p.rank<<endl;
}

int main()
{
    person p1(20,23);
    person p2=p1;
    person p3=p1+p2;    
    cout<<endl;  
    /*for line 'p3=p1+p2' first the copy constructor is called then the + operator is called and then default constructor is called for p3*/

    // p3++;    // error: no ‘operator++(int)’ declared for postfix ‘++’...........post   >>extra (int)
          //        ###pass int as referance in post increment.
    // ++p3        // error: no match for ‘operator++’................................pre
    (p3).display();
    (++p3).display();
    (p3++).display(); 
    (p3).display();
    cout<<endl;
    cout<<p3<<p2;   //


    // cout<<"first age-"<<p1.getage();
    // cout<<"first rank-"<<p1.getrank()<<endl;
    // cout<<"second age-"<<p2.getage();
    // cout<<"second rank-"<<p2.getrank()<<endl;
    // cout<<"third age -"<<p1.getage();
    // cout<<"third rank -"<<p1.getrank()<<endl;

}

//###
//internally compiler creates temporary objects for its own use and that time also constructor made by us is called.
//so some time you may notice that calling of default or copy constructor within the program.
//###