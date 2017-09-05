#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define OK 0
#define DENEID -1





/**-------------------------------------------------------*////1)

int addMovieList(int* len, int* size, EMovie** movie)
{
    int returnAux = DENEID;

    if(*size == *len)
        resizeUp(size, movie);

    *(movie+(*len+1)) = (EMovie*) malloc(sizeof(EMovie));


    if(movie == NULL) return returnAux;

    *(movie+*len) = addMovie();

    if(movie != NULL)
        returnAux = movieList->add(movieList, movie);


    return returnAux;
}

/**-------------------------------------------------------*////2)

int removeMovieList(ArrayList* movieList)
{

    int returnAux = DENEID, index, val;


    if(movieList == NULL) return returnAux;

    printf("elija la pelicula que quiere borrar por indice\n0)Cancel");
    val = showMovieListIndex(movieList);
    if(val == DENEID) printf("Error en la funcion showMovieList");

    scanf("%d", &index);
    while(index < 0 || index > movieList->len(movieList))
    {
        printf("elijio mal la pelicula que quiere borrar, por favor ingrese de nuevo\n");
        scanf("%d", &index);
    }

    index--;

    if(index >= 0)
        returnAux = movieList->remove(movieList, index);
    else
        returnAux = OK;


    return returnAux;
}

/**-------------------------------------------------------*////3)

int setMovieList(ArrayList* movieList)
{
    int returnAux = DENEID, index, val;
    EMovie* movie;

    if(movieList == NULL) return returnAux;

    printf("ingrese el indice la pelicula que quiere modificar:\n0)Cancel");
    val = showMovieListIndex(movieList);
    if(val == DENEID) printf("Error en la funcion showMovieList");

    scanf("%d", &index);

    while(index < 0 || index > movieList->len(movieList))
    {
        printf("elijio mal la pelicula que quiere modificar, por favor ingrese de nuevo\n");
        scanf("%d", &index);
    }


    index--;
    if(index >= 0)
    {

        movie = addMovie();

        if(movie != NULL)
            returnAux = movieList->set(movieList, index, movie);
    }
    else
        returnAux = OK;

    return returnAux;

}

/**-------------------------------------------------------*////4)

int generarPagina(EMovie** movie)
{
    int i, returnAux = DENEID, val;


    FILE* file;

    movie = (EMovie*) malloc(sizeof(EMovie));

    if(movieList == NULL || movie == NULL) return returnAux;

    printf("ingrese el indice la pelicula que quiere generar pagina:\n\n0)Cancel");
    val = showMovieListIndex(movieList);
    if(val == DENEID) printf("Error en la funcion showMovieList");

    scanf("%d", &i);
    while(i < 0 || i > movieList->len(movieList))
    {
        printf("elijio mal el indice, por favor ingrese de nuevo\n");
        scanf("%d", &i);
    }
    i--;

    if(i >= 0)
    {

        movie = (EMovie*) movieList->get(movieList, i);

        file = fopen("index.HTML", "w");


        fprintf(file,"<img  src=%s alt=%s style=width:200px;hight:200px>",movie->linkImagen,movie->titulo);

                //titulo
        fprintf(file,"<h2><a href=#>%s</a></h2>",movie->titulo);

                //otros aspectos

        fprintf(file,"<h3><li> Genero: %s</li>   <li>Puntaje: %d </li>     <li>Duracion: %d </li>               </h3>",movie->genero,movie->puntaje,movie->duracion);

        fprintf(file,"<pre>%s</pre>", movie->descripcion);


        fclose(file);

    }
    returnAux = OK;
    return returnAux;
}

/**-------------------------------------------------------*////n)

int fileToMovie(int *len,int *size, EMovie** movie)
{
    FILE* file;
    int index, returnAux = DENEID;


    file = fopen("data.dat", "rb");

    if(file == NULL || movieList == NULL)
    {
        fclose(file);
        return returnAux;
    }

    fseek(file, 0 , SEEK_END);

    *len = ftell(file)/sizeof(EMovie);

    rewind(file);

    returnAux = OK;
    for(index = 0; index<*len; index++)
    {

        if(index == *size)
        {

            if(resizeUp(size, movie) == DENEID)
            {
                *len = index;
                returnAux = DENEID;
                break;
            }
        }

        *(movie+index) = (EMovie*) malloc(sizeof(EMovie));

        fread(*(movie+index), sizeof(EMovie*), 1,file);
  //      printf("%d-%s\n",len, movie->titulo);

    }
/*
    len = showMovieListIndex(movieList);
        if(len == DENEID) printf("Error en la funcion showMovieList");*/

    fclose(file);
    return size;
}


/**-------------------------------------------------------*////n)

int movieListToFile(int size, EMovie** movie)
{
    FILE* file;
    int returnAux = DENEID, index, len;

    file = fopen("data.dat", "w+b");

    if(file == NULL || movieList == NULL)
    {
        fclose(file);
        return returnAux;
    }

    //fseek(file, 0 , SEEK_END);

    for(index = 0; index<size; index++)
    {
        len = fwrite(*(movie+index), sizeof(EMovie*), 1,file);
        //printf("%d-%d-%s",index,len, movie->titulo);
    }



    fclose(file);
    return returnAux;
}

/**-------------------------------------------------------*////n)

int resizeUp(int *size, EMovie** movie)
{
    int returnAux = DENEID;
    EMovie** aux;

    aux = (EMovie**) realloc(movie, sizeof(EMovie*)*3)
    if(aux == NULL) return returnAux;

    movie = aux;
    *size += 3;
    returnAux = OK;

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

int compareMovie(void* MovieA, void* MovieB)
{

    if( strcmp(((EMovie*)MovieA)->titulo, ((EMovie*)MovieB)->titulo) == 1)
    {
        return 1;
    }
    if( strcmp(((EMovie*)MovieA)->titulo, ((EMovie*)MovieB)->titulo) == -1)
    {
        return -1;
    }
    return 0;


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
