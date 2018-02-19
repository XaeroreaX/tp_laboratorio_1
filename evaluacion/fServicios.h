
#define OKP 1
#define OK 0
#define DENIED -1


typedef struct
{
    int NRO_servicio;
    char codigo[100];
    double costo;
    int estado;
    int idCliente;

}sServicio;


int S_getId(ArrayList* servicioList);

sServicio* S_contructParamServicio(int NRO_servicio, char codigo[], double costo, int estado, int idCliente);


sServicio* S_cargarServicio(int NRO_servicio, ArrayList* clienteList);

int S_getNRO_servicio(ArrayList* servicioList, ArrayList* clienteList);



/**------------------------------------shows-----------------------------------*/

void S_showAllSevicio(ArrayList* servicioList, ArrayList* clienteList);


/**------------------------------------------------------------------------------------*/

/**------------------------------------ARCHIVOS-----------------------------------*/


int S_fileToListBin(ArrayList* serviciosList);


int S_ListToFileBin(ArrayList* servicioList);

/**------------------------------------------------------------------------------------*/


int S_validarCliente(sServicio* servicio, ArrayList* servicioList);

int S_compareProductos(void* servicioA, void* servicioB);
