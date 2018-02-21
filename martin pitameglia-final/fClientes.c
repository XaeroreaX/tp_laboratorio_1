#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "fClientes.h"



int C_getId(ArrayList* clienteList)
{
    int flagEncontrado = DENIED,i, j,id;



    sCliente* cliente1, *cliente2;

    if(clienteList == NULL) return DENIED;


    if(clienteList->isEmpty(clienteList) == 1)
    {
        id = 1;
    }
    else
    {


        cliente1 =(sCliente*) clienteList->get(clienteList, 0);
        id = cliente1->idCliente +1;


        for(i = 1; i < clienteList->len(clienteList); i++)
        {
            cliente1 =(sCliente*) clienteList->get(clienteList, i);

            if(cliente1->idCliente == id)
            {
                id = cliente1->idCliente +1;
            }
            else
            {

                for(j = i + 1; j < clienteList->len(clienteList); j++)
                {
                    cliente2 =(sCliente*) clienteList->get(clienteList, j);

                    if(id == cliente2->idCliente) break;

                }


                if(j < clienteList->len(clienteList)) flagEncontrado = OK;

            }

            if(flagEncontrado == DENIED)
            {
                id = cliente1->idCliente + 1;
            }
            else
            {
                break;
            }
        }

    }

    return id;
}


sCliente* C_cargarCliente(int id)
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

    cliente = C_contructParamClientes(id,nombre, apellido, documento);

    return cliente;
}


sCliente* C_contructParamClientes(int id, char nombre[], char apellido[], int documento)
{
    sCliente* cliente;

    cliente =(sCliente*) malloc(sizeof(sCliente));

    if(cliente != NULL)
    {
        cliente->idCliente = id;

        strcpy(cliente->nombre, nombre);

        strcpy(cliente->apellido, apellido);

        cliente->dni = documento;

        cliente->estado = 1;
    }

    return cliente;
}



int C_getIndex(ArrayList* clientetList)
{
    int i = DENIED, id;
    sCliente* cliente;

    if(clientetList == NULL) return i;

    C_showAllClientes(clientetList, C_showClienteId);

    printf("ingrese el id:");
    scanf("%d", &id);


    for(i = 0; i < clientetList->len(clientetList);i++)
    {
        cliente = (sCliente*) clientetList->get(clientetList, i);

        if(cliente->idCliente == id) break;

    }

    //printf("i = %d", i);

    //i++;
    return i;
}



int C_getIdCliente(ArrayList* clientetList)
{
    int i = DENIED, id;
    sCliente* cliente;

    if(clientetList == NULL) return i;

    C_showAllClientes(clientetList, C_showClienteId);

    printf("ingrese el id:");
    scanf("%d", &id);


    for(i = 0; i < clientetList->len(clientetList);i++)
    {
        cliente = (sCliente*) clientetList->get(clientetList, i);

        if(cliente->idCliente == id) break;

    }

    //printf("i = %d", i);

    //i++;
    return id;
}



///**-------------------------------------shows------------------------------------------------*/

void C_showAllClientes(ArrayList* clienteList, void (*funcion)(sCliente*))
{
    int i;

    sCliente* cliente;



    for(i = 0; i < clienteList->len(clienteList); i++)
    {

        cliente = clienteList->get(clienteList, i);

        funcion(cliente);

        printf("\n");

    }

}

void C_showCliente(sCliente* cliente)
{
    if(cliente == NULL) printf("ERROR");

    if(cliente != NULL)
        printf("%s %s", cliente->nombre, cliente->apellido);
}

void C_showClienteData(sCliente* cliente)
{
    printf("----------------------------------------------------------------------\n\n");
    printf("cliente: %s %s\n\n", cliente->apellido, cliente->nombre);
    printf("DNI:%d\n\n", cliente->dni);

}

void C_showClienteId(sCliente* cliente)
{
    printf("%d)%s %s", cliente->idCliente, cliente->nombre, cliente->apellido);
}



///**-----------------------------------------------------------------------------------------*/





/**----------------------------------------------------ARCHIVOS-------------------------------------------------------------------------*/


int C_fileToListText(ArrayList* clienteList)
{
    FILE* pFile;

    int returnAux = DENIED, idCliente;
    char nombre[100], apellido[100], dni[50];
    sCliente* cliente;

    pFile = fopen("clientes.txt", "r");

    if(clienteList == NULL || pFile == NULL) return returnAux;

    fscanf(pFile, "%[^,],%[^,],%[^\n]\n", nombre, apellido, dni);

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^\n]\n", nombre, apellido, dni);

        idCliente = C_getId(clienteList);

        cliente = C_contructParamClientes(idCliente, nombre, apellido, atoi(dni));

        returnAux = clienteList->add(clienteList, cliente);
    }

    return returnAux;
}




/**-----------------------------------------------------------------------------------------------------------------------------*/




int C_compareCliente(void* clienteA, void* clienteB)
{

    if(strcmp(((sCliente*)clienteA)->apellido, ((sCliente*)clienteB)->apellido ) < 0)
    {
        return -1;
    }

    if(strcmp(((sCliente*)clienteA)->apellido, ((sCliente*)clienteB)->apellido ) > 0)
    {
        return 1;
    }


    if(strcmp(((sCliente*)clienteA)->apellido, ((sCliente*)clienteB)->apellido ) == 0)
    {

        if(strcmp(((sCliente*)clienteA)->nombre, ((sCliente*)clienteB)->nombre ) < 0)
        {
            return -1;
        }

        if(strcmp(((sCliente*)clienteA)->nombre, ((sCliente*)clienteB)->nombre ) > 0)
        {
            return 1;
        }

    }

    return 0;
}
