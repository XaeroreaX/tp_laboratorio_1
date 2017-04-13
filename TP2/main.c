#include "FSPersona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 20


int main()
{
    SPersona persona[T];
    int Seleccion, quit = 1;



    /*persona[0] = HarcodearS("pepe", 12, 37880456, 1);
    persona[1] = HarcodearS("juan", 24, 38840456, 0);
    persona[2] = HarcodearS("yusepe", 54, 44750446, 0);*/

    while(quit == 1)
    {
        printf("1. Agregar una persona\n2. Borrar una persona\n3. Imprimir lista ordenada por nombre\n4. Imprimir grafico de edades\n");
        scanf("%d",&Seleccion);
        switch(Seleccion)
        {
            case 1:
                printf("falta programar\n");
                break;
            case 2:
                printf("falta programar\n");
                break;
            case 3:
                persona[T] = ordenarS(T, persona);
                mostraArrayS(T, persona);
                break;
            case 4:
                mostrarBarraEdades(T, persona);
                break;
            default:
                break;
        }
    }

    return 0;
}
