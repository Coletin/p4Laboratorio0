#include <assert.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#include "clases.h"
using namespace std;
#define MAX_PALABRA 32
#define MAX_LINEA 256

char leerChar() {
  char res;
  scanf(" %c", &res);
  return res;
}
typedef char *ArregloChars; // arreglo de char
void leerChars(ArregloChars cs) { scanf("%s", cs); }


int main() {
char nom_comando[MAX_PALABRA];
  Sistema s;
  int cont_comandos = 0;
  bool salir = false;
  while (!salir) {
    try{
    system("cls");
    printf("1.Agregar Huesped.\n");
    printf("2.Agregar Habitacion.\n");
    printf("3.Obtener Huespedes.\n");
    printf("4.Obtener Habitaciones.\n");
    printf("5.Registrar Reserva.\n");
    printf("6.Obtener Reserva.\n");
    printf("7.Salir.\n");
    printf("\n");

    // mostrar el prompt
    cont_comandos++;
    printf("%u>", cont_comandos);

    // leer el comando
    leerChars(nom_comando);

    // procesar el comando
    if (!strcmp(nom_comando, "Fin")) {
      salir = true;
      printf("Fin.\n");
      // comentario
    } else if (!strcmp(nom_comando, "#")) {
      

    } else if (!strcmp(nom_comando, "1")) { //agrgear huesped
    
      printf("1.Agregar Huesped.\n");
      printf("Ingrese el nombre(sin espacios)\n");
      leerChars(nom_comando);
      string nombre = (string)nom_comando;
      printf("Ingrese el email\n");
      leerChars(nom_comando);
      string email = (string)nom_comando;
      printf("Es Finger? 1-Si 0-No\n");
      leerChars(nom_comando);
      bool esFinger = nom_comando[0] == '1';
      s.agregarHuesped(nombre, email, esFinger);
      system("pause");

    } else if (!strcmp(nom_comando, "2")) { //agregar habitacion
     
      printf("2.Agregar Habitacion.\n");
      printf("Ingrese el numero\n");
      int numero;
      leerChars(nom_comando);
      sscanf(nom_comando,"%d",&numero);
      printf("Ingrese el precio\n");
      float precio;
      leerChars(nom_comando);
      sscanf(nom_comando,"%f",&precio);
      printf("Ingrese la capacidad\n");
      int capacidad;
      leerChars(nom_comando);
      sscanf(nom_comando,"%d",&capacidad);
      s.agregarHabitacion(numero, precio, capacidad);
      system("pause");
    } else if (!strcmp(nom_comando, "3")) { //obtener huespedes
      
      printf("3.Obtener Huespedes.\n");
      int numero = 0;
      DTHuesped** huespedes = s.obtenerHuespedes(numero);
      for(int i = 0; i<numero; i++){
        //cout << numero;
        huespedes[i]->toString();
      }
      system("pause");

    } else if (!strcmp(nom_comando, "4")) { //obtener habitaciones
      system("cls");
      printf("4.Obtener Habitaciones.\n");
      int numero = 0;
      DTHabitacion** habitaciones = s.obtenerHabitaciones(numero);
      for(int i = 0; i<numero; i++){
        //cout << numero;
        habitaciones[i]->toString();
      }
      system("pause");
    } else if (!strcmp(nom_comando, "5")) { //registrar reserva
      printf("5.Registrar Reserva.\n");
      int codigo, habitacion, dia, mes, ano, cantidad;
      string email;
      DTFecha *desde, *hasta;
      EstadoReserva estado = EstadoReserva::Abierta;
      DTReserva *res = nullptr;

      cout << "Ingrese email del huesped principal: ";
      cin >> email;
      if(!s.existeHuesped(email))
        throw std::invalid_argument( "No se encontro el cliente asociado al email [" + email + "]" );

      cout << "habitacion: ";
      cin >> habitacion;
      if(!s.existeHabitacion(habitacion))
        throw std::invalid_argument( "No se encontro la habitacion numero [" + std::to_string(habitacion) + "]" );

      cout << "Ingrese codigo: ";
      cin >> codigo;
      cout << "Ingrese dia: ";
      cin >> dia;
      cout << "Ingrese mes: ";
      cin >> mes;
      cout << "Ingrese año: ";
      cin >> ano;
      desde = new DTFecha(dia, mes, ano);
      cout << "Ingrese dia: ";
      cin >> dia;
      cout << "Ingrese mes: ";
      cin >> mes;
      cout << "Ingrese año: ";
      cin >> ano;
      hasta = new DTFecha(dia, mes, ano);
      cout << "Reserva individual o grupal: [1-Individual 2-Grupal] ";
      cin >> cantidad;
      if(cantidad == 1){
        res = new DTReservaIndividual(codigo,*desde,*hasta,estado,habitacion,true);
        s.registrarReserva(email,res); 
      }else if(cantidad == 2){
        //pedimos el resto de huespedes
      }else{

      }

      system("pause");

    } else if (!strcmp(nom_comando, "6")) { //obtener reserva
      
      printf("6.Obtener Reserva.\n");
      int tope = 0;
      DTFecha *fecha = new DTFecha(1,1,1);
      DTReserva **listareservas = s.obtenerReservas(*fecha,tope);
      for(int i = 0; i<tope; i++){
        //cout << (*listareservas[i]);

        // try{
        //   DTReservaIndividual *individual = dynamic_cast<DTReservaIndividual*>(listareservas[i]);
        //   cout << individual;
        // }catch(...)
        // {}
        // try{
        //     DTReservaGrupal *grupal = dynamic_cast<DTReservaGrupal*>(listareservas[i]);
        //     cout << grupal;
        // }catch(...)
        // {}
        
      }
      system("pause");

    } else if (!strcmp(nom_comando, "7")) { //salir
      salir = true;
      printf("Fin.\n");
      printf("7.Salir.\n");

    } else { //no reconocido
      printf("Comando no reconocido.\n");
       system("pause");
    }
    }catch(const std::invalid_argument& ex){
      cout << ex.what();  
      system("pause");
    }    
  }
}
