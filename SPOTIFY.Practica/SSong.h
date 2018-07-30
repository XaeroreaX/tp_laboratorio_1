

typedef struct
{
    int id;
    char name[101];
    char Albun[101];
    char Artist[101];
    int visit;
    int durationSeg;

}SSong;

SSong* Song_GetSongArgument(int id);

int Song_getIdUnrepeatable(ArrayList* List);

SSong* Song_contructor(int id, char name[51], char Artist[51], char albun[51], int durationSeg);

void Song_showList(ArrayList* playList, void (*funcion)(SSong*));

void Song_showListRestrictedAlbun(ArrayList* playList, void (*funcion), char albun[101]);

void Song_showIdNombre(SSong* music);

void Song_ShowAllData(SSong* music);

ArrayList* Song_Harcodear();


int Song_getIndex(ArrayList* playList, int (*funcion)(ArrayList*));

int Song_getIdAboutName(ArrayList* playList);

int Song_fileToListText(char path[], ArrayList* playList);

int Song_ListToFile(ArrayList* playList, char path[]);

int Song_fileToList(ArrayList* playList, char path[]);

int Song_CompareNombreVistas(void* movieA, void* movieB);
