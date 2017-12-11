#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "fCientes.h"




sCliente* contructParamClientes(int id, char nombre[], char apellido[], int documento)
{
    sCliente* cliente;

    cliente =(sCliente*) malloc(sizeof(sCliente));

    if(cliente != NULL)
    {
        cliente->idCliente = id;

        cliente->nombre = dinamicCharacter(nombre);
        cliente->apellido = dinamicCharacter(apellido);

        cliente->documento = documento;

    }

    return cliente;
}


sCliente* cargarCliente(int id)
{
    sCliente* cliente;

    char nombre[100];
    char apellido[100];
    int documento;
    printf("ingrese un nombre:");
    cargarCaracter(100, nombre);

    printf("ingrese el apellido:");
    cargarCaracter(100, apellido);

    printf("ingrese el documneto");
    scanf("%d",&documento);

    cliente = contructParamClientes(id,nombre, apellido, documento);

    return cliente;
}



void showAllClientes(ArrayList* clienteList, void (*funcion)(sCliente*))
{
    int i;

    sCliente* cliente;

    for(i = 0; i < standList->len(standList); i++)
    {

        stand = clienteList->get(standList, i);

        funcion(cliente);

        printf("\n");

    }

}
