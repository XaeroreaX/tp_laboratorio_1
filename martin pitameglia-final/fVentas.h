#define OKP 1
#define OK 0
#define DENIED -1


typedef struct
{
    int idCliente;
    char codigo[100];
    float costo;

    int cantidad;

    int dia;
    int mes;
    int ano;


}sVentas;

sVentas* V_cargarVenta(ArrayList* clienteList);

sVentas* V_contructParamVenta(int id, char codigo[100], float costo, int cantidad, int dia, int mes, int ano);

int V_fileToListText(ArrayList* ventaList);
