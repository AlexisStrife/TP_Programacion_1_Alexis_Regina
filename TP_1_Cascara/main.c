#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    float numeroUno = 0;
    float numeroDos = 0;
    float resultado = 0;
    int opcion=0;
    char conservarInfo = 'n';

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%.2f)\n", numeroUno);
        printf("2- Ingresar 2do operando (B=%.2f)\n", numeroDos);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese el primer numero: ");
                fflush(stdin);
                scanf("%f", &numeroUno);
                conservarInfo = 'n';
                break;
            case 2:
                printf("Ingrese el segundo numero: ");
                fflush(stdin);
                scanf("%f", &numeroDos);
                conservarInfo = 'n';
                break;
            case 3:
                resultado = sumar(numeroUno, numeroDos);
                printf("\nLa suma es: %.2f\n\n", resultado);
                conservarInfo = 's';
                break;
            case 4:
                resultado = restar(numeroUno, numeroDos);
                printf("\nLa resta es: %.2f\n\n", resultado);
                conservarInfo = 's';
                break;
            case 5:
                if (numeroDos != 0)
                {
                    resultado = dividir(numeroUno, numeroDos);
                    printf("\nLa division es: %.2f\n\n", resultado);
                    conservarInfo = 's';
                }
                else
                {
                    printf("\nNo se puede dividir por 0. Favor de cambiar segundo numero.\n\n");
                }
                break;
            case 6:
                resultado = multiplicar(numeroUno, numeroDos);
                printf("\nLa multiplicacion es: %.2f\n\n", resultado);
                conservarInfo = 's';
                break;
            case 7:
                if (numeroUno > 0)
                {
                    if (validaEntero(numeroUno) > 0)
                    {
                        resultado = factorial(numeroUno);
                        printf("\nEl factorial es: %d\n\n", (int) resultado);
                    }
                    else
                    {
                        printf("\nNo se puede calcular el factorial de un numero con decimales.\n\n");
                    }
                }
                else
                {
                    printf("\nNo se puede calcular el factorial de un numero menor o igual a 0.\n\n");
                }
                conservarInfo = 's';
                break;
            case 8:
                //Suma
                resultado = sumar(numeroUno, numeroDos);
                printf("\nLa suma es: %.2f\n", resultado);
                //Resta
                resultado = restar(numeroUno, numeroDos);
                printf("\nLa resta es: %.2f\n", resultado);
                //Division
                if (numeroDos != 0)
                {
                    resultado = dividir(numeroUno, numeroDos);
                    printf("\nLa division es: %.2f\n", resultado);
                }
                else
                {
                    printf("\nNo se puede dividir por 0. Favor de cambiar segundo numero.\n");
                }
                //Multiplicacion
                resultado = multiplicar(numeroUno, numeroDos);
                printf("\nLa multiplicacion es: %.2f\n", resultado);
                //Factorial
                if (numeroUno > 0)
                {
                    if (validaEntero(numeroUno) > 0)
                    {
                        resultado = factorial(numeroUno);
                        printf("\nEl factorial es: %d\n\n", (int) resultado);
                    }
                    else
                    {
                        printf("\nNo se puede calcular el factorial de un numero con decimales.\n\n");
                    }
                }
                else
                {
                    printf("\nNo se puede calcular el factorial de un numero menor o igual a 0.\n\n");
                }
                conservarInfo = 's';
                break;
            case 9:
                seguir = 'n';
                break;
        }
        if (conservarInfo == 'n')
        {
            system("cls");
        }

    }
        return 0;
}
