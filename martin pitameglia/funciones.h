#define DENEID -1
#define OK 0
#define AMOLADORA 1
#define MEZCLADORA 2
#define TALADRO 3

sCliente cargarCliente(int);


sAlquiler cargarAlquileres();


int findEspacioClientes(sCliente clientes[], int size);


int findEspacioAlquileres(sAlquiler alquileres[], int size);


void cargarCaracter(int tam, char caracteres[tam]);
