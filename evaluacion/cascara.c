#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "cascara.h"
#include "fClientes.h"
#include "fServicios.h"

///1)
int AltaDeCliente(ArrayList* clienteList)
{
    int returnAux = DENIED, id;
    sCliente* cliente;

    if(clienteList == NULL) return returnAux;

    id = C_getId(clienteList);

    printf("ingrese los datos del cliente: \n\n");
    cliente = C_cargarCliente(id);

    //C_showCliente(cliente);

    returnAux = clienteList->add(clienteList, cliente);

    return returnAux;

}


///2)
int modificacionDeCliente(ArrayList* clienteList)
{
    int i, id, returnAux = DENIED;
    sCliente* cliente;

    if(clienteList == NULL) return returnAux;

    if(clienteList->isEmpty(clienteList) != OKP)
    {
        printf("ingrese el Id que desea modificar\n\n");

        i = C_getIndex(clienteList);



        if(i != DENIED)
        {


            cliente = clienteList->get(clienteList, i);

            id = cliente->idCliente;

            cliente = C_cargarCliente(id);

            returnAux = clienteList->set(clienteList, i, cliente);
        }
        if(returnAux != DENIED)
        {
            printf("el cliente ha sido modificado con exito\n");

        }
    }
    else
    {
        printf("isEmpty!!!\n");
        returnAux = OK;
    }

    return returnAux;
}


///3)
int bajaDeCliente(ArrayList* clienteList)
{
    int i, returnAux = DENIED;
    sCliente* cliente;

    if(clienteList == NULL) return returnAux;

    if(clienteList->isEmpty(clienteList) != OKP)
    {
        i = C_getIndex(clienteList);

        if(i != DENIED);
        {


            cliente = clienteList->pop(clienteList, i);

            if(cliente != NULL)
            {
                printf("el cliente:");
                C_showCliente(cliente);
                printf("ha sido eliminado\n");
                returnAux = OK;
            }
        }
    }
    else
    {
        printf("isEmpty!!!\n");
        returnAux = OK;
    }

    return returnAux;
}


///4)
int listarClientes(ArrayList* clienteList)
{
    int returnAux = DENIED;

    ArrayList* listaB;

    if(clienteList == NULL) return returnAux;

    if(clienteList->isEmpty(clienteList) != OKP)
    {
        listaB = clienteList->clone(clienteList);

        returnAux = listaB->sort(listaB, C_compareCliente,1);

        if(returnAux != DENIED)
        {

            C_showAllClientes(listaB, C_showClienteData);

        }
    }
    else
    {
        if(clienteList->isEmpty(clienteList) == OKP)
        {
            printf("isEmpty!!!\n");
            returnAux = OK;
        }
    }


    return returnAux;

}



///5)
int importarServicios(ArrayList* clienteList, ArrayList* servicioList)
{
    FILE* pFile;



    int returnAux = DENIED, idCliente, flagCliente = DENIED, flagServicio = DENIED;
    char nombre[100], apellido[100], documento[100], codigo[50], costo[50], estado[10], NRO_servicio[100];
    sCliente* cliente;

    sServicio* servicio;

    pFile = fopen("servicios.csv", "r");

    if((clienteList == NULL || servicioList == NULL) || pFile == NULL) return returnAux;

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", nombre, apellido, documento, codigo, costo,estado, NRO_servicio);




    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", nombre, apellido, documento, codigo, costo,estado, NRO_servicio);

        //printf("%s\n", nombre);

        idCliente = 1000;

        cliente = C_contructParamClientes(idCliente, nombre, apellido, atoi(documento));

        idCliente = C_validarCliente(cliente, clienteList);

        if(idCliente > OK)
        {
            servicio = S_contructParamServicio(atoi(NRO_servicio), codigo, atof(costo), atoi(estado), idCliente);

            idCliente = S_validarCliente(servicio, servicioList);

            if(idCliente == OK) flagServicio = OK;


        }
        else
        {

            if(idCliente != DENIED)
            {

                flagCliente = OK;
                flagServicio = OK;

            }
        }
        if(flagCliente == OK)
        {

            idCliente = C_getId(clienteList);

            cliente->idCliente = idCliente;

            returnAux = clienteList->add(clienteList, cliente);


        }


        if(flagServicio == OK)
        {
            if(flagCliente == OK)
            {
                servicio = S_contructParamServicio(atoi(NRO_servicio), codigo, atof(costo), atoi(estado), idCliente);
            }
            else
            {
                idCliente = C_validarCliente(cliente, clienteList);
                servicio->idCliente = idCliente;
            }

            returnAux = servicioList->add(servicioList, servicio);

        }

    }

    return returnAux;
}
