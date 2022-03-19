#include<iostream>
#include"clases.h"
using namespace std;



int main(){
B b(5);
A a(4);
C c(7);
b.ba = &a;
b.bc = &c;
c.ca = &a;
c.cb = &b;
a.ab = &b;
a.ac = &c;
a.printInt();
b.printInt();
c.printInt();
return 0;   
}