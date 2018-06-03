#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"
#include "input.h"

#define A 3

int main()
{
    EMovie movie[A];
	char seguir='s';
	char guardar= 's';
	int i;

    for( i=0; i<A; i++)
    {
        movie[i].codigo=0;
    }
	if(cargarDesdeArchivo(movie))
	{
		printf("No se pudo abrir el fichero");
	}
	else
	{
		printf("Se cargaron las estructuras con exito\n");
	}
    system("pause");
	system("cls");

    while(seguir=='s')
    {
        switch(menu())
        {
            case '1':
                system("cls");
                agregarPelicula(movie);
                break;
            case '2':
                system("cls");
                borrarPelicula(movie);
                break;
            case '3':
                system("cls");
                modificarPelicula(movie);
                break;
            case '4':
                system("cls");
                generarPagina(movie);
                break;
            case '5':
                printf("\nGuardar cambios S/N ?: ");
                guardar = tolower(getche());
                while(guardar!= 's' && guardar != 'n'){
                    printf("\nIngrese S o N\n");
                    guardar = tolower(getche());
                }

				if(guardar == 's')
				{
					if(guardarEnArchivo(movie))
					{
						printf("\nNo se pudo abrir el fichero\n");
					}
					else
					{
						printf("\nSe guardo la informacion con exito\n");
					}
				}
				seguir='n';
				break;
            default:
                system("cls");
                printf("No ingreso una opcion valida.\n\n");
                break;
        }
    }
    return 0;
}
