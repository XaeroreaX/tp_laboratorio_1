#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "fClientes.h"
#include "fVentas.h"




sVentas* V_cargarVenta(ArrayList* clienteList)
{
    sVentas* venta;

    int idCliente;
    char codigo[100];
    float costo;
    int cantidad;

    int dia, mes, ano;

    printf("elija cliente:");

    C_getIdCliente(clienteList);


    printf("ingrese el codigo del producto:");
    cargarCaracter(100, codigo);

    printf("ingrese el costo:");
    scanf("%f", &costo);

    printf("ingrese la cantidad");
    scanf("%d",&cantidad);

    printf("ingrese el dia");
    scanf("%d",&dia);

    printf("ingrese el mes");
    scanf("%d",&mes);

    printf("ingrese el año");
    scanf("%d",&ano);

    venta = V_contructParamVenta(idCliente, codigo, costo, cantidad, dia, mes, ano);

    return venta;
}


sVentas* V_contructParamVenta(int id, char codigo[100], float costo, int cantidad, int dia, int mes, int ano)
{
    sVentas* venta;

    venta =(sVentas*) malloc(sizeof(sVentas));

    if(venta != NULL)
    {
        venta->idCliente = id;

        strcpy(venta->codigo, codigo);

        venta->costo = costo;

        venta->cantidad = cantidad;

        venta->dia = dia;

        venta->mes = mes;

        venta->ano = ano;
    }

    return venta;
}


void V_showClienteMaxProducto(ArrayList* ventaList, ArrayList* clienteList)
{
    int i, j, cont = 0, max, flag = DENIED;

    sCliente* cliente;
    sVentas* venta;

    for(i = 0; i < clienteList->len(ventaList); i++)
    {
        cliente = (sCliente*) clienteList->get(clienteList, i);


        for(j = 0; j < ventaList->len(ventaList); j++)
        {
            venta = (sVentas*) ventaList->get(ventaList, j);

            if(venta->idCliente == cliente->idCliente) cont++;
        }

        if(flag == DENIED || max < cont)
        {
            max = cont;
            flag = OK;
        }

        cont = 0;
    }


    for(i = 0; i < clienteList->len(ventaList); i++)
    {
        cliente = (sCliente*) clienteList->get(clienteList, i);


        for(j = 0 ; j < ventaList->len(ventaList); j++)
        {
            venta = (sVentas*) ventaList->get(ventaList, j);

            if(venta->idCliente == cliente->idCliente) cont++;
        }

        if(cont == max) C_showCliente(cliente);

        cont = 0;
    }


}


void V_showProductoMaxVentas(ArrayList* ventaList)
{
    int i, j, cont = 0, max, flag = DENIED;

    sVentas* venta, *ventaB;

    for(i = 0; i < ventaList->len(ventaList); i++)
    {
        venta = (sVentas*) ventaList->get(ventaList, i);


        for(j = i; j < ventaList->len(ventaList); j++)
        {
            ventaB = (sVentas*) ventaList->get(ventaList, j);

            if(strcmp(ventaB->codigo, venta->codigo) == 0) cont += ventaB->cantidad;
        }

        if(flag == DENIED || max < cont)
        {
            max = cont;
            flag = OK;
        }

        cont = 0;
    }


    for(i = 0; i < ventaList->len(ventaList); i++)
    {
        venta = (sVentas*) ventaList->get(ventaList, i);


        for(j = i ; j < ventaList->len(ventaList); j++)
        {
            ventaB = (sVentas*) ventaList->get(ventaList, j);

            if(strcmp(ventaB->codigo, venta->codigo) == 0) cont += ventaB->cantidad;
        }

        if(cont == max) printf("\t\t%s\n", venta->codigo);

        cont = 0;
    }


}

/**----------------------------------------------------ARCHIVOS-------------------------------------------------------------------------*/


int V_fileToListText(ArrayList* ventaList)
{
    FILE* pFile;

    int returnAux = DENIED;
    char idCliente[15], codigo[100], costo[100], cantidad[50], dia[50], mes[50], ano[50];
    sVentas* venta;

    pFile = fopen("ventas.txt", "r");

    if(ventaList == NULL || pFile == NULL) return returnAux;

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idCliente, codigo, costo, cantidad, dia);

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^/],%[^/],%[^\n]\n", idCliente, codigo, costo, cantidad, dia, mes, ano);


        venta = V_contructParamVenta(atoi(idCliente), codigo, atof(costo), atoi(cantidad), atoi(dia), atoi(mes), atoi(ano));

        //printf("%s", venta->codigo);


        returnAux = ventaList->add(ventaList, venta);
    }

    return returnAux;
}




/**-----------------------------------------------------------------------------------------------------------------------------*/


