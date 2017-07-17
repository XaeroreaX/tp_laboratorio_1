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

    userList = al_newArrayList();
    movieList = al_newArrayList();
    fileToMovieList(movieList);


    if(harcodearSUser(userList) == DENEID) printf("ERROR en la funsion harcodearSUser");

    // aqui pide loguearse
    logeado = login(userList);

    //printf("%s\n", logeado->nickName);

    if(logeado != NULL)
    {

        if(menuAdministrador(movieList) == DENEID) printf("ERROR en la funsion menuAdministrador\n");

    }

    return 0;
}
