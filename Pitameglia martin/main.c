#include <stdio.h>
#include <stdlib.h>
#define H 20
#define C 51
#define FIAT 1
#define PEUGEOT 2
#define FORD 3
#define OTRO 4
#include "Funsion.h"

int main()
{
    int i, profesor,seleccionar = 0;
    ;
    int estacionamiento[H] = {0};//profesor estacionado 0 vacio
    Sauto aut0[H];
    for(i = 0 ; i < H; i++)
        aut0[i] = bajaAuto(H, estacionamiento, aut0[i]);
    HarcodearSArray(H, aut0);
    while( seleccionar != 6 )
    {
        OrdenarSP(H, aut0);
        printf("1. cargar nuevo profesor(1 - 20)\n2. quitar profesor\n3. ingresar un auto al estacionamiento(0 - 20)\n4. egresar un auto\n5. informar\n6. Salir");
        fflush(stdin);
        scanf("%d", &seleccionar);
        switch(seleccionar)
        {
            case 1: //1. cargar nuevo profesor(1 - 20)
                i = cargarAutoA(H, aut0);
                if(i = 0)
                {
                    printf("no hay mas lugares reservados");
                }

                break;
            case 2: //2. quitar profesor


                printf("que auto desea dar de baja?:\n");
                printf("elija profesor\n");
                i = elegirP(H, aut0);
                aut0[i] = bajaAuto(H, estacionamiento, aut0[i]);

                break;
            case 3://3. ingresar un auto al estacionamiento(0 - 20)

                printf("ingrese el profesor que quiere ingresar a la cochera\n");
                i = elegirP(H, aut0);
                profesor = aut0[i].profesor;
                i = valProfesor(H, profesor, aut0);

                while(i < 0)
                {
                    printf("ingreso mal el profesor, por favor ingrese de nuevo");
                    scanf("%d", &profesor);

                    i = valProfesor(H, profesor, aut0);
                }
                estacionar(H, estacionamiento, profesor);
                break;
            case 4: //4. egresar un auto
                egresar(H, estacionamiento);
                break;
            case 5: //5. informar
                MostrarOrdenadoMP(H, aut0);
                printf("\n");
                i = MostrarE(H, estacionamiento, aut0);
                if(i == 0)
                    printf("no hay autos estacionados\n");
                i = MostrarAutosFIAT(H, aut0);
                if(i == 0)
                    printf("no hay profesores con la marca de autos FIAT");
                i = MostrarEgresados(H, estacionamiento, aut0);
                if(i == 0)
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
