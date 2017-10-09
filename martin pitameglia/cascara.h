#define DENEID -1
#define OK 0
#define AMOLADORA 1
#define MEZCLADORA 2
#define TALADRO 3




typedef struct
{
    int idCliente;
    int DNI;
    char nombre[50];
    char apellido[50];
    int flagAlta;

}sCliente;


typedef struct
{
    int idAlquiler;
    int idCliente;
    int equipo;
    int time;
    int tiempoEstimado;
    int flagEstado;
    char operador[100];
    int flagAlta;


}sAlquiler;


int altaCliente(sCliente clientes[], int size);

int altaAlquiler(sAlquiler alquileres[], sCliente clientes[], int sizeC, int sizeA);

int mostrarClientes(sCliente clientes[], sAlquiler alquileres[], int sizeC, int sizeA);

int bajaCliente(sCliente cliente[], sAlquiler alquileres[], int sizeC, int sizeA);

int modifCliente(sCliente clientes[], int sizeC);

int finAlquiler(sCliente clientes[], sAlquiler alquiler[], int sizeC, int sizeA);

int maxClienteAlquileres(sAlquiler alquileres[], sCliente clientes[], int sizeA, int sizeC);

int equipoMasAlquilado(sAlquiler alquileres[], int sizeA);

int promedioEquipos(sAlquiler alquileres[], int sizeA);

void HarcodearClientes(sCliente clientes[]);

void HarcodearAlquiler(sAlquiler alquileres[],sCliente clientes[], int sizeC);
