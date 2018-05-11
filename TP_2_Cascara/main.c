#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "inc/input.h"

#define TAM 5

int main()
{
    char seguir='s';
    char auxOpcion[1];
    int opcion=0;
    int validado;
    EPersona per[TAM];

    inicializar(per, TAM);

    //Descomentar si se quiere tener personas hardcodeadas para pruebas
    //hardCode(per);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n\n");
        do
        {
            fflush(stdin);
            scanf("%s", auxOpcion);
            validado = validaNumero(auxOpcion);
        }
        while(validado == 0);

        opcion = atoi(auxOpcion);

        switch(opcion)
        {
            case 1:
                alta(per, TAM);
                break;
            case 2:
                baja(per, TAM);
                break;
            case 8:
                modificar(per, TAM);
                break;
            case 3:
                listar(per, TAM);
                break;
            case 4:
                listarGrafico(per, TAM);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
