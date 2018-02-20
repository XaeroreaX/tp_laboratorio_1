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


int S_getNRO_servicio(ArrayList* servicioList, ArrayList* clienteList)
{
    int i, NRO_servicio, returnAux = DENIED;

    sServicio* servicio;

    if(servicioList == NULL || clienteList == NULL) return returnAux;


    returnAux = OK;

    printf("ingrese el NRO de servicio que quiera finalizar");

    S_showAllSevicio(servicioList, clienteList);


    scanf("%d", &NRO_servicio);

    for(i = 0; i < servicioList->len(servicioList); i++)
    {
        servicio =(sServicio*) servicioList->get(servicioList, i);

        if(servicio->NRO_servicio == NRO_servicio || servicio->estado == 1) break;
    }

    if(i < servicioList->len(servicioList)) returnAux = NRO_servicio;


    return returnAux;

}



/**------------------------------------shows-------------------------------------------*/

void S_showAllSevicio(ArrayList* servicioList, ArrayList* clienteList)
{
    int i, j;

    sCliente* cliente;
    sServicio* servicio;


    for(i = 0; i < clienteList->len(clienteList); i++)
    {

        cliente =(sCliente*) clienteList->get(clienteList, i);

        C_showClienteData(cliente);

        printf("servicios:\n");

        printf("\t\tNRO_servicio           codigo       costo\n\n");
        for(j = 0; j < servicioList->len(servicioList); j++)
        {
            servicio = (sServicio*) servicioList->get(servicioList, j);
            //printf("%d --- %d\n", servicio->idCliente, cliente->idCliente);
            if(servicio->idCliente == cliente->idCliente)
            {
                if(servicio->estado == 1)
                {
                    printf("\t\t%12d%18s%12.2f\n", servicio->NRO_servicio, servicio->codigo, servicio->costo);
                }
            }


        }

        printf("----------------------------------------------------------------------\n\n");

    }


}

void S_showServiciosFinalizados(ArrayList* servicioList, ArrayList* clienteList)
{
    int i, j;

    sCliente* cliente;
    sServicio* servicio;


    printf("\t\tcliente---codigo---costo\n\n");
    for(i = 0; i < servicioList->len(servicioList); i++)
    {
        servicio = (sServicio*) servicioList->get(servicioList, i);
        if(servicio->estado == 0)
        {
            for(j = 0; j < clienteList->len(clienteList); j++)
            {
                cliente =(sCliente*) clienteList->get(clienteList, j);

                if(cliente->idCliente == servicio->idCliente)
                {
                    printf("\t\t%s %s---", cliente->nombre, cliente->apellido);
                }

            }

            printf("---%s---%1.2f\n\n", servicio->codigo, servicio->costo);

        }

    }


}


void S_showProducto(ArrayList* servicioList)
{
    sServicio* servicioA, *servicioB;

    int cont = 0, max, i, j, flag = DENIED;

    for(i = 0; i < servicioList->len(servicioList); i++)
    {

        servicioA = (sServicio*) servicioList->get(servicioList, i);

        if(servicioA->estado == 1)
        {
            for(j = 0; j < servicioList->len(servicioList); j++)
            {
                servicioB = (sServicio*) servicioList->get(servicioList, j);

                if(strcmp(servicioA->codigo, servicioB->codigo) == 0 && servicioB->estado == 1) cont++;


            }

            if(max < cont || flag == DENIED)
            {
                max = cont;
                flag = OK;

            }


            cont = 0;
        }




    }

     for(i = 0; i < servicioList->len(servicioList); i++)
    {

        servicioA = (sServicio*) servicioList->get(servicioList, i);


        if(servicioA->estado == 1)
        {

            for(j = 0; j < servicioList->len(servicioList); j++)
            {
                servicioB = (sServicio*) servicioList->get(servicioList, j);

                if(strcmp(servicioA->codigo, servicioB->codigo) == 0 && servicioB->estado == 1) cont++;


            }

            if(cont == max) printf("\t\t-%s\n", servicioA->codigo);


        }


        cont = 0;
    }

}

/**------------------------------------------------------------------------------------*/


/**------------------------------------ARCHIVOS----------------------------------------*/


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


int S_exportarServiciosCliente(char name[200], int idCliente, ArrayList* servicioList)
{
    int i, returnAux = DENIED;
    FILE* pFile;
    sServicio* servicio;

    if(servicio == NULL || servicioList == NULL) return returnAux;

    strcat(name,".csv");

    pFile = fopen(name,"w+");


    fprintf(pFile,"\t\tproducto\t\t\tcosto\n");
    for(i = 0; i < servicioList->len(servicioList); i++)
    {

        servicio = (sServicio*) servicioList->get(servicioList, i);

        if(idCliente == servicio->idCliente && servicio->estado == OK)
        {

            fprintf(pFile,"\t\t%s\t\t\t%1.2f\n", servicio->codigo, servicio->costo);
            returnAux = OK;

        }

    }
    return returnAux;
}


/**------------------------------------------------------------------------------------*/

int S_validarServicio(sServicio* servicio, ArrayList* servicioList)
{
    int i, returnAux = DENIED;
    sServicio* servicioA;

    if(servicio == NULL || servicioList == NULL) return returnAux;

    returnAux = OK;

    if(servicioList->isEmpty(servicioList) == OKP) return returnAux;

    for(i = 0; i<servicioList->len(servicioList); i++)
    {
        servicioA = (sServicio*)servicioList->get(servicioList,i);

        servicio->idCliente = servicioA->idCliente;


        if(servicio->NRO_servicio == servicioA->NRO_servicio && servicioA->estado == 1)
        {
            break;
        }


    }

    if(i < servicioList->len(servicioList)) returnAux = servicio->idCliente;

    //printf("%d\n", returnAux);

    return returnAux;


}



int S_compareProductos(void* servicioA, void* servicioB)
{

    if(strcmp(((sServicio*)servicioA)->codigo, ((sServicio*)servicioB)->codigo ) < 0)
    {
        return -1;
    }

    if(strcmp(((sServicio*)servicioA)->codigo, ((sServicio*)servicioB)->codigo ) > 0)
    {
        return 1;
    }


}
