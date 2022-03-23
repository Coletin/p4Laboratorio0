#include "../clases.h"

string Huesped::getEmail(){
    return this->email;
};

Huesped::Huesped(string Nnombre, string Nemail, bool NesFinger){
    this->nombre = Nnombre;
    this->email = Nemail;
    this->esFinger = NesFinger;
};