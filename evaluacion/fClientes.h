
#define OKP 1
#define OK 0
#define DENIED -1

typedef struct
{
    int idCliente;
    char nombre[100];
    char apellido[100];
    int documento;

}sCliente;

int C_getId(ArrayList* clienteList);

int C_selectIdCliente(ArrayList* clienteList);

int C_validarCliente(sCliente* cliente, ArrayList* clienteList);

sCliente* C_cargarCliente(int id);

sCliente* C_contructParamClientes(int id, char nombre[], char apellido[], int documento);

int C_getIndex(ArrayList* clientetList);


///**-------------------------------------shows------------------------------------------------*/

void C_showAllClientes(ArrayList* clienteList, void (*funcion)(sCliente*));

void C_showCliente(sCliente* cliente);

void C_showClienteData(sCliente* cliente);

void C_showClienteId(sCliente* cliente);


///**-----------------------------------------------------------------------------------------*/


int C_compareCliente(void* clienteA, void* clienteB);
