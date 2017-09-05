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



int addMovieList(ArrayList*);

int removeMovieList(ArrayList* movieList);

int setMovieList(ArrayList* movieList);

int fileToMovie(int*,int*, EMovie**);

int movieListToFile(ArrayList* movieList);

int showMovieListIndex(ArrayList* movieList);

EMovie* addMovie();

int compareMovie(void* MovieA, void* MovieB);

void cargarCaracter(int tam, char caracteres[tam]);

#endif // FUNCIONES_H_INCLUDED
