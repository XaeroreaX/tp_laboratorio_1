#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayList.h"
#define OK 1
#define DENEID 0





/**-------------------------------------------------------*////1)

int agregarPelicula(EMovie* movie)
{

    FILE* arch;
    int len;

    cargarSmovie(movie, 0);

    //lo almacenamos en data.txt
    arch = fopen("data.txt", "ab+");
    if(arch == NULL) return 0;

    len = fwrite(movie, sizeof(EMovie), 1, arch);


    fclose(arch);


    return 1;
}

/**-------------------------------------------------------*////2)

int borrarPelicula(EMovie movie)
{


    return 1;
}

/**-------------------------------------------------------*////2)

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
}



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

void cargarSmovie(EMovie* movie, int index)
{

    printf("ingrese el titulo de la pelicula\n");
    cargarCaracter(20, (movie+index)->titulo);


    printf("ingrese el genero de la pelicula\n");
    cargarCaracter(20, (movie + index)->genero);

    printf("ingrese la duracion de la pelicula(en minutos)");
    scanf("%d", &(movie + index)->duracion);

    printf("ingrese la descripcion de la pelicula");
    cargarCaracter(50, (movie+index)->descripcion);

    printf("ingrese el puntahe de la pelicula\n");
    scanf("%d", &(movie+index)->puntaje);

    printf("ingrese el link de imagen de la pelicula\n");
    cargarCaracter(50, (movie+index)->linkImagen);


}
/**-------------------------------------------------------*////n)

int leerArchData(ArrayList* list)
{
    int dim
    FILE* arch;
    EMovie* movie;
    movie = (EMovie*)malloc(sizeof(EMovie));

    arch = fopen("data.txt", "+rb");


    //situa el cursor al final
    fseek(arch, 0, SEEK_END);

    //contamos los bytes y lo dividimos por el tamaño de EMovie y despues redimensionamos
    dim = ftell(arch)/sizeof(EMovie);

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
