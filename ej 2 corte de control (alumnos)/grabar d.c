#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char tString[40];

typedef struct 
{
	int nroLibreta, codMateria;
	float nota;	
}tRegistro;

tRegistro regAlumnos;
FILE *archivo;
char respuesta, respuesta2;

void Inicializacion();
void Grabar();
void Finalizacion();

int main()
{
	Inicializacion();
	Grabar();
	Finalizacion();
	return 0;
}

void Inicializacion()
{
	archivo = fopen("Notas.dat", "wb");
}

void Grabar()
{
	printf("Desea resgistrar un alumno? s/n: ");
	scanf("%s", &respuesta); fflush(stdin);
	printf("\n");
	while(respuesta != 'n')
	{
		printf("Ingrese numero de libreta universitaria: ");
		scanf("%d", &regAlumnos.nroLibreta);
		fflush(stdin);printf("\n");
		printf("Ingrese codigo de materia: ");
		scanf("%d", &regAlumnos.codMateria);
		fflush(stdin);printf("\n");
		printf("Ingrese nota obtenida: ");
		scanf("%f", &regAlumnos.nota);
		fflush(stdin);printf("\n");
		
		fwrite(&regAlumnos, sizeof(regAlumnos), 1 , archivo);
		printf("Desea ingresar otra nota para este alumno? s/n: ");
		scanf("%s", &respuesta2); fflush(stdin);printf("\n");
		while(respuesta2 != 'n')
		{
			printf("Ingrese codigo de materia: ");
			scanf("%d", &regAlumnos.codMateria);
			fflush(stdin);printf("\n");
			printf("Ingrese nota obtenida: ");
			scanf("%f", &regAlumnos.nota);
			fflush(stdin);printf("\n");
			fwrite(&regAlumnos, sizeof(regAlumnos), 1 , archivo);
			printf("Desea ingresar otra nota para este alumno? s/n: ");
			scanf("%s", &respuesta2); fflush(stdin);printf("\n");
		}
		printf("Desea registrar otro alumno? s/n: ");
		scanf("%s", &respuesta); fflush(stdin);
		printf("\n");
	}
	printf("Alumno registrado!\n");
	system("\nPAUSE");
    system("cls");
}

void Finalizacion()
{
	fclose(archivo);
}






































