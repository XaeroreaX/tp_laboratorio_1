#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cascara.h"
#include "funciones.h"






int altaCliente(sCliente clientes[], int size)
{
    int i, returnAux = DENEID, id;

    i = findEspacioClientes(clientes, size);

    if(i != DENEID)
    {
        returnAux = OK;

        printf("ingrese datos del cliente");
        printf("ingrese id:");
        scanf("%d", &id);
        clientes[i] =  cargarCliente(id);

    }

    return returnAux;
}


int altaAlquiler(sAlquiler alquileres[], sCliente clientes[], int sizeC, int sizeA)
{
    int i, id, returnAux = DENEID;

    i = findEspacioAlquileres(alquileres, sizeA);

    if(i != DENEID)
    {
        returnAux = OK;

        printf("ingrese datos del alquiler\n");
        printf("ingrese id del alquiler");
        scanf("%d", &id);
        alquileres[i] =  cargarAlquileres(id, clientes, sizeC);

    }

    return returnAux;
}



int mostrarClientes(sCliente clientes[], sAlquiler alquileres[], int sizeC, int sizeA)
{
    int i, returnAux = DENEID;

    printf("informacion de todos los clientes\n");

    for(i = 0; i < 20; i++)
    {
        if(clientes[i].flagAlta == OK)
        {

            printf("nombre:%s %s---DNI:%d---Equipos:", clientes[i].nombre, clientes[i].apellido, clientes[i].DNI);
            if(mostrarEquipo(clientes[i].idCliente, alquileres, sizeA) == DENEID) printf("NONE");
            printf("\n");
        }


    }


    return returnAux;

}


int bajaCliente(sCliente cliente[], sAlquiler alquileres[], int sizeC, int sizeA)
{
    int i, idCiente, returnAux = DENEID;
    printf("id disponible:\n");

    mostraIndexClientes(cliente, sizeC);

    printf("ingrese id que quiere eliminar:");
    scanf("%d", &idCiente);

    i = getIndexId(idCiente, cliente, sizeC);

    if(i != DENEID)
    {
        returnAux = OK;
        cliente[i].flagAlta = DENEID;
        bajasAlquileres(idCiente, alquileres, sizeA);

    }


}


int modifCliente(sCliente clientes[], int sizeC)
{
    int i, idCiente, returnAux = DENEID;

    printf("id disponible:\n");

    mostraIndexClientes(clientes, sizeC);


    printf("ingrese id que quiere modificar:");
    scanf("%d", &idCiente);

    i = getIndexId(idCiente, clientes, sizeC);

    if(i != DENEID)
    {
        returnAux = OK;
        clientes[i] = cargarCliente(idCiente);


    }


}


int finAlquiler(sCliente clientes[], sAlquiler alquiler[], int sizeC, int sizeA)
{
    int i, j, idAlquiler, returnAux = DENEID;
    printf("elija un alquiler para darle fin\n");


    if(mostraIndexAlquiler(alquiler, sizeA, OK) == OK);
    {



        printf("ingrese id:");
        scanf("%d", &idAlquiler);

        i = getIndexIdAlquiler(idAlquiler, alquiler, sizeA);
        while(i == DENEID) i = getIndexIdAlquiler(idAlquiler, alquiler, sizeA);


        if(alquiler[i].flagEstado == OK)
        {
            returnAux = OK;

            printf("ingrese el tiempo de alquiler\n");
            scanf("%d", &alquiler[i].time);

            printf("el cliente %s finalizo", alquiler[i].operador);

            alquiler[i].flagEstado = DENEID;


        }
    }


    return returnAux;

}


int maxClienteAlquileres(sAlquiler alquileres[], sCliente clientes[], int sizeA, int sizeC)
{
    int i, acumAlquileres = 0, max, flag = DENEID, returnAux =DENEID;


    for(i = 0; i < sizeC; i++)
    {
        if(clientes[i].flagAlta == OK)
        {
            returnAux = OK;
            acumAlquileres = numAlquileres(clientes[i].idCliente, alquileres, sizeA);

            if(max < acumAlquileres || flag == DENEID)
            {
                max = acumAlquileres;
                flag = OK;
            }

        }
    }

    if(returnAux == OK)
    {


        printf("los clientes con mas alquileres son:\n");

        for(i = 0; i < sizeC; i++)
        {
            if(clientes[i].flagAlta == OK)
            {
                if(max == numAlquileres(clientes[i].idCliente, alquileres, sizeA))
                {
                    printf("%s %s\n", clientes[i].nombre, clientes[i].apellido);
                }


            }

        }

    }


    return returnAux;
}


int equipoMasAlquilado(sAlquiler alquileres[], int sizeA)
{
    int i, returnAux = DENEID;
    int cantAmoladora = 0, cantMescladora = 0, cantTaladro = 0, max;

    for(i = 0; i < sizeA; i++)
    {
        if(alquileres[i].flagAlta == OK)
        {
            returnAux = OK;
            switch(alquileres[i].equipo)
            {

                case AMOLADORA:
                    cantAmoladora++;
                    break;
                case MEZCLADORA:
                    cantMescladora++;
                    break;
                case TALADRO:
                    cantTaladro++;
                    break;

            }





        }

    }



    if(returnAux == OK)
    {

        max = cantAmoladora;
        if(max <= cantMescladora) max = cantMescladora;

        if(max <= cantTaladro) max = cantTaladro;

        printf("los equipos con mas alquileres son:\n");
        if(max == cantAmoladora) printf("amoladora\n");

        if(max == cantMescladora) printf("amoladora\n");

        if(max == cantTaladro) printf("taladro\n");

    }

    return returnAux;

}


int promedioEquipos(sAlquiler alquileres[], int sizeA)
{
    int i, returnAux = DENEID;
    int cantAmoladora = 0, cantMescladora = 0, cantTaladro = 0, acumTimeAmoladora = 0, acumTimeMezcladora = 0, acumTimeTaladro = 0, promAmoladora, promMezcladora, promTaladro;

    for(i = 0; i < sizeA; i++)
    {

        if(alquileres[i].flagAlta == OK)
        {
            if(alquileres[i].flagEstado == DENEID)
            {

                returnAux = OK;
                switch(alquileres[i].equipo)
                {

                    case AMOLADORA:
                        cantAmoladora++;
                        acumTimeAmoladora += alquileres[i].time;
                        break;
                    case MEZCLADORA:
                        cantMescladora++;
                        acumTimeMezcladora += alquileres[i].time;
                        break;
                    case TALADRO:
                        cantTaladro++;
                        acumTimeTaladro += alquileres[i].time;
                        break;

                }

            }


        }


    }

    if(returnAux == OK)
    {
        if(cantAmoladora != 0)
        promAmoladora = acumTimeAmoladora/ cantAmoladora;

        if(cantMescladora != 0)
        promMezcladora = acumTimeMezcladora/ cantMescladora;

        if(cantTaladro != 0)
            promTaladro = acumTimeTaladro/ cantTaladro;

        printf("los promedios de los equipos son:\n");

        if(cantAmoladora != 0)
        {

            printf("AMOLADORA: %dHs\n", promAmoladora);
        }
        else
        {
            printf("no hay alquileres finalizados de amoladoras");
        }

        if(cantMescladora != 0)
        {

            printf("MEZCLADORA: %dHs\n", promMezcladora);
        }
        else
        {
            printf("no hay alquileres finalizados de mezcladora\n");
        }


        if(cantTaladro != 0)
        {

            printf("AMOLADORA: %dHs\n", promTaladro);
        }
        else
        {
            printf("no hay alquileres finalizados de taladro\n");
        }

    }

    return returnAux;
}

void HarcodearClientes(sCliente clientes[])
{
    int i;
    int idClientes[5] = {1000, 1001, 1002, 1003, 1004};
    int DNI [5] = {37894321, 12387924, 459876211, 45687541, 4546878};
    char nombre[][50] = {"Gyro", "tincho", "fernando", "josep", "peter"};
    char apellido[][50] = {"Zepelli", "pity", "hurtado", "joestar", "parker"};

    for(i = 0; i < 5; i++)
    {
        clientes[i].idCliente = idClientes[i];
        clientes[i].DNI = DNI[i];
        strcpy(clientes[i].nombre, nombre[i]);
        strcpy(clientes[i].apellido, apellido[i]);

        clientes[i].flagAlta = OK;

    }

}


void HarcodearAlquiler(sAlquiler alquileres[], sCliente clientes[], int sizeC)
{
    int i, j;
    int idAlquiler[5] = {1000, 1001, 1002, 1003, 1004};
    int idClientes[5] = {1000, 1001, 1000, 1004, 1004};
    int equipo[5] = {1, 2, 3, 2, 3};

    for(i = 0; i < 5; i++)
    {

        alquileres[i].idCliente = idClientes[i];

        j = getIndexId(alquileres[i].idCliente, clientes, sizeC);

        strcpy(alquileres[i].operador , clientes[j].nombre);
        strcat(alquileres[i].operador, " ");
        strcat(alquileres[i].operador, clientes[j].apellido);

        alquileres[i].idAlquiler = idAlquiler[i];
        alquileres[i].idCliente = idClientes[i];
        alquileres[i].equipo = equipo[i];

        alquileres[i].tiempoEstimado = 5;


        alquileres[i].flagAlta = OK;

        alquileres[i].flagEstado = OK;

    }

}



