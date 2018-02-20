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



    int returnAux = DENIED, idCliente, flagCliente = DENIED, flagServicio = DENIED,i;
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

            idCliente = S_validarServicio(servicio, servicioList);

            if(idCliente == OK) flagServicio = OK;


        }
        else
        {



            flagCliente = OK;
            flagServicio = OK;


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

                //printf("idCliente:%d\n", idCliente);

                servicio->idCliente = idCliente;
            }

            returnAux = servicioList->add(servicioList, servicio);

        }

            /*for(i = 0; i < servicioList->len(servicioList); i++)
            {
                servicio = (sServicio*) servicioList->get(servicioList, i);

                if(idCliente == servicio->idCliente)
                {
                    servicio->estado = 1;
                    servicioList->set(servicioList, servicio);
                }

            }*/

        flagCliente = DENIED;
        flagServicio = DENIED;
    }

    return returnAux;
}

///6)
int ingresarServicioTecnico(ArrayList* servicioList, ArrayList* clienteList)
{
    int returnAux = DENIED, NRO_servicio;

    sServicio* servicio;

    NRO_servicio = S_getId(servicioList);

    servicio = S_cargarServicio(NRO_servicio, clienteList);

    if(servicio != NULL)
    {
        returnAux = servicioList->add(servicioList, servicio);
    }

    return returnAux;

}

///7)
int finalizarServicioTecnico(ArrayList* servicioList, ArrayList* clienteList)
{
    int i, returnAux = DENIED, NRO_servicio;
    sServicio* servicio;

    if(servicioList == NULL || clienteList == NULL) return returnAux;

    returnAux = OK;
    NRO_servicio = S_getNRO_servicio(servicioList, clienteList);

    if(NRO_servicio > OK)
    {
        for(i = 0; i < servicioList->len(servicioList); i++)
        {
            servicio = (sServicio*) servicioList->get(servicioList, i);

            if(servicio->NRO_servicio == NRO_servicio && servicio->estado == 1) break;
        }
        if(i < servicioList->len(servicioList))
        {
            printf("costo:%1.2f", servicio->costo);

            servicio->estado = OK;

        }
        else
        {
            printf("seleccion incorrecta");
        }

    }

    return returnAux;
}


///8)
int exportarCSV(ArrayList* servicioList, ArrayList* clienteList)
{
    int i, returnAux = DENIED;

    char name[200];
    sCliente* cliente;

    sServicio* servicio;


    if(servicioList == NULL || clienteList == NULL) return returnAux;

    returnAux = OK;

    if(clienteList->isEmpty(clienteList) == OKP) return returnAux;

    cliente = C_selectCliente(clienteList);

    while(cliente == NULL)
    {
        printf("el id que selecciono no es valido, porfavor ingrese otro");
        cliente = C_selectCliente(clienteList);
    }

    for(i = 0; i < servicioList->len(servicioList); i++)
    {

        servicio = (sServicio*) servicioList->get(servicioList, i);

        if(servicio->idCliente == cliente->idCliente)
        {
            strcpy(name, cliente->nombre);
            strcat(name, " ");
            strcat(name, cliente->apellido);

            S_exportarServiciosCliente(name, servicio->idCliente, servicioList);



        }


    }

    returnAux = OKP;

    return returnAux;

}



///9)
int imprimirProducto(ArrayList* servicioList, ArrayList* clienteList)
{
    int returnAux = DENIED;

    ArrayList* auxList;

    if(clienteList == NULL) return returnAux;

    auxList = al_newArrayList();

    auxList = servicioList->clone(servicioList);

    returnAux = auxList->sort(auxList, S_compareProductos, 1);

    if(returnAux != DENIED)
        S_showServiciosFinalizados(servicioList,clienteList);

    return returnAux;
}


///10)
int informar(ArrayList* servicioList, ArrayList* clienteList)
{

    int returnAux = DENIED;

    printf("el producto con mayor numeros de servicios pendientes son:\n");
    S_showProducto(servicioList);

    printf("\n\nel cliente con mayor numeros de servicios pendiente son:\n");
    S_showClienteMayor(servicioList, clienteList, 1);

    printf("\n\nel cliente con mayor numeros de servicios finalizados son:\n");
    S_showClienteMayor(servicioList, clienteList, 0);

    return returnAux;

}
