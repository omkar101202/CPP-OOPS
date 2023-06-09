#include <iostream>
using namespace std;

class base
{
public:
    // base()
    // {
    //     cout << "base constructor" << endl;
    // }

    void printbase()
    {
        cout<<"base class."<<endl;
    }
};

class derived : public base
{
public:
    // derived()
    // {
    //     cout << "derived constructor" << endl;
    // }


    //###function overriding###
    //in function overriding which function will run will be decided by the pointer type which is calling the function.
    void printbase()
    {
        cout<<"modified base class.(function overriding)"<<endl;
    }

    void printderived()
    {
        cout<<"derived class."<<endl;
    }
};

int main()
{
    base *b;
    derived *d;

    base obj1;
    derived obj2;

    /*
    below-lhs=pointer type
          rhs=object type.
    
    ##pointer jis type ka hai uska function call hoga.##
    */
    b=&obj1;     //1.base pointer can point to base object->valid
    b->printbase();
    // b->printderived();  //{error because pointer is of base type so it can call only function of base class.}

    d=&obj2;     //2.derived pointer can point to dreived object->valid
    d->printbase();
    d->printderived();
    //as pointer is of derived type it can call function of derived class(and derived class contain both base +derived function.)

    b=&obj2;     //3.base pointer can point to derived object->valid
    b->printbase();
    // b->printderived();  //{error because pointer is of base type so it can call only function of base class.} 

    //d=&obj1;   //4.##->derived pointer cannot point to base object.##
}

/*#pointer and reference variable is created at compile time.
  #object is created at runtime.
  (first compile time then runtime.)

reason-
    ##pointer jis type ka hai uska function call hoga##
    now in 4.d=&obj1
    ->pointer is of derived type so it can access function of derived class (and derived class contain func of base class also) but pointer is holding object of base class and there are no function of derived class so pointer may try to access function of derived class which is not present.
    so it gives error.

*/

/*
'function overloading" and 'function overriding' are two different things.

func overloading->it takes place in a same class.
{class is same and we have make different versions of same function}

func overriding->it takes place between two inherited class.
{name of function and parameter everything is same but we change the code(functionality) of that function in other(derived) class.}
*/

//virtual function depends on object type.

/*###
instead of pointer we can use referance variables ,like
instead of "*b" or "*d"-
we can make {base &b=obj1/derived &d=obj2}-here b and d are referance variable and direct object is pointing to them.
and the function of the object are accessed using dot operator where in pointer we use arrow operator.
other things are same as pointer (like "jiska pointer(reference var.) uska function call hoga")
###*/