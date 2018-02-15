#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "fClientes.h"
#include "fServicios.h"
#include "funciones.h"



int S_getId(ArrayList* servicioList)
{
    int flagEncontrado = DENIED,i, j,id;



    sServicio* servicio1, *servicio2;

    if(servicioList == NULL) return DENIED;


    if(servicioList->isEmpty(servicioList) == 1)
    {
        id = 25;
    }
    else
    {


        servicio1 =(sServicio*) servicioList->get(servicioList, 0);
        id = servicio1->NRO_servicio +1;


        for(i = 1; i < servicioList->len(servicioList); i++)
        {
            servicio1 =(sServicio*) servicioList->get(servicioList, i);

            if(servicio1->NRO_servicio == id)
            {
                id = servicio1->NRO_servicio +1;
            }
            else
            {

                for(j = i + 1; j < servicioList->len(servicioList); j++)
                {
                    servicio2 =(sServicio*) servicioList->get(servicioList, j);

                    if(id == servicio2->NRO_servicio) break;

                }


                if(j < servicioList->len(servicioList)) flagEncontrado = OK;

            }

            if(flagEncontrado == DENIED)
            {
                id = servicio1->NRO_servicio + 1;
            }
            else
            {
                break;
            }
        }

    }

    return id;
}



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



sServicio* S_cargarServicio(int NRO_servicio, ArrayList* clienteList)
{
    int idCliente;

    double costo;

    char codigo[100];

    sServicio* servicio;


    if(clienteList != NULL)
    {


        printf("ingrese el id del cliente:\n\n");

        idCliente = C_selectIdCliente(clienteList);

        if(idCliente > OK)
        {

            printf("ingrese el costo:");

            scanf("%f", &costo);

            printf("ingrese el codigo alfaNumerico:");

            cargarCaracter(10, codigo);

            servicio = S_contructParamServicio(NRO_servicio, codigo, costo, 1, idCliente);

        }
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


int S_validarCliente(sServicio* servicio, ArrayList* servicioList)
{
    int i, returnAux = DENIED;
    sServicio* servicioA;

    if(servicio == NULL || servicioList == NULL) return returnAux;


    if(servicioList->isEmpty(servicioList) == OKP) return OK;

    for(i = 0; i<servicioList->len(servicioList); i++)
    {
        servicioA = (sServicio*)servicioList->get(servicioList,i);

        servicio->idCliente = servicioA->idCliente;


        if(servicio->NRO_servicio == servicioA->NRO_servicio) break;



    }

    if(i < servicioList->len(servicioList)) returnAux = OK;

    printf("%d\n", returnAux);

    return returnAux;


}
