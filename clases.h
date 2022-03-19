#include <iostream>
#include <string>
#include "tipos.h"
using namespace std;

#define MAX_HUESPEDES 256;

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
     Huesped(string nombre, string email, bool esFinger);
     string getEmail();
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
    private:
     Huesped *huespedes[MAX_HUESPEDES];
    public:
     Sistema();
     void agregarHuesped(string nombre, string email, bool esFinger);

};