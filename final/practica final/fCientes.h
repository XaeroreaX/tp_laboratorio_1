#define OKP 1
#define OK 0
#define DENIED



typedef struct
{
    int idCliente;
    char* nombre;
    char* apellido;
    int documento;

}sCliente;


sCliente* contructParamClientes(int id, char nombre[], char apellido[], int documento);

sCliente* cargarCliente(int id);

