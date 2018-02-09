#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "fClientes.h"
#include "fServicios.h"
#include "funciones.h"





sServicio* S_contructParamServicio(int NRO_servicio, char codigo[], double costo, int estado, int idCliente)
{
    sServicio* servicio;

    servicio =(sServicio*) malloc(sizeof(sServicio));

    if(servicio != NULL)
    {
        servicio->NRO_servicio = NRO_servicio;

        strcpy(servicio->codigo, codigo);
        servicio->costo = costo;
        servicio->estado = estado;
        servicio->idCliente = idCliente;

    }

    return servicio;
}

/**------------------------------------ARCHIVOS-----------------------------------*/


int S_fileToListBin(ArrayList* serviciosList)
{
    FILE* file;
    int returnAux = DENIED, index, size;

    sServicio* servicio;



    file = fopen("servicios.dat", "rb");

    if(file == NULL || serviciosList == NULL)
    {
        fclose(file);
        return returnAux;
    }

    fseek(file, 0 , SEEK_END);

    size = ftell(file)/sizeof(sServicio);

    rewind(file);

    for(index = 0; index<size; index++)
    {
        servicio = (sServicio*) malloc(sizeof(sServicio));

        fread(servicio,sizeof(sServicio), 1,file);


        returnAux = serviciosList->add(serviciosList, servicio);
        if(returnAux == DENIED) break;

    }

    fclose(file);
    return returnAux;
}



int S_ListToFileBin(ArrayList* servicioList)
{
    FILE* file;
    int returnAux = DENIED, index;

    sServicio* servicio;

    servicio = (sServicio*) malloc(sizeof(sServicio));

    file = fopen("servicios.dat", "w+b");

    if(file == NULL || servicioList == NULL)
    {
        fclose(file);
        return returnAux;
    }

    //fseek(file, 0 , SEEK_END);



    for(index = 0; index < servicioList->len(servicioList); index++)
    {
        servicio =(sServicio*) servicioList->get(servicioList, index);

        fwrite(servicio, sizeof(sServicio), 1 ,file);

        //printf("%d-%d-%s",index,len, movie->titulo);
    }



    fclose(file);
    return returnAux;
}



/**
sServicio* S_cargarServicio(int nro_servicio, sCliente elCliente)
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
*/
/**
int S_validarServicio(sServicio* servicio, ArrayList* servicioList)
{
    int i, returnAux = DENIED;
    sServicio* servicioA;


    for(i = 0; i<servicioList->len(servicioList); i++)
    {
        servicioA = (sServicio*)servicioList->get(servicioList,i);

        servicio->idCliente = servicioA->idCliente;

        returnAux = servicioList->contains(servicioList, servicio);

        if(returnAux == OKP) break;


    }


    return returnAux;


}
*/
