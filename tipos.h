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
     DTHuesped(string&, string&, bool&);
     string getNombre();
     string getEmail();
     bool getEsFinger(); 
     void toString();    
};

class DTHabitacion{
    private:
        int numero;
        float precio;
        int capacidad;
    public:
        DTHabitacion(); //PREGUNTA debemos tener constructor por defecto para los datatypes?
        DTHabitacion(int&, float&, int&);
        int getNumero();
        float getPrecio();
        int getCapacidad();
        void toString();
};

enum EstadoReserva{
    Abierta = 0,
    Cerrada = 1,
    Cancelada = 2
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
     private: 
        int codigo;
        DTFecha chekIn;
        DTFecha checkOut;
        EstadoReserva estado;
        float costo;
        int habitacion;
    public: 
        DTReserva(int,DTFecha,DTFecha,enum EstadoReserva,float,int);
        DTReserva(int,DTFecha,DTFecha,enum EstadoReserva,int);
        int getCodigo();
        DTFecha getchekIn(); 
        DTFecha getchekOut();
        EstadoReserva getEstadoReserva();
        float getCosto();
        int getHabitacion(); 
        //~DTReserva();
        virtual void operacion() = 0;
};

class DTReservaIndividual : public DTReserva{
 private: 
    bool pagado;
 public: 
    //orden:codigo,checkIn,checkOut,estadoReserva,costo,habitacion,pago
    DTReservaIndividual(int,DTFecha,DTFecha,enum EstadoReserva,float,int,bool);
    DTReservaIndividual(int,DTFecha,DTFecha,enum EstadoReserva,int,bool);
    bool getPagado(); 
    virtual void operacion();
};

class DTReservaGrupal : public DTReserva{
 private: 
    DTHuesped** huespedes;
 public: 
    //orden:codigo,checkIn,checkOut,estadoReserva,costo,habitacion,huespedes
    DTReservaGrupal(int,DTFecha ,DTFecha ,EstadoReserva,float,int,DTHuesped**);
    DTReservaGrupal(int,DTFecha ,DTFecha ,EstadoReserva,int,DTHuesped**);
    DTHuesped** getHuespedes(); 
    virtual void operacion();
};

ostream& operator<<(ostream&, DTReservaGrupal&);
ostream& operator<<(ostream&, DTReservaIndividual&);
ostream& operator<<(ostream&, DTFecha&);
istream& operator>>(istream&, DTFecha&);
ostream& operator<<(ostream&, DTReserva&);