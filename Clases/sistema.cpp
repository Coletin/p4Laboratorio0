#include "../clases.h"
#include <iostream>
using namespace std;
#include <stdexcept>
Sistema::Sistema(){
    this->huespedes[0]=nullptr;
    this->habitaciones[0]=nullptr;
    this->reservas[0]=nullptr;
};

void Sistema::agregarHuesped(string nombre, string email, bool esFinger){
    bool esta = false;
    bool final = false;
    int i = 0;
    while (!esta && !final && i < MAX_HUESPEDES){
        if(this->huespedes[i] != nullptr){            
            esta = this->huespedes[i]->getEmail() == email;
            i += 1;
        }else{
            final = true;
        }
    }
    if(final && !esta){
        this->huespedes[i] = new Huesped(nombre, email, esFinger);
        this->cantHuespedes = cantHuespedes + 1;
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
    this->habitaciones[topeHabitaciones] = habitacionAgregar;
    this->topeHabitaciones= this->topeHabitaciones + 1;
};

void Sistema::registrarReserva(string email,DTReserva reserva){
    int huespedEnSistema = 0;
    int habitacionEnSistema = 0;
    while((huespedEnSistema <= topeHuespedes) && (email != huespedes[huespedEnSistema]->getEmail())){
        huespedEnSistema++;
    }
    if(huespedEnSistema > topeHuespedes)
        throw std::invalid_argument("No existe un huésped registrado con el email");
    else{
        while((habitacionEnSistema <= topeHabiataciones) && (reserva:getHabitacion() != habitaciones[habitacionEnSistema]->getNumero())){
            habitacionEnSistema++;
        }
        if(habitacionEnSistema > topeHabitaciones){
            throw std::invalid_argument("no existe una habitación registrada en el sistema con el número indicado");
        }else{
            int codigo= reserva:getCodigo();
            DTFecha cIn= reserva:getCheckIn();
            DTFecha cOut= reserva:getCkeckOut();
            EstadoReserva estado = reserva:getEstado();
            Habitacion* habitacion = habitaciones[habitacionEnSistema];
            Huesped* huesped = husepedes[huespedEnSistema];
            if(esResrvaGrupal){
                Huesped** huespedes = reserva:getHuespedes();
                reservas[topeReservas] = new ReservaGrupal(codigo,cIn,cOut,estado,habitacion,huesped,huespedes);
                topeResrvas++;
            }else{
                bool pagado = reserva:getPagado();
                reservas[topeReservas] = new ReservaIndividual(codigo,cIn,cOut,estado,habitacion,huesped,pagado);
                topeReservas++;
            }
        }
    }
};

const DTHuesped** Sistema::obtenerHuespedes(int& cantHuespedes){
    const DTHuesped** respuesta[this->cantHuespedes];
    respuesta[this->cantHuespedes] = nullptr;
    cantHuespedes = this->cantHuespedes;
    
    for(int i = 0; i<this->cantHuespedes; i++){
        string nombre = this->huespedes[i]->getNombre();
        string email = this->huespedes[i]->getEmail();
        bool esFinger = this->huespedes[i]->getEsFinger();
        DTHuesped* agregar = new DTHuesped(nombre, email, esFinger);
        *respuesta[i] = agregar;
    }
    return *respuesta;
};

const DTHabitacion** Sistema::obtenerHabitaciones(int& cantHabitaciones){
    const DTHabitacion** respuesta[this->topeHabitaciones];
    respuesta[this->topeHabitaciones] = nullptr;
    cantHabitaciones = this->topeHabitaciones;
    for(int i = 0; i<this->topeHabitaciones; i++){
        int numero = this->habitaciones[i]->getNumero();
        float precio = this->habitaciones[i]->getPrecio();
        int capacidad = this->habitaciones[i]->getCapacidad();
        DTHabitacion* agregar = new DTHabitacion(numero, precio, capacidad);
        *respuesta[i] = agregar;
    };
    return *respuesta;
};
