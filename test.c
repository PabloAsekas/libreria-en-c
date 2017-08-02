/*
*
* Relizada por Pablo Bermejo y Blanca Romero
*
* https://github.com/PabloAsekas/
*
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "libreria.h"
#include <stdlib.h>

int main (int argc, char *argv[]){

	int opcion;
	int N;

	if(argc < 2){

		fprintf(stderr, "ERROR. Faltan argumentos. %s\n" , strerror(errno));
		printf("Quizas quiso decir: %s opcion N\n" , argv[0]);
		return -1;
	}

	opcion = atoi(argv[1]);

	if(argc == 2){

		switch(opcion){
			case 1: head(10);
				return 0;
				break;
			case 2: tail(10);
				return 0;
				break;
			case 3: longlines(10);
				return 0;
				break;
			default:
				fprintf(stderr, "ERROR. La opcion debe ser 1, 2 o 3. %s\n" , strerror(errno));
				return -1;
				break;
		}
	}

	if(argc == 3){

		N = atoi(argv[2]);
		switch(opcion){
			case 1: head(N);
				return 0;
				break;
			case 2: tail(N);
				return 0;
				break;
			case 3: longlines(N);
				return 0;
				break;
			default:
				fprintf(stderr, "ERROR. La opcion debe ser 1, 2 o 3. %s\n" , strerror(errno));
				return -1;
				break;
		}
	}

	if(argc > 3){
		 fprintf(stderr, "ERROR. Sobran argumentos. %s\n" , strerror(errno));
		 printf("Quizas quiso decir: %s opcion N\n" , argv[0]);
		 return -1;
	}
}
