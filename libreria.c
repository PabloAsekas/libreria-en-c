#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"

/*
*
* Relizada por Pablo Bermejo y Blanca Romero
*
* https://github.com/PabloAsekas/
*
*/

int head (int N){

	char cadena[1024];	//Creamos una linea de 1024
	int i;

	for(i=0; i<N; i++){	//Respetimos tantas veces como nos lo haya indicado el usuario en el parametro N

		if((fgets(cadena,1024,stdin) != NULL)){	//Obtenemos por la entrada estandar lo que nos inserta el usuario
			printf("%s" , cadena);		//Imprimimos lo que haya en cadena
		}
	}
	return 0;
}

int tail (int N){

	char **cadena = (char**) malloc (N*sizeof(char *)); //Reservamos memoria para un array con punteros a N char
	char *aux = malloc(1024*sizeof(char));		    //Reservamos memoria para un puntero auxiliar con el tamaño de una linea (1024)
	int i,j;

	for(i=0; i<N; i++){

		cadena[i] = (char *) malloc (1024*sizeof(char)); //Reservamos memoria para cada puntero del array
	}

	i = 0;
	while(((fgets(cadena[N-1],1024,stdin)) != NULL)){ //Mientras no se pulse ctrl+d, cada linea que meta el usuario se insertara
							  //en la ultima posicion de nuestro array

		strcpy(aux,cadena[i]); //Guadamos en aux, la primera linea de nuestro array,para evitar que se pierda

		for(j=0; j<N-1; j++){

			strcpy(cadena[j],cadena[j+1]); //Cada linea de nuestro array se desplazara una posicion hacia arriba
		}
		strcpy(cadena[N-1], ""); //La ultima posicion de nuestro array quedara en blanco para evitar que se repita
	}

	printf("\n");

	fputs(aux,stdout); //Se imprime por pantalla lo que hay en aux
	for(i=0; i<N; i++){
		fputs(cadena[i],stdout); //Se imprime por pantalla cada linea de nuestro array
		free(cadena[i]); //Liberamos memoria por cada linea insertada en el array
	}

	free(aux); //Liberamos la memoria del puntero aux
	free(cadena); //Liberamos la memoria de nuestro array
	cadena = NULL; //Nuestro array apunta a NULL
	return 0;
}

int longlines (int N){

	char ** lineas = (char**) malloc(N*sizeof(char*)); //Reservamos memoria para un array con punteros a N char
	int i;

	for (i = 0; i<N; i++) {
		lineas[i] = (char *) malloc (1024 * sizeof(char)); //Creamos el array que guardará las N lineas
	}

	char *cadena = (char*) malloc(1024*sizeof(char)); //Creamos el puntero auxiliar que guardará la frase que ha insertado el usuario
	//cadena[0] = (char *) malloc(1024 * sizeof(char)); //creamos la estructura auxiliar que guardará la frase que ha insertado el usuario

	while (fgets(cadena, 1024, stdin) != NULL) {

		int tamano = strlen(cadena);
		for (i = 0; i < N; i++) {

			if (strlen(lineas[i]) < tamano) {

				int j;
				for (j = N-1; j>i; j--) {
					strcpy(lineas[j],lineas[j-1]);
				}

				strcpy(lineas[i], cadena);
				break;
			} //Condicion de comparacion, si el tamaño de la frase es mayor, se le busca un hueco en el array y se guarda
		}
	} //Bucle que captura cada frase hasta que el usuario decide parar la ejecucion

	printf("\n");

	for (i = 0; i < N; i++) {
		fputs (lineas[i], stdout); //Impresión por pantalla del array con las frases de mayor a menor
		free(lineas[i]); //Liberamos memoria por cada linea insertada en el array
	}

	free(cadena); //Liberamos la memoria del puntero auxiliar
	free(lineas); //Liberamos la memoria de nuestro array
	lineas = NULL; //Nuestro array apunta a NULL
	return 0;
}
