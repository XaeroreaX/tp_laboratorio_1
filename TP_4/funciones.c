#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayList.h"
#define OK 1
#define DENEID 0





/**-------------------------------------------------------*////1)

int agregarPelicula(ArrayList* list)
{

    FILE* arch;
    EMovie* movie;
    int len;

    movie = (EMovie*) malloc(sizeof(movie));
    cargarSmovie(movie);

    list->add(list, movie);

    //lo almacenamos en data.txt
    arch = fopen("data.txt", "ab+");
    if(arch == NULL) return 0;

    len = fwrite(movie, sizeof(EMovie), 1, arch);


    fclose(arch);

    free(movie);

    return 1;
}

/**-------------------------------------------------------*////2)

int borrarPelicula(EMovie movie)
{


    return 1;
}

/**-------------------------------------------------------///2)

int modificarM(EMovie* movie, int dim)
{

    FILE* arch;
    int index;

    index = findMovie(movie, dim);

    cargarSmovie(movie, index);

    arch = fopen("data.exe","wb");
    if(arch == NULL) return DENEID;

    fseek(arch, sizeof(EMovie) * index, SEEK_CUR);

    fwrite(movie+index, sizeof(EMovie), 1 , arch);

    fclose(arch);

    return OK;
}*/



/**-------------------------------------------------------*////4)

void generarPagina(EMovie lista[], char nombre[])
{

}

/**-------------------------------------------------------*////4)


int findMovie(EMovie* movie, int dim)
{
    int index;
    char name[20];
    printf("ingrese el nombre que quiera modificar");
    cargarCaracter(20,name);

    //bucle para validar y encontrar la pelicula
    do{


        index = 0;
        while(index < dim)
        {
            if(strcmp(name,(movie+index)->titulo) == 0)break;

            index++;
        }
        if(index == dim)
        {
            printf("ingreso mal el nombre, por favor ingrese de nuevo que quiera modificar: ");
            cargarCaracter(20,name);
        }

    }while(index == dim);

    return index;
}

/**-------------------------------------------------------*////4)

void cargarSmovie(EMovie* movie)
{

    printf("ingrese el titulo de la pelicula\n");
    cargarCaracter(20, movie->titulo);


    printf("ingrese el genero de la pelicula\n");
    cargarCaracter(20, movie->genero);

    printf("ingrese la duracion de la pelicula(en minutos)");
    scanf("%d", &movie->duracion);

    printf("ingrese la descripcion de la pelicula");
    cargarCaracter(50, movie->descripcion);

    printf("ingrese el puntahe de la pelicula\n");
    scanf("%d", &movie->puntaje);

    printf("ingrese el link de imagen de la pelicula\n");
    cargarCaracter(50, movie->linkImagen);


}
/**-------------------------------------------------------*////n)

int leerArchData(ArrayList* list)
{
    int dim, i, val;
    FILE* arch;
    EMovie* movie;

    movie = (EMovie*)malloc(sizeof(EMovie));

    arch = fopen("data.txt", "rb+");


    //situa el cursor al final
    fseek(arch, 0, SEEK_END);

    //contamos los bytes y lo dividimos por el tama�o de EMovie y despues redimensionamos
    dim = ftell(arch)/sizeof(EMovie);
    //while
    for(i = 0; i < dim; i++)
    {
        fread(movie, sizeof(movie), 1, arch);
        val = list->add(list, movie);
        if(val == -1) printf("no se pudo leer el registro");
    }

    fclose(arch);
    free(movie);
    return OK;
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
