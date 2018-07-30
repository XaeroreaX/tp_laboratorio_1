#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "SSong.h"
#include "Tools.h"
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


void Song_showListRestrictedAlbun(ArrayList* playList, void (*funcion), char albun[101])
{


}

void Song_showIdNombre(SSong* music)
{
    if(music != NULL)
        printf("Id:%d   Nombre:%s", music->id, music->name);

}


void Song_ShowAllData(SSong* music)
{

    printf("%40s %40s %40s%10d          ", music->name,music->Albun,music->Artist, music->visit);
    ShowTimeMin(music->durationSeg);


}

int Song_getIndex(ArrayList* playList, int (*funcion)(ArrayList*))
{
    int i = DENIED, id = 0;
    int flagEncontrado = DENIED;

    SSong* music;

    if(playList == NULL || funcion == NULL) return i;


    id = funcion(playList);


    for(i = 0; i < playList->len(playList);i++)
    {
        music = (SSong*) playList->get(playList, i);

        if(music->id == id)
        {
            flagEncontrado = OK;
            break;
        }


    }


    if(flagEncontrado == OK);
        return i;

    return DENIED;
}

int Song_getIdAboutName(ArrayList* playList)
{
    int id = DENIED, i, flagEncontrado = DENIED;

    SSong* music;

    if(playList == NULL) return id;

    char name[101];



    Song_showList(playList, Song_showIdNombre);

    printf("ingrese la cancion que desea escuchar:");
    cargarCaracter(101, name);


    for(i = 0; i < playList->len(playList); i++)
    {
        music = playList->get(playList, i);

        if(strcmpi(music->name, name ) == 0)
        {
            flagEncontrado = OK;
            id = music->id;
            break;
        }

    }

    if(flagEncontrado == DENIED)
    {
        id = flagEncontrado;
    }

    return id;
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
        music->visit = atoi(visitas);

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


int Song_ListToFile(ArrayList* playList, char path[])
{
    FILE* file;
    int returnAux = DENIED, index;

    SSong* music;

    file = fopen(path, "w+b");

    if(file == NULL || playList == NULL)
    {
        fclose(file);
        return returnAux;
    }


    for(index = 0; index < playList->len(playList); index++)
    {
        music =(SSong*) playList->get(playList, index);

        returnAux = fwrite(music, sizeof(SSong), 1 ,file);

    }



    fclose(file);
    return returnAux;
}



int Song_fileToList(ArrayList* playList, char path[])
{
    FILE* file;
    int returnAux = DENIED, index, size;

    SSong* music;



    file = fopen(path, "rb");

    if(file == NULL || playList == NULL)
    {
        fclose(file);
        return returnAux;
    }

    fseek(file, 0 , SEEK_END);

    size = ftell(file)/sizeof(SSong);

    rewind(file);

    for(index = 0; index<size; index++)
    {
        music = (SSong*) malloc(sizeof(SSong));

        fread(music, sizeof(SSong), 1,file);

        returnAux = playList->add(playList, music);
        if(returnAux == DENIED) break;

    }
/*
    len = showMovieListIndex(movieList);
        if(len == DENEID) printf("Error en la funcion showMovieList");*/

    fclose(file);
    return returnAux;
}




int Song_CompareNombreVistas(void* movieA, void* movieB)
{
    int returnAux = 0;
    if(strcmpi(((SSong*)movieA)->name, ((SSong*)movieB)->name) > 0)
    {
        returnAux = 1;
    }
    else
    {
        if(strcmpi(((SSong*)movieA)->name, ((SSong*)movieB)->name) < 0)
        {
            returnAux = -1;
        }
        else
        {
            if(((SSong*)movieA)->visit < ((SSong*)movieB)->visit)
            {

                returnAux = 1;
            }
            else
            {
                if(((SSong*)movieA)->visit > ((SSong*)movieB)->visit)
                {
                    returnAux = -1;
                }
            }
        }


    }


    return returnAux;
}



















