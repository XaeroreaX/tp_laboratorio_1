#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ArrayList.h"
#define OK 0
#define DENEID -1



int main()
{
    char seguir='s';
    int opcion=0;

    SUser* logeado;

    ArrayList* movieList;
    ArrayList* userList;
    ArrayList* rankList;

    userList = al_newArrayList();
    movieList = al_newArrayList();
    rankList = al_newArrayList();



    fileToMovieList(movieList);
    fileToUserList(userList);
    fileToRankList(rankList);


    if(harcodearAdmin(userList) == DENEID) printf("ERROR en la funsion harcodearAdmin");


    do
    {
        printf("1- ingresar usuario\n");
        printf("2- registrarse\n");
        printf("3- Salir\n");

        scanf("%d", &opcion);
        system("cls");
        switch(opcion)
        {
            case 1:
                // aqui pide loguearse
                logeado = login(userList);

                //printf("%s\n", logeado->nickName);

                if(logeado != NULL)
                {

                    if(logeado->id == 1)
                    {
                        if(menuAdministrador(movieList, rankList) == DENEID) printf("ERROR en la funsion menuAdministrador\n");
                    }
                    else
                    {
                        if(menuCliente(movieList, logeado, rankList) == DENEID) printf("ERROR en la funsion menuAdministrador\n");
                    }

                }
                break;
            case 2:
                if(signUp(userList) == DENEID) printf("ERROR en la funsion signUp");
                break;
            case 3:
                seguir = 'n';
                break;
        }
    }while(seguir == 's');

    movieListToFile(movieList);
    userListToFile(userList);
    rankListToFile(rankList);

    return 0;
}
