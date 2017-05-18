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

    for(i = 0; i < 5; i++)
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

    switch(i)
    {
        case 0:
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
            break;

        case 1:
            printf("\npatente:%s---profesor:%d", aut0.patente, aut0.profesor);
            break;
        case 2:
            printf("profesor:%d\n", aut0.profesor);
            break;

    }

}


/**-----------------------------------------------------------------------------------------------------------------------*/ ///3)


void OrdenarSP(int tam, Sauto aut0[tam])
{

    int i, j;
    Sauto aux;

     for(i = 0; i < tam - 1; i++)
    {
        for(j = i + 1; j < tam; j++)
        {

            if( (aut0[i].profesor > aut0[j].profesor && aut0[j].profesor != 0) || aut0[i].profesor == 0)
            {
                aux = aut0[i];
                aut0[i] = aut0[j];
                aut0[j] = aux;

            }

        }
    }

}

/**-----------------------------------------------------------------------------------------------------------------------*/ ///4)


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



/**-----------------------------------------------------------------------------------------------------------------------*/  ///9)


void estacionar(int tam, int estacion[tam], int profesor)
{
    int i;
    for(i = 0;estacion[i] != 0 && i < tam; i++);
    if(i < t)
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

void egresar(int tam, int garage[tam])
{
    int i;
    for(i = 0; garage[i] > 0 && i < tam; i++);

    if(i < tam)
    {
        printf("lista del estacionamiento:");
        for(i = 0; i < tam; i++)
        {
            if(garage[i] != 0)
                printf("lugar%d: %d", (i+1),garage[i]);
            else
                printf("lugar%d: Libre", (i+1));

        }
        i--;
        scanf("%d", &i);
        garage[i] = 0;

    }
}


/**-----------------------------------------------------------------------------------------------------------------------*/  ///10)

void cargarCaracter(int tam, char caracteres[tam])
{
    char buffer[1024];

    fflush(stdin);
    gets(buffer);
    while(strlen(buffer) > tam)
    {
        printf("ingreso mal la cadena de caracteres, ingrese de nuevo");
        fflush(stdin);
        gets(buffer);
    }
    strcpy(caracteres, buffer);


}



/**-----------------------------------------------------------------------------------------------------------------------*/  ///11)


int cargarAutoA(int tam, Sauto aut0[tam])
{
    int i,j, flag = 0;

    for(i = 0; i < tam && aut0[i].profesor != 0; i++);


    if(i < tam)
    {

        printf("\ningrese la patente del auto");
        cargarCaracter(C, aut0[i].patente);
        //aut0[i].patente[C] = cargarCaracter(C, aut0[i].patente);
        printf("\ningrese el modelo del auto");
        cargarCaracter(C, aut0[i].modelo);
        //aut0[i].modelo[C] = cargarCaracter(C, aut0[i].modelo);
        printf("\ningrese la marca:\n1. FIAT\n2.PEUGEOT\n3. FORD\n4. OTRO");
        scanf("%d", &aut0[i].marca);
        printf("\ningrese el numero del profesor no existente:\n");
        for(j = 0; aut0[j].profesor != 0; j++)
        {
            MostrarS(2, aut0[j]);
        }
        scanf("%d", &aut0[i].profesor);
        for(j = 0; aut0[i].profesor != aut0[j].profesor; j++);
        while(aut0[i].profesor < 1000 || j < i)
        {
            printf("\ningreso mal el numero del profesor, porfavor ingrese de nuevo");
            scanf("%d", &aut0[i].profesor);
            for(j = 0; aut0[i].profesor != aut0[j].profesor; j++);
        }
        flag = 1;
    }
    return flag;
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
    int i, vacio = 0,profesor;
    for(i = 0; i < tam; i++)
    {
        if(i != tam - 1)
        {
            if(aut0[i].profesor == 0)
            {
                vacio++;
            }
            else
                printf("--%d",aut0[i].profesor);
        }


    }
    printf("--\n");
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



/**-----------------------------------------------------------------------------------------------------------------------*/  ///12)



Sauto bajaAuto(int tam, int estacionamiento[tam], Sauto aut0)
{
    Sauto erased;
    int i;
    strcpy(erased.patente, "");
    strcpy(erased.modelo, "");
    erased.marca = 10;
    erased.profesor = 0;

    for(i = 0; i < tam && aut0.profesor != estacionamiento[i]; i++)

    if(i < tam)
        estacionamiento[i] = 0;

    return erased;
}

