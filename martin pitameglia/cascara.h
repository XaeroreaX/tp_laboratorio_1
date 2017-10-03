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
    char operador[50];
    int flagAlta;


}sAlquiler;


int altaCliente(sCliente clientes[], int size);
