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


sAlquiler cargarAlquileres(int id, sCliente clientes[], int sizeC)
{
    int i = 0, idCliente, error = OK;
    sAlquiler alquiler;


    alquiler.idAlquiler = id;

    mostraIndexClientes(clientes, sizeC);


    printf("ingrese id:");
    scanf("%d", &idCliente);

    i = getIndexIdCliente(idCliente, clientes, sizeC);
    while(i == DENEID) i = getIndexIdCliente(idCliente, clientes, sizeC);


    alquiler.idCliente = clientes[i].idCliente;

    strcpy(alquiler.operador , clientes[i].nombre);
    strcat(alquiler.operador, " ");
    strcat(alquiler.operador, clientes[i].apellido);




    do
    {

        printf("ingrese el equipo:");
        printf("\n1.-Amoladora\n2.-Mezcladora\n3.-Taladro\n");

        scanf("%d", &alquiler.equipo);

        switch(alquiler.equipo)
        {
            case AMOLADORA:
                printf("usted ingreso amoladora");
                error = DENEID;
                break;
            case MEZCLADORA:
                printf("usted ingreso mezcladora,");
                error = DENEID;
                break;
            case TALADRO:
                printf("usted ingreso taladro");
                error = DENEID;
                break;
            default:
                error = OK;
                printf("ingreso mal la opcion\n\n");
                break;
        }



    }while(error == OK);

    printf("ingrese tiempo estimado:");

    scanf("%d", &alquiler.tiempoEstimado);

    alquiler.time = OK;

    alquiler.flagEstado = OK;

    alquiler.flagAlta = OK;


    return alquiler;
}


int findEspacioClientes(sCliente clientes[], int size)
{
    int i, returnAux = DENEID;

    for(i = 0; i <size; i++)
    {
        if(clientes[i].flagAlta == DENEID) break;

    }

    if(i<size) returnAux = i;

    return returnAux;
}

int findEspacioAlquileres(sAlquiler alquileres[], int size)
{
    int i, returnAux = DENEID;

    for(i = 0; i <size; i++)
    {
        if(alquileres[i].flagAlta == DENEID) break;

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
                }

            }
        }
    }

    return returnAux;
}

int mostraIndexClientes(sCliente clientes[], int sizeC)
{
    int i, returnAux = DENEID;

    for(i = 0; i < sizeC; i++)
    {

        if(clientes[i].flagAlta == OK)
        {
            returnAux = OK;
            printf("id:%d---Nombre:%s %s\n", clientes[i].idCliente, clientes[i].nombre, clientes[i].apellido);


        }

    }

    return returnAux;

}

int mostraIndexAlquiler(sAlquiler alquiler[], int sizeA, int flagId)
{
    int i, returnAux = DENEID;

    for(i = 0; i < sizeA; i++)
    {

        if(alquiler[i].flagAlta == OK)
        {
            returnAux = OK;

            if(flagId == OK)
            {

                printf("id:%d---operador:%s---Equipo:", alquiler[i].idAlquiler, alquiler[i].operador);
            }
            else
            {
                printf("operador:%s---Equipo:", alquiler[i].operador);
            }
            switch(alquiler[i].equipo)
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

            if(alquiler[i].flagEstado == OK)
            {
                printf("---Estado:en curso");
            }
            else
            {
                printf("---Estado:FINALIZADO---tiempo:%d", alquiler[i].time);

            }
            printf("\n");


        }

    }

    return returnAux;

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

int getIdC(sCliente clientes[], int sizeC)
{

    int i, id = 1000;

    for(i = 0; i < sizeC; i++)
    {
        if(clientes[i].flagAlta == OK)
        {
            id = clientes[i].idCliente + 1;

        }
        else break;

    }

    return id;
}

int getIdA(sAlquiler alquileres[], int sizeA)
{

    int i, id = 1000;

    for(i = 0; i < sizeA; i++)
    {
        if(alquileres[i].flagAlta == OK)
        {
            id = alquileres[i].idAlquiler + 1;

        }
        else break;

    }

    return id;
}

int getIndexIdCliente(int idCliente, sCliente clientes[], int sizeC)
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

int getIndexIdAlquiler(int idAlquiler, sAlquiler alquiler[], int sizeA)
{
    int i, returnAux = DENEID;

    for(i = 0; i < sizeA; i++)
    {
        if(alquiler[i].flagAlta == OK)
        {
            if(alquiler[i].idAlquiler == idAlquiler)break;


        }


    }
    if(i < sizeA) returnAux = i;


    return returnAux;
}

int getIndexIdCienteAlquiler(int idCliente, sAlquiler alquiler[], int sizeA)
{
    int i, returnAux = DENEID;

    for(i = 0; i < sizeA; i++)
    {
        if(alquiler[i].flagAlta == OK)
        {
            if(alquiler[i].idCliente == idCliente)break;


        }


    }
    if(i < sizeA) returnAux = i;


    return returnAux;
}

int numAlquileres(int idCliente, sAlquiler alquileres[], int sizeA)
{
    int i, len = 0;

    for(i = 0; i < sizeA; i++)
    {
        if(alquileres[i].flagAlta == OK)
        {
            if(idCliente == alquileres[i].idCliente) len++;

        }


    }

    return len;
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
