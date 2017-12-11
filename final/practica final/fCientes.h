#define OKP 1
#define OK 0
#define DENIED -1



typedef struct
{
    int idCliente;
    char* nombre;
    char* apellido;
    int documento;

}sCliente;


sCliente* contructParamClientes(int id, char nombre[], char apellido[], int documento);

sCliente* cargarCliente(int id);

int getId(ArrayList* clienteList);

int getIndex(ArrayList* clientetList);

///**-------------------------------------shows------------------------------------------------*/

void showAllClientes(ArrayList* clienteList, void (*funcion)(sCliente*));
void showCliente(sCliente* cliente);
void showClienteData(sCliente* cliente);
void showClienteId(sCliente* cliente);

///**-------------------------------------shows------------------------------------------------*/

int compareCliente(void* clienteA, void* clienteB);
