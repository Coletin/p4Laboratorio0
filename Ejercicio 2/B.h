#include<iostream>
#include "A.h"
#include "C.h"
using namespace std;
C c();
A a();


class B
{
private:
   int b;
    A ba;
    C bc;

public:
   B(){
       b=0;
   }
        B(int a, int b,int c):ba(a),bc(c)
    {
        this->b=b;
    };
    void printInt(){
             printf("%d \n",b);
    }
    ~B();
};

B::~B(){
};
