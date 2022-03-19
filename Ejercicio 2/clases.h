#include<iostream>
using namespace std;

class C;
class B;



class A
{
private:
    int a;
    B ab;  
    C ac;

public:
   A(){
    a=0;
   }
    A(int a,int b, int c):ab(),ac()
    {
        this->a=a;
    };
    void printInt(){
         printf("%d \n",a);
    }
    ~A();
};


class C
{
    B* cb;
private:

   int c;
public:
    C(){
    c=0;
    }
    C(int c){
    this->c=c;
    }
    C(int c):cb(){
        this->c=c;
    };
    void printInt(){
            printf("%d \n",c);
    }
    ~C();
};












class B
{
private:
   int b;

public:
   B(){
       b=0;
   }
        B( int b)
    {
        this->b=b;
    };
    void printInt(){
             printf("%d \n",b);
    }
    ~B();
};







A::~A(){
};



B::~B(){
};



C::~C(){
};

