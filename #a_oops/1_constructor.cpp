#include<iostream>
using namespace std;
class complex
{
    private:
        int a,b;
    public:
            //constructor>>instance member
            /*
             compiler creates 2 constructors by its own 
             1)default con. 2)copy con.
             */
        complex()  
        {
            a=0; b=0;
        }
        
        complex(int p, int q)
        {
            a=p;
            b=q;
        }

        complex(int x)
        {
            a=x;
            b=0;
        }

        complex(complex &c) //##copy constructor
        {
            a=c.a;
            b=c.b;
        }

        void setdata(int x,int y)
        {
            a=x;
            b=y;
        }
        void showdata()
        {
            cout<<a<<"+"<<b<<"i"<<endl;
        }
        complex add(complex c)  //func. taking and returning object.
        {   
            complex temp;
            temp.a=a+c.a;
            temp.b=b+c.b;

            return temp;
        }
};

int main()
{
    complex c1(5,6),c2(2,1),c3(2),c4;
    //complex c1=complex(5,6) is same as complex c1(5,6)
    complex c5=c1; 
    //you can also write >> complex c1(c5) is same as complex c5=c1
    //c5 is a object in which c1 object is passed as argument.
    /*
    in line 'c5=c1' none of the constuctor is used here a "copy constructor"is used which was created by a compiler 
    */

    c4=c2;   //here no cunstructor is called bcoz objects are already created .>>here only assignment(=) operator is used.
   
   /* //use of add func.
    c1.setdata(3,4);
    c2.setdata(5,6);
    // c3=c1+c2;
    c3=c1.add(c2);    //....imp.>>>c1 is a object called add func. in which object c2 is passed as argument and add returned the value is stored in c3
    c3.showdata();
    */

   
   c1.showdata();
   c2.showdata();
   c3.showdata();
   c5.showdata();

    return 0;
}

/*
constructor can be overlosded similar to function overloading.
but
destructor cannot be overloaded.
*/