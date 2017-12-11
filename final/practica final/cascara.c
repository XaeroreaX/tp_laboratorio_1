#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "fCientes.h"
#include "fventas.h"



///1)

int AltaDeCliente(ArrayList* clienteList)
{
    int returnAux = DENIED, id;
    sCliente* cliente;

    if(clienteList == NULL) return returnAux;

    id = getId(clienteList);

    printf("ingrese los datos del cliente: \n\n");
    cliente = cargarCliente(id);

    returnAux = clienteList->add(clienteList, cliente);

    return returnAux;

}

///2)
int modificarCliente(ArrayList* clienteList)
{
    int returnAux = DENIED, i, id;
    sCliente* cliente;


    if(clienteList == NULL) return returnAux;

    if(clienteList->isEmpty(clienteList) != OKP)
    {
        i = getIndex(clienteList);

        cliente = clienteList->get(clienteList, i);

        id = cliente->idCliente;

        cliente = cargarCliente(id);

        returnAux = clienteList->set(clienteList, i, cliente);

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
        i = getIndex(clienteList);

        cliente = clienteList->pop(clienteList, i);

        if(cliente != NULL)
        {
            printf("el cliente:");
            showCliente(cliente);
            printf("ha sido eliminado\n");
            returnAux = OK;
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
    ArrayList* listaOrdenada;

    if(clienteList->isEmpty(clienteList) == OK)
    {
        listaOrdenada = clienteList->clone(clienteList);

        listaOrdenada->sort(listaOrdenada, compareCliente, 1);


        showAllClientes(listaOrdenada, showClienteData);

        returnAux = OK;
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
