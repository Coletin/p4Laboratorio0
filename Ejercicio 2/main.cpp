#include<iostream>
#include"A.h"
#include"B.h"
#include"C.h"
using namespace std;



int main(){
    C c();
    B b();
    A a();
    A a(2);
    B b(2);
    C c(18);
    a.printInt();
    b.printInt();
    c.printInt();
    
    return 0;   
}