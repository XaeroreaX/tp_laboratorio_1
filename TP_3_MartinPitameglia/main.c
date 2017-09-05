#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define OK 0
#define DENEID -1



int main()
{
    char seguir='s';
    int opcion=0, val, *size, *len;

    EMovie** movies;

    size = (int*) malloc(sizeof(int));
    *size = 3;

    len = (int*) malloc(sizeof(int));
    *len = 0;

    movies = (EMovie**) malloc(sizeof(EMovie*) * 3)

    if(fileToMovie(len, size, movies) == DENEID)
    {
        printf("fallo la funcion fileToMovie");
    }


    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                val = addMovieList(list);
                if(val == DENEID)
                {
                    printf("Error en la funcion addMovieList");
                    system("pause");
                }
                break;
            case 2:
                system("cls");
                val = removeMovieList(list);
                if(val == DENEID)
                {
                    printf("Error en la funcion removeMovieList");
                    system("pause");
                }
                break;
            case 3:
                val = setMovieList(list);
                if(val == DENEID)
                {

                    printf("Error en la funcion removeMovieList");
                    system("pause");
                }
                break;
            case 4:
                generarPagina(list);
                if(val == DENEID)
                {

                    printf("Error en la funcion generarPagina");
                    system("pause");
                }
               break;
            case 5:
                seguir = 'n';
                break;


        }

        system("cls");
        val = list->sort(list, compareMovie, 1);
//        if(val < 1) printf("error");
       /*val = showMovieListIndex(list);
        if(val == DENEID) printf("Error en la funcion showMovieList");*/

        movieListToFile(list);
        system("pause");
        system("cls");

    }

    return 0;
}
