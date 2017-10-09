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

    HarcodearClientes(clientes);

    HarcodearAlquiler(alquileres, clientes, 20);

    while(opcion != 11)
    {

        printf("1.- Alta de clientes\n");
        printf("2.- Alta de alquileres\n");
        printf("3.- mostrar informacion de los clientes\n");
        printf("4.- baja de cliente\n");
        printf("5.- modificar clientes\n");
        printf("6.- Fin del alquiler\n");
        printf("7.- mostrar todos los alquileres\n");
        printf("8.- mostrar a los clientes con mas alquileres\n");
        printf("9.- mostrar los equipos mas alquilados\n");
        printf("10.- mostrar los promedios de los equipos\n");
        printf("11.- quit\n");

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
                altaAlquiler(alquileres, clientes, 20, 20);
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
                system("cls");
                if(finAlquiler(clientes, alquileres, 20, 20) == DENEID) printf("el alquiler ya habia finalizado");
                break;

            case 7:

                system("cls");
                mostraIndexAlquiler(alquileres, 20, DENEID);

                break;

            case 8:
                system("cls");
                if(maxClienteAlquileres(alquileres, clientes, 20, 20)) printf("no hay alquileres");

                break;

            case 9:
                system("cls");

                if(equipoMasAlquilado(alquileres, 20) == DENEID) printf("no hay equipos\n");

                break;

            case 10:

                system("cls");

                if(promedioEquipos(alquileres, 20) == DENEID) printf("no hay alquileres finalizados\n");

                break;

            case 11:

                break;


            default:
                printf("ingreso mal la opcion");
                break;


        }


    system("pause");
    system("cls");
    }



    return 0;
}


























