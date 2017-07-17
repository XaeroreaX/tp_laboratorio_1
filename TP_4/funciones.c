#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayList.h"
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
    if(movieList->isEmpty(movieList) == 0)
    {

        printf("ingrese el indice la pelicula que quiere borrar:\n0)Cancel");
        if(showMovieListIndex(movieList) == DENEID) printf("Error en la funcion showMovieList");
        scanf("%d", &index);
        while(index < 0 || index > movieList->len(movieList))
        {
            printf("elijio mal la pelicula que quiere borrar, por favor ingrese de nuevo\n");
            scanf("%d", &index);
        }

        index--;

        if(index >= 0)
            returnAux = movieList->remove(movieList, index);
        else
            returnAux = OK;


    }
    else printf("no hay peliculas almacenadas\n");

    return returnAux;
}

/**-------------------------------------------------------*////3)

int setMovieList(ArrayList* movieList)
{
    int returnAux = DENEID, index;
    EMovie* movie;

    if(movieList == NULL) return returnAux;

    returnAux = OK;

    if(movieList->isEmpty(movieList) == 0)
    {

        printf("ingrese el indice la pelicula que quiere modificar:\n0)Cancel");
        if( showMovieListIndex(movieList) == DENEID) printf("Error en la funcion showMovieList");

        scanf("%d", &index);

        while(index < 0 || index > movieList->len(movieList))
        {
            printf("elijio mal la pelicula que quiere modificar, por favor ingrese de nuevo\n");
            scanf("%d", &index);
        }


        index--;
        if(index >= 0)
        {

            movie = addMovie();

            if(movie != NULL)
                returnAux = movieList->set(movieList, index, movie);
        }
        else
            returnAux = OK;
    }
    else printf("no hay peliculas almacenadas\n");

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

            fprintf(file,"<h3><li> Genero: %s</li>   <li>Puntaje: %d </li>     <li>Duracion: %d </li>               </h3>",movie->genero,movie->puntaje,movie->duracion);

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
  //      printf("%d-%s\n",len, movie->titulo);

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

/**-------------------------------------------------------*////n)

int showMovieListIndex(ArrayList* movieList)
{
    int i, returnAux = DENEID;

    EMovie* movie;

    movie = (EMovie*) malloc(sizeof(EMovie));

    if(movieList == NULL || movie == NULL) return returnAux;

    for(i = 0; i < movieList->len(movieList); i++)
    {
        movie = (EMovie*) movieList->get(movieList, i);
        printf("\n%d)titulo:%s", (i + 1), movie->titulo);
    }

    printf("\n");
    returnAux = i;

    return returnAux;
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

        printf("\nIngrese el puntuacion de la pelicula(de 10 a 100):");
        fflush(stdin);
        scanf("%d", &movie->puntaje);
        while(movie->puntaje < 10 || movie->puntaje > 100)
        {
            fflush(stdin);
            printf("\nIngreso mal la puntuacion de la pelicula, por favor ingrese de nuevo:");
            scanf("%d", &movie->puntaje);
        }

        printf("\nIngrese un link para la imagen de la pelicula:");
        cargarCaracter(800, movie->linkImagen);

    }

    return movie;
}

/**-------------------------------------------------------*////n)

int compareMovie(void* MovieA, void* MovieB)
{

    if( strcmp(((EMovie*)MovieA)->titulo, ((EMovie*)MovieB)->titulo) == 1)
    {
        return 1;
    }
    if( strcmp(((EMovie*)MovieA)->titulo, ((EMovie*)MovieB)->titulo) == -1)
    {
        return -1;
    }
    return 0;


}


/**-------------------------------------------------------*////n)

int menuAdministrador(ArrayList* movieList)
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

            if(movieList->sort(movieList, compareMovie, 1) == DENEID ) printf("ERROR en la funsion sort de arrayList de EMovie");
            movieListToFile(movieList);
            system("cls");

        }
    returnAux = OK;
    return returnAux;
}



int harcodearSUser(ArrayList* userList)
{
    int i, returnAux = DENEID, id[5] = {1, 1001, 1002, 1003, 1004};
    char nickName[5][50] = {"XaeroreaX", "mr. queen", "camila","Atilio", "pucci"};
    char password[5][50] = {"master6060", "rey2501", "camila","abel6060", "Made in heaven"};
    SUser* user;



    if(user == NULL || userList == NULL) return returnAux;

    for(i = 0; i < 5; i++)
    {


        user = (SUser*) malloc(sizeof(SUser));
        user->id = id[i];

        strcpy(user->nickName, nickName[i]);
        strcpy(user->password, password[i]);

        returnAux = userList->add(userList, user);
        if(returnAux == DENEID) break;

    }

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
                if(i == 3) user = NULL;

            }
        }while(flag == DENEID);


    }

    return user;
}



/**-------------------------------------------------------*////n)
/*
int addRank(ArrayList* rankList, ArrayList* userList, ArrayList* movieList)
{
    int returnAux = DENEID;

    EMovie* movie;
    SUser* user;
    SRanking* rank;

    movie = (EMovie*) malloc(sizeof(EMovie));
    user = (SUser*) malloc(sizeof(SUser));
    SRanking = (SRanking*) malloc(sizeof(SRanking));

    if(rankList == NULL || rank == NULL) return returnAux;

    if(movieList == NULL || movie == NULL) return returnAux;

    if(userList == NULL || user == NULL) return returnAux;


}
*/
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

