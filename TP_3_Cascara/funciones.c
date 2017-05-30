/*char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];*/
/**-------------------------------------------------------*////1)

int agregarPelicula(EMovie movie)
{
    FILE* arch;

    printf("ingrese el titulo de la pelicula\n");
    cargarCaracter(20, movie.titulo);



}


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
