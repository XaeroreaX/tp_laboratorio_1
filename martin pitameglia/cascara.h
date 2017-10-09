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




/** \brief esta funcion agrega un cliente al array sCliente
 *
 * \param recibe un array de la estructura del tipo sCliente
 * \param recibe un entero con la cantidad de elementos del array sCliente
 * \return (-1) si no hay espacio para crear en el array
 *         (0) si creo un elemento de la estructura
 *
 */
int altaCliente(sCliente clientes[], int size);



/** \brief esta funcion agrega un alquiler al array sAlquiler
 *
 * \param recibe un array de la estructura del tipo sCliente
 * \param recibe un array de la estructura del tipo sAlquiler
 * \param recibe un entero con la cantidad de elementos del array sCliente
 * \param recibe un entero con la cantidad de elementos del array sAlquiler
 * \return (-1) si no encontro espacio en el array para un nuevo alquiler
 *         (0) si pudo crear un nuevo alquiler
 *
 */
int altaAlquiler(sCliente clientes[], sAlquiler alquileres[], int sizeC, int sizeA);




/** \brief esta funcion muestra la informacion de todo los clientes con todos los equipos alquilados
 *
 * \param recibe un array de la estructura del tipo sCliente
 * \param recibe un array de la estructura del tipo sAlquiler(para mostrar los equipos)
 * \param recibe un entero con la cantidad de elementos del array sCliente
 * \param recibe un entero con la cantidad de elementos del array sAlquiler
 * \return (-1) si no hay clientes en el array
 *         (0) si hay clientes en el array
 */
int mostrarClientes(sCliente clientes[], sAlquiler alquileres[], int sizeC, int sizeA);



/** \brief borra un cliente del array
 *
 * \param recibe un array de la estructura del tipo sCliente
 * \param recibe un array de la estructura del tipo sAlquiler(para borrar todos los alquileres asociados al cliente)
 * \param recibe un entero con la cantidad de elementos del array sCliente
 * \param recibe un entero con la cantidad de elementos del array sAlquiler
 * \return (-1) si se ingreso un id invalido
 *         (0) si pudo borrar el cliente
 */
int bajaCliente(sCliente cliente[], sAlquiler alquileres[], int sizeC, int sizeA);


/** \brief modificar un cliente de la lista de clientes
 *
 * \param recibe un array de la estructura del tipo sCliente
 * \param recibe un entero con la cantidad de elementos del array sCliente
 * \return (-1) si se ingresa id invalido
 *         (0) si se pudo modificar correctamente
 *
 */
int modifCliente(sCliente clientes[], sAlquiler alquileres[], int sizeC, int sizeA);


/** \brief esta funcion finaliza el estado del alquiler y registra su duracion
 *
 * \param recibe un array de la estructura del tipo sCliente
 * \param recibe un array de la estructura del tipo sAlquiler(para borrar todos los alquileres asociados al cliente)
 * \param recibe un entero con la cantidad de elementos del array sCliente
 * \param recibe un entero con la cantidad de elementos del array sAlquiler
 * \return
 *
 */
int finAlquiler(sCliente clientes[], sAlquiler alquiler[], int sizeC, int sizeA);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int maxClienteAlquileres(sCliente clientes[], sAlquiler alquileres[], int sizeC, int sizeA);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int equipoMasAlquilado(sAlquiler alquileres[], int sizeA);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int promedioEquipos(sAlquiler alquileres[], int sizeA);


void HarcodearClientes(sCliente clientes[]);

void HarcodearAlquiler(sAlquiler alquileres[],sCliente clientes[], int sizeC);
