#include<iostream>
using namespace std;

class C;
class B;

class A
{
private:
    int a;
public:
    B* ab;  
    C* ac;
    A(int na)
    {
        this->a=na;
    };
    void printInt(){
        cout << this->a << endl;
    };
    ~A();
};


class C
{
private:
   int c;
public:
    B* cb;
    A* ca;
    C(int nc){
    this->c=nc;
    };
    void printInt(){
            cout << this->c << endl;
    }
    ~C();
};


class B
{
private:
   int b;
public:
    A* ba;
    C* bc;
    B(int nb){
        this->b=nb;
    };
    void printInt(){
            cout<<this->b << endl;
    };
    ~B();
};







A::~A(){
};



B::~B(){
};



C::~C(){
};

