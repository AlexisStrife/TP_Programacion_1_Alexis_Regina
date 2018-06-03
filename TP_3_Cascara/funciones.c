#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"
#include "input.h"

#define A 3

char menu()
{
    char c[1];
    int validado;
	system("cls");
    printf("\tMENU\n1- Agregar pelicula\n2- Borrar pelicula\n3- Modificar pelicula\n4- Generar pagina web\n5- Salir\n");
	printf("Elija una opcion: ");
	do{
        fflush(stdin);
        scanf("%s", c);
        validado = validaNumero(c);
    }while(validado == 0);
	return c[0];
}

int buscarLibre(EMovie movie[])
{
	int index=-1;
	int i;
	for( i=0; i < A; i++)
	   if(movie[i].codigo==0){
		index=i;
		break;
	   }
	return index;
}

void agregarPelicula(EMovie movie[])
{
    int index, i;
	int codigo;
	int encontro=0;
	int validaCodigo, validaTitulo, validaGenero, validaDuracion, validaDescripcion, validaPuntaje, validaLink;
	/*Buscamos cual es el primer indice libre dentro del array*/
	index=buscarLibre(movie);
    if(index!=-1)//si hay lugar:
	{
		printf("---Agregar Pelicula---\n\n");
		do{
            validaCodigo = getInt(&codigo,"Ingrese codigo: ","Rango valido [1 - 9999]",1,9999);
        }while(validaCodigo == -1);
		/*Buscamos si el codigo ya existe*/
		for(i=0; i<A; i++)
		{
			if(codigo==movie[i].codigo)
			{
				encontro=1;//encontro en true
				break;
			}
		}
		if(!encontro)//entra si encontro==0
		{
			movie[index].codigo=codigo;
            do{
                validaTitulo = validaLargo(movie[index].titulo,"Titulo: ","El largo debe ser entre 2 y 20",2,50);
            }
            while(validaTitulo == -1);
            do{
                validaGenero = validaLargo(movie[index].genero,"Genero: ","El largo debe ser entre 2 y 20",2,50);
            }
            while(validaGenero == -1);
            do{
                validaDuracion = getInt(&movie[index].duracion,"Duracion: ","Rango valido (Minutos) [1 - 300]",1,300);
            }
            while(validaDuracion == -1);
            do{
                validaDescripcion = validaLargo(movie[index].descripcion,"Descripcion: ","El largo debe ser entre 2 y 50",2,100);
            }
            while(validaDescripcion == -1);
            do{
                validaPuntaje = getInt(&movie[index].puntaje,"Puntaje: ","Rango valido [0 - 100]",0,100);
            }
            while(validaPuntaje == -1);
            do{
                validaLink = validaLargo(movie[index].linkImagen,"Link Imagen: ","El largo debe ser entre 2 y 100",2,500);
            }
            while(validaLink == -1);
			system("cls");
		}
		else
		{
			printf("­­El codigo ingresado ya existe!!");
			getch();
		}
	}
	else
	{
		printf("No queda espacio");
		getch();
	}
}

void toString(EMovie* movie)
{
	printf("Codigo: %d\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink Imagen: %s\n\n", movie->codigo, movie->titulo, movie->genero, movie->duracion, movie->descripcion, movie->puntaje, movie->linkImagen);
}

void borrarPelicula(EMovie *movie)
{
	int codigo, flag=0,i, validaCodigo;
	char opcion;
	printf("---Borrar Pelicula---\n\n");
    do{
        validaCodigo = getInt(&codigo,"Ingrese codigo a dar de baja: ","Rango valido [1 - 9999]",1,9999);
    }while(validaCodigo == -1);

	for(i=0; i<A; i++)
	{
		if(codigo==movie[i].codigo)
		{
			printf("\nDatos a eliminar:\n\n");

			toString((movie + i));

			printf("\nCodigo encontrado. ¨Seguro desea dar de baja? S/N\n");
			opcion=tolower(getche());
			if(opcion=='s')
			{
				movie[i].codigo=0;
				printf("­­Registro eliminado!!\n");
				getch();
			}
			else
			{
				printf("El registro no fue eliminado!\n");
				getch();
			}
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("Codigo inexistente\n");
		getch();
	}
}

void modificarPelicula(EMovie *movie)
{
	int codigo, flag=0, i, validado, flag2 = 0;
	int validaCodigo, validaTitulo, validaGenero, validaDuracion, validaDescripcion, validaPuntaje, validaLink;
	char seguir='s';
	char c[1];
	system("cls");
	printf("Ingrese codigo a modificar: ");
	scanf("%d",&codigo);
	for( i=0; i<A; i++)
	{
		if(codigo==movie[i].codigo)
		{
			printf("Datos encontrados:\n");

			toString((movie + i));
			while(seguir == 's')
            {
            printf("Seleccione el dato que quiere cambiar: \n");
            printf("1)Codigo\n2)Titulo\n3)Genero\n4)Duracion\n5)Descripcion\n6)Puntaje\n7)Link Imagen\n8)Volver\n");
            do{
                fflush(stdin);
                scanf("%s", c);
                validado = validaNumero(c);
            }while(validado == 0);

                flag = 0;
                switch(c[0])
                {
                    case '1':
                        do{
                            validaCodigo = getInt(&movie[i].codigo,"Ingrese el nuevo codigo: ","Rango valido [1 - 9999]",1,9999);
                        }
                        while(validaCodigo == -1);
                        flag=1;
                        break;
                    case '2':
                        do{
                            validaTitulo = validaLargo(movie[i].titulo,"Ingrese el nuevo titulo: ","El largo debe ser entre 2 y 20",2,50);
                        }
                        while(validaTitulo == -1);
                        flag=1;
                        break;
                    case '3':
                        do{
                            validaGenero = validaLargo(movie[i].genero,"Ingrese el nuevo genero: ","El largo debe ser entre 2 y 20",2,50);
                        }
                        while(validaGenero == -1);
                        flag=1;
                        break;
                    case '4':
                        do{
                            validaDuracion = getInt(&movie[i].duracion,"Ingrese la nueva duracion: ","Rango valido (Minutos) [1 - 300]",1,300);
                        }
                        while(validaDuracion == -1);
                        flag=1;
                        break;
                    case '5':
                        do{
                            validaDescripcion = validaLargo(movie[i].descripcion,"Ingrese la nueva descripcion: ","El largo debe ser entre 2 y 50",2,100);
                        }
                        while(validaDescripcion == -1);
                        flag=1;
                        break;
                    case '6':
                        do{
                            validaPuntaje = getInt(&movie[i].puntaje,"Ingrese el nuevo puntaje: ","Rango valido [0 - 100]",0,100);
                        }
                        while(validaPuntaje == -1);
                        flag=1;
                        break;
                    case '7':
                        do{
                            validaLink = validaLargo(movie[i].linkImagen,"Ingrese el nuevo Link de Imagen: ","El largo debe ser entre 2 y 100",2,500);
                        }
                        while(validaLink == -1);
                        flag=1;
                        break;
                    case '8':
                        flag2 = 1;
                        seguir = 'n';
                        break;
                    default:
                        printf("Opcion invalida\n");
                        flag2 = 1;
                        break;
                }
                if(flag == 1)
                {
                    printf("\nEl registro fue actualizado con exito.\n");
                    getch();
                }
                printf("Desea cambiar otro dato? S/N\n");
                seguir = tolower(getche());
                system("cls");
            }
            break;
        }
	}
	if(flag == 0 && flag2 == 0)
	{
		printf("Codigo inexistente");
		getch();
	}
}

int cargarDesdeArchivo(EMovie *x)
{
	int flag = 0;
	FILE *f;

	f=fopen("lista.dat", "rb");
	if(f==NULL)
	{
		f= fopen("lista.dat", "wb");
		if(f==NULL)
		{
			return 1;
		}
		flag=1;
	}
	if(flag ==0)
	{
	fread(x,sizeof(EMovie),A,f);
    }
	fclose(f);
	return 0;
}

int guardarEnArchivo(EMovie * x)
{

	FILE *f;

		f=fopen("lista.dat","wb");
		if(f == NULL)
		{
			return 1;
		}

	fwrite(x,sizeof(EMovie),A,f);

	fclose(f);

	return 0;
}

void generarPagina(EMovie *movie)
{
     int i;
     FILE *f;
     char nombre[20];
     printf("Ingrese nombre de pagina a generar: \n");
     scanf("%s", nombre);
     strcat(nombre, ".html");
     f=fopen(nombre, "w");
     if(f == NULL)
     {
          printf("No se pudo abrir el archivo\n");
     }
     else
     {
         generaCabeza(f);
         for(i=0; i<A; i++)
         {
            if(movie[i].codigo != 0)
            {
                generaCuerpo(f, movie + i);
            }
         }
         generaPie(f);
      }
      fclose(f);
      printf("Pagina creada con exito\n");
      system("pause");
}

void generaCabeza(FILE *pagina)
{
    fprintf(pagina, "<!DOCTYPE html>\n<!-- Template by Quackit.com -->\n<html lang='en'>\n<head>\n    <meta charset='utf-8'>\n");
    fprintf(pagina, "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n    <meta name='viewport' content='width=device-width, initial-scale=1'>\n");
    fprintf(pagina, "    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n");
    fprintf(pagina, "    <title>Lista peliculas</title>\n    <!-- Bootstrap Core CSS -->\n    <link href='css/bootstrap.min.css' rel='stylesheet'>\n");
    fprintf(pagina, "    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n");
    fprintf(pagina, "    <link href='css/custom.css' rel='stylesheet'>\n    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n");
    fprintf(pagina, "    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n    <!--[if lt IE 9]>\n");
    fprintf(pagina, "        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n");
    fprintf(pagina, "    <![endif]-->\n</head>\n<body>\n    <div class='container'>\n        <div class='row'>\n\n		\n			<!-- Repetir esto para cada pelicula -->\n");
}

void generaCuerpo(FILE *pagina, EMovie *movie)
{
      fprintf(pagina, "            <article class='col-md-4 article-intro'>\n                <a href='#'>\n");
      fprintf(pagina, "                    <img class='img-responsive img-rounded' src='%s' alt=''>\n", movie->linkImagen);
      fprintf(pagina, "                </a>\n                <h3>\n                    <a href='#'>%s</a>\n", movie->titulo);
      fprintf(pagina, "                </h3>\n				<ul>\n					<li>Género:%s</li>\n", movie->genero);
      fprintf(pagina, "					<li>Puntaje:%d</li>\n					<li>Duración:%d</li>					\n", movie->puntaje, movie->duracion);
      fprintf(pagina, "				</ul>\n                <p>%s</p>\n            </article>\n", movie->descripcion);
}

void generaPie(FILE *pagina)
{
    fprintf(pagina, "			<!-- Repetir esto para cada pelicula -->\n			\n        </div>\n        <!-- /.row -->\n    </div>\n");
    fprintf(pagina, "    <!-- /.container -->\n    <!-- jQuery -->\n    <script src='js/jquery-1.11.3.min.js'></script>\n    <!-- Bootstrap Core JavaScript -->\n");
    fprintf(pagina, "    <script src='js/bootstrap.min.js'></script>\n	<!-- IE10 viewport bug workaround -->\n	<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
    fprintf(pagina, "	<!-- Placeholder Images -->\n	<script src='js/holder.min.js'></script>\n</body>\n</html>\n");
}


