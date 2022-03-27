#include "../clases.h"
#include <iostream>
#include <typeinfo>
using namespace std;
#include <stdexcept>
Sistema::Sistema(){
    this->huespedes[0]=nullptr;
    this->habitaciones[0]=nullptr;
    this->reservas[0]=nullptr;
};

void Sistema::agregarHuesped(string nombre, string email, bool esFinger){
    if(this->existeHuesped(email)){
        throw std::invalid_argument("Ya existe el huesped.");
    }
         this->huespedes[this->cantHuespedes] = new Huesped(nombre, email, esFinger);
         this->cantHuespedes ++;
         this->huespedes[this->cantHuespedes] = nullptr;
}

void Sistema::agregarHabitacion(int numero, float precio, int capacidad){
    if(this->topeHabitaciones == MAX_HABITACIONES)
        throw std::invalid_argument( "Se alcanzó la cantidad máxima de huéspedes" );
    if(numero < 0)
        throw std::invalid_argument( "El numero de habitación debe ser positivo" );
    if(precio < 0)
        throw std::invalid_argument( "El precio no debe ser negativo" );
    if(capacidad < 0)
        throw std::invalid_argument( "La capacidad no debe ser negativa" );

    int busqueda = 0;
    while(busqueda < topeHabitaciones && this->habitaciones[busqueda]->getNumero() != numero){
        busqueda ++;
    }
    if(busqueda < topeHabitaciones)
        throw std::invalid_argument( "Ya existe una habitación con el número indicado" );
    //llegamos hasta aca entonces podemos agregar OK
    Habitacion* habitacionAgregar = new Habitacion(numero, precio, capacidad);
    this->habitaciones[this->topeHabitaciones] = habitacionAgregar;
    this->topeHabitaciones= this->topeHabitaciones + 1;
    this->habitaciones[this->topeHabitaciones] = nullptr;
};

void Sistema::registrarReserva(string email,DTReserva* reserva){
    int huespedEnSistema = 0;
    int habitacionEnSistema = 0;
    while((huespedEnSistema <= this->cantHuespedes) && (email != huespedes[huespedEnSistema]->getEmail())){
        huespedEnSistema++;
    }
    if(huespedEnSistema > this->cantHuespedes)
        throw std::invalid_argument("No existe un huésped registrado con el email");
    else{
        while((habitacionEnSistema <= this->topeHabitaciones) && (reserva->getHabitacion() != habitaciones[habitacionEnSistema]->getNumero())){
            habitacionEnSistema++;
        }
        if(habitacionEnSistema > topeHabitaciones){
            throw std::invalid_argument("no existe una habitación registrada en el sistema con el número indicado");
        }else{
            int codigo= reserva->getCodigo();
            DTFecha cIn= reserva->getchekIn();
            DTFecha cOut= reserva->getchekOut();
            EstadoReserva estado = reserva->getEstadoReserva();
            Habitacion* habitacion = habitaciones[habitacionEnSistema];
            Huesped* huesped = huespedes[huespedEnSistema];
            if( dynamic_cast<DTReservaGrupal*>(reserva) != 0 ){
                DTReservaGrupal *reservaGrupal = dynamic_cast<DTReservaGrupal*>(reserva);
                Huesped** huespedes = new Huesped*[MAX_HUESPEDES]; //TODO cambiar por el tamaño actual de huespedes del DT
                DTHuesped** dtHuespedes = reservaGrupal->getHuespedes();
                int i = 0;
                while (dtHuespedes[i] != nullptr){
                     string nombre = dtHuespedes[i]->getNombre();
                     string email = dtHuespedes[i]->getEmail();
                     bool esFinger = dtHuespedes[i]->getEsFinger();
                     huespedes[i] = new Huesped(nombre, email, esFinger);
                     i++;
                }
                huespedes[i] = nullptr;
                reservas[this->topeReservas] = new ReservaGrupal(codigo,cIn,cOut,estado,habitacion,huesped,huespedes);
                this->topeReservas++;
                reservas[this->topeReservas] = nullptr;
                //cout << "reserva grupal";
            }else if( dynamic_cast<DTReservaIndividual*>(reserva) != 0 ){
                DTReservaIndividual *reservaIndividual = dynamic_cast<DTReservaIndividual*>(reserva);
                bool pagado = reservaIndividual->getPagado();
                reservas[this->topeReservas] = new ReservaIndividual(codigo,cIn,cOut,estado,habitacion,huesped,pagado);
                this->topeReservas++;
                reservas[this->topeReservas] = nullptr;
            };
        };
    };
};

bool Sistema::existeHuesped(string _email){
    int contador = 0;
    while(contador < this->cantHuespedes && _email.compare(this->huespedes[contador]->getEmail()) != 0){
        contador ++;
    }
    return contador < this->cantHuespedes;
}

Huesped* Sistema::buscarHuesped(string _email){
    int contador = 0;
    while(contador < this->cantHuespedes && _email.compare(this->huespedes[contador]->getEmail()) != 0){
        contador ++;
    }
    return huespedes[contador];
}

bool Sistema::existeHabitacion(int _numero){
    int contador = 0;
    while(contador < this->topeHabitaciones && this->habitaciones[contador]->getNumero() != _numero){
        contador ++;
    }
    return contador < this->topeHabitaciones;
}

DTReserva** Sistema::obtenerReservas(DTFecha fecha,int& cantReservas){
    cantReservas=0;
    DTReserva** resu = new DTReserva*[this->topeReservas + 1];
    //DTReserva** resuN = resu;
    int i = 0;
    //cout << this->reservas[0]->calcularCosto();
    while (i < this->topeReservas && this->reservas[i] != nullptr){
        if(this->reservas[i]->getCheckIn() == fecha){
            if(dynamic_cast<ReservaGrupal*>(reservas[i]) != 0){
                ReservaGrupal *_ReservaGrupal = dynamic_cast<ReservaGrupal*>(this->reservas[i]);
                int _codigo = _ReservaGrupal->getCodigo();
                DTFecha checkin = _ReservaGrupal->getCheckIn();
                DTFecha checkout = _ReservaGrupal->getCheckOut();
                EstadoReserva _estado = _ReservaGrupal->getEstado();
                float _costo = _ReservaGrupal->calcularCosto();
                int _habitacion = _ReservaGrupal->getHabitacion()->getNumero();
                DTHuesped** _huespedes = new DTHuesped*[cantHuespedes]; //TODO obtener la cantidad actual de huespedes de la reserva
                Huesped** auxhuespedes = _ReservaGrupal->getHuespedes();
                int j = 0;
                while (auxhuespedes[j] != nullptr){
                     string nombre = auxhuespedes[j]->getNombre();
                     string email = auxhuespedes[j]->getEmail();
                     bool esFinger = auxhuespedes[j]->getEsFinger();
                     _huespedes[j] = new DTHuesped(nombre,email,esFinger);
                     j++;
                }
                _huespedes[j]= nullptr;
                resu[i]= new DTReservaGrupal(_codigo,checkin,checkout,_estado,_costo,_habitacion,_huespedes );
            }else{
                ReservaIndividual *_ReservaIndividual = dynamic_cast<ReservaIndividual*>(this->reservas[i]);
                int _codigo = _ReservaIndividual->getCodigo();
                DTFecha checkin = _ReservaIndividual->getCheckIn();
                DTFecha checkout = _ReservaIndividual->getCheckOut();
                EstadoReserva _estado = _ReservaIndividual->getEstado();
                float _costo = _ReservaIndividual->calcularCosto();
                int _habitacion = _ReservaIndividual->getHabitacion()->getNumero();
                bool _pagado = _ReservaIndividual->getPagado();
                resu[i]= new DTReservaIndividual(_codigo,checkin,checkout,_estado,_costo,_habitacion,_pagado);
            }
            cantReservas ++;
        }
        i++;
    }
    resu[i] = nullptr;
    return resu;
};

DTHuesped** Sistema::obtenerHuespedes(int& cantHuespedes){
    DTHuesped** respuesta = new DTHuesped*[this->cantHuespedes + 1];
    //DTHuesped** respuestaN = respuesta;
    respuesta[this->cantHuespedes] = nullptr;
    cantHuespedes = this->cantHuespedes;
    for(int i = 0; i<cantHuespedes; i++){
        string nombre = this->huespedes[i]->getNombre();
        string email = this->huespedes[i]->getEmail();
        bool esFinger = this->huespedes[i]->getEsFinger();
        respuesta[i] = new DTHuesped(nombre, email, esFinger);
    }
    return respuesta;
};

DTHabitacion** Sistema::obtenerHabitaciones(int& cantHabitaciones){
    DTHabitacion** respuesta = new DTHabitacion*[this->topeHabitaciones + 1];
    //DTHabitacion** respuestaN = respuesta;
    respuesta[this->topeHabitaciones] = nullptr;
    cantHabitaciones = this->topeHabitaciones;
    for(int i = 0; i<this->topeHabitaciones; i++){
        int numero = this->habitaciones[i]->getNumero();
        float precio = this->habitaciones[i]->getPrecio();
        int capacidad = this->habitaciones[i]->getCapacidad();
        respuesta[i] = new DTHabitacion(numero, precio, capacidad);
    };
    return respuesta;
};
