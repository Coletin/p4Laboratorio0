#include<iostream>
#include "C.h"
#include "B.h"
using namespace std;
B b();
C c();


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
    A(int a, int b,int c):ab(b),ac(c)
    {
        this->a=a;
    };
    void printInt(){
         printf("%d \n",a);
    }
    ~A();
};

A::~A(){
};