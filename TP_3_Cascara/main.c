#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define OK 1
#define DENEID 0



int main()
{
    char seguir='s';
    int opcion=0, val, dim, i = 2;

    EMovie* movie = (EMovie*) malloc(sizeof(EMovie) * 5);



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
                val = agregarPelicula(movie);
                if(val == DENEID) printf("no se pudo agregar la pelicula");

                break;
            case 2:
                break;
            case 3:

                dim = leerArchData(movie);


                val = modificarM(movie, dim);
               break;
            case 4:
               break;
            case 5:
                seguir = 'n';
                break;


        }


    }

    return 0;
}
