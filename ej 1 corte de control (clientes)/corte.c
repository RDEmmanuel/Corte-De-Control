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

int nroCuentaAnt;
int totalMovimientos;
float totalDepositos, totalExtraccion, saldoTotal;
tString nombreAnt;

void Inicializacion();
void Proceso();
void Finalizacion();
void Corte();
void Listado();

int main()
{
	Inicializacion();
	Proceso();
	Finalizacion();
	return 0;
}

void Inicializacion()
{
	archivo = fopen("Clientes.dat", "rb");
	
	fread(&regCliente, sizeof(regCliente), 1, archivo);
	
	nroCuentaAnt = regCliente.nroCuenta;
	printf("Cuenta\tNombre y Apellido\n");	
}

void Proceso()
{	
	while(!feof(archivo))
	{
		totalMovimientos = 0;
		totalDepositos = 0.0;
		totalExtraccion = 0.0;
		saldoTotal = 0.0;
		Listado();
		while(!feof(archivo) && regCliente.nroCuenta == nroCuentaAnt)
		{
			totalMovimientos = totalMovimientos + 1;
			if(regCliente.codOperacion == 1)
			{
				totalDepositos = totalDepositos + regCliente.importe;
			}
			if(regCliente.codOperacion == 2)
			{
				totalExtraccion = totalExtraccion + regCliente.importe;
			}
			saldoTotal = totalDepositos - totalExtraccion;
			fread(&regCliente, sizeof(regCliente), 1, archivo);
		}
		Corte();
	}
}

void Corte()
{
	printf("Total de movimientos del cliente %d: %d\n", nroCuentaAnt, totalMovimientos);
	printf("Monto total de depositos del cliente: $%.2f\n", totalDepositos);
	printf("Monto total de extracciones del cliente: $%.2f\n", totalExtraccion);
	printf("El saldo total de la cuenta es: $%.2f\n", saldoTotal);
	printf("-------------------------------------------------------\n");
	nroCuentaAnt = regCliente.nroCuenta;
	/*totalMovimientos = 0;
	totalDepositos = 0.0;
	totalExtraccion = 0.0;
	saldoTotal = 0.0;*/
}

void Finalizacion()
{	
	fclose(archivo);
}

void Listado()
{
	printf("%d\t%s\n", regCliente.nroCuenta, regCliente.nombre);		
}


















































