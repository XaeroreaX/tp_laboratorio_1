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

/**-------------------------------------------------------*////2)

int removeMovieList(ArrayList* movieList)
{

    int returnAux = DENEID, index, val;


    if(movieList == NULL) return returnAux;

    printf("elija la pelicula que quiere borrar por indice\n");
    val = showMovieListIndex(movieList);
    if(val == DENEID) printf("Error en la funcion showMovieList");

    scanf("%d", &index);

    index--;

    returnAux = movieList->remove(movieList, index);

    return returnAux;
}

/**-------------------------------------------------------*////3)

int setMovieList(ArrayList* movieList)
{
    int returnAux = DENEID, index, val;
    EMovie* movie;

    if(movieList == NULL) return returnAux;

    printf("ingrese el indice la pelicula que quiere modificar:\n");
    val = showMovieListIndex(movieList);
    if(val == DENEID) printf("Error en la funcion showMovieList");

    scanf("%d", &index);
    index--;

    movie = addMovie();

    if(movie != NULL)
        returnAux = movieList->set(movieList, index, movie);


    return returnAux;

}

/**-------------------------------------------------------*////n)

int fileToMovieList(ArrayList* movieList)
{
    FILE* file;
    int returnAux = DENEID, index, size, len;

    EMovie* movie;

    movie = (EMovie*) malloc(sizeof(EMovie));

    file = fopen("data.dat", "rb");

    if(file == NULL || movieList == NULL)
    {
        fclose(file);
        return returnAux;
    }

    fseek(file, 0 , SEEK_END);

    size = ftell(file)/sizeof(EMovie);

    rewind(file);

    for(index = 0; index<size; index++)
    {
        len = fread(movie, sizeof(EMovie), 1,file);
        printf("%d-%s\n",len, movie->titulo);
        returnAux = movieList->add(movieList, movie);
        if(returnAux == DENEID) break;

    }

    len = showMovieListIndex(movieList);
        if(len == DENEID) printf("Error en la funcion showMovieList");

    fclose(file);
    return returnAux;
}


/**-------------------------------------------------------*////n)

int movieListToFile(ArrayList* movieList)
{
    FILE* file;
    int returnAux = DENEID, index, size, len;

    EMovie* movie;

    movie = (EMovie*) malloc(sizeof(EMovie));

    file = fopen("data.dat", "w+b");

    if(file == NULL || movieList == NULL)
    {
        fclose(file);
        return returnAux;
    }

    //fseek(file, 0 , SEEK_END);

    size = movieList->len(movieList);

    for(index = 0; index<size; index++)
    {
        movie =(EMovie*) movieList->get(movieList, index);
        len = fwrite(movie, sizeof(EMovie), 1,file);
        //printf("%d-%d-%s",index,len, movie->titulo);
    }



    fclose(file);
    return returnAux;
}

/**-------------------------------------------------------*////n)

int showMovieListIndex(ArrayList* movieList)
{
    int i, returnAux = DENEID;

    EMovie* movie;

    movie = (EMovie*) malloc(sizeof(EMovie));

    if(movieList == NULL || movie == NULL) return returnAux;

    for(i = 0; i < movieList->len(movieList); i++)
    {
        movie = (EMovie*) movieList->get(movieList, i);
        printf("\n%d)titulo:%s", (i + 1), movie->titulo);
    }

    printf("\n");
    returnAux = i;

    return returnAux;
}

/**-------------------------------------------------------*////n)

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

/**-------------------------------------------------------*////n)

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
