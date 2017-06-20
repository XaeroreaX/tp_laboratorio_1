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

    list = (ArrayList*) malloc(sizeof(ArrayList));

    list = al_newArrayList();

    val = leerArchData(list);

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
                agregarPelicula(list);
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
        showList(list);

    }

    return 0;
}
