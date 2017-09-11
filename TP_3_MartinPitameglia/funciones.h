#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[1024];
    int puntaje;
    char linkImagen[500];
}EMovie __attribute__ ((packed));


int generarPagina(int *len, EMovie** movieList);

int movieListToFile(int *len, EMovie** movieList);

int HarcodearMovieList(int*, int* ,EMovie**);

int addMovieList(int *, int *, EMovie**, EMovie*);

void cascara(int *, int *, EMovie**);

int resizeUp(int* , EMovie**);

void cargarCaracter(int tam, char caracteres[tam]);

#endif // FUNCIONES_H_INCLUDED
