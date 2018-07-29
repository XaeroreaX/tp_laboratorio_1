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

    Song_showList(playList, Song_showIdNombre);


}
