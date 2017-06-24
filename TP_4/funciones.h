#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "ArrayList.h"
typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
}EMovie __attribute__ ((packed));



/**1)
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int addMovieList(ArrayList*);

/**2)
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie);

int listWFile(ArrayList* MovieList);

int modificarM(EMovie*, int);

/**4)
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[]);


int leerArchData(ArrayList* list);

int findMovie(EMovie* movie, int dim);


void cargarSmovie(EMovie*);

/**n)
 *  carga un dato de tipo string
 *  @param el tama�o del string
 *  @param el string que quiere cargar
 */
void cargarCaracter(int, char[]);


#endif // FUNCIONES_H_INCLUDED