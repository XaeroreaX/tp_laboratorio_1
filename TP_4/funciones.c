#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayList.h"
#define OKP 1
#define OK 0
#define DENEID -1





/**-------------------------------------------------------*////1)

/** \brief añade una pelicula a un arrayList
 *
 * \param  arraylist donde se almacena las peliculas
 * \return entero (-1) si falla al añadir una pelicula en el arraylist  (0) si añadio exitosamente la pelicula
 *
 */


int addMovieList(ArrayList* movieList)
{
    int returnAux = DENEID;
    EMovie* movie;

    if(movieList == NULL) return returnAux;

    movie = addMovie();

    if(movie != NULL)
        returnAux = movieList->add(movieList, movie);


    return returnAux;
}

/**-------------------------------------------------------*////2)

/** \brief da elegir una pelicula para borrar en el arraylist
 *
 * \param arraylist de peliculas
 * \return entero (-1) si hay un error en el remove de una pelicula (0) si remueve exitosamente
 *
 */


int removeMovieList(ArrayList* movieList)
{

    int returnAux = DENEID, index;


    if(movieList == NULL) return returnAux;

    returnAux = OK;

    index = selectMovie(movieList);

    if( index == -2) returnAux = DENEID;

    if(index >= 0) returnAux = movieList->remove(movieList, index);


    return returnAux;
}

/**-------------------------------------------------------*////3)

int setMovieList(ArrayList* movieList)
{
    int returnAux = DENEID, index;
    EMovie* movie;

    if(movieList == NULL) return returnAux;

    returnAux = OK;

    index = selectMovie(movieList);

    if( index == -2) returnAux = DENEID;

    if(index >= 0)
    {

        movie = addMovie();

        if(movie != NULL)
            returnAux = movieList->set(movieList, index, movie);
    }


    return returnAux;

}

/**-------------------------------------------------------*////4)

int generarPagina(ArrayList* movieList)
{
    int i, returnAux = DENEID;

    EMovie* movie;

    FILE* file;

    movie = (EMovie*) malloc(sizeof(EMovie));

    if(movieList == NULL || movie == NULL) return returnAux;

    if(movieList->isEmpty(movieList) == 0)
    {



        file = fopen("index.HTML", "w");

        if(file == NULL) return returnAux;


        for(i = 0; i < movieList->len(movieList); i++)
        {

            movie = (EMovie*) movieList->get(movieList, i);




            fprintf(file,"<img  src=%s alt=%s style=width:200px;hight:200px>",movie->linkImagen,movie->titulo);

                        //titulo
            fprintf(file,"<h2><a href=#>%s</a></h2>",movie->titulo);

                        //otros aspectos
            if(movie->puntaje != 0)
                fprintf(file,"<h3><li> Genero: %s</li>   <li>Puntaje: %d </li>     <li>Duracion: %d </li>               </h3>",movie->genero,movie->puntaje,movie->duracion);
            else
                fprintf(file,"<h3><li> Genero: %s</li>   <li>Puntaje: -- </li>     <li>Duracion: %d </li>               </h3>",movie->genero,movie->duracion);

            fprintf(file,"<pre>%s</pre>", movie->descripcion);


        }



        fclose(file);
        printf("pagina generada esxitosamente");


    }
    else
    {

        printf("no hay peliculas almacenadas\n");
    }

    returnAux = OK;
    return returnAux;
}



/**-------------------------------------------------------*////n)

int selectMovie(ArrayList* movieList)
{
    int i;

    EMovie* movie;

    movie = (EMovie*) malloc(sizeof(EMovie));

    if(movieList == NULL || movie == NULL) return -2;


    if(movieList->isEmpty(movieList) == 0)
    {

        printf("ingrese el indice la pelicula que quiere modificar:\n0)Cancel");

        for(i = 0; i < movieList->len(movieList); i++)
        {
            movie = (EMovie*) movieList->get(movieList, i);
            printf("\n%d)titulo:%s", (i + 1), movie->titulo);
        }

        scanf("%d", &i);

        while(i < 0 || i > movieList->len(movieList))
        {
            printf("elijio mal la pelicula que quiere modificar, por favor ingrese de nuevo\n");
            scanf("%d", &i);
        }


        i--;
    }
    else
    {

        printf("no hay peliculas almacenadas\n");
        i = DENEID;
    }


    printf("\n");

    return i;
}

/**-------------------------------------------------------*////n)

EMovie* addMovie()
{
    EMovie* movie;

    movie = (EMovie*) malloc(sizeof(EMovie));


    if(movie != NULL)
    {
        printf("\nIngrese el titulo de la pelicula:");
        cargarCaracter(50, movie->titulo);

        printf("\nIngrese el genero de la pelicula:");
        cargarCaracter(100,movie->genero);

        printf("\nIngrese el duracion de la pelicula(en minutos):");
        fflush(stdin);
        scanf("%d", &movie->duracion);
        while(movie->duracion < 3)
        {
            fflush(stdin);
            printf("\nIngreso mal el duracion de la pelicula, por favor ingrese de nuevo:");
            scanf("%d", &movie->duracion);
        }

        printf("\nIngrese la descripcion de la pelicula:");
        cargarCaracter(800, movie->descripcion);

        movie->puntaje = 0;

        printf("\nIngrese un link para la imagen de la pelicula:");
        cargarCaracter(800, movie->linkImagen);

    }

    return movie;
}

/**-------------------------------------------------------*////n)

int compareMovie(void* MovieA, void* MovieB)
{

    if(((EMovie*)MovieA)->puntaje < ((EMovie*)MovieB)->puntaje)
    {
        return 1;
    }


    if(((EMovie*)MovieA)->puntaje > ((EMovie*)MovieB)->puntaje)
    {
        return -1;
    }

    if(((EMovie*)MovieA)->puntaje == ((EMovie*)MovieB)->puntaje)
    {
        if(strcmp(((EMovie*)MovieA)->titulo, ((EMovie*)MovieB)->titulo) == 1)
        {
            return 1;
        }
        else
        {
            return -1;
        }

    }


    return 0;


}


/**-------------------------------------------------------*////n)

int menuAdministrador(ArrayList* movieList, ArrayList* rankList)
{

    char seguir='s';
    int opcion=0, returnAux = DENEID;

    if(movieList == NULL) return returnAux;

    while(seguir=='s')
        {
            printf("1- Agregar pelicula\n");
            printf("2- Borrar pelicula\n");
            printf("3- Modificar pelicula\n");
            printf("4- Generar pagina web\n");
            printf("5- Limpiar la lista de peliculas\n");
            printf("6- Salir\n");

            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    system("cls");

                    if(addMovieList(movieList) == DENEID) printf("Error en la funcion addMovieList\n");

                    system("pause");
                    break;
                case 2:
                    system("cls");
                    if(removeMovieList(movieList) == DENEID) printf("Error en la funcion removeMovieList\n");

                    system("pause");
                    break;
                case 3:
                    system("cls");

                    if(setMovieList(movieList) == DENEID) printf("Error en la funcion removeMovieList\n");

                    system("pause");
                    break;
                case 4:
                    system("cls");


                    if(generarPagina(movieList) == DENEID) printf("Error en la funcion generarPagina\n");

                    system("pause");
                   break;
                case 5:
                    system("cls");
                    if(movieList->clear(movieList) == DENEID)
                    {


                        printf("ERROR en la funsion CLEAR en movieList\n");
                    }
                    else
                    {


                        printf("el arrayList fue limpiado\n");
                    }

                    system("pause");
                    break;
                case 6:
                    seguir = 'n';
                    break;


            }
            if(Rank(movieList, rankList) == DENEID) printf("ERROR en la funsion Rank");
            if(movieList->sort(movieList, compareMovie, 1) == DENEID ) printf("ERROR en la funsion sort de arrayList de EMovie");
            system("cls");

        }
    returnAux = OK;
    return returnAux;
}



int harcodearAdmin(ArrayList* userList)
{
    int i, returnAux = DENEID, id = 1;
    char nickName[50] = {"XaeroreaX"};
    char password[50] = {"master6060"};
    SUser* user;
    SUser* aux;

    user = (SUser*) malloc(sizeof(SUser));
    aux = (SUser*) malloc(sizeof(SUser));

    if((aux == NULL || user == NULL) || userList == NULL) return returnAux;

    user->id = id;

    strcpy(user->nickName, nickName);
    strcpy(user->password, password);



    for(i = 0; i < userList->len(userList); i++)
    {
        aux = (SUser*) userList->get(userList, i);

        if(strcmp(user->nickName, aux->nickName) == 0) break;

    }



    if(i == userList->len(userList))
    {

        returnAux = userList->add(userList, user);
    }
    else returnAux = OK;


    return returnAux;
}

/**-------------------------------------------------------*////n)

SUser* login(ArrayList* userList)
{
    int i, flag = DENEID;

    char find[50];

    SUser* user;

    user = (SUser*) malloc(sizeof(SUser));

    if(user == NULL || userList == NULL) return NULL;

    if(userList->isEmpty(userList) == 1)
    {
        printf("no hay usuarios cargados en sistema");
        return NULL;
    }
    else
    {

        //bucle para loguear si falla la contraseña 3 veces devolvera NULL
        do
        {
            printf("ingrese el usuario:");
            cargarCaracter(50, find);
            for(i = 0; i < userList->len(userList); i++)
            {


                user = (SUser*) userList->get(userList, i);

                if(strcmp(user->nickName, find) == 0)
                {
                    flag = OK;
                    break;
                }


            }
            if(i == userList->len(userList))
            {

                printf("no existe ese usuario\n");

            }
            else
            {


                for(i = 0; i < 3; i++)
                {
                    printf("ingrese la contraseña:");
                    cargarCaracter(50, find);

                    if(strcmp(user->password, find) == 0) break;

                }



                if(i == 3)
                {
                    user = NULL;
                    printf("fallo en ingresar la contraseña");
                }
                else
                {
                    printf("se logueo como %s\n", user->nickName);
                }


            }
        }while(flag == DENEID);


    }
    system("pause");
    system("cls");

    return user;
}

/**-------------------------------------------------------*////n)

int signUp(ArrayList* userList)
{
    int i, returnAux = DENEID;
    SUser* user;

    user = addUser(userList);

    if(userList == NULL || user == NULL) return returnAux;


    returnAux = userList->add(userList, user);

    return returnAux;

}

/**-------------------------------------------------------*////n)

SUser* addUser(ArrayList* userList)
{
    int i;
    SUser* user;
    SUser* aux;

    user = (SUser*) malloc(sizeof(SUser));
    aux = (SUser*) malloc(sizeof(SUser));

    if(userList == NULL || (user == NULL || aux == NULL)) return user;

    printf("ingrese el nickname:");

    do{

        cargarCaracter(50, user->nickName);

        for(i = 0; i < userList->len(userList); i++)
        {
            aux = (SUser*) userList->get(userList, i);

            if(strcmp(user->nickName, aux->nickName) == 0) break;

        }
        if(i < userList->len(userList)) printf("ingreso mal el nickname por favor ingrese de nuevo:");

    }while(i < userList->len(userList));

    printf("ingrese una contraseña:");

    cargarCaracter(50,user->password);


    if(aux == 1)
    {
        user->id = 1000;
    }
    else
    {

        user->id = aux->id + 1;
    }

    return user;
}

/**-------------------------------------------------------*////n)

int validarRank(char nombre[50], SUser* user, ArrayList* rankList)
{
    int i;
    SRanking* rank;

    rank = (SRanking*) malloc(sizeof(SRanking));

    if(user == NULL || (rank == NULL || rankList == NULL)) return -2;

    for(i = 0; i < rankList->len(rankList); i++)
    {

        rank = (SRanking*) rankList->get(rankList, i);

        if(strcmp(rank->waching, nombre) == 0 && rank->id == user->id) break;


    }

    if(i == rankList->len()) i = DENEID;

    return i;

}



/**-------------------------------------------------------*////n)



int addRank(ArrayList* movieList, SUser* user, ArrayList* rankList)
{
    int index, returnAux = DENEID, puntaje;

    EMovie* movie;
    SRanking* rank;

    movie = (EMovie*) malloc(sizeof(EMovie));
    rank = (SRanking*) malloc(sizeof(SRanking));

    if(rankList == NULL || rank == NULL) return returnAux;

    if(movieList == NULL || movie == NULL) return returnAux;

    returnAux = OK;

    index = selectMovie(movieList);

    if(index == -2) returnAux DENEID;

    if(index >= 0)
    {

        do{

            printf("ingrese la calificacion:\n");
            printf("\n\t10.(obra maestra)");
            printf("\n\t9.(grandioso)");
            printf("\n\t8.(muy bueno)");
            printf("\n\t7.(bueno)");
            printf("\n\t6.(pasable)");
            printf("\n\t5.(medicre)");
            printf("\n\t4.(malo)");
            printf("\n\t3.(muy malo)");
            printf("\n\t2.(horrible)");
            printf("\n\t1.(pesimo)");
            printf("\n\tingrese calificacion:");
            scanf("%d",&puntaje);
            if(puntaje > 10 || puntaje < 1)
            {
                printf("ingreso mal la calificacion");
                system("pause");
                system("cls");
            }
        }while(puntaje > 10 || puntaje < 1);

        switch(puntaje)
        {
            case 1:
                puntaje = 10;
                break;
            case 2:
                puntaje = 20;
                break;
            case 3:
                puntaje = 30;
                break;
            case 4:
                puntaje = 40;
                break;
            case 5:
                puntaje = 50;
                break;
            case 6:
                puntaje = 60;
                break;
            case 7:
                puntaje = 70;
                break;
            case 8:
                puntaje = 80;
                break;
            case 9:
                puntaje = 90;
                break;
            case 10:
                puntaje = 100;
                break;

        }

        movie = (EMovie*) movieList->get(movieList, index);

        index = validarRank(movie->titulo, user, rankList);

        if(index == DENEID)
        {



            rank->id = user->id;

            strcpy(rank->waching, movie->titulo);

            rank->puntaje = puntaje;

            returnAux = rankList->add(rankList, rank);
        }
        else
        {
            if(index == -2)
            {
                returnAux = DENEID;
            }
            else
            {
                rank->id = user->id;

                strcpy(rank->waching, movie->titulo);

                rank->puntaje = puntaje;

                returnAux = rankList->set(rankList, index, rank);
            }
        }

    }



    return returnAux;

}

/**-------------------------------------------------------*////n)

int Rank(ArrayList* movieList, ArrayList* rankList)
{
    int i, j, returnAux = DENEID, acumPuntaje = 0, puntuadores = 0;

    EMovie* movie;
    SRanking* rank;

    rank = (SRanking*) malloc(sizeof(SRanking));
    movie = (EMovie*) malloc(sizeof(EMovie));

    if(rank == NULL || rankList == NULL) return returnAux;
    if(movie == NULL || movieList == NULL) return returnAux;



        for(i = 0; i < movieList->len(movieList); i++)
        {
            acumPuntaje = 0;
            puntuadores = 0;
            movie = (EMovie*) movieList->get(movieList, i);
            for(j = 0; j < rankList->len(rankList); j++)
            {
                rank = (SRanking*) rankList->get(rankList, j);

                if(strcmp(movie->titulo, rank->waching) == 0)
                {
                    acumPuntaje += rank->puntaje;
                    puntuadores++;
                }


            }

            if(acumPuntaje != 0)
            {
                movie->puntaje = acumPuntaje/puntuadores;
                returnAux = movieList->set(movieList, i, movie);
                //printf("%d\n", movie->puntaje);

            }
        }



    returnAux++;
    return returnAux;

}

/**-------------------------------------------------------*////n)
/*
int showUserListIndex(ArrayList* userList)
{
    int i, returnAux = DENEID;

    SUser* user;

    user = (SUser*) malloc(sizeof(SUser));

    if(userList == NULL || user == NULL) return returnAux;


    for(i = 0; i < userList->len(userList); i++)
    {
        user = (SUser*) movieList->get(userList, i);
        printf("\n%d)nickName:%s", (i + 1), user->nickName);
    }

    printf("\n");
    returnAux = i;

    return returnAux;
}*/


/**-------------------------------------------------------*////n)


int menuCliente(ArrayList* movieList, SUser* user, ArrayList* rankList)
{

    char seguir='s';
    int opcion=0, returnAux = DENEID;

    if((movieList == NULL || user == NULL) || rankList == NULL) return returnAux;

    while(seguir=='s')
        {
            printf("1- Agregar pelicula a vistos\n");
            printf("6- Salir\n");

            fflush(stdin);
            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    system("cls");

                    if(addRank(movieList, user, rankList) == DENEID) printf("Error en la funcion addMovieList\n");

                    system("pause");
                    break;
                case 2:
                    system("cls");
                    //if(removeMovieList(movieList) == DENEID) printf("Error en la funcion removeMovieList\n");

                    system("pause");
                    break;
                case 3:
                    system("cls");

                    //f(setMovieList(movieList) == DENEID) printf("Error en la funcion removeMovieList\n");

                    system("pause");
                    break;
                case 4:
                    system("cls");

                    //if(generarPagina(movieList) == DENEID) printf("Error en la funcion generarPagina\n");

                    system("pause");
                   break;
                case 5:
                    system("cls");
                    /*if(movieList->clear(movieList) == DENEID)
                    {


                        printf("ERROR en la funsion CLEAR en movieList\n");
                    }
                    else
                    {


                        printf("el arrayList fue limpiado\n");
                    }*/

                    system("pause");
                    break;
                case 6:
                    seguir = 'n';
                    break;


            }

            //if(movieList->sort(movieList, compareMovie, 1) == DENEID ) printf("ERROR en la funsion sort de arrayList de EMovie");
            //movieListToFile(movieList);
            system("cls");

        }
    returnAux = OK;
    return returnAux;
}

/**-------------------------------------------------------*////n)

//int rank(ArrayList* rankList, ArrayList*)

/**-------------------------------------------------------////n)

int charAddDinamic(char* caracter)
{
    int len, returnAux = DENEID;
    char* aux;

    caracter = (char*) malloc(sizeof(char) * 1024);

    if(caracter == NULL) return returnAux;

    fflush(stdin);
    scanf("%1023[^\n]", caracter);

    len = strlen(caracter);

    aux = (char*) realloc(caracter, sizeof(char*)* len+1);

    if(aux != NULL)
    {
        caracter = aux;
        returnAux = OK;
    }

    return returnAux;
}*/

/**-------------------------------------------------------*////n)

void cargarCaracter(int tam, char caracteres[tam])
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

}

/**-------------------------------------------------------*////n)

int fileToUserList(ArrayList* userList)
{
    FILE* file;
    int returnAux = DENEID, index, size;

    SUser* user;



    file = fopen("dataUser.dat", "rb");

    if(file == NULL || userList == NULL)
    {
        fclose(file);
        return returnAux;
    }

    fseek(file, 0 , SEEK_END);

    size = ftell(file)/sizeof(SUser);

    rewind(file);

    for(index = 0; index<size; index++)
    {
        user = (SUser*) malloc(sizeof(SUser));

        fread(user, sizeof(SUser), 1,file);

        returnAux = userList->add(userList, user);
        if(returnAux == DENEID) break;

    }

    fclose(file);
    return returnAux;
}


/**-------------------------------------------------------*////n)

int fileToRankList(ArrayList* rankList)
{
    FILE* file;
    int returnAux = DENEID, index, size;

    SRanking* rank;



    file = fopen("dataRank.dat", "rb");

    if(file == NULL || rankList == NULL)
    {
        fclose(file);
        return returnAux;
    }

    fseek(file, 0 , SEEK_END);

    size = ftell(file)/sizeof(SRanking);

    rewind(file);

    for(index = 0; index < size; index++)
    {
        rank = (SRanking*) malloc(sizeof(SRanking));

        fread(rank, sizeof(SRanking), 1,file);

        returnAux = rankList->add(rankList, rank);
        if(returnAux == DENEID) break;

    }

    fclose(file);
    return returnAux;
}


/**-------------------------------------------------------*////n)

int fileToMovieList(ArrayList* movieList)
{
    FILE* file;
    int returnAux = DENEID, index, size;

    EMovie* movie;



    file = fopen("data.dat", "rb");

    if(file == NULL || movieList == NULL)
    {
        fclose(file);
        return returnAux;
    }

    fseek(file, 0 , SEEK_END);

    size = ftell(file)/sizeof(EMovie);

    rewind(file);

    for(index = 0; index<size; index++)
    {
        movie = (EMovie*) malloc(sizeof(EMovie));

        fread(movie, sizeof(EMovie), 1,file);

        returnAux = movieList->add(movieList, movie);
        if(returnAux == DENEID) break;

    }
/*
    len = showMovieListIndex(movieList);
        if(len == DENEID) printf("Error en la funcion showMovieList");*/

    fclose(file);
    return returnAux;
}



/**-------------------------------------------------------*////n)

int userListToFile(ArrayList* userList)
{
    FILE* file;
    int returnAux = DENEID, index;

    SUser* user;

    user = (SUser*) malloc(sizeof(SUser));

    file = fopen("dataUser.dat", "w+b");

    if(file == NULL || userList == NULL)
    {
        fclose(file);
        return returnAux;
    }


    for(index = 0; index < userList->len(userList); index++)
    {
        user =(SUser*) userList->get(userList, index);

        fwrite(user, sizeof(SUser), 1 ,file);

    }



    fclose(file);
    return returnAux;
}


/**-------------------------------------------------------*////n)

int rankListToFile(ArrayList* rankList)
{
    FILE* file;
    int returnAux = DENEID, index;

    SRanking* rank;

    rank = (SRanking*) malloc(sizeof(SRanking));

    file = fopen("dataRank.dat", "w+b");

    if(file == NULL || rankList == NULL)
    {
        fclose(file);
        return returnAux;
    }


    for(index = 0; index < rankList->len(rankList); index++)
    {
        rank =(SRanking*) rankList->get(rankList, index);
        fwrite(rank, sizeof(SRanking), 1 ,file);

    }



    fclose(file);
    return returnAux;
}


/**-------------------------------------------------------*////n)

int movieListToFile(ArrayList* movieList)
{
    FILE* file;
    int returnAux = DENEID, index;

    EMovie* movie;

    movie = (EMovie*) malloc(sizeof(EMovie));

    file = fopen("data.dat", "w+b");

    if(file == NULL || movieList == NULL)
    {
        fclose(file);
        return returnAux;
    }

    //fseek(file, 0 , SEEK_END);



    for(index = 0; index < movieList->len(movieList); index++)
    {
        movie =(EMovie*) movieList->get(movieList, index);

        fwrite(movie, sizeof(EMovie), 1 ,file);

    }



    fclose(file);
    return returnAux;
}
