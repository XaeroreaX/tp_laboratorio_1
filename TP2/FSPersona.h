typedef struct
{
    char nombre[20];
    int edad;
    int dni;
    int flagEstado;
}SPersona;
/** \brief un tipo de dato tipo estructura de una persona basica
 *
 * \param nombre (veinte caracteres)
 * \param edad
 * \param dni documento
 * \param flag estado 1 casado 0 soltero
 *
 */


SPersona HarcodearS(char[], int, int, int);
/** \brief funcion para harcodear una bariable tipo SPersona
 *
 * \param nombre char vector de veinte caracteres
 * \param edad entero
 * \param dni entero
 * \param flag del estado (1 o 0)
 * \return retorna todo un dato de la estructura tipo SPersona
 *
 */


void mostraArrayS(int ,SPersona[]);
/** \brief muestra un vector de la estructura SPersona
 *
 * \param tamaño del vector
 * \param vector de la estructura
 *
 */

 void mostrarBarraEdades(int ,SPersona[]);
 /** \brief imprime una barra que dependiendp de la edad(<18 19-35 >35) contara con un *
  *
  * \param vector de la estructura SPersona
  * \param tamaño del vector en entero
  *
  */



SPersona ordenarS(int ,SPersona[]);
/** \brief ordena alfabeticamente un vector de la estructura SPersona
 *
 * \param entero tamaño de la estructura
 * \param vector a ordenar
 * \return vector ordenado alfabeticamente
 *
 */
