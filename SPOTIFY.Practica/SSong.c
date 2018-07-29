#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "SSong.h"
#define DENIED -1
#define OK 0
#define OKP 1



SSong* Song_GetSongArgument(int id)
{

    SSong* music;

    char nombre[51];
    char albun[51];
    char Artista[51];
    int durationSeg;
    int visitas;

    printf("ingrese el nombre de la cancion:");
    cargarCaracter(101, nombre);

    printf("ingrese el nombre del albun:");
    cargarCaracter(101, albun);

    printf("ingrese el nombre del artista:");
    cargarCaracter(51, Artista);

    printf("ingrese la duracion en segundos");
    scanf("%d",&durationSeg);

    music = Song_contructor(id, nombre, Artista, albun, durationSeg);

    return music;
}

int Song_getIdUnrepeatable(ArrayList* List)
{
    int flagEncontrado = DENIED,i, j,id = 1;



    SSong* Struct1, *Struct2;

    if(List == NULL) return DENIED;



    if(List->isEmpty(List) == OK)
    {


        for(i = 0; i < List->len(List); i++)
        {
            Struct1 =(SSong*) List->get(List, i);

            if(Struct1->id == id)
            {
                id = Struct1->id +1;
            }
            else
            {

                for(j = i + 1; j < List->len(List); j++)
                {
                    Struct2 =(SSong*) List->get(List, j);

                    if(id == Struct2->id) break;

                }


                if(j < List->len(List)) flagEncontrado = OK;

            }

            if(flagEncontrado == DENIED)
            {
                id = Struct1->id + 1;
            }
            else
            {
                break;
            }
        }

    }

    return id;
}


SSong* Song_contructor(int id, char name[51], char Artist[51], char albun[51], int durationSeg)
{
    int len;
    SSong* cancion;

    cancion = (SSong*) malloc(sizeof(SSong));

    if(cancion == NULL) return cancion;

    cancion->id = id;

    strcpy(cancion->name, name);

    strcpy(cancion->Albun, albun);

    strcpy(cancion->Artist, Artist);

    cancion->visit = 0;

    cancion->durationSeg = durationSeg;

    return cancion;

}


void Song_showList(ArrayList* playList, void (*funcion)(SSong*))
{
    int i;

    SSong* music;


    if(playList != NULL && funcion != NULL)
    {


        for(i = 0; i < playList->len(playList); i++)
        {

            music = playList->get(playList, i);

            funcion(music);

            printf("\n");

        }
    }
}


void Song_showIdNombre(SSong* music)
{
    if(music != NULL)
        printf("Id:%d   Nombre:%s", music->id, music->name);

}


ArrayList* Song_Harcodear()
{
    ArrayList* SongList;

    SongList = al_newArrayList();

    if(SongList != NULL)
    {

        SongList->add(SongList, Song_contructor(1, "Watching over","Iced earth", "Something Wicked This Way Comes", 269));
        SongList->add(SongList, Song_contructor(2, "Fiddle About","The Who", "Tommy", 91));
        SongList->add(SongList, Song_contructor(3, "Full Moon","Sonata Artistica", "Ecliptica", 307));
        SongList->add(SongList, Song_contructor(4, "Hotel California","Eagle", "Hotel California", 391));
        SongList->add(SongList, Song_contructor(5, "Mab in the mirror","Michael Jackson", "Michael Jackson's this is it", 319));

    }

    return SongList;
}



int Song_fileToListText(char path[], ArrayList* playList)
{
    FILE* pFile;

    int returnAux = DENIED;
    char id[101], nombre[101], albun[101], artista[101], visitas[101], duracionSeg[101];
    SSong* music;

    pFile = fopen(path, "r");

    if(playList == NULL || pFile == NULL) return returnAux;

    fgets(nombre, 101, pFile);

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, albun, artista, visitas, duracionSeg);
        music = Song_contructor(atoi(id), nombre, artista,albun, atoi(duracionSeg));
        music->visit = visitas;

        returnAux = playList->add(playList, music);
    }

    fclose(pFile);

    return returnAux;
}



int Song_listToFileText(char path[], ArrayList* playList)
{
    FILE* pFIle;
    int i, returnAux = DENIED;
    SSong* music;

    pFIle = fopen(path, "w+");

    if(playList == NULL || pFIle == NULL) return returnAux;

    fprintf(pFIle, "id,nombre,albun,artista,visitas,durationSeg\n");

    for(i = 0; i < playList->len(playList); i++)
    {
        music = (SSong*) playList->get(playList, i);
        if(music != NULL)
        {
            fprintf(pFIle, "%d,%s,%s,%s,%d,%d\n", music->id, music->name, music->Albun, music->Artist, music->visit,music->durationSeg);
            returnAux = OK;
        }
    }

    fclose(pFIle);

    return returnAux;
}























