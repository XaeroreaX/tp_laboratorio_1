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
                if(altaCliente(clientes, 20) == DENEID) printf("no hay espacio en el array\n");
                break;

            case 2:
                system("cls");
                if(altaAlquiler(clientes, alquileres, 20, 20) == DENEID) printf("no hay espacio en el array\n");
                break;

            case 3:
                system("cls");
                if(mostrarClientes(clientes, alquileres, 20, 20) == DENEID) printf("no hay clientes cargados\n");
                break;
            case 4:

                system("cls");

                if(bajaCliente(clientes, alquileres, 20, 20) == DENEID) printf("id no valido\n");

                break;

            case 5:

                system("cls");

                if(modifCliente(clientes, alquileres,20, 20) == DENEID) printf("no existe ese id\n");

                break;
            case 6:
                system("cls");
                if(finAlquiler(clientes, alquileres, 20, 20) == DENEID) printf("el alquiler ya habia finalizado\n");
                break;

            case 7:

                system("cls");
                if(mostraIndexAlquiler(alquileres, 20, DENEID) == DENEID) printf("no hay alquileres\n");

                break;

            case 8:
                system("cls");
                if(maxClienteAlquileres(clientes, alquileres, 20, 20)) printf("no hay alquileres\n");

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
                printf("fin del programa\n");
                break;


            default:
                printf("opcion incorrecta\n");
                break;


        }


    system("pause");
    system("cls");
    }



    return 0;
}


























