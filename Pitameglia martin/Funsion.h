#define C 51
typedef struct
{
    char patente[C];
    char modelo[C];
    int marca;//(1.fiat 2.peugeot 3.ford 4.otros)
    int profesor;

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
void OrdenarSP(int , Sauto[]);



///5)
void MostrarOrdenadoMP(int, Sauto[]);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 ///11)
void estacionar(int, int[], int);

///6)
void egresar(int , int[]);

///13)
void cargarCaracter(int , char[]);

///12)
int cargarAutoA(int, Sauto[]);


///6)
int MostrarE(int, int[],Sauto[]);

///7)
int MostrarAutosFIAT(int, Sauto[]);

///8)
int MostrarEgresados(int, int[], Sauto[]);

///9)
int elegirP(int, Sauto[]);

///10)
int valProfesor(int, int, Sauto[]);






///14)
Sauto bajaAuto(int , int[], Sauto );















