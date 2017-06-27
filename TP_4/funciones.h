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

int showMovieList(ArrayList* movieList);

EMovie* addMovie();

void cargarCaracter(int tam, char caracteres[tam]);

#endif // FUNCIONES_H_INCLUDED
