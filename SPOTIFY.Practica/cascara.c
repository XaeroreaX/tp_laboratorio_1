#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "SSong.h"
#include "cascara.h"
#define DENIED -1
#define OK 0
#define OKP 1





int AltaSong(ArrayList* playList)
{
    int returnAux = DENIED;
    if(playList != NULL)
    {
        returnAux = playList->add(playList, Song_GetSongArgument(Song_getIdUnrepeatable(playList)));



    }

    return returnAux;
}


void ListarPlaylist(ArrayList* playList)
{
    ArrayList* AuxList = playList->clone(playList);

    AuxList->sort(AuxList, Song_CompareNombreVistas, 1);
    printf("                                 Cancion                                    Albun                                  Artista   visitas       duracion\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    Song_showList(AuxList, Song_ShowAllData);


}


int VisitaMusic(ArrayList* playList)
{
    int returnAux = DENIED;

    if(playList != NULL)
    {
        int i = Song_getIndex(playList, Song_getIdAboutName);

        if(i != DENIED)
        {
            SSong* music = playList->get(playList, i);

            music->visit++;

            returnAux = playList->set(playList, i, music);

        }
    }


    //if()

    return returnAux;
}
