#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "SSong.h"
#include "cascara.h"
#define DENIED -1
#define OK 0
#define OKP 1

int main()
{

    ArrayList* playList = al_newArrayList();

    //playList=Song_Harcodear();

    char seguir='s';
    int opcion=0;


    if(Song_fileToListText("PlayList.txt", playList) == DENIED)
    {
        printf("ERROR En Song_fileToListText");

    }



    system("pause");

    do
    {
        printf("1- Agregar cancion\n");
        printf("2- Borrar cancion\n");
        printf("3- Modificar cancion\n");
        printf("4- Visitar cancion\n");
        printf("5- listar cancion\n");
        printf("6- Salir\n");
        printf("ingrese opcion");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");

                if(AltaSong(playList) == DENIED)
                    printf("ERROR en la alta\n");

                system("pause");
                break;
            case 2:
                system("cls");


                system("pause");
                break;
            case 3:
                system("cls");


                system("pause");
                break;
            case 4:
                system("cls");



                system("pause");
               break;
            case 5:
                system("cls");

                ListarPlaylist(playList);

                system("pause");
                break;
            case 6:
                seguir = 'n';
                break;
            default:
                system("cls");
                printf("ingreso mal la opcion, por favor ingrese de nuevo");
                system("pause");
                break;


        }
        system("cls");

    }while(seguir=='s');

    if(Song_listToFileText("PlayList.txt", playList) == DENIED)
    {
        printf("ERROR En Song_listToFileText");

    }

    return 0;
}
