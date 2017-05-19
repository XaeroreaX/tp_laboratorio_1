#include <stdio.h>
#include <stdlib.h>
#define H 5
#define C 51
#define FIAT 1
#define PEUGEOT 2
#define FORD 3
#define OTRO 4
#include "Funsion.h"

int main()
{
    int i , j, todos ,seleccionar = 0, val = 0;
    int estacionamiento[H] = {0};//profesor estacionado 0 vacio
    Sauto aut0[H];


    for(i = 0 ; i < H; i++)
        aut0[i] = bajaAuto(H, estacionamiento, aut0[i]);

    HarcodearSArray(H, aut0);
    while( seleccionar != 6 )
    {
        OrdenarSP(H, aut0);
        printf("1. cargar nuevo profesor(1 - %d)\n2. quitar profesor\n3. ingresar un auto al estacionamiento(1 - %d)\n4. egresar un auto\n5. informar\n6. Salir", H, H);
        fflush(stdin);
        scanf("%d", &seleccionar);
        switch(seleccionar)
        {
            case 1: //1. cargar nuevo profesor(1 - H)
                val = cargarAutoA(H, aut0);
                if(val == 0)
                {
                    printf("no hay mas lugares reservados\n");
                }

                break;
            case 2: //2. quitar profesor


                printf("que auto desea dar de baja?:\n");
                printf("elija profesor\n");
                val = elegirP(H, aut0);
                if(val > -1)
                    aut0[val] = bajaAuto(H, estacionamiento, aut0[val]);
                else
                    printf("no hay profesor registrado");
                break;


            case 3://3. ingresar un auto al estacionamiento(0 - H)
                val = 0;
                for(todos = 0; aut0[todos].profesor != 0 && todos < H ; todos++);


                for(i = 0; i < todos; i++)
                {
                    for(j = 0; j < H; j++)
                    {
                        if(aut0[i].profesor == estacionamiento[j])
                            val++;


                    }
                }
                if(val < todos)
                    estacionar(H, estacionamiento, aut0);

                break;
            case 4: //4. egresar un auto
                egresar(H, estacionamiento);
                break;
            case 5: //5. informar


                val = MostrarOrdenadoMP(H, aut0);
                if(val == 0)
                    printf("no hay profesor registrado");
                printf("\n\n-----------------------------------------------\n");
                system("pause");


                val = MostrarE(H, estacionamiento, aut0);
                if(val == 0)
                    printf("no hay autos estacionados\n");
                printf("\n\n-----------------------------------------------\n");
                system("pause");



                val = MostrarAutosFIAT(H, aut0);
                if(val == 0)
                    printf("no hay profesores con la marca de autos FIAT");
                printf("\n\n-----------------------------------------------\n");
                system("pause");



                val = MostrarEgresados(H, estacionamiento, aut0);
                if(val == 0)
                    printf("todos los profesores estacionaron");


                break;
            case 6: //6. salir
                break;
            default:
                printf("ingreso mal en el campo de seleccion\n");
                break;
        }
        system("pause");
        system("cls");
    }


    //aut0[2]=cargarAuto(aut0[2]);


    return 0;
}
