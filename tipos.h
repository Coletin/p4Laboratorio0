#include <string>
#include <iostream>
//#include <cstring>
using namespace std;
//Constantes predefinidas de letra
//const int MAX_HABITACIONES = 256;
//const int MAX_HUESPEDES = 256;
//const int MAX_RESERVAS = 256;

class DTHuesped{
    private:
     string nombre;
     string email;
     bool esFinger;
    public:
     DTHuesped();
     DTHuesped(string, string, bool);
     string getNombre();
     string getEmail();
     bool getEsFinger();     
};

class DTHabitacion{
    private:
        int numero;
        float precio;
        int capacidad;
    public:
        DTHabitacion(); //PREGUNTA debemos tener constructor por defecto para los datatypes?
        DTHabitacion(int, float, int);
        int getNumero();
        float getPrecio();
        int getCapacidad();
};

enum EstadoReserva{

};

class DTFecha{
    private:
     int dia;
     int mes;
     int anio;
    public:
     DTFecha();
     DTFecha(int, int, int);
     int getDia();
     int getMes();
     int getAnio();
     bool operator==(const DTFecha&);
     bool operator<=(const DTFecha&);
     bool operator>=(const DTFecha&);
     bool operator!=(const DTFecha&);
     bool operator<(const DTFecha&);
     bool operator>(const DTFecha&);
};

class DTReserva{

};

class DTReservaIndividual : public DTReserva{

};

class DTReservaGrupal : public DTReserva{

};