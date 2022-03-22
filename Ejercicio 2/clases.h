#include<iostream>
using namespace std;

class C;
class B;

class A
{
private:
    int a;
    B* ab;
    C* ac;
public:
    A(int na);
    void printInt();
    void setAC(C& acn);
    C* getAC();
    void setAB(B& abn);
    B* getAB();
    ~A();
};


class C
{
private:
    int c;
    B* cb;
    A* ca;
public:
    C(int nc);
    void printInt();
    void setCA(A& can);
    A* getCA();
    void setCB(B& cbn);
    B* getCB();
    ~C();
};


class B
{
private:
    int b;
    A* ba;
    C* bc;
public:
    B(int nb);
    void printInt();
    void setBA(A& ban);
    A* getBA();
    void setbc(C& bcn);
    C* getBC();
    ~B();
};