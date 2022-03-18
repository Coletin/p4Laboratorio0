#include "tipos.h"
#include <iostream>
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
    DTFecha nueva(diaN, mesN, anioN);
    f = nueva;
    return i;
};