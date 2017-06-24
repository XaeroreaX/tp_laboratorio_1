#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ArrayList.h"
#define OK 1
#define DENEID 0



int main()
{
    char seguir='s';
    int opcion=0, val;
    ArrayList* list;

    list = al_newArrayList();




    while(seguir=='s')
    {


        val = leerArchData(list);
        printf("%d", val);

        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                addMovieList(list);
                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
               break;
            case 5:

                seguir = 'n';
                break;

        }
        //listWFile(list);
        showList(list);

    }

    return 0;
}
