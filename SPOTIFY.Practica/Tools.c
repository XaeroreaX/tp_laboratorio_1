#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DENIED -1
#define OK 0
#define OKP 1



char cargarCaracter(int tam, char caracteres[])
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

    return caracteres[tam];
}


void vaciar(int size, char string[size])
{
    int i;

    for(i = 0; i < size; i++)
        string[i] = '\0';


}



void ShowTimeMin(int time)
{
    printf("%d:%d", (time / 60), (time%60));

}
