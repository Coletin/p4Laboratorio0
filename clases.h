#include <iostream>
#include <string>
#include "tipos.h"
using namespace std;

#define MAX_HUESPEDES 256
#define MAX_HABITACIONES 256
#define MAX_RESERVAS 256

class Habitacion{
    private:
     int numero;
     float precio;
     int capacidad;
    public:
     Habitacion();
     Habitacion(int, float, int);
     int getNumero();
     void setNumero(int _numero);
     float getPrecio();
     void setPrecio(float _precio);
     int getCapacidad();
     void setCapacidad(int _capacidad);
};

class Huesped{
    private:
     string nombre;
     string email;
     bool esFinger;
    public:
     Huesped();
     Huesped(string, string, bool);
     string getEmail();
     string getNombre();
     bool getEsFinger();
};

class Reserva{
    private:
     int codigo;
     DTFecha checkIn;
     DTFecha checkOut;
     EstadoReserva estado;
    public:
     virtual float calcularCosto() = 0;
     int getCodigo();
     DTFecha getCheckIn();
     DTFecha getCheckOut();
     EstadoReserva getEstado();
     void setCodigo(int&);
     void setCheckIn(DTFecha&);
     void setCheckOut(DTFecha&);
     void setEstado(EstadoReserva&);
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
        Huesped* huespedes[(int)(MAX_HUESPEDES)];
        Habitacion* habitaciones[(int)(MAX_HABITACIONES)];
        Reserva* reservas[(int)(MAX_RESERVAS)];
        int topeHabitaciones;
        int cantHuespedes = 0;
    public:
     Sistema();
     void agregarHuesped(string nombre, string email, bool esFinger);
     void agregarHabitacion(int, float, int);
     const DTHuesped** obtenerHuespedes(int&);
     const DTHabitacion** obtenerHabitaciones(int&);
};