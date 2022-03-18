
//#include "tipos.h"

//#include "clases.h"

#include <assert.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

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

  int cont_comandos = 0;
  bool salir = false;
  while (!salir) {
    system("cls");
    printf("1.Agregar Huesped.\n");
    printf("2.Agregar Habitacion.\n");
    printf("3.Obtener Huesped.\n");
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
      system("pause");

    } else if (!strcmp(nom_comando, "2")) {
     
      printf("2.Agregar Habitacion.\n");
      system("pause");

    } else if (!strcmp(nom_comando, "3")) {
      
      printf("3.Obtener Huesped.\n");
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
