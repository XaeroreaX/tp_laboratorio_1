#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cascara.h"
#include "funciones.h"



sCliente cargarCliente(int id)
{
    int i = 0;
    sCliente cliente;


    cliente.idCliente = id;
    printf("ingrese el DNI:");
    scanf("%d", &cliente.DNI);
    printf("\ningrese el nombre:");
    cargarCaracter(50, cliente.nombre);
    printf("\ningrese el apellid:");
    cargarCaracter(50, cliente.apellido);

    cliente.flagAlta = OK;


    return cliente;
}


sAlquiler cargarAlquileres()
{
    int i = 0;
    sAlquiler alquiler;


    alquiler.idCliente = OK;

    printf("ingrese el equipo:");
    scanf("%d", &alquiler.equipo);
    printf("\ningrese el operador:");
    cargarCaracter(50, alquiler.operador);


    alquiler.time = OK;

    alquiler.flagEstado = DENEID;

    alquiler.flagAlta = OK;


    return alquiler;
}


int findEspacioClientes(sCliente clientes[], int size)
{
    int i, returnAux = DENEID;

    for(i = 0; i <size; i++)
    {
        if(clientes[i].flagAlta = DENEID) break;

    }

    if(i<size) returnAux = i;

    return returnAux;
}

int findEspacioAlquileres(sAlquiler alquileres[], int size)
{
    int i, returnAux = DENEID;

    for(i = 0; i <size; i++)
    {
        if(alquileres[i].flagAlta = DENEID) break;

    }

    if(i<size) returnAux = i;

    return returnAux;
}

int mostrarEquipo(int idCliente, sAlquiler alquileres[], int sizeA)
{
    int i, returnAux = DENEID;

    for(i = 0; i < sizeA; i++)
    {
        if(alquileres[i].flagAlta == OK)
        {
            if(idCliente == alquileres[i].idCliente)
            {
                returnAux = OK;
                switch(alquileres[i].equipo)
                {
                    case AMOLADORA:
                        printf(" amoladora,");
                        break;
                    case MEZCLADORA:
                        printf(" mezcladora,");
                        break;
                    case TALADRO:
                        printf(" taladro,");
                        break;
                    default:
                        printf("NONE");
                        break;
                }

            }
        }
    }

    return returnAux;
}

void mostraIndexClientes(sCliente clientes[], int sizeC)
{
    int i;

    for(i = 0; i < sizeC; i++)
    {

        if(clientes[i].flagAlta == OK)
        {
            printf("id:%d---operador:%s %s\n", clientes[i].idCliente, clientes[i].nombre, clientes[i].apellido);


        }

    }

}

void mostraIndexAlquiler(sAlquiler alquiler[], int sizeA)
{
    int i;

    for(i = 0; i < sizeA; i++)
    {

        if(alquiler[i].flagAlta == OK)
        {
            printf("id:%d---operador:%s---\n", alquiler[i].idAlquiler, alquiler[i].operador);
        }

    }

}


void bajasAlquileres(int idClientse, sAlquiler alquileres[], int sizeA)
{
    int i;


    for(i = 0; i < sizeA; i++)
    {
        if(alquileres[i].flagAlta == OK)
        {

            if(idClientse == alquileres[i].idCliente) alquileres[i].flagAlta == DENEID;

        }


    }




}

int getIndexId(int idCliente, sCliente clientes[], int sizeC)
{
    int i, returnAux = DENEID;

    for(i = 0; i < sizeC; i++)
    {
        if(clientes[i].flagAlta == OK)
        {
            if(clientes[i].idCliente == idCliente)break;


        }


    }
    if(i < sizeC) returnAux = i;


    return returnAux;
}

/**-----------------------------------------------------------------------------------------------------------------------*/

void cargarCaracter(int tam, char caracteres[tam])
{
    char buffer[1024];

    fflush(stdin);
    gets(buffer);
    while(strlen(buffer) > tam)
    {
        printf("ingreso mal la cadena de caracteres, ingrese de nuevo");
        gets(buffer);
    }
    strcpy(caracteres, buffer);

    return caracteres[tam];
}
