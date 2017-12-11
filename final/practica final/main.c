#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "fCientes.h"
#include "cascara.h"
#define OKP 1
#define OK 0
#define DENIED -1



int main()
{
    ArrayList* clienteList;
    ArrayList* ventaList;

    char seguir='s';
    int opcion=0;

    clienteList = al_newArrayList();
    ventaList = al_newArrayList();

    fileToListText(clienteList);

    while(seguir=='s')
        {
            printf("1- Alta de cliente \n");
            printf("2- Modificación de cliente \n");
            printf("3- Baja de cliente\n");
            printf("4- Listar clientes\n");
            printf("5- Realizar una venta\n");
            printf("6- Anular una venta\n");
            printf("7- Informar ventas\n");
            printf("8- Informar ventas por producto\n");
            printf("9- Salir\n");
            printf("ingrese opcion:");

            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    system("cls");

                    if(AltaDeCliente(clienteList) == DENIED) printf("no se pudo cargar el cliente al sistema");

                    system("pause");
                    break;
                case 2:
                    system("cls");

                    if(modificarCliente(clienteList) == DENIED) printf("no se pudo modificar el cliente \n");

                    system("pause");
                    break;
                case 3:
                    system("cls");

                    if(bajaDeCliente(clienteList) == DENIED) printf("hubo un error al dar de baja al cliente");

                    system("pause");
                    break;
                case 4:
                    system("cls");

                    listarClientes(clienteList);

                    system("pause");
                   break;
                case 5:
                    system("cls");

                    system("pause");
                    break;
                case 6:
                    system("cls");

                    system("pause");
                    break;
                case 7:
                    system("cls");

                    system("pause");
                    break;
                case 8:
                    system("cls");

                    system("pause");
                    break;
                case 9:
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

    listToFileText(clienteList);
    return 0;
}
