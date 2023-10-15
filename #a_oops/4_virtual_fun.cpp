#include<iostream>
using namespace std;

class A{

    // *_vptr

    /*
    1. whenever we declare any VF in a class compiler creates a new variable as a member[it is not static so for each object there will be vptr] *_vptr in class[we can check by sizeof(A) , it will be '4' more then expected.]

    2.then a static array will be created. it is the array of pointers and will not store address of variable but will store address of functions(these aer such pointers that stores address of virtual function only)
    and this array is known as 'vtable'.
    [it will be created for each class parent(A) , inherited(B) but *_vptr will only be one in parent class.]
    */

    public:

    void f1() {}

    virtual void f2() {}

    virtual void f3() {}

    virtual void f4() {}

    /*
    vtable of A will have address of,
    f2  ->parent
    f3  ->parent
    f4  ->parent
    */
};

class B : public A{

    public:

    void f1() {}   

    void f2() {}

    void f4(int x) {}  //it is not VF. this is function hiding.

    /*
    vtable of B will have address of,
    f2  ->child
    f3  ->parent
    f4  ->child
    */

};

int main(){
     A a;
    cout<<sizeof(A)<<endl;
}