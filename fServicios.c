#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
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

