#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define OK 0
#define DENEID -1



int main()
{

    int *size, *len;

    EMovie** movies;

    size = (int*) malloc(sizeof(int));
    *size = 3;

    len = (int*) malloc(sizeof(int));
    *len = 0;

    movies = (EMovie**) malloc(sizeof(EMovie*) * 3);

    if(HarcodearMovieList(len, size, movies) == DENEID) printf("X");


    generarPagina(len, movies);

    movieListToFile(len, movies);

    //showMovieListIndex(len, movies);

    return 0;
}
