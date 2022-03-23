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
      

    } else if (!strcmp(nom_comando, "1")) {
    
      printf("1.Agregar Huesped.\n");
      printf("Ingrese el nombre(sin espacios)\n");
      leerChars(nom_comando);
      string nombre = (string)nom_comando;
      printf("Ingrese el email\n");
      leerChars(nom_comando);
      string email = (string)nom_comando;
      printf("Es Finger? 1-Si 0-No\n");
      leerChars(nom_comando);
      bool esFinger = (bool)nom_comando[0];
      s.agregarHuesped(nombre, email, esFinger);
      system("pause");

    } else if (!strcmp(nom_comando, "2")) {
     
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
    } else if (!strcmp(nom_comando, "3")) {
      
      printf("3.Obtener Huespedes.\n");
      system("pause");

    } 
    else if (!strcmp(nom_comando, "4")) {
      
      printf("4.Obtener Habitaciones.\n");
      system("pause");

    } 

    else if (!strcmp(nom_comando, "5")) {
      
      printf("5.Registrar Reserva.\n");
      system("pause");

    } 

     else if (!strcmp(nom_comando, "6")) {
      
      printf("6.Obtener Reserva.\n");
      system("pause");

    } 
    
     else if (!strcmp(nom_comando, "7")) {
      salir = true;
      printf("Fin.\n");
      printf("7.Salir.\n");

    }  else {
      printf("Comando no reconocido.\n");
       system("pause");
    }
  }
}
