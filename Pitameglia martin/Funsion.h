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
void MostrarS(int i,Sauto aut0);
/** \brief muestra todos los campos o algunos de un elemento del tipo Sauto
 *
 * \param parametro de tipo entero que decide que mostrar(mayores a 0 solo para mostrar patente y profesor, si es 0 muestra todos los campos)
 * \param el elemnto del tipo Sauto que quiere mostrar
 *
 */


///3)
void MostrarOrdenadoMP(int, Sauto[]);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */




///4)
int MostrarE(int, int[],Sauto[]);

///5)
int MostrarAutosFIAT(int, Sauto[]);

///6)
int MostrarEgresados(int, int[], Sauto[]);

///7)
int elegirP(int, Sauto[]);

///8)
int valProfesor(int, int, Sauto[]);

///9)
int estacionar(int[], int);

///10)
char cargarCaracter(int , char[]);

///11)
Sauto cargarAuto(Sauto);

///12)
Sauto bajaAuto();








void MostrarS(int, Sauto);








