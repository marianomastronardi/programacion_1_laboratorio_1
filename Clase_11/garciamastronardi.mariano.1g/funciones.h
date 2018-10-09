#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct{
int Codigo;
char Descripcion[21];
float Importe;
int idCategoria;
} eJuego;

typedef struct{
int id;
char Descripcion[51];
} eCategoria;

typedef struct{
int Codigo;
char Nombre[51];
char sexo;
char Telefono[21];
} eCliente;

typedef struct{
int CodigoAlquiler;
int CodigoJuego;
int CodigoCliente;
eFecha fecha;
} eAlquileres;

int menu();
int submenu();
int altaCliente(eCliente vCliente[], int tam);
int bajaCliente(eCliente vCliente[], int tam);
int existeCliente(eCliente vCliente[], int tam, int codigo);
int modificarCliente(eCliente vCliente[], int tam);
void listarClientes(eCliente vClientes[], int tam);
void inicializarClientes(eCliente vCliente[], int tam);
void ordenarClientes(eCliente vCliente[], int tam);
void altaAlquiler(eAlquileres vAlquiler[], int tam);
void listarAlquileres(eAlquileres vAlquiler[], int tam);
void inicializarAlquileres(eAlquileres vAlquiler[], int tam);
#endif  FUNCIONES_H_INCLUDED
