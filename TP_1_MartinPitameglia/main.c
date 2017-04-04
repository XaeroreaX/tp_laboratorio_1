#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



int main()
{
    char seguir='s';
    int opcion=0, factor;
    long long int resultadoFactorial;
    float num1 = 0, num2 = 0, resultado;
    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        printf("\noperando 1 es %f \noperando 2 es %f\n\n", num1, num2);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                num1 = ingresarNumeroF("ingrese el 1er operando", num1);
                factor = num1;
                break;
            case 2:
                num2 = ingresarNumeroF("ingrese el 2do operando", num2);
                break;
            case 3:
                resultado = sumarFloats(num1, num2);
                printf("el resultado de la suma es %f\n\n", resultado);
                break;
            case 4:
                resultado = restarFloats(num1, num2);
                printf("el resultado de la resta es %f\n\n", resultado);
                break;
            case 5:
                while(num2 == 0)
                {
                    num2 = ingresarNumeroF("no puedes dividir 0, ingrese de nuevo", num1);
                }
                resultado = dividirFloats(num1, num2);
                printf("el resultado de la division es %f\n\n", resultado);
                break;
            case 6:
                resultado = multiplicarFloats(num1,num2);
                printf("el resultado de la multiplicacion es %f\n\n", resultado);
                break;
            case 7:
                while(num1 != factor || (num1 < 1 || num1 > 25))
                {
                    num1 = ingresarNumeroF("no puedes hacer factorial de numeros decimales ni menores a 1 y mayores de 25", num1);
                    factor = num1;
                }
                resultadoFactorial = factorial(factor);
                printf("el resultado del facotorial es: %lld \n\n",resultadoFactorial);
                break;
            case 8:

                resultado = sumarFloats(num1, num2);
                printf("el resultado de la suma es %f\n\n", resultado);

                resultado = restarFloats(num1, num2);
                printf("el resultado de la resta es %f\n\n", resultado);

                if(num2 == 0)
                {
                    printf("no se pudo efectuar la division dado que el dividendo es 0\n\n");
                }
                else
                {
                    resultado = dividirFloats(num1, num2);
                    printf("el resultado de la division es %f\n\n", resultado);
                }


                resultado = multiplicarFloats(num1,num2);
                printf("el resultado de la multiplicacion es %f\n\n", resultado);

                if(num1 != factor || (num1 < 1 || num1 > 25))
                {
                    printf("no se pudo efectuar el factorial\n\n");
                }
                else
                {
                    resultadoFactorial = factorial(factor);
                    printf("el resultado del facotorial es: %lld \n\n",resultadoFactorial);
                }


                break;
            case 9:
                seguir = 'n';
                break;
        }
        system("pause");
        system("cls");
    }


    return 0;
}



