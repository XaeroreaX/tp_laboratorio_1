#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define OK 1
#define DENEID 0





/**-------------------------------------------------------*////1)

int agregarPelicula(EMovie* movie)
{

    FILE* arch;
    int len;

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
    char name[20];
    printf("ingrese el nombre que quiera modificar");
    cargarCaracter(20,name);

    //bucle para validar y encontrar la pelicula
    do{


        for(index = 0; index < dim && strcmp((movie + index)->titulo,name)!= 0; index++);

        if(index == dim)
        {
            printf("ingreso mal el nombre, por favor ingrese de nuevo que quiera modificar");
            cargarCaracter(20,name);
        }

    }while(index == dim);

    arch = fopen("data.exe","wb");

    fseek(arch, sizeof(EMovie) * index, SEEK_CUR);



    fclose(arch);

    return 1;
}


/**-------------------------------------------------------*////4)

void generarPagina(EMovie lista[], char nombre[])
{

}

/**-------------------------------------------------------*////n)

int leerArchData(EMovie* movies)
{


    FILE* arch;
    int i, dim;
    arch = fopen("data.txt", "rb");
    if(arch == NULL) return DENEID;

    //situa el cursor al final
    fseek(arch, 0, SEEK_END);

    //contamos los bytes y lo dividimos por el tamaño de EMovie y despues redimensionamos
    dim = ftell(arch)/sizeof(EMovie);
    movies = (EMovie*) realloc(movies,sizeof(EMovie) * dim);
    if(movies == NULL) return DENEID;


    //rebobinamos
    rewind(arch);

    //y leemos el archivo
    dim = fread(movies, sizeof(EMovie), dim, arch);


    fclose(arch);

    /*char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];*/

    //mostramos
    for(i = 0; i < dim; i++){

        printf("titulo:%s---genero:%s---duracion:%d---puntaje:%d\n", (movies+i)->titulo,(movies+i)->genero,(movies+i)->duracion,(movies+i)->puntaje);
        printf("descripcion:%s\n\n", (movies+i)->descripcion);
    }

    return dim;

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
