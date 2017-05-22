#include <stdio.h>
#include <stdlib.h>
#define A 50
#define E 20
#define C 51
#define OK 1
#define DENIED 0
#include "Funsion.h"

int main()
{
    int i ,seleccionar = 0, val = 0;
    int estacionamiento[E] = {0}, ListEspera[A] = {0};//profesor estacionado 0 vacio
    Sauto aut0[A];


    for(i = 0 ; i < A; i++)
        aut0[i] = bajaAuto(A, ListEspera, aut0[i]);

    HarcodearSArray(E, aut0);
    while( seleccionar != 6 )
    {
        OrdenarSP(A, aut0);
        printf("1. Alta de automovil (maximo %d)\n2. Baja de automovil\n3. Ingreso de un automovil a la playa estacionamiento (%d lugares)\n4. Egreso de automovil\n5. Informar\n6. Salir\n\n", A, E);
        fflush(stdin);
        scanf("%d", &seleccionar);
        switch(seleccionar)
        {
            case 1: //1. cargar nuevo profesor(1 - H)
                system("cls");
                //alta y validar
                val = cargarAutoA(A, aut0);
                if(val == DENIED)
                {
                    printf("No es posible reservar mas lugares");
                }

                break;
            case 2: //2. quitar profesor
                system("cls");
                val = verificarS(A, aut0);
                if(val == OK)
                {
                    //muestra profesor
                    printf("Que auto desea dar de baja?:\n");
                    printf("Elija profesor\n");

                    // elije y valida profesor
                    val = elegirP(A, aut0);
                    //tambien valida si esta en el etacionamiento
                    for(i = 0; aut0[val].profesor != estacionamiento[i] && i < E; i++);

                    if(i == E)
                        aut0[val] = bajaAuto(A, ListEspera, aut0[val]);
                    else
                        printf("Este auto esta en el estacionamiento\n");
                }
                else
                    printf("No hay profesor registrado\n");


                break;


            case 3://3. ingresar un auto al estacionamiento(0 - H)
                system("cls");
                val = verificarS(E, aut0);
                if(val == OK)
                {
                    estacionar(A, E, estacionamiento, ListEspera, aut0);
                }
                else
                    printf("No hay profesor registrado\n");
                break;
            case 4: //4. egresar un auto
                system("cls");
                val = verificarS(E, aut0);
                if(val == OK)
                {
                    val = egresar(E, A, estacionamiento, ListEspera);
                    if(val == DENIED)
                        printf("No hay autos estacionados\n\n");
                }
                else
                    printf("No hay profesor registrado\n");
                break;
            case 5: //5. informar
                system("cls");
                val = verificarS(E, aut0);

                if(val == DENIED)
                {

                    printf("No hay profesor registrado\n");
                }
                else
                {
                    MostrarOrdenadoMP(A, aut0);
                    printf("\n\n-----------------------------------------------\n");
                    system("pause");


                    val = MostrarE(E, A, estacionamiento, aut0);
                    if(val == DENIED)
                        printf("No hay autos estacionados\n");
                    printf("\n\n-----------------------------------------------\n");
                    system("pause");



                    val = MostrarAutosFIAT(A, aut0);
                    if(val == DENIED)
                        printf("No hay profesores con la marca de autos FIAT\n");
                    printf("\n\n-----------------------------------------------\n");
                system("pause");
                MostrarEgresados(E, A, estacionamiento, aut0);

                break;
            case 6: //6. salir
                break;
            default:
                printf("Ingreso mal en el campo de seleccion\n");
                break;
            }

        }
        system("pause");
        system("cls");

    }
    //aut0[2]=cargarAuto(aut0[2]);


    return 0;
}
