#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"




/*char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];*/
/**-------------------------------------------------------*////1)

int agregarPelicula(EMovie movie)
{

    FILE* arch;
    int len;

    printf("ingrese el titulo de la pelicula\n");
    cargarCaracter(20, movie.titulo);


    printf("ingrese el genero de la pelicula\n");
    cargarCaracter(20, movie.genero);

    printf("ingrese la duracion de la pelicula(en minutos)");
    scanf("%d", &movie.duracion);

    printf("ingrese la descripcion de la pelicula");
    cargarCaracter(50, movie.descripcion);

    printf("ingrese el puntahe de la pelicula\n");
    scanf("%d", &movie.puntaje);

    printf("ingrese el link de imagen de la pelicula\n");
    cargarCaracter(50, movie.linkImagen);

    //lo almacenamos en data.txt
    arch = fopen("data.txt", "ab+");
    if(arch == NULL) return 0;


    len = fwrite(&movie, sizeof(EMovie), 1, arch);


    fclose(arch);


    return 1;
}

/**-------------------------------------------------------*////2)

int borrarPelicula(EMovie movie)
{


    return 1;
}

/**-------------------------------------------------------*////3)

void generarPagina(EMovie lista[], char nombre[])
{

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
