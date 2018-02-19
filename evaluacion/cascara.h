#define OKP 1
#define OK 0
#define DENIED -1



///1)
int AltaDeCliente(ArrayList* clienteList);


///2)
int modificacionDeCliente(ArrayList* clienteList);

///3)
int bajaDeCliente(ArrayList* clienteList);

///4)
int listarClientes(ArrayList* clienteList);

///5)
int importarServicios(ArrayList* clienteList, ArrayList* servicioList);

///6)
int ingresarServicioTecnico(ArrayList* servicioList, ArrayList* clienteList);

///7)
int finalizarServicioTecnico(ArrayList* servicioList, ArrayList* clienteList);
