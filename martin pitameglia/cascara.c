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


int altaAlquiler(sAlquiler alquileres[], int size)
{
    int i, returnAux = DENEID;

    i = findEspacioAlquileres(alquileres, size);

    if(i != DENEID)
    {
        returnAux = OK;

        printf("ingrese datos del alquiler");
        alquileres[i] =  cargarAlquileres();

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
    printf("elija un alquiler para darle fin\n");

    mostraIndexAlquiler(alquiler, sizeA);





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



void HarcodearAlquiler(sAlquiler alquileres[])
{
    int i;
    int idAlquiler[5] = {1000, 1001, 1002, 1003, 1004};
    int idClientes[5] = {1000, 1001, 1000, 1004, 1004};
    int equipo[5] = {1, 2, 3, 2, 3};
    int time[5] = {4, 1, 3, 2 , 5};
    int flagEstado[] = {DENEID, OK, DENEID, OK, DENEID};
    char operador[][50] = {"", "", "", "", ""};

    for(i = 0; i < 5; i++)
    {
        alquileres[i].idAlquiler = idAlquiler[i];
        alquileres[i].idCliente = idClientes[i];
        alquileres[i].equipo = equipo[i];
        alquileres[i].time = time[i];

        alquileres[i].tiempoEstimado = 5;

        alquileres[i].flagEstado = flagEstado[i];
        strcpy(alquileres[i].operador, operador[i]);

        alquileres[i].flagAlta = OK;



    }

}
