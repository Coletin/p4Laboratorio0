#include "tipos.h"
#include <iostream>
#include <stdexcept>
using namespace std;

DTFecha::DTFecha(){
};

DTFecha::DTFecha(int dian, int mesn, int anion){
    this->dia = dian;
    this->mes = mesn;
    this->anio = anion;
};

int DTFecha::getDia(){
    return this->dia;
};

int DTFecha::getMes(){
    return this->mes;
};

int DTFecha::getAnio(){
    return this->anio;
};

bool DTFecha::operator==(const DTFecha& igual){
    return (this->dia == igual.dia)&&(this->mes == igual.mes)&&(this->anio == igual.anio);
};

bool DTFecha::operator!=(const DTFecha& distinta){
    return (this->dia != distinta.dia)||(this->mes != distinta.mes)||(this->anio != distinta.anio);
};

bool DTFecha::operator<(const DTFecha& mayor){
    bool resu = false;
    if(this->anio < mayor.anio){
        resu = true;
    }
    else if((this->mes < mayor.mes)&&(this->anio == mayor.anio)){
        resu = true;
    }
    else if((this->dia < mayor.dia)&&(this->mes == mayor.mes)&&(this->anio == mayor.anio)){
        resu = true;
    };
    return resu;
};

bool DTFecha::operator>(const DTFecha& menor){
    bool resu = false;
    if(this->anio > menor.anio){
        resu = true;
    }
    else if((this->mes > menor.mes)&&(this->anio == menor.anio)){
        resu = true;
    }
    else if((this->dia > menor.dia)&&(this->mes == menor.mes)&&(this->anio == menor.anio)){
        resu = true;
    };
    return resu;
};

bool DTFecha::operator<=(const DTFecha& maIgual){
    bool mayor = false;
    if(this->anio < maIgual.anio){
        mayor = true;
    }
    else if((this->mes < maIgual.mes)&&(this->anio == maIgual.anio)){
        mayor = true;
    }
    else if((this->dia < maIgual.dia)&&(this->mes == maIgual.mes)&&(this->anio == maIgual.anio)){
        mayor = true;
    };
    bool igual = (this->dia == maIgual.dia)&&(this->mes == maIgual.mes)&&(this->anio == maIgual.anio);
    return mayor||igual;
};

bool DTFecha::operator>=(const DTFecha& meIgual){
    bool menor = false;
    if(this->anio > meIgual.anio){
        menor = true;
    }
    else if((this->mes > meIgual.mes)&&(this->anio == meIgual.anio)){
        menor = true;
    }
    else if((this->dia > meIgual.dia)&&(this->mes == meIgual.mes)&&(this->anio == meIgual.anio)){
        menor = true;
    };
    bool igual = (this->dia == meIgual.dia)&&(this->mes == meIgual.mes)&&(this->anio == meIgual.anio);
    return menor||igual;
};

ostream& operator<<(ostream& o, DTFecha& f){
    if((f.getDia()-10) < 0) o << '0';
    o << f.getDia();
    o << '/';
    if((f.getMes()-10) < 0) o << '0';
    o << f.getMes();
    o << '/';
    o << f.getAnio();
    return o;
};

istream& operator>>(istream& i, DTFecha& f){
    char fLeer[12];
    i.getline(fLeer, 12);
    string diaS;
    string mesS;
    string anioS;
    int indice = 0;
    while (fLeer[indice]!='/'){
        diaS = diaS + fLeer[indice];
        indice++;
    }
    indice++;
    while (fLeer[indice]!='/'){
        mesS = mesS + fLeer[indice];
        indice++;
    }
    indice++;
    while (fLeer[indice]!='\0'){
        anioS = anioS + fLeer[indice];
        indice++;
    }
    int diaN = stoi(diaS);
    int mesN = stoi(mesS);
    int anioN = stoi(anioS);
    if(diaN > 31 || diaN < 1 || mesN > 12 || mesN < 1 || anioN < 1900) throw std::invalid_argument("Fecha fuera de rango");
    DTFecha nueva(diaN, mesN, anioN);
    f = nueva;
    return i;
};

DTHuesped::DTHuesped(){
};

DTHuesped::DTHuesped(string nombree, string emaile, bool esFingere){
    this->nombre = nombree;
    this->email = emaile;
    this->esFinger = esFingere;
};

string DTHuesped::getNombre(){
    return this->nombre;
};

string DTHuesped::getEmail(){
    return this->email;
};

bool DTHuesped::getEsFinger(){
    return this->esFinger;
};

DTHabitacion::DTHabitacion(){

};

DTHabitacion::DTHabitacion(int _numero, float _precio, int _capacidad){
    this->numero = _numero;
    this->precio = _precio;
    this->capacidad = _capacidad;
};

int DTHabitacion::getNumero(){return this->numero;};

float DTHabitacion::getPrecio(){return this->precio;};

int DTHabitacion::getCapacidad(){return this->capacidad;};

DTReserva::DTReserva(int _codigo,DTFecha _checkIn,DTFecha _checkOut,EstadoReserva _estado,float _costo,int _habitacion){
    codigo = _codigo;
    chekIn = _checkIn;
    checkOut = _checkOut;
    estado = _estado;
    costo = _costo;
    habitacion = _habitacion;
};

DTFecha DTReserva::getchekIn(){
    return chekIn;
};
DTFecha DTReserva::getchekOut(){
    return checkOut;
};

int DTReserva::getCodigo(){
    return codigo;
};

EstadoReserva DTReserva::getEstadoReserva(){
    return estado;
};

float DTReserva::getCosto(){
    return costo;
};

int DTReserva::getHabitacion(){
    return habitacion;
};

DTReservaIndividual::DTReservaIndividual(int _codigo,DTFecha _chekIn,DTFecha _chekOut,EstadoReserva _estado,float _costo,int _habitacion,bool _pagado):DTReserva(_codigo,_chekIn,_chekOut,_estado,_costo,_habitacion){
    this->pagado= _pagado;
};

bool DTReservaIndividual::getPagado(){
    return pagado;
};

DTReservaGrupal::DTReservaGrupal(int _codigo,DTFecha _chekIn,DTFecha _chekOut,EstadoReserva _estado,float _costo,int _habitacion,DTHuesped** _huespedes):DTReserva(_codigo, _chekIn, _chekOut, _estado, _costo, _habitacion){
    this->huespedes= _huespedes;   
};

DTHuesped** DTReservaGrupal::getHuespedes(){
    return huespedes;
};

ostream& operator<<(ostream& o, DTReservaIndividual& ri){
    o << "TipoReserva: Individual" << endl;
    o << "FechaCheckIn: ";
    DTFecha f = ri.getchekIn();
    o << f;
    o << endl;
    o << "FechaCheckOut: ";
    f = ri.getchekOut();
    o << f;
    o << endl;
    o << "Habitación: " << ri.getHabitacion() << endl;
    o << "Costo: " << ri.getCosto() << endl;
    o << "Pagado: ";
    if(ri.getPagado()) o << "Si";
    else o << "No";
    o << endl;
    return o;
};

ostream& operator<<(ostream& o, DTReservaGrupal& rg){
    o << "TipoReserva: Grupal" << endl;
    o << "FechaCheckIn: ";
    DTFecha f = rg.getchekIn();
    o << f;
    o << endl;
    o << "FechaCheckOut: ";
    f = rg.getchekOut();
    o << f;
    o << endl;
    o << "Habitación: " << rg.getHabitacion() << endl;
    o << "Costo: $" << rg.getCosto() << endl;
    o << "Huespedes: ";
    int i = 0;
    while(rg.getHuespedes()[i]!=nullptr){
        o << rg.getHuespedes()[i]->getNombre() << " - " << rg.getHuespedes()[i]->getEmail();
        if(rg.getHuespedes()[i]->getEsFinger() && i == 0) o << " - es Finger";
        else if(i == 0) o << " - no es Finger";
        o << "," << endl << "           ";
        i++;
    }
    return o;
};