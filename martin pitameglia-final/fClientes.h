#define OKP 1
#define OK 0
#define DENIED -1


typedef struct
{
    int idCliente;
    char nombre[100];
    char apellido[100];
    int dni;
    int estado;


}sCliente;


int C_getId(ArrayList* clienteList);

sCliente* C_cargarCliente(int id);

sCliente* C_contructParamClientes(int id, char nombre[], char apellido[], int documento);


///**-------------------------------------shows------------------------------------------------*/

void C_showAllClientes(ArrayList* clienteList, void (*funcion)(sCliente*));

void C_showCliente(sCliente* cliente);

void C_showClienteData(sCliente* cliente);

void C_showClienteId(sCliente* cliente);


///**-----------------------------------------------------------------------------------------*/



/**----------------------------------------------------ARCHIVOS-------------------------------------------------------------------------*/


int C_fileToListText(ArrayList* clienteList);


/**-----------------------------------------------------------------------------------------------------------------------------*/

int C_compareCliente(void* clienteA, void* clienteB);
