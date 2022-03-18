class DTHuesped{

};

class DTHabitacion{

};

enum EstadoReserva{

};

class DTFecha{
    private:
     int dia;
     int mes;
     int anio;
    public:
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