#include<iostream>
#include "A.h"
#include "B.h"
using namespace std;
B b();
A a();

class C
{
private:
    A ca;
    B cb;
   int c;
public:
    C(){
    c=0;
    }
    C(int a, int b,int c):ca(a),cb(c){
        this->c=c;
    };
    void printInt(){
            printf("%d \n",c);
    }
    ~C();
};
C::~C(){
};

