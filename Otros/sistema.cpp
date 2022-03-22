#include "../clases.h"
<<<<<<< Updated upstream
#include <iostream>
using namespace std;

#define MAX_HUESPEDES 256;
=======
#include "../tipos.h"
#include <stdexcept>
>>>>>>> Stashed changes

Sistema::Sistema(){
};

<<<<<<< Updated upstream
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
=======
void agregarHabitacion(int numero, float precio, int capacidad){
    //chequeamos si los datos pasados son coerentes
    if(numero < 0)
        throw std::invalid_argument( "El numero de habitación debe ser positivo" );
    if(precio < 0)
        throw std::invalid_argument( "El precio no debe ser negativo" );
    if(capacidad < 0)
        throw std::invalid_argument( "La capacidad no debe ser negativa" );
    
    bool hayLugar = true; //TODO chequeamos contra el array de tamaño de reservas si tenemos disponibles
    if(hayLugar){
        bool yaExisteHabitacion = false; //TODO chequeamos contra el array de habitaciones si ya existe una con este numero
        if(!yaExisteHabitacion){
            Habitacion habitacionAgregar = new Habitacion(numero, precio, capacidad);
            //TODO con la habitacion valida ya creada, agregamos al listado
        }else{
            throw std::invalid_argument("Ya existe una habitación con el número indicado");
        }
    }else{
        //PREGUNTA lanzamos exception si no hay lugar para agregar?
    }

};

DTHabitacion** obtenerHabitaciones(int& cantHabitaciones){
    cantHabitaciones = 0;
    int cantidadHabitacionesActuales = 5;//TODO obtener del listado la cantidad de habitaciones actuales
    Habitacion habitacionesActuales = [cantidadHabitacionesActuales]; //TODO obtener el listado de habitaciones
    DTHabitacion respuesta = [cantidadHabitacionesActuales];
    
    for(int i = 0; i<habitacionesActuales; i++){
        int numero = habitacionesActuales[i]->getNumero();
        float precio = habitacionesActuales[i]->getPrecio();
        int capacidad = habitacionesActuales[i]->getCapacidad();
        DTHabitacion agregar = new DTHabitacion(numero, precio, capacidad);
        respuesta[i] = agregar;
    }
    return respuesta;
};
>>>>>>> Stashed changes
