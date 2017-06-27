#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayList.h"
#define OK 0
#define DENEID -1





/**-------------------------------------------------------*////1)

int addMovieList(ArrayList* movieList)
{
    int returnAux = DENEID;
    EMovie* movie;

    if(movieList == NULL) return returnAux;

    movie = addMovie();

    if(movie != NULL)
        returnAux = movieList->add(movieList, movie);


    return returnAux;
}

int showMovieList(ArrayList* movieList)
{
    int i, returnAux = DENEID;

    EMovie* movie;

    movie = (EMovie*) malloc(sizeof(EMovie));

    if(movieList == NULL || movie == NULL) return returnAux;

    for(i = 0; i < movieList->len(movieList); i++)
    {
        movie = (EMovie*) movieList->get(movieList, i);
        printf("\ntitulo:%s", movie->titulo);
    }

    returnAux = OK;

    return returnAux;
}


EMovie* addMovie()
{
    EMovie* movie;

    movie = (EMovie*) malloc(sizeof(EMovie));

    /*char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];*/

    if(movie != NULL)
    {
        printf("\nIngrese el titulo de la pelicula:");
        cargarCaracter(20, movie->titulo);

        printf("\nIngrese el genero de la pelicula:");
        cargarCaracter(20, movie->genero);

        printf("\nIngrese el duracion de la pelicula(en minutos):");
        scanf("%d", &movie->duracion);
        while(movie->duracion < 3)
        {
            printf("\nIngreso mal el duracion de la pelicula, por favor ingrese de nuevo:");
            scanf("%d", &movie->duracion);
        }

        printf("\nIngrese la descripcion de la pelicula:");
        cargarCaracter(50, movie->descripcion);

        printf("\nIngrese el puntuacion de la pelicula(de 10 a 100):");
        scanf("%d", &movie->puntaje);
        while(movie->puntaje < 10 || movie->puntaje > 100)
        {
            printf("\nIngreso mal la puntuacion de la pelicula, por favor ingrese de nuevo:");
            scanf("%d", &movie->puntaje);
        }

        printf("\nIngrese un link para la imagen de la pelicula:");
        cargarCaracter(50, movie->linkImagen);

    }

    return movie;
}


void cargarCaracter(int tam, char caracteres[tam])
{
    char buffer[1024];

    fflush(stdin);

    gets(buffer);
    while(strlen(buffer) > tam)
    {
        printf("ingreso mal la cadena de caracteres, ingrese de nuevo");
        fflush(stdin);
        gets(buffer);
    }
    strcpy(caracteres, buffer);

}
