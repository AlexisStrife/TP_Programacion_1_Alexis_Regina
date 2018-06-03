#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    int codigo;
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[100];
    int puntaje;
    char linkImagen[500];
}EMovie;

/**
 *  Imprime el menu principal
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna la opcion ingresada por teclado
 */
char menu(void);

/**
 *  Busca el indice de un lugar libre en la estructura
 *  @param movie la estructura a ser buscada
 *  @return retorna el indice que esta libre o -1 si no hay lugar
 */
int buscarLibre(EMovie *movie);

/**
 *  Agrega una pelicula a la estructura de peliculas
 *  @param movie la pelicula a ser agregada a la estructura
 */
void agregarPelicula(EMovie *movie);

/**
 *  Imprime la lista de peliculas actualmente cargadas
 *  @param movie las peliculas actuales
 */
void toString(EMovie* movie);

/**
 *  Borra una pelicula de la estructura
 *  @param movie la pelicula a ser eliminada de la estructura
 */
void borrarPelicula(EMovie *movie);

/**
 *  Modifica una pelicula de la estructura
 *  @param movie la pelicula a ser modificada de la estructura
 */
void modificarPelicula(EMovie *movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie *movie);

/**
 *  Carga los datos actuales en el archivo en la variable alumno
 *  @param movie estructura en la cual se almacenan los datos del archivo.
 */
int cargarDesdeArchivo(EMovie *x);

/**
 *  Carga los datos actuales en la variable movie en el archivo
 *  @param movie estructura en la cual se almacenan los datos a guardarse en el archivo.
 */
int guardarEnArchivo(EMovie *movie);

/**
 *  Escribe la cabecera de la pagina en el archivo
 *  @param pagina archivo a generarse con la cabecera
 */
void generaCabeza(FILE *pagina);

/**
 *  Escribe el cuerpo de la pagina en el archivo
 *  @param pagina archivo a generarse con el cuerpo
 *  @param movie datos que van a escribirse
 */
void generaCuerpo(FILE *pagina, EMovie *movie);

/**
 *  Escribe el pie de la pagina en el archivo
 *  @param pagina archivo a generarse con el pie
 */
void generaPie(FILE *pagina);

#endif // FUNCIONES_H_INCLUDED
