
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


sServicio* S_contructParamServicio(int NRO_servicio, char codigo[], double costo, int estado, int idCliente);
