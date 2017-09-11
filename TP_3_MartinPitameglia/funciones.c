#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define OK 0
#define DENEID -1


/**-------------------------------------------------------------------------------------------------------------------------------------------*/


int generarPagina(int *len, EMovie** movieList)
{
    int i, returnAux = DENEID, val;

    EMovie* movie;

    FILE* file;

    movie = (EMovie*) malloc(sizeof(EMovie));

    if(movieList == NULL || movie == NULL) return returnAux;





    file = fopen("index.HTML", "w");

    if(file == NULL) return returnAux;


    for(i = 0; i < *len; i++)
    {

        movie = *(movieList+i);




        fprintf(file,"<img  src=%s alt=%s style=width:200px;hight:200px>",movie->linkImagen,movie->titulo);

                //titulo
        fprintf(file,"<h2><a href=#>%s</a></h2>",movie->titulo);

                //otros aspectos

        fprintf(file,"<h3><li> Genero: %s</li>   <li>Puntaje: %d </li>     <li>Duracion: %d </li>               </h3>",movie->genero,movie->puntaje,movie->duracion);

        fprintf(file,"<pre>%s</pre>", movie->descripcion);


    }




    printf("pagina generada esxitosamente");



    fclose(file);
    returnAux = OK;
    return returnAux;
}


/**-------------------------------------------------------------------------------------------------------------------------------------------*/


int movieListToFile(int *len, EMovie** movieList)
{
    FILE* file;
    int returnAux = DENEID, index;

    EMovie* movie;

    movie = (EMovie*) malloc(sizeof(EMovie));

    file = fopen("data.dat", "w+b");

    if((file == NULL || movieList == NULL) || len == NULL)
    {
        fclose(file);
        return returnAux;
    }

    //fseek(file, 0 , SEEK_END);



    for(index = 0; index < *len; index++)
    {
        movie = *(movieList+index);

        fwrite(movie, sizeof(EMovie), 1 ,file);

        //printf("%d-%d-%s",index,len, movie->titulo);
    }



    fclose(file);
    return returnAux;
}



/**-------------------------------------------------------------------------------------------------------------------------------------------*/

int HarcodearMovieList(int* len, int* size, EMovie** movieList)
{
    int i, returnAux = DENEID;

    /*char titulo[];
    char genero[];
    int duracion;
    char descripcion[];
    int puntaje;
    char linkImagen[];*/
    char titulo[5][50] = {"volver al futuro", "jojo", "v13", "terminator", "ut2k4"};
    char genero[5][50] = {"aventura", "shonen/seinen", "horror", "accion", "fps"};
    int duracion[5] = {120, 500, 80, 90, 10000};
    char descripcion[5][1024] = {"peli de viajes en el tiempo","peleas en un linaje fabuloso","peli de asesinatos","apocalipcis skinet","juego multiplayer"};
    int puntaje[5] = {90, 70, 60, 80, 80};
    char linkImagen[5][500] = {"https://images-na.ssl-images-amazon.com/images/M/MV5BZmU0M2Y1OGUtZjIxNi00ZjBkLTg1MjgtOWIyNThiZWIwYjRiXkEyXkFqcGdeQXVyMTQxNzMzNDI@._V1_SY1000_CR0,0,643,1000_AL_.jpg","https://myanimelist.cdn-dena.com/images/anime/2/82464.jpg","https://images-na.ssl-images-amazon.com/images/M/MV5BNWMxYTYzYWQtNGZmNy00MTg5LTk1N2MtNzQ5NjQxYjQ5NTJhXkEyXkFqcGdeQXVyMTQxNzMzNDI@._V1_SX669_CR0,0,669,999_AL_.jpg","https://images-na.ssl-images-amazon.com/images/M/MV5BODE1MDczNTUxOV5BMl5BanBnXkFtZTcwMTA0NDQyNA@@._V1_SY1000_CR0,0,666,1000_AL_.jpg","https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSm_VFglXxfyRpFKwavBlewLlgNEY-YXIpVza1f5LnlGhjIevyF"};

    EMovie* movie;

    for(i = 0; i < 5;i++)
    {

        movie = (EMovie*) malloc(sizeof(EMovie));

        strcpy(movie->titulo, titulo[i]);

        strcpy(movie->genero, genero[i]);

        movie->duracion = duracion[i];

        strcpy(movie->descripcion, descripcion[i]);

        movie->puntaje = puntaje[i];

        strcpy(movie->linkImagen, linkImagen[i]);

        returnAux = addMovieList(len, size, movieList, movie);


    }

    showMovieListIndex(len, movieList);

    return returnAux;
}

/**-------------------------------------------------------------------------------------------------------------------------------------------*/

int addMovieList(int *len, int *size, EMovie** movieList, EMovie* movie)
{
    int returnAux = DENEID, i;

    if((len == NULL || size == NULL) || (movie == NULL || movieList == NULL)) return returnAux;

    if(*len ==  *size)
    {
        if(resizeUp(size, movieList) == DENEID) return returnAux;

    }

    i = *len;
    *(movieList+i) = movie;
    *len = i + 1;

    printf("%d--%d", *len, *size);

    returnAux = OK;

    return returnAux;
}

/**-------------------------------------------------------------------------------------------------------------------------------------------*/


int showMovieListIndex(int* len, EMovie** movieList)
{
    int i, returnAux = DENEID;

    EMovie* movie;

    movie = (EMovie*) malloc(sizeof(EMovie));

    if(movieList == NULL || movie == NULL) return returnAux;

    for(i = 0; i < *len; i++)
    {
        movie = *(movieList+i);
        printf("\n%d)titulo:%s", (i + 1), movie->titulo);
    }

    printf("\n");
    returnAux = i;

    return returnAux;
}

/**-------------------------------------------------------------------------------------------------------------------------------------------*/


void cascara(int *len, int *size, EMovie** movieList)
{

    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");

                break;
            case 2:
                system("cls");

                break;
            case 3:
                system("cls");

                break;
            case 4:
               break;
            case 5:
                seguir = 'n';
                break;


        }


        system("pause");
        system("cls");

    }




}

/**-------------------------------------------------------------------------------------------------------------------------------------------*/

int resizeUp(int *size, EMovie** movieList)
{
    int returnAux = DENEID;
    EMovie** aux;

    aux = (EMovie**) realloc(movieList, sizeof(EMovie*)*(*size + 3));
    if(aux == NULL) return returnAux;

    movieList = aux;
    *size += 3;
    returnAux = OK;

    return returnAux;

}

/**-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/

EMovie* addMovie()
{
    EMovie* movie;

    movie = (EMovie*) malloc(sizeof(EMovie));


    if(movie != NULL)
    {
        printf("\nIngrese el titulo de la pelicula:");
        cargarCaracter(20, movie->titulo);

        printf("\nIngrese el genero de la pelicula:");
        cargarCaracter(20, movie->genero);

        printf("\nIngrese el duracion de la pelicula(en minutos):");
        scanf("%d", &movie->duracion);
        while(movie->duracion < 3)
        {
            printf("\nIngreso mal el duracion de la pelicula, por favor ingrese de nuevo:");
            scanf("%d", &movie->duracion);
        }

        printf("\nIngrese la descripcion de la pelicula:");
        cargarCaracter(50, movie->descripcion);

        printf("\nIngrese el puntuacion de la pelicula(de 10 a 100):");
        scanf("%d", &movie->puntaje);
        while(movie->puntaje < 10 || movie->puntaje > 100)
        {
            printf("\nIngreso mal la puntuacion de la pelicula, por favor ingrese de nuevo:");
            scanf("%d", &movie->puntaje);
        }

        printf("\nIngrese un link para la imagen de la pelicula:");
        cargarCaracter(50, movie->linkImagen);

    }

    return movie;
}
/*
/**------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/

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


}*/

/**-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

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
