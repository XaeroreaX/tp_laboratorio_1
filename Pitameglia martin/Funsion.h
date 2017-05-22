#define C 51
typedef struct
{
    char patente[C];
    char modelo[C];
    int marca;//(1.fiat 2.peugeot 3.ford 4.otros)
    int profesor;
    int horaEntrada;
    int horaSalida;

}Sauto;

///1)
void HarcodearSArray(int ,Sauto[]);
/** \brief  harcodea un vector del tipo Sauto
 *
 * \param un entero que tiene el valor del tamaño del vector
 * \param el vector de tipo Sauto que quier harcodear
 *
 */


///2)
void MostrarS(int ,Sauto );
/** \brief muestra todos los campos o algunos de un elemento del tipo Sauto
 *
 * \param parametro de tipo entero que decide que mostrar(mayores a 0 solo para mostrar patente y profesor, si es 0 muestra todos los campos)
 * \param el elemnto del tipo Sauto que quiere mostrar
 *
 */


///3)
void OrdenarSP(int, Sauto[]);
/** \brief ordena un vector de la estructura Sauto
 *
 * \param un entero con la dimension del vector Sauto
 * \param vector Sauto que quiere ordenar
 *
 */


///4)
void MostrarOrdenadoMP(int, Sauto[]);
/** \brief muestra una lista ordenadas por patente y marca todos los elementos de la estructura Sauto
 *
 * \param dimension de la estructura
 * \param estructura Sauto
 *
 */

 ///5)
void estacionar(int, int, int[], int[], Sauto[]);
/** \brief funcion pensada para estacionar o ingresar la lista de espera
 *
 * \param dimension de la estructura y de la lista de espera
 * \param dimension del estacionamiento
 * \param el vector que tiene todos los automoviles estacionados
 * \param el vector con la lista de espera para estacionar
 * \param el vector de la estructura Sauto
 *
 */


///6)
void cargarCaracter(int , char[]);

///7)
int cargarAutoA(int, Sauto[]);


///8)
int egresar(int, int, int[], int[], Sauto[]);

///n)
int calcularHorarioDeEgreso(int, int);

///9)
int elegirE(int, int[]);

///10)
int MostrarE(int, int, int[],Sauto[]);

///11)
int MostrarAutosFIAT(int, Sauto[]);

///12)
int MostrarEgresados(int, int, int[], Sauto[]);

///13)
int verificarS(int, Sauto[]);

///14)
int elegirP(int, Sauto[]);

///15)
int valProfesor(int, int, Sauto[]);

///16)
int valTodosEstacionados(int, int[]);

///17)
Sauto bajaAuto(int, int[], Sauto );















