#include<iostream>
#include"clases.h"
using namespace std;



int main(){
B b(5);
A a(4);
C c(7);
a.setAC(c);
a.setAB(b);
a.printInt();
a.getAB()->printInt();
a.getAC()->printInt();
return 0;   
}