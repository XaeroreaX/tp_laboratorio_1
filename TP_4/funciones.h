#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "ArrayList.h"
typedef struct{
    char titulo[50];
    char genero[100];
    int duracion;
    char descripcion[800];
    int puntaje;
    char linkImagen[800];
}EMovie __attribute__ ((packed));

typedef struct{
    int id;
    char nickName[50];
    char password[50];

}SUser;

typedef struct{

    int id;
    char waching[50];
    int puntaje;
}SRanking;

int addMovieList(ArrayList*);

int removeMovieList(ArrayList* movieList);

int setMovieList(ArrayList* movieList);

int fileToUserList(ArrayList* userList);

int fileToRankList(ArrayList* rankList);

int fileToMovieList(ArrayList* movieList);

int userListToFile(ArrayList* userList);

int rankListToFile(ArrayList* rankList);

int movieListToFile(ArrayList* movieList);

int showMovieListIndex(ArrayList* movieList);

EMovie* addMovie();

int compareMovie(void* MovieA, void* MovieB);


int harcodearSUser(ArrayList*);

SUser* login(ArrayList* userList);

int addRank(ArrayList* movieList, SUser* user, ArrayList* rankList);

int Rank(ArrayList* movieList, ArrayList* rankList);

int menuCliente(ArrayList* movieList, SUser* user, ArrayList* rankList);

void cargarCaracter(int tam, char caracteres[tam]);

#endif // FUNCIONES_H_INCLUDED
