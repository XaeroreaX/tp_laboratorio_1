#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define H 5
#define C 51
#define FIAT 1
#define PEUGEOT 2
#define FORD 3
#define OTRO 4
#include "Funsion.h"



/**-----------------------------------------------------------------------------------------------------------------------*/ ///1)

void HarcodearSArray(int tam, Sauto aut0[H])
{

    int i = 0;
    char patente[H][C] = {"jgh-456","pit-785","Pae-159","yTe-762","poe-789"};
    char modelo[H][C] = {"fiat 600","pepito","gigabite","german","nahue"};
    int marca[H] = {FORD, PEUGEOT, OTRO, FORD, FIAT};//(1.fiat 2.peugeot 3.ford 4.otros)
    int profesor[H] = {1001, 1002, 1003, 1004, 1005};

    for(i = 0; i < tam; i++)
    {
        strcpy(aut0[i].patente, patente[i]);
        strcpy(aut0[i].modelo, modelo[i]);
        aut0[i].marca = marca[i];
        aut0[i].profesor = profesor[i];

    }
}

/**-----------------------------------------------------------------------------------------------------------------------*/ ///2)


void MostrarS(int i,Sauto aut0)
{
    if(i == 0)
    {

        if(aut0.profesor != 0)
        {
            printf("\npatente:%s----modelo:%s----profesor:%d", aut0.patente, aut0.modelo, aut0.profesor);
            printf("-------------marca:");
            switch(aut0.marca)
            {
                case FIAT:
                    printf("FIAT\n");
                    break;
                case PEUGEOT:
                    printf("PEUGEOT\n");
                    break;
                case FORD:
                    printf("FORD\n");
                    break;
                case OTRO:
                    printf("OTRO\n");
                    break;


            }

        }
    }
    else
    {
        printf("\npatente:%s---profesor:%d", aut0.patente, aut0.profesor);
    }
}

/**-----------------------------------------------------------------------------------------------------------------------*/ ///3)

void MostrarOrdenadoMP(int tam, Sauto Original[tam])
{
    Sauto aut0[tam], aux;
    int i, j;
    for(i = 0; i < tam; i++)
    {
        aut0[i] = Original[i];
    }

    for(i = 0; i < tam - 1; i++)
    {
        for(j = i + 1; j < tam; j++)
        {
            if(aut0[i].marca > aut0[j].marca)
            {
                aux = aut0[i];
                aut0[i] = aut0[j];
                aut0[j] = aux;

            }
            else
            {
                if(aut0[i].marca == aut0[j].marca)
                {
                    if(strcmp(aut0[i].patente, aut0[j].patente) == 1)
                    {
                        aux = aut0[i];
                        aut0[i] = aut0[j];
                        aut0[j] = aux;
                    }
                }
            }

        }

    }


    printf("listado de profesores habilitado estacionar");
    for(i = 0; i < H; i++)
    {
        MostrarS(1 ,aut0[i]);
    }

}

/**-----------------------------------------------------------------------------------------------------------------------*/ ///4)


int MostrarE(int tam, int estacionar[tam],Sauto aut0[tam])
{
    int i, j,flag = 0;
    for(i = 0; flag != 1 && i < tam; i++)
    {
        for(j = 0;estacionar[i] != aut0[j].profesor && j < tam; j++);
        if(j < tam)
        {
            flag = 1;
        }


    }
    if(flag == 1)
    {
        printf("los autos estacionados son:\n");
        for(i = 0; i < tam; i++)
        {
            for(j = 0;estacionar[i] != aut0[j].profesor && j < tam; j++);
            if(j < tam)
            {
                printf("\t");
                MostrarS(0, aut0[j]);

            }
        }


    }
    return flag;

}
/**-----------------------------------------------------------------------------------------------------------------------*/  ///5)

int MostrarAutosFIAT(int tam, Sauto aut0[tam])
{
    int i, flag = 0;

    for(i = 0; i < tam; i++)
    {
        if(aut0[i].marca == FIAT)
        {
            printf("Listado de autos FIAT:\n");
            MostrarS(0, aut0[i]);
            flag = 1;
        }

    }
    return flag;
}

/**-----------------------------------------------------------------------------------------------------------------------*/  ///6)

int MostrarEgresados(int tam, int estacionamiento[tam], Sauto aut0[tam])
{

    int i,j,flag = 0;
    printf("lista de autos no estacionados\n");
    for(i = 0; i < tam; i++)
    {
        j = 0;
        while(j < tam && estacionamiento[j] != aut0[i].profesor)
            j++;

        if(j == tam)
        {
            flag = 1;
            MostrarS(0, aut0[i]);
        }


    }

    return flag;
}




/**-----------------------------------------------------------------------------------------------------------------------*/  ///7)


int elegirP(int tam, Sauto aut0[tam])
{
    int i, profesor;
    for(i = 0; i < tam; i++)
    {
        if(i != tam - 1)
            printf("%d--",aut0[i].profesor);
        else
            printf("%d\n", aut0[i].profesor);
    }
    scanf("%d",&profesor);
    i = valProfesor(tam, profesor, aut0);
    while(i < 0)
    {
        printf("ingreso mal el profesor, por favor ingrese de nuevo");
        scanf("%d", &profesor);
        i = valProfesor(tam, profesor, aut0);
    }

    for(i = 0; profesor != aut0[i].profesor && i < tam; i++);
    return i;
}

/**-----------------------------------------------------------------------------------------------------------------------*/  ///8)


int valProfesor(int tam,int profesor, Sauto aut0[tam])
{
    int i;
    for(i = 0; aut0[i].profesor != profesor && i < tam; i++);
    if(i < tam)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

/**-----------------------------------------------------------------------------------------------------------------------*/  ///9)


int estacionar(int estacion[H], int profesor)
{
    int i;
    for(i = 0;estacion[i] != 0 && i < H; i++);
    if(i < H)
    {
        estacion[i] = profesor;
        printf("ingreso en el lugar %d", i + 1);
    }
    else
    {
        printf("no se encontro lugar de estacionamiento");
    }
}




/**-----------------------------------------------------------------------------------------------------------------------*/  ///10)

char cargarCaracter(int tam, char caracteres[tam])
{
    char buffer[1024];

    gets(buffer);
    while(strlen(buffer) > tam)
    {
        printf("ingreso mal la cadena de caracteres, ingrese de nuevo");
        gets(buffer);
    }
    strcpy(caracteres, buffer);

    return caracteres;
}

/**-----------------------------------------------------------------------------------------------------------------------*/  ///11)


Sauto cargarAuto(Sauto aut0)
{



        printf("\ningrese la patente del auto");
        aut0.patente[C] = cargarCaracter(C, aut0.patente);
        printf("\ningrese el modelo del auto");
        aut0.modelo[C] = cargarCaracter(C, aut0.modelo);
        printf("\ningrese la marca:\n1. FIAT\n2.PEUGEOT\n3. FORD\n4. OTRO");
        scanf("%d", &aut0.marca);
        printf("\ningrese el numero del profesor");
        scanf("%d", &aut0.profesor);
        while(aut0.profesor < 1000)
        {
            printf("\ningreso mal el numero del profesor, porfavor ingrese de nuevo");
            scanf("%d", &aut0.profesor);
        }
        return aut0;
}


/**-----------------------------------------------------------------------------------------------------------------------*/  ///12)



Sauto bajaAuto()
{
    Sauto aut0;
    strcpy(aut0.patente, "");
    strcpy(aut0.modelo, "");
    aut0.marca = 10;
    aut0.profesor = 0;

    return aut0;
}
