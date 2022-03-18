#include <iostream>
#include "tipos.h"
using namespace std;

class Habitacion{
    private:
     int numero;
     float precio;
     int capacidad;
    public:
     Habitacion();
};

class Huesped{
    private:
     string nombre;
     string email;
     bool esFinger;
    public:
     Huesped();
};

class Reserva{
    private:
     int codigo;
     DTFecha checkIn;
     DTFecha checkOut;
     EstadoReserva estado;
    public:
     virtual float calcularCosto() = 0;
};

class ReservaGrupal : public Reserva{
    public:
     virtual float calcularCosto();
};

class ReservaIndividual : public Reserva{
    private:
     bool pagado;
    public:
     virtual float calcularCosto();
};

class Sistema{
    public:
     void agregarHuesped(string nombre, string email, boolean esFinger);

}