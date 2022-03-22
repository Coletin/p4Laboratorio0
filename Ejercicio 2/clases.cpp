#include "clases.h"
//Clase A
A::A(int na)
    {
        this->a=na;
    };
void A::printInt(){
        cout << this->a << endl;
    };
void A::setAC(C& acn){
        this->ac = &acn;
    };
C* A::getAC(){
        return this->ac;
    };
void A::setAB(B& abn){
        this->ab = &abn;
    };
B* A::getAB(){
        return this->ab;
    };
A::~A(){};

//Clase C
C::C(int nc){
    this->c=nc;
    };
void C::printInt(){
            cout << this->c << endl;
    };
void C::setCA(A& can){
        this->ca = &can;
    };
A* C::getCA(){
        return this->ca;
    };
void C::setCB(B& cbn){
        this->cb = &cbn;
    };
B* C::getCB(){
        return this->cb;
    };
C::~C(){};

//Clase B
B::B(int nb){
        this->b=nb;
    };
void B::printInt(){
            cout<<this->b << endl;
    };
void B::setBA(A& ban){
        this->ba = &ban;
    };
A* B::getBA(){
        return this->ba;
    };
void B::setbc(C& bcn){
        this->bc = &bcn;
    };
C* B::getBC(){
        return this->bc;
    };
B::~B(){};