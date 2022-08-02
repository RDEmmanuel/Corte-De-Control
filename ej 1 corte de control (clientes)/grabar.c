/* 
Escribir un programa que genere un archivo de nombre Clientes (secuencial), que contendrá la 
información sobre los movimientos realizados por los clientes de un banco. Los datos son:
-Nro. Cuenta (int)
-Nombre Cliente (string)
-Codigo Operacion (int 1=Deposito, 2=Extracción)
-Importe (float) 
*/

#include <stdio.h>
#include <string.h>

typedef char tString[40];

typedef struct 
{
	int nroCuenta, codOperacion;
	float importe;
	tString nombre;
}tRegistro;

tRegistro regCliente;
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
	archivo = fopen("Clientes.dat", "wb");
}

void Grabar()
{
		printf("Desea registrar una operacion? s/n: ");
		scanf("%s", &respuesta); fflush(stdin);
		while(respuesta != 'n')
		{
		printf("Ingrese nro de cuenta: ");
		fflush(stdin);printf("\n");
		scanf("%d", &regCliente.nroCuenta);
		printf("Ingrese Nombre y Apellido del cliente: ");
		fflush(stdin);printf("\n");
		gets(regCliente.nombre);
		printf("Ingrese Codigo de Operacion (1=DEPOSITO / 2=EXTRACCION): ");
		fflush(stdin);printf("\n");
		scanf("%d", &regCliente.codOperacion);
		printf("Ingrese Importe: ");
		fflush(stdin);printf("\n");
		scanf("%f", &regCliente.importe);
		
		fwrite(&regCliente, sizeof(regCliente), 1, archivo);
		
		printf("Desea realizar otra operacion con este cliente? s/n: ");
		fflush(stdin);printf("\n");
		scanf("%s", &respuesta2);
		
			while(respuesta2 != 'n')
			{
				printf("Ingrese Codigo de Operacion (1=DEPOSITO / 2=EXTRACCION): ");
				fflush(stdin);printf("\n");;
				scanf("%d", &regCliente.codOperacion);
				printf("Ingrese Importe: ");
				fflush(stdin);printf("\n");
				scanf("%f", &regCliente.importe);
				printf("Desea realizar otra operacion con este cliente? s/n: ");
				fflush(stdin);printf("\n");
				scanf("%s", &respuesta2);
				
				fwrite(&regCliente, sizeof(regCliente), 1, archivo);
			}
		printf("Operacion registrada!\n");
		system("\nPAUSE");
        system("cls");
        printf("Desea registrar una operacion? s/n: ");
		scanf("%s", &respuesta); fflush(stdin);
		}
}

void Finalizacion()
{
	fclose(archivo);
}













































































