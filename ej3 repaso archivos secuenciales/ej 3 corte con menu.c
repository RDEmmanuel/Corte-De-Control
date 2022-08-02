#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char tString[40];

typedef struct 
{
	int dni, nroEmpleado;
	tString nombre;
	float sueldo;
}tRegistro;

tRegistro regEmpleados;
FILE *archivo;
char respuesta;

void InicializacionCrear();
void InicializacionLeer();
void InicializacionAgregar();
void Grabar();
void Finalizacion();
void Listado();
void Menu();

int main()
{
	Menu();
	return 0;
}

void InicializacionCrear()
{
	archivo = fopen("Empleados.dat", "wb");
}

void Finalizacion()
{
	fclose(archivo);
}

void Grabar()
{
	do
	{
	printf("Ingrese nro de empleado: ");
	fflush(stdin);printf("\n");
	scanf("%d", &regEmpleados.nroEmpleado);
	printf("\nIngrese Nombre y Apellido del empleado: ");
	fflush(stdin);printf("\n");
	gets(regEmpleados.nombre);
	printf("\nIngrese DNI: ");
	fflush(stdin);printf("\n");
	scanf("%d", &regEmpleados.dni);
	printf("\nIngrese sueldo a percibir: ");
	fflush(stdin);printf("\n");
	scanf("%f", &regEmpleados.sueldo);
	
	fwrite(&regEmpleados, sizeof(regEmpleados), 1, archivo);
	
	printf("\nDesea seguir ingresando datos? s/n: ");
	fflush(stdin);printf("\n");
	scanf("%s", &respuesta);
	}while (respuesta != 'n');
}

void Listado()
{
	archivo = fopen("Empleados.dat", "rb");
	fread(&regEmpleados, sizeof(regEmpleados), 1, archivo);
	printf("Empleado\tNombre\t\t\tDNI\t\tSueldo\n");
	
	while(!feof(archivo))
	{
		printf("%d\t\t%s\t\t%d\t%.2f\n", regEmpleados.nroEmpleado, regEmpleados.nombre, regEmpleados.dni, regEmpleados.sueldo);
		fread(&regEmpleados, sizeof(regEmpleados), 1, archivo);
		
	}
}

void Menu()
{
	int opcion;
	printf("***Opciones del menu***\n");
	printf("1-Crear Archivo Empleados\n");
	printf("2-Grabar Datos en el Archivo\n");
	printf("3-Lista de Empleados\n");
	printf("4-Agregar Datos al archivo\n");
	printf("0-Salir\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &opcion); fflush(stdin);
	system("cls");
	
	while (opcion != 0)
	{
		switch(opcion)
		{
			case 1:
				{
					InicializacionCrear();
					printf("El Archivo Empleados.dat se ha creado con exito!\n");
					system("pause"); system("cls");
					Menu();
				}break;
				
			case 2:
				{
					Grabar();
					Finalizacion();
					printf("Se grabaron los datos con exito en el archivo!\n");
					system("pause"); system("cls");
					Menu();
				}break;
				
			case 3:
				{
					InicializacionLeer();
					Listado();
					Finalizacion();
					system("pause"); system("cls");
					Menu();
				}break;
				
			case 4:
				{
					InicializacionAgregar();
					Grabar();
					Finalizacion();
					printf("Se agregaron los datos con exito en el archivo!\n");
					system("pause"); system("cls");
				}
				
			case 0:
				{
					Finalizacion();
				}
		}
		printf("***Opciones del menu***\n");
		printf("1-Crear Archivo Empleados\n");
		printf("2-Grabar Datos en el Archivo\n");
		printf("3-Lista de Empleados\n");
		printf("4-Agregar Datos al archivo\n");
		printf("0-Salir\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &opcion); fflush(stdin);
		system("cls");
	}
}


void InicializacionLeer()
{
	archivo = fopen("Empleados.dat", "rb");
}

void InicializacionAgregar()
{
	archivo = fopen("Empleados.dat", "ab");
}


















































