#include <stdio.h>
#include <string.h>

typedef char tString[40];

typedef struct 
{
	int nroLibreta, codMateria;
	float nota;	
}tRegistro;

tRegistro regAlumnos;
FILE *archivo;

tRegistro alumnoAnt;
int contMaterias;
float acumNotas;
int contAlumnosTotal;
float promedio;

void Inicializacion();
void Corte();
void Proceso();
void TotalAlumnos();
void Finalizacion();

int main()
{
	Inicializacion();
	Proceso();
	Finalizacion();
}

void Inicializacion()
{
	archivo = fopen("Notas.dat", "rb");
	fread(&regAlumnos, sizeof(regAlumnos), 1, archivo);
	alumnoAnt = regAlumnos;
	printf("LU\t\tPromedio\n");
}

void Proceso()
{
	contAlumnosTotal = 0;
	while(!feof(archivo))
	{	
		/*promedio = 0.0;*/
		acumNotas = 0.0;
		contMaterias = 0;
		
		contAlumnosTotal ++;
		
		while(!feof(archivo) && regAlumnos.nroLibreta == alumnoAnt.nroLibreta)
		{	
			contMaterias++;
			acumNotas = acumNotas + regAlumnos.nota;
			fread(&regAlumnos, sizeof(regAlumnos), 1, archivo);
		}
		Corte();
	}
	TotalAlumnos();
}

void Corte()
{
	printf("%d\t\t%.2f\n", regAlumnos.nroLibreta, (float)acumNotas/contMaterias);
	printf("-------------------------------------------------------\n");
	
	alumnoAnt.nroLibreta = regAlumnos.nroLibreta;	
}

void Finalizacion()
{
	fclose(archivo);
}

void TotalAlumnos()
{
	printf("El total de alumnos es: %d", contAlumnosTotal);	
}





























































