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

    //if(rankList->isEmpty(rankList) == 1) printf("esta vacio");

    //if(harcodearSUser(userList) == DENEID) printf("ERROR en la funsion harcodearSUser");

    // aqui pide loguearse
    logeado = login(userList);

    //printf("%s\n", logeado->nickName);

    if(logeado != NULL)
    {
        if(Rank(movieList, rankList) == DENEID) printf("ERROR en la funsion Rank");
        if(logeado->id == 1)
        {
            if(menuAdministrador(movieList) == DENEID) printf("ERROR en la funsion menuAdministrador\n");
        }
        else
        {
            if(menuCliente(movieList, logeado, rankList) == DENEID) printf("ERROR en la funsion menuAdministrador\n");
        }

    }

    movieListToFile(movieList);
    userListToFile(userList);
    rankListToFile(rankList);

    return 0;
}
