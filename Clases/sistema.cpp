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
    bool esta = false;
    bool finals = false;
    int i = 0;
    while (!esta && !finals && i < MAX_HUESPEDES){
        if(this->huespedes[i] != nullptr){            
            esta = this->huespedes[i]->getEmail() == email;
            i += 1;
        }else{
            finals = true;
        }
    }
    if(finals && !esta){
        this->huespedes[i] = new Huesped(nombre, email, esFinger);
        this->cantHuespedes = this->cantHuespedes + 1;
        this->huespedes[this->cantHuespedes] = nullptr;
    }else{
        throw std::invalid_argument("Ya existe el huesped.");
    }
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
            if(typeid(reserva).name()=="DTReservaGrupal"){              
                DTReservaGrupal* dtReservagrupal = (DTReservaGrupal*)reserva; //no estoy seguro si funciona
                Huesped* huespedes[MAX_HUESPEDES];
                DTHuesped** dtHuespedes = dtReservagrupal->getHuespedes();
                int i = 0;
                while (dtHuespedes[i] != nullptr){
                    string nombre = dtHuespedes[i]->getNombre();
                    string email = dtHuespedes[i]->getEmail();
                    bool esFinger = dtHuespedes[i]->getEsFinger();
                    huespedes[i] = new Huesped(nombre,email,esFinger); //no se si falta *
                    i++;
                }
                huespedes[i] = nullptr;
                reservas[this->topeReservas] = new ReservaGrupal(codigo,cIn,cOut,estado,habitacion,huesped,huespedes);
                this->topeReservas++;
            }else{
                DTReservaIndividual* reservaindividual = (DTReservaIndividual*)reserva;
                bool pagado = reservaindividual->getPagado();
                bool pagado = true;
                reservas[this->topeReservas] = new ReservaIndividual(codigo,cIn,cOut,estado,habitacion,huesped,pagado);
                this->topeReservas++;
            }
        }
    }
};

DTReserva** Sistema::obtenerReservas(DTFecha fecha,int& cantReservas){
    cantReservas=0;
    DTReserva* resu[MAX_RESERVAS];
    int i = 0;
    while (i <= topeReservas){
        if(this->reservas[i] == nullptr){
            resu[cantReservas] = nullptr;
        }else{
            if(typeid(this->reservas[i]).name()=="ReservaGrupal*"){//duda
                ReservaGrupal* _ReservaGrupal = (ReservaGrupal*)this->reservas[i];
                int _codigo = _ReservaGrupal->getCodigo();
                DTFecha _chekIn = _ReservaGrupal->getCheckIn();
                DTFecha _chekOut = _ReservaGrupal->getCheckOut();
                EstadoReserva _estado = _ReservaGrupal->getEstado();
                float _costo = _ReservaGrupal->calcularCosto();
                int _habitacion = _ReservaGrupal->getHabitacion()->getNumero();
                DTHuesped* _huspedes[MAX_HUESPEDES];
                Huesped** auxhuespedes = _ReservaGrupal->getHuespedes();
                int j = 0;
                while (auxhuespedes[j] != nullptr){
                    string nombre = auxhuespedes[j]->getNombre();
                    string email = auxhuespedes[j]->getEmail();
                    bool esFinger = auxhuespedes[j]->getEsFinger();
                    _huspedes[j] = new DTHuesped(nombre,email,esFinger); //no se si falta * y si huesped esta en arreglo
                    j++;
                }
                _huspedes[j]= nullptr;
                resu[i] = new DTReservaGrupal(_codigo,_chekIn,_chekOut,_estado,_costo,_habitacion,_huspedes);
            }else{
                ReservaIndividual* _ReservaIndividual = (ReservaIndividual*)this->reservas[i];
                int _codigo = _ReservaIndividual->getCodigo();
                DTFecha _chekIn = _ReservaIndividual->getCheckIn();
                DTFecha _chekOut = _ReservaIndividual->getCheckOut();
                EstadoReserva _estado = _ReservaIndividual->getEstado();
                float _costo = _ReservaIndividual->calcularCosto();
                int _habitacion = _ReservaIndividual->getHabitacion()->getNumero();
                bool _pagado = _ReservaIndividual->getPagado();
                resu[i]= new DTReservaIndividual(_codigo,_chekIn,_chekOut,_estado,_costo,_habitacion,_pagado);
            }
        }
    }
    return resu;
};

DTHuesped** Sistema::obtenerHuespedes(int& cantHuespedes){
    DTHuesped* respuesta[(int)MAX_HUESPEDES];
    DTHuesped** respuestaN = respuesta;
    respuesta[this->cantHuespedes] = nullptr;
    cantHuespedes = this->cantHuespedes;
    for(int i = 0; i<cantHuespedes; i++){
        string nombre = this->huespedes[i]->getNombre();
        string email = this->huespedes[i]->getEmail();
        bool esFinger = this->huespedes[i]->getEsFinger();
        respuesta[i] = new DTHuesped(nombre, email, esFinger);
    }
    return respuestaN;
};

DTHabitacion** Sistema::obtenerHabitaciones(int& cantHabitaciones){
    DTHabitacion* respuesta[(int)MAX_HABITACIONES];
    DTHabitacion** respuestaN = respuesta;
    respuesta[this->topeHabitaciones] = nullptr;
    cantHabitaciones = this->topeHabitaciones;
    for(int i = 0; i<this->topeHabitaciones; i++){
        int numero = this->habitaciones[i]->getNumero();
        float precio = this->habitaciones[i]->getPrecio();
        int capacidad = this->habitaciones[i]->getCapacidad();
        respuesta[i] = new DTHabitacion(numero, precio, capacidad);
    };
    return respuestaN;
};