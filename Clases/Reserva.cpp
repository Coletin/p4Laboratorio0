#include "../clases.h"

int Reserva::getCodigo(){
    return this->codigo;
};

DTFecha Reserva::getCheckIn(){
    return this->checkIn;
};

DTFecha Reserva::getCheckOut(){
    return this->checkOut;
};

EstadoReserva Reserva::getEstado(){
    return this->estado;
};

void Reserva::setCodigo(int& Ncodigo){
    this->codigo = Ncodigo;
};

void Reserva::setCheckIn(DTFecha& NcheckIn){
    this->checkIn = NcheckIn;
};

void Reserva::setCheckOut(DTFecha& NcheckOut){
    this->checkOut = NcheckOut;
};

void Reserva::setEstado(EstadoReserva& Nestado){
    this->estado = Nestado;
};