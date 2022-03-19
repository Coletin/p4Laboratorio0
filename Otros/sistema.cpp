#include "../clases.h"
#include <iostream>
using namespace std;

#define MAX_HUESPEDES 256;

Sistema::Sistema(){
};

Sistema::agregarHuesped(string nombre, string email, bool esFinger){
    bool esta = false;
    bool final = false;
    int i = 0;
    while (!esta && !final && i < MAX_HUESPEDES){
        if(this->huespedes[i] != null){            
            esta = this->huespedes[i]->getEmail() == email;
            i += 1;
        }else{
            final = true;
        }
    }

    if(final && !esta){
        this->huespedes[i] = new Huesped(nombre, email, esFinger);
    }else{
        throw std::invalid_argument("Ya existe el huesped.");
    }
    
}