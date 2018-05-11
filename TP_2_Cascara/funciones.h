#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**
 * Estructura de personas ingresadas
 */
typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int cantidad);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int cantidad, long dni);

/**
 * Ingresa un nuevo elemento en la lista
 * @param lista el array se pasa como parametro, int cantidad de elementos en el array.
 */
void alta(EPersona[], int);

/**
 * inhabilita un elemento de la lista
 * @param lista el array se pasa como parametro, int cantidad de elementos en el array.
 */
void baja(EPersona[], int);

/**
 * modifica un elemento de la lista
 * @param lista el array se pasa como parametro, int cantidad de elementos en el array.
 */
void modificar(EPersona[], int);

/**
 * Lista los elementos en la lista
 * @param lista el array se pasa como parametro, int cantidad de elementos en el array.
 */
void listar(EPersona[], int);

/**
 * Ordena los elementos de la lista
 * @param lista el array se pasa como parametro, int cantidad de elementos en el array.
 */
void ordenar(EPersona[], int);

/**
 * inicializa en estado 0(sin datos) todos los elementos de la lista
 * @param lista el array se pasa como parametro, int cantidad de elementos en el array.
 */
void inicializar(EPersona[], int);

/**
 * crea un grafico con las edades de los elementos de la lista
 * @param lista el array se pasa como parametro, int cantidad de elementos en el array.
 */
void listarGrafico(EPersona[], int);

/**
 * ingresa datos hardcodeados en cada elemento de la lista para pruebas
 * @param lista el array se pasa como parametro, int cantidad de elementos en el array.
 */
void hardCode(EPersona per[]);


#endif // FUNCIONES_H_INCLUDED
