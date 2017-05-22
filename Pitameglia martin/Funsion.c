#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define H 5
#define C 51
#define OK 1
#define DENIED 0
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
    char modelo[H][C] = {"Focus","207","A3","Ford ka","siena"};
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

    switch(i)//segun la variable i mostrara diferentes opciones
    {
        case 0: // todo
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

        case 1: //solo patente y profesor
            printf("\npatente:%s---profesor:%d", aut0.patente, aut0.profesor);
            break;
        case 2: //solo profesor
            printf("profesor:%d\n", aut0.profesor);
            break;

    }

}


/**-----------------------------------------------------------------------------------------------------------------------*/ ///3)


void OrdenarSP(int tam, Sauto aut0[tam])
{

    int i, j;
    Sauto aux;

     for(i = 0; i <tam - 1; i++)
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
                if(aut0[i].marca == aut0[j].marca )
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
        for(i = 0; i < tam ; i++)
        {
            if(aut0[i].profesor != 0)
                MostrarS(1 ,aut0[i]);
        }



}



/**-----------------------------------------------------------------------------------------------------------------------*/  ///5)


void estacionar(int sTam, int tam, int estacionamiento[tam], int ListEspera[sTam], Sauto aut0[sTam])
{
    int i, j, val; //operadores de control y validacion

    val = valTodosEstacionados(tam, estacionamiento);
    if(val == DENIED) //DENIED es 0 si hay lugar en el estacionamiento OK es 1 si el estacionamiento lleno
    {

        //seleccion de estructura
        printf("ingrese el automovil que quiere ingresar a la cochera\n");
        i = elegirP(sTam, aut0); //solo devuelve la posicion del vector

        //valida si ya esta estacionado
        for(j = 0; j < tam && estacionamiento[j] != aut0[i].profesor; j++);
        while(j < tam)
        {
            printf("ese automovil ya esta estacionado en la cochera, ingrese otro\n");
            i = elegirP(sTam, aut0);
            for(j = 0; j < tam && estacionamiento[j] != aut0[i].profesor; j++);
        }
        /////////////////////////////////////////////////////////////
        // ingreso de horario de entrada y validacion
        printf("ingrese la hora en que estaciono");
        scanf("%d", &aut0[i].horaEntrada);
        while(aut0[i].horaEntrada > 23 || aut0[i].horaEntrada < 0)
        {
            printf("ingreso mal el horario de estacionamiento, por favor ingrese de nuevo");
            scanf("%d", &aut0[i].horaEntrada);

        }
        //////////////////////////////////////////////////////////////////////
        //estaciona el coche en el primer lugar que encuentre disponible
        for(j = 0; estacionamiento[j] != 0; j++);
        estacionamiento[j] = aut0[i].profesor;
        printf("ingreso en el lugar %d\n", j + 1);


    }
    else //OK
    {

        //elegimos el auto que quiere ingresar a la lista de espera
        printf("ingrese el automovil que quiere anotar a la lista de espera\n");
        i = elegirP(sTam, aut0);

        //valida si esta estacionado
        for(j = 0; j < tam && estacionamiento[j] != aut0[i].profesor; j++);
        while(j < tam)
        {
            printf("el automovil ya esta en el estacionamiento, ingrese otro\n");
            i = elegirP(sTam, aut0);
            for(j = 0; j < tam && estacionamiento[j] != aut0[i].profesor; j++);
        }

        //ingresa el automovil en la cola pero si ya esta en la cola no lo hace
        for(j = 0; ListEspera[j] != aut0[i].profesor && ListEspera[j] != 0; j++);

        ListEspera[j] = aut0[i].profesor;
        printf("el automovil %d ingreso en la lista de espera\n", ListEspera[j]);







    }
}

/**-----------------------------------------------------------------------------------------------------------------------*/  ///6)

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



/**-----------------------------------------------------------------------------------------------------------------------*/  ///7)


int cargarAutoA(int tam, Sauto aut0[tam])
{
    int i,j, flag = 0;



    for(i = 0; i < tam && aut0[i].profesor != 0; i++);

    ///valida si hay lugar reservado para hacer la alta
    if(i < tam)
    {
        //cargar campo de patente
        printf("\ningrese la patente del auto: ");
        cargarCaracter(C, aut0[i].patente);

        //cargar campo de modelo
        printf("\ningrese el modelo del auto: ");
        cargarCaracter(C, aut0[i].modelo);

        //cargar campo de marca
        printf("\ningrese la marca:\n1. FIAT\n2.PEUGEOT\n3. FORD\n4. OTRO\n");
        scanf("%d", &aut0[i].marca);
        while(aut0[i].marca <= 0 || aut0[i].marca >= 5)
        {
            printf("ingreso mal la marca, por favor ingrese de nuevo las siguientes opciones:\n");
            printf("1. FIAT\n2.PEUGEOT\n3. FORD\n4. OTRO");
            scanf("%d", &aut0[i].marca);
        }

        //cargar el numero de profesor
        printf("\ningrese el numero del profesor no existente:\n");
        for(j = 0; aut0[j].profesor != 0; j++)
        {
            MostrarS(2, aut0[j]);
        }
        scanf("%d", &aut0[i].profesor);
        for(j = 0; aut0[i].profesor != aut0[j].profesor; j++);
        while(aut0[i].profesor < 1000 || j < i)
        {
            printf("\ningreso mal el numero del profesor, por favor ingrese de nuevo");
            scanf("%d", &aut0[i].profesor);
            for(j = 0; aut0[i].profesor != aut0[j].profesor; j++);
        }
        flag = 1;
    }
    return flag;
}


/**-----------------------------------------------------------------------------------------------------------------------*/  ///8)

int egresar(int tam, int sTam, int garage[tam],int Lista[sTam], Sauto aut0[sTam])
{
    int i, j, hora;

    //fijandose si hay algien estacionado
    for(i = 0; garage[i] == 0 && i < tam; i++);

    if(i < tam)//valida
    {
        //elegir lugar
        printf("lista del estacionamiento, ingrese el lugar que desea liberar (ingrese 0 para cancelar):");
        i = elegirE(tam, garage);
        while(i > tam - 1 || i < -1)//valida el lugar
        {

            printf("\ningreso mal el lugar, por favor ingrese de nuevo\n");
            printf("lista del estacionamiento(ingrese 0 para cancelar):");
            i = elegirE(tam, garage);
        }


        if(i >= 0)//cancela si ingresa 0
        {

            //revisa la lista de espera y si no hay automoviles solo borra

            if(Lista[0] != 0)
            {


                ////////////////////////////////////////////////////////
                //busco el profesor
                for(j = 0; aut0[j].profesor != garage[i]; j++);

                //pido ingreso y valido el horario de salida
                printf("ingrese el horario de salida del automovil %d\n", aut0[j].profesor);
                scanf("%d", &aut0[j].horaSalida);


                while(aut0[j].horaSalida < 0 || aut0[j].horaSalida > 23)
                {
                    printf("ingreso mal el horario de salida del automovil %d, por favor ingrese de nuevo\n", aut0[j].profesor);
                    scanf("%d", &aut0[j].horaSalida);
                }

                //para luego asignarlo al proximo que entre
                hora = aut0[j].horaSalida;
                //calculo y muestro cuanto tiempo estuvo y cuanto debe
                calcularHorarioDeEgreso(aut0[j].horaEntrada, aut0[j].horaSalida);
                //////////////////////////////////////////////////////////////////////////////

                //pasa lo que hay en la cola
                printf("el automovil %d esta ingresando en la posicion %d\n", Lista[0], i + 1);
                garage[i] = Lista[0];


                /////////////////////////////////////////////////////////////
                // busca profesor ingreso y lo asigna a la hora que salio el anterior
                for(j = 0; garage[i] != aut0[j].profesor; j++);
                aut0[j].horaEntrada = hora;
                //////////////////////////////////////////////////////////////////////


                //pisa toda la lista
                for(i = 0; Lista[i] != 0; i++)
                    Lista[i] = Lista[i + 1];





                i = 0;
                //muestra el proximo en la lista y si no queda nadie muestra que se vacio
                if(Lista[i] == 0)
                    printf("se vacio la lista de espera\n");
                else
                    printf(" el proximo en la lista es %d\n", Lista[0]);


            }
            else//borra
            {
                ////////////////////////////////////////////////////////
                //busco el profesor
                for(j = 0; aut0[j].profesor != garage[i]; j++);

                //pido ingreso y valido el horario de salida
                printf("ingrese el horario de salida del automovil %d\n", aut0[j].profesor);
                scanf("%d", &aut0[j].horaSalida);
                while((aut0[j].horaSalida < 0 || aut0[j].horaSalida > 23) || aut0[j].horaSalida == aut0[j].horaEntrada)
                {
                    printf("ingreso mal el horario de salida del automovil %d, por favor ingrese de nuevo\n", aut0[j].profesor);
                    scanf("%d", &aut0[j].horaSalida);
                }
                //calculo y muestro cuanto tiempo estuvo y cuanto debe
                calcularHorarioDeEgreso(aut0[j].horaEntrada, aut0[j].horaSalida);
                //////////////////////////////////////////////////////////////////////////////


                printf("el automovil %d dejo el lugar %d\n", garage[i], i + 1);
                garage[i]  = 0;




            }



        }

        return 1;

    }

    return 0;//si no queda nadie en el estacionamiento
}

/**-----------------------------------------------------------------------------------------------------------------------*/ ///9)

int calcularHorarioDeEgreso(int horarioEntrada, int horarioSalida)
{
    int resultado, debe = 10, i = 1;

    if(horarioEntrada < horarioSalida)
    {
        resultado = horarioSalida - horarioEntrada;


    }
    else
    {

        resultado = 24 - horarioEntrada;

        resultado = resultado + horarioSalida;

    }
    printf("el automovil permanecio %d cantidad de horas\n", resultado);

    if(resultado > 3)
    {
        if(resultado != 4)
            i = resultado - 4;

        debe = debe * i;

        printf("se le cobrara %d peso\n", debe);
    }
    return resultado;
}



/**-----------------------------------------------------------------------------------------------------------------------*/ ///9)



int elegirE(int tam, int garage[tam])
{
    int i;
    for(i = 0; i < tam; i++)
    {
        if(garage[i] != 0)
            printf("\nlugar %d: %d\n", (i+1),garage[i]);
        else
            printf("\nlugar %d: Libre\n", (i+1));

    }
    scanf("%d", &i);

    return i - 1;


}


/**-----------------------------------------------------------------------------------------------------------------------*/ ///10)





int MostrarE(int tam, int sTam, int estacionamiento[tam],Sauto aut0[sTam])
{
    int i, j,flag = 0;

    //me fijo si hay algien estacionado
    for(i = 0; estacionamiento[i] != 0 && i < tam; i++);

    //flag para para el return
    if(i != DENIED)
        flag = OK;

    //mostraremos los datos

    printf("Lista de autos estacionados:\n\n");
    for(i = 0; i < tam; i++)
    {
        //discriminar los lugares libres(0)
        if(estacionamiento[i] > 0)
        {

            for(j = 0; estacionamiento[i] != aut0[j].profesor; j++);
            MostrarS(0, aut0[j]);

        }


    }

    return flag;

}


/**-----------------------------------------------------------------------------------------------------------------------*/  ///11)

int MostrarAutosFIAT(int tam, Sauto aut0[tam])
{
    int i, flag = 0;
    printf("Listado de autos FIAT:\n");
    for(i = 0; i < tam; i++)
    {
        if(aut0[i].marca == FIAT)
        {

            MostrarS(0, aut0[i]);
            flag = 1;
        }

    }
    return flag;
}

/**-----------------------------------------------------------------------------------------------------------------------*/  ///12)

int MostrarEgresados(int tam, int sTam, int estacionamiento[tam], Sauto aut0[sTam])
{

    int i,j,flag = 0;
    printf("lista de autos no estacionados\n");
    for(i = 0; i < sTam; i++)
    {
        for(j = 0; j < tam && estacionamiento[j] != aut0[i].profesor; j++);

        if(j == tam)
        {
            flag = 1;
            MostrarS(0, aut0[i]);
        }


    }

    return flag;
}

/**-----------------------------------------------------------------------------------------------------------------------*/  ///13)

int verificarS(int tam, Sauto aut0[tam])
{
    int i;

    for(i = 0; i < tam && aut0[i].profesor == 0; i++);
    if(i < tam)
        return 1;

    return 0;
}


/**-----------------------------------------------------------------------------------------------------------------------*/  ///14)


int elegirP(int tam, Sauto aut0[tam])
{
    int i, profesor; //operador de control y seleccion



        //imprime los autos habilitando
        for(i = 0; i < tam; i++)
        {
            if(i < tam)
            {
                if(aut0[i].profesor > 0)
                printf("--%d",aut0[i].profesor);
            }


        }
        printf("--\n");
        scanf("%d",&profesor);

        i = valProfesor(tam, profesor, aut0);
        while(i < 0)
        {
            printf("ingreso mal el automovil, por favor ingrese de nuevo");
            scanf("%d", &profesor);
            i = valProfesor(tam, profesor, aut0);
        }

        for(i = 0; profesor != aut0[i].profesor && i < tam; i++);

        return i;


    return -1;

}

/**-----------------------------------------------------------------------------------------------------------------------*/  ///15)


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



/**-----------------------------------------------------------------------------------------------------------------------*/  ///16)

int valTodosEstacionados(int tam, int estacionamiento[tam])
{

    int  i;

    for(i = 0; estacionamiento[i] > 0 && i < tam ; i++);

    if(i < tam)
        return DENIED;

    return OK;



}


/**-----------------------------------------------------------------------------------------------------------------------*/  ///17)


Sauto bajaAuto(int tam, int ListaDeEspera[tam], Sauto aut0)
{
    Sauto erased;
    int i;
    strcpy(erased.patente, "");
    strcpy(erased.modelo, "");
    erased.marca = 10;
    erased.profesor = 0;


    for(i = 0; i < tam && aut0.profesor != ListaDeEspera[i]; i++);

    if(i < tam)
        ListaDeEspera[i] = 0;

    for(;ListaDeEspera[i] != 0;i++)
    {
        ListaDeEspera[i] = ListaDeEspera[i + 1];

    }

    return erased;
}

