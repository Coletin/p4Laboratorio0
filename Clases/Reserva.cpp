#include "../clases.h"

Reserva::Reserva(int _codigo,DTFecha _checkIn,DTFecha _checkOut,EstadoReserva _estado,Habitacion* _habitacion,Huesped * _huesped){
    this->codigo= _codigo;
    this->checkIn= _checkIn;
    this->checkOut= _checkOut;
    this->estado= _estado;
    this->habitacion= _habitacion;
    this->huesped= _huesped;
};

Huesped* Reserva::getHuesped(){
    return this->huesped;
};

Reserva::~Reserva(){}

int Reserva::getCodigo(){
    return this->codigo;
};

DTFecha Reserva::getCheckIn(){
    return this->checkIn;
};

DTFecha Reserva::getCheckOut(){
    return this->checkOut;
};

EstadoReserva Reserva::getEstadoReserva(){
    return this->estado;
};

Habitacion* Reserva::getHabitacion(){
    return this->habitacion;
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

int diasDeReserva(DTFecha cIn,DTFecha cOut){ //mal
    int diascIn = cIn:getDia + ((cIn:getMes - 1) * 31) + (cIn:getAnio * 364);
    int diascOut = cOut:getDia + ((cOut:getMes - 1) * 31) + (cOut:getAnio * 364);
    return diascOut - diascIn;
}

ReservaGrupal::ReservaGrupal(int _codigo,DTFecha _checkIn,DTFecha _checkOut,EstadoReserva _estado,Habitacion* _habitacion,Huesped* _huesped, Huesped** _huespedes):Reserva(_codigo, _checkIn, _checkOut, _estado, _habitacion, _huesped){
    this->huespedes = _huespedes;
};

float ReservaGrupal::CalcularCosto(){
    int i = 0;
    int fing = 0;
    while(this->huespedes[i] != NULL){
        if(this->huespedes[i]->Huesped:getEsFinger())
            fing++;
    }
    float costo = (this->habitacion->Habitacion::getCosto() * diasDeReserva(this->checkIn,this->checkOut)) * (i-1);
    if(fing > 1)
        costo = costo - costo*0.3;
    return costo;
};

ReservaGrupal::~ReservaGrupal(){};

Huesped** ReservaGrupal::getHuespedes(){
    return huespedes;
};

ReservaIndividual::ReservaIndividual(int _codigo,DTFecha _checkIn,DTFecha _checkOut,EstadoReserva _estado,Habitacion* _habitacion,Huesped* _huesped, bool _pagado):Reserva(_codigo, _checkIn, _checkOut, _estado, _habitacion, _huesped){
    this->pagado = _pagado;
};

ReservaIndividual::~ReservaIndividual(){};

bool ReservaIndividual::getPagado(){
    return this->pagado;
};

float ReservaIndividual::calcularCosto(){
    return habitacion->Habitacion::getCosto * diasDeReserva(checkIn,checkOut);
};