#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cascara.h"
#include "fClientes.h"
#include "fVentas.h"
#include "funciones.h"

///1)
int AltaDeCliente(ArrayList* clienteList)
{
    int returnAux = DENIED, id;
    sCliente* cliente;

    if(clienteList == NULL) return returnAux;

    id = C_getId(clienteList);

    printf("ingrese los datos del cliente: \n\n");
    cliente = C_cargarCliente(id);

    returnAux = clienteList->add(clienteList, cliente);

    return returnAux;

}

///2)
int modifiCliente(ArrayList* clienteList)
{
    int i, returnAux = DENIED;
    sCliente* cliente;

    if(clienteList == NULL) return returnAux;

    if(clienteList->isEmpty(clienteList) != OKP)
    {
        i = C_getIndex(clienteList);



        if(i > DENIED)
        {
            cliente = (sCliente*) clienteList->get(clienteList, i);
            cliente = C_cargarCliente(cliente->idCliente);
            returnAux = clienteList->set(clienteList, i, cliente);
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

        cliente =(sCliente*) clienteList->pop(clienteList, i);

        if(cliente != NULL)
        {
           /* printf("el cliente:");
            C_showCliente(cliente);*/
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

    ArrayList* clienteAuxList;

    clienteAuxList = al_newArrayList();

    if(clienteList == NULL  || clienteAuxList == NULL) return returnAux;


    clienteAuxList = clienteList->clone(clienteList);

    returnAux = clienteAuxList->sort(clienteAuxList, C_compareCliente, 1);

    if(returnAux == OK)
        C_showAllClientes(clienteList, C_showCliente);

    return returnAux;

}


///5)
int realizarVenta(ArrayList* ventaList, ArrayList* clienteList)
{
    int returnAux = DENIED;
    sVentas* venta;

    if(ventaList == NULL || clienteList == NULL) return returnAux;


    printf("ingrese los datos de la venta: \n\n");
    venta = V_cargarVenta(clienteList);

    returnAux = ventaList->add(ventaList, venta);

    return returnAux;

}



///9)
int informar(ArrayList* clienteList, ArrayList* ventaList)
{
    int returnAux = DENIED;


    if(clienteList == NULL || ventaList == NULL) return returnAux;

    if(clienteList->isEmpty(clienteList) != OKP && ventaList->isEmpty(ventaList) != OKP)
    {
        printf("el producto con mayor numero de venta:\n");
        V_showProductoMaxVentas(ventaList);

        printf("el cliente con mas cantidad de productos es:\n");
        V_showClienteMaxProducto(ventaList, clienteList);

        returnAux = OK;

    }

    return returnAux;

}
