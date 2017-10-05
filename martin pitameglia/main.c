#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cascara.h"
#include "funciones.h"
#define DENEID -1
#define OK 0
int main()
{
    int i;
    int opcion = 0;

    sCliente clientes[20];

    sAlquiler alquileres[20];

    for(i = 0; i < 20; i++)
    {

        clientes[i].flagAlta = DENEID;

        alquileres[i].flagAlta = DENEID;
    }

    HarcodearAlquiler(alquileres);

    HarcodearClientes(clientes);

    while(opcion != 7)
    {

        printf("1.- Alta de clientes\n");
        printf("2.- Alta de alquileres\n");
        printf("3.- mostrar informacion de los clientes\n");
        printf("4.- baja de cliente\n");
        printf("5.- modificar clientes\n");
        printf("7.- quit\n");

        printf("ingresen opcion:");
        scanf("%d", &opcion);


        switch(opcion)
        {

            case 1:
                system("cls");
                altaCliente(clientes, 20);
                break;

            case 2:
                system("cls");
                altaAlquiler(alquileres, 20);
                break;

            case 3:
                system("cls");
                mostrarClientes(clientes, alquileres, 20, 20);
                break;
            case 4:

                system("cls");

                bajaCliente(clientes, alquileres, 20, 20);

                break;

            case 5:

                system("cls");

                modifCliente(clientes, 20);

                break;
            case 6:
                finAlquiler(clientes, alquileres, 20, 20);
                break;

            case 7:

                break;

            default:

                break;


        }


    system("pause");
    system("cls");
    }


    printf("Hello world!\n");
    return 0;
}


























