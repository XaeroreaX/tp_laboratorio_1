#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "cascara.h"
#include "fClientes.h"
#define OKP 1
#define OK 0
#define DENIED -1


int main()
{
    ArrayList* clienteList, *servicioList;
    char seguir='s';
    int opcion=0;

    clienteList = al_newArrayList();
    servicioList = al_newArrayList();

    if(C_fileToListBin(clienteList) == DENIED) printf(" no se pudo habrir el archivo\n");

    while(seguir=='s')
        {
            printf("1- Alta de cliente \n");
            printf("2- modificacion de clientes \n");
            printf("3- baja de clientes \n");
            printf("4- listar clientes\n");
            printf("5- importar servicio tecnico desde CSV\n");
            printf("6- Salir\n");
            printf("ingrese opcion");

            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    system("cls");

                    if(AltaDeCliente(clienteList) == DENIED) printf("hubo un error en la alta del cliente!!");

                    system("pause");
                    break;
                case 2:
                    system("cls");

                    if(modificacionDeCliente(clienteList) == DENIED) printf("hubo un error en la modificacion del cliente");

                    system("pause");
                    break;
                case 3:
                    system("cls");

                    if(bajaDeCliente(clienteList) == DENIED)printf("hubo un error en la baja del cliente");


                    system("pause");
                    break;
                case 4:
                    system("cls");

                    if(listarClientes(clienteList) == DENIED) printf("hubo un error al listar los clientes");

                    system("pause");
                   break;
                case 5:
                    system("cls");

                    importarServicios(clienteList, servicioList);

                    system("pause");
                    break;
                case 6:
                    seguir = 'n';
                    break;
                default:
                    system("cls");
                    printf("ingreso mal la opcion, por favor ingrese de nuevo");
                    system("pause");
                    break;


            }
            system("cls");

        }

    C_ListToFileBin(clienteList);

    return 0;
}
