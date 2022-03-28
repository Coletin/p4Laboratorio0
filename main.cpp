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
void leerChars(ArregloChars cs) { 
  scanf("%s", cs); 
}
DTFecha estandar(1,1,1);

int main() {
char nom_comando[MAX_PALABRA];
  Sistema s;
  int cont_comandos = 0;
  bool salir = false;
  while (!salir) {
    try{
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
      cout << "Ingrese el nombre: ";
      std::string nombre;
      cin.ignore();
      cin.clear();
      cin.sync();
      std::getline(cin,nombre);
      printf("Ingrese el email: ");
      leerChars(nom_comando);
      string email = (string)nom_comando;
      printf("Es Finger? 1-Si 0-No: ");
      leerChars(nom_comando);
      bool esFinger = nom_comando[0] == '1';
      s.agregarHuesped(nombre, email, esFinger);

    } else if (!strcmp(nom_comando, "2")) { //agregar habitacion
     
      printf("2.Agregar Habitacion.\n");
      printf("Ingrese el numero: ");
      int numero;
      leerChars(nom_comando);
      sscanf(nom_comando,"%d",&numero);
      printf("Ingrese el precio: ");
      float precio;
      leerChars(nom_comando);
      sscanf(nom_comando,"%f",&precio);
      printf("Ingrese la capacidad: ");
      int capacidad;
      leerChars(nom_comando);
      sscanf(nom_comando,"%d",&capacidad);
      s.agregarHabitacion(numero, precio, capacidad);
    } else if (!strcmp(nom_comando, "3")) { //obtener huespedes
      
      printf("3.Obtener Huespedes.\n");
      int numero = 0;
      DTHuesped** huespedes = s.obtenerHuespedes(numero);
      for(int i = 0; i<numero; i++){
        //cout << numero;
        huespedes[i]->toString();
      }

    } else if (!strcmp(nom_comando, "4")) { //obtener habitaciones
      printf("4.Obtener Habitaciones.\n");
      int numero = 0;
      DTHabitacion** habitaciones = s.obtenerHabitaciones(numero);
      for(int i = 0; i<numero; i++){
        //cout << numero;
        habitaciones[i]->toString();
      }
    } else if (!strcmp(nom_comando, "5")) { //registrar reserva
      printf("5.Registrar Reserva.\n");
      int codigo, habitacion, cantidad;
      string email;
      DTFecha desde(1,1,1), hasta(1,1,1);
      EstadoReserva estado = EstadoReserva::Abierta;
      DTReserva *res = nullptr;

      cout << "Ingrese email del huesped principal: ";
      cin >> email;
      if(!s.existeHuesped(email))
        throw std::invalid_argument( "No se encontro el cliente asociado al email [" + email + "]" + "\n" );

      cout << "Habitacion: ";
      cin >> habitacion;
      if(!s.existeHabitacion(habitacion))
        throw std::invalid_argument( "No se encontro la habitacion numero [" + std::to_string(habitacion) + "]" + "\n" );

      cout << "Ingrese codigo: ";
      cin >> codigo;
      bool error = true;
      while(error){
        error = false;
        desde = estandar;
        hasta = estandar;
        while(desde == estandar){
            try {
            cout << "Ingrese fecha de entrada (DD/MM/AAAA): ";
            cin >> desde;
        }
          catch (const invalid_argument& e){
            cerr << e.what() << endl;
        };
        };
        while(hasta == estandar){
            try {
            cout << "Ingrese fecha de salida (DD/MM/AAAA): ";
            cin >> hasta;
        }
          catch (const invalid_argument& e){
            cerr << e.what() << endl;
          };
        };
        if(desde > hasta){
            cout << ( "La fecha de entrada no puede ser mayor a la de salida \n" );
            error = true;
        };
      };
      cout << "Ingrese la cantidad de huespedes totales: ";
      cin >> cantidad;

      if(cantidad > s.getCantHuespedes())
              throw std::invalid_argument( "Debe agregar mas huespedes al sistema, huespedes acutales: [" + std::to_string(s.getCantHuespedes()) + "]" + "\n" );

      if(cantidad == 1){
        res = new DTReservaIndividual(codigo,desde,hasta,estado,habitacion,true);
        s.registrarReserva(email,res); 
      }else{
        DTHuesped* huespedes[MAX_HUESPEDES];
        Huesped* aAgregar = s.buscarHuesped(email);
        string _nombre = aAgregar->getNombre();
        string _email = aAgregar->getEmail();
        bool _esFinger = aAgregar->getEsFinger();
        huespedes[0] = new DTHuesped(_nombre, _email, _esFinger);
        for(int i = 1; i < cantidad; i++){
          bool ingresoEmail = true;
          while(ingresoEmail){
            cout << "Ingrese email del huesped " << std::to_string(i + 1) << ": ";
            cin >> email;
            if(!s.existeHuesped(email))
              throw std::invalid_argument( "No se encontro el cliente asociado al email [" + email + "]" + "\n" );

            int contadorRepetido = 0;
            bool encontreRepetido = false;
            while(!encontreRepetido && contadorRepetido < i){
              DTHuesped *hu = huespedes[contadorRepetido];
              encontreRepetido = hu->getEmail().compare(email) == 0;
              contadorRepetido ++;
            }
            if(encontreRepetido){
              cout << "Huesped ya ingresado, ingrese uno diferente. " << endl;
            }else{
              ingresoEmail = false;
            }
          }

          Huesped* aAgregar = s.buscarHuesped(email);
          string _nombre = aAgregar->getNombre();
          string _email = aAgregar->getEmail();
          bool _esFinger = aAgregar->getEsFinger();
          huespedes[i] = new DTHuesped(_nombre, _email, _esFinger);
        };
        huespedes[cantidad] = nullptr;
        res = new DTReservaGrupal(codigo,desde,hasta,estado,habitacion,huespedes);
        s.registrarReserva(email, res);
      };

    } else if (!strcmp(nom_comando, "6")) { //obtener reserva
      
      printf("6.Obtener Reserva.\n");
      int tope = 0;
      DTFecha fecha(1,1,1);
      while(fecha == estandar){
          try {
          cout << "Ingrese fecha de reservas a obtener (DD/MM/AAAA): ";
          cin >> fecha;
       }
        catch (const invalid_argument& e){
          cerr << e.what() << endl;
       };
      };
      DTReserva **listareservas = s.obtenerReservas(fecha,tope);
      for(int i = 0; i<tope;i++) cout << *listareservas[i];

    } else if (!strcmp(nom_comando, "7")) { //salir
      salir = true;
      printf("Fin.\n");
    } else { //no reconocido
      printf("Comando no reconocido.\n");
    }
    }catch(const std::invalid_argument& ex){
      cout << ex.what();  
    }    
  }
}
