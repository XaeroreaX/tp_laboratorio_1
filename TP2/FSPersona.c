#include "FSPersona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SPersona HarcodearS(char nombre[20],int edad,int dni, int flag)
{
    SPersona persona;
    strcpy(persona.nombre,nombre);
    persona.edad = edad;
    persona.dni = dni;
    persona.flagEstado = flag;
    return persona;
}

void mostraArrayS(int tam, SPersona persona[tam])
{
    int i;
    char estado[10];
    //char prueba[20] = "martin";
    for(i = 0; i < tam; i++)
    {
        if(persona[i].flagEstado == 1)
        {
            strcpy(estado, "casado");
        }
        else
        {
            if(persona[i].flagEstado == 0)
            {
                strcpy(estado, "soltero");
            }
        }
        printf("Nombre:%s----Edad:%d----DNI:%d---Estado:%s\n",persona[i].nombre, persona[i].edad, persona[i].dni, estado);
    }
    /*i = strcmp(persona[0].nombre,prueba);
    printf("la comparacion da %d",i);*/
}

void mostrarBarraEdades(int tam, SPersona persona[tam])
{
    int i;
    int Menores18 = 0, Mayores18 = 0, Mayores35 = 0, Mayor;
    for(i = 0; i < tam; i++)
    {
        if(persona[i].edad < 18)
        {
            Menores18++;
        }
        else
        {
            if(persona[i].edad > 35)
            {
                Mayores35++;
            }
            else
            {
                Mayores18++;
            }
        }

    }
    if(Mayores18 > Menores18)
    {
        if(Mayores18 > Mayores35)
        {
            Mayor = Mayores18;
        }
        else
        {
            Mayor = Mayores35;
        }
    }
    else
    {
        Mayor = Menores18;
    }
    printf("\n\tBarra de edades contadas por *\n\n");
    for(i = Mayor; i > 0; i--)
    {
         if(i == Menores18)
        {
            printf("\t\t*");
            Menores18--;
        }
        else
        {
            printf("\t\t ");
        }

        if(i == Mayores18)
        {
            printf("\t*");
            Mayores18--;
        }
        else
        {
            printf("\t ");
        }

        if(i == Mayores35)
        {
            printf("\t*");
            Mayores35--;
        }
        else
        {
            printf("\t ");
        }

        printf("\n");
    }
    printf("\t       <18    19-35    >35");

}

SPersona ordenarS(int tam, SPersona persona[tam])
{
    SPersona Aux;
    int i, j;
    for(i = 0; i < tam-1; i++)
    {
        for(j = i+1; j < tam; j++)
        {
            if(strcmp(persona[j].nombre, persona[i].nombre) == -1)
            {
                Aux = persona[i];
                persona[i] = persona[j];
                persona[j] = Aux;
            }
        }
    }

    return persona[tam];
}


