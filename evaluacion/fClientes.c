#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "fClientes.h"
#include "funciones.h"


int C_getId(ArrayList* clienteList)
{
    int flagEncontrado = DENIED,i, j,id;



    sCliente* cliente1, *cliente2;

    if(clienteList == NULL) return DENIED;


    if(clienteList->isEmpty(clienteList) == 1)
    {
        id = 1000;
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



int C_validarCliente(sCliente* cliente, ArrayList* clienteList)
{
    int i, returnAux = DENIED;
    sCliente* clienteA;

    if(cliente == NULL || clienteList == NULL) return returnAux;

    returnAux = OK;

    if(clienteList->isEmpty(clienteList) == OKP) return returnAux;

    for(i = 0; i<clienteList->len(clienteList); i++)
    {
        clienteA = (sCliente*)clienteList->get(clienteList,i);

        cliente->idCliente = clienteA->idCliente;

        returnAux = clienteList->contains(clienteList, cliente);

        printf("%d\n", returnAux);

        if(returnAux == OKP) break;


    }

    if(returnAux == OKP) returnAux = clienteA->idCliente;


    return returnAux;


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

        cliente->documento = documento;

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

    return i;
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

void C_showCliente(sCliente* cliente){printf("%s %s", cliente->nombre, cliente->apellido);}

void C_showClienteData(sCliente* cliente)
{
    if(cliente==NULL) printf("sasa");
    else
    {
       printf("----------------------------------------------------------------------\n\n");
    printf("cliente: %s %s\n\n", cliente->apellido, cliente->nombre);
    printf("DNI:%d\n\n", cliente->documento);
    }


}

void C_showClienteId(sCliente* cliente)
{
    printf("%d)%s %s", cliente->idCliente, cliente->nombre, cliente->apellido);
}



///**-----------------------------------------------------------------------------------------*/


///**----------------------------------------ARCHIVOS-----------------------------------------*/



int C_fileToListBin(ArrayList* clienteList)
{
    FILE* file;
    int returnAux = DENIED, index, size;

    sCliente* cliente;



    file = fopen("clientes.dat", "rb");

    if(file == NULL || clienteList == NULL)
    {
        fclose(file);
        return returnAux;
    }

    fseek(file, 0 , SEEK_END);

    size = ftell(file)/sizeof(sCliente);

    rewind(file);

    for(index = 0; index<size; index++)
    {
        cliente = (sCliente*) malloc(sizeof(sCliente));

        fread(cliente, sizeof(sCliente), 1,file);


        returnAux = clienteList->add(clienteList, cliente);
        if(returnAux == DENIED) break;

    }

    fclose(file);
    return returnAux;
}




int C_ListToFileBin(ArrayList* clienteList)
{
    FILE* file;
    int returnAux = DENIED, index;

    sCliente* cliente;

    cliente = (sCliente*) malloc(sizeof(sCliente));

    file = fopen("clientes.dat", "w+b");

    if(file == NULL || clienteList == NULL)
    {
        fclose(file);
        return returnAux;
    }

    //fseek(file, 0 , SEEK_END);



    for(index = 0; index < clienteList->len(clienteList); index++)
    {
        cliente =(sCliente*) clienteList->get(clienteList, index);

        fwrite(cliente, sizeof(sCliente), 1 ,file);

        //printf("%d-%d-%s",index,len, movie->titulo);
    }



    fclose(file);
    return returnAux;
}


///**-----------------------------------------------------------------------------------------*/



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
}

