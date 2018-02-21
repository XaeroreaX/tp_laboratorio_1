#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cascara.h"
#include "fClientes.h"
#include "fVentas.h"
#include "funciones.h"
#define OKP 1
#define OK 0
#define DENIED -1

int main()
{
    char seguir='s';
    int opcion=0;

    ArrayList* clienteList;
    ArrayList* ventaList;

    clienteList = al_newArrayList();
    ventaList = al_newArrayList();


    if(C_fileToListText(clienteList) == DENIED) printf("ERROR AL ABRIR EL ARCHIVO!!!");

    if(V_fileToListText(ventaList) == DENIED) printf("ERROR AL ABRIR EL ARCHIVO!!!");



    while(seguir=='s')
        {
            printf("1- alta de cliente\n");
            printf("2- modificar cliente \n");
            printf("3- baja de cliente \n");
            printf("4- listar clientes\n");
            printf("5- realizar servicio CSV\n");
            printf("8- informar\n");
            printf("10- Salir\n");
            printf("ingrese opcion");

            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    system("cls");

                    if(AltaDeCliente(clienteList) == DENIED) printf("ERROR!!!");


                    system("pause");
                    break;
                case 2:
                    system("cls");

                    if(modifiCliente(clienteList) == DENIED) printf("ERROR!!!");

                    system("pause");
                    break;
                case 3:
                    system("cls");

                    if(bajaDeCliente(clienteList) == DENIED) printf("ERROR!!!");

                    system("pause");
                    break;
                case 4:
                    system("cls");

                    if(listarClientes(clienteList) == DENIED) printf("ERROR");

                    system("pause");
                   break;
                case 5:
                    system("cls");

                    if(realizarVenta(ventaList, clienteList) == DENIED) printf("ERROR");

                    system("pause");
                    break;
                case 8:
                    system("cls");

                    if(informar(clienteList, ventaList) == DENIED) printf("ERROR");

                    system("pause");
                    break;

                case 10:
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
    return 0;
}
