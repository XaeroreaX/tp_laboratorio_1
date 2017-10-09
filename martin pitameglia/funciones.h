#define DENEID -1
#define OK 0
#define AMOLADORA 1
#define MEZCLADORA 2
#define TALADRO 3

sCliente cargarCliente(int);


sAlquiler cargarAlquileres(int id, sCliente clientes[], int sizeC);


int findEspacioClientes(sCliente clientes[], int size);


int findEspacioAlquileres(sAlquiler alquileres[], int size);

int mostrarEquipo(int idCliente, sAlquiler alquileres[], int sizeA);

int mostraIndexClientes(sCliente clientes[], int sizeC);

int mostraIndexAlquiler(sAlquiler alquiler[], int sizeA, int flagId);

void bajasAlquileres(int idClientse, sAlquiler alquileres[], int sizeA);

int getIndexIdCliente(int idCliente, sCliente clientes[], int sizeC);

int getIndexIdAlquiler(int idAlquiler, sAlquiler alquiler[], int sizeA);

int getIndexIdCienteAlquiler(int idCliente, sAlquiler alquiler[], int sizeA);

void cargarCaracter(int tam, char caracteres[tam]);
