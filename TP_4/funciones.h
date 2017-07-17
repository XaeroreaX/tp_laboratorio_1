#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "ArrayList.h"
typedef struct{
    char titulo[50];
    char genero[100];
    int duracion;
    char descripcion[800];
    int puntaje;
    char linkImagen[800];
}EMovie __attribute__ ((packed));



int addMovieList(ArrayList*);

int removeMovieList(ArrayList* movieList);

int setMovieList(ArrayList* movieList);

int fileToMovieList(ArrayList* movieList);

int movieListToFile(ArrayList* movieList);

int showMovieListIndex(ArrayList* movieList);

EMovie* addMovie();

int compareMovie(void* MovieA, void* MovieB);

typedef struct{
    int id;
    char nickName[50];
    char password[50];

}SUser;

typedef struct{

    int id;
    ArrayList* waching;
    int puntaje;
}SRanking;

int harcodearSUser(ArrayList*);

SUser* login(ArrayList* userList);

void cargarCaracter(int tam, char caracteres[tam]);

#endif // FUNCIONES_H_INCLUDED
