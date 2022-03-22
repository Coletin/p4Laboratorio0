#include "../clases.h"
#include "../tipos.h"

Habitacion::Habitacion(){
};

Habitacion::Habitacion(int _numero, float _precio, int _capacidad){
    this->capacidad = _capacidad;
    this->numero = _numero;
    this->precio = _precio;
};

int Habitacion::getNumero(){
    return this->numero;
};

void Habitacion::setNumero(int _numero){
    this->numero = _numero;
};

float Habitacion::getPrecio(){
    return this->precio;
};

void Habitacion::setPrecio(float _precio){
    this->precio = _precio;
};

int Habitacion::getCapacidad(){
    return this->capacidad;
};

void Habitacion::setCapacidad(int _capacidad){
    this->capacidad = _capacidad;
};

