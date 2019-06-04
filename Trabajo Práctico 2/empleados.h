#include <stdio.h>
#include "string.h"
#include "funciones.h"
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int idSector;
    char descripcion[20];
    float valor;

}eSector;

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    int idSector;
    float sueldo;
    int estado;

} eEmpleado;



/** \brief
 * \param [] char recibe el mensaje a mostrar en el menu
 * \param int la primer opcion posible
 * \param int la ultima opcion posible
 * \return int la opcion elegida
 */
int menuDeOpciones(char [],int ,int);


/** \brief
 * \param eEmpleado[] recibe el array de empleados para inicializarlo
 * \param int recibe el tamaño del array
 */
void inicializarEmpleados(eEmpleado[], int);


/** \brief
 * \param eEmpleado[] recibe el array de empleados
 * \param int recibe el tamaño del array
 *  hardcodea los datos en la estructura
 */
void hardcodearDatosEmpleados(eEmpleado[], int);


/** \brief
 * \param eSector[] recibe el array de sectores
 * \param int recibe el tamaño del array
 * hardcodea los datos en la estructura
 */
void hardcodearSectores(eSector[],int);



/** \brief
 * \param eEmpleado[] recibe el array de empleados
 * \param int recibe el tamaño del array
 * \return int devuelve el indice donde hay un lugar libre
 */
int buscarLibre(eEmpleado[], int);


/** \brief
 * \param eEmpleado[] el array de empleados
 * \param int el tamaño del array
 * \return int el nuevo id del empleado
 */
int idAutoIncremental(eEmpleado[], int);


/** \brief
 * \param eEmpleado[] recibe el array de empleados
 * \param eSector[] recibe el array de sectores
 * \param int el tamaño del array empleados
 * \param int el tamaño del array sectores
 *  permite al usuario cargar los datos de un nuevo empleado
 */
void cargarEmpleado(eEmpleado[],eSector[], int, int);


/** \brief
 * \param empleado[] recibe el array de empleados
 * \param int el tamaño del array de empleados
 * \param int el id que el usuario desea buscar
 * \return int el indice donde se encuentra tal id
 */
int buscarEmpleado(eEmpleado[], int, int);


/** \brief
 * \param eEmpleado[] recibe el array de empleados
 * \param int recibe el tamaño del array
 * \param int el id del empleado a borrar
 * permite borrar un empleado de la lista de manera logica
 */
void borrarEmpleado(eEmpleado[], int, int);


/** \brief
 * \param eEmpleado[] recibe el array de empleados
 * \param int el tamaño del array empleados
 * \param eSector[] recibe el array de los sectores
 * \param int  recibe el tamaño del array de los sectores
 * permite modificar los distintos parametros de un empleado
 */
void modificar(eEmpleado[], int, eSector[],int);


/** \brief
 * \param eEmpleado recibe los datos de un solo empleado
 * \param eSector[] recibe el array de sectores
 * \param int el tamaño del array de sectores
 * permite mostrar los datos de un empleado
 */
void mostrarEmpleado(eEmpleado, eSector[], int);


/** \brief
 * \param eEmpleado[] recibe el array de empleados
 * \param int el tamaño del array empleados
 * \param eSector[] recibe el array de sectores
 * \param int el tamaño del array sectores
 * permite mostrar la lista completa de los empleados
 */
void mostrarListaEmpleados(eEmpleado[], int, eSector[], int);


/** \brief
 * \param eSector[] recibe el array de sectores
 * \param int el tamaño del array sectores
 * permite mostrar los sectores
 */
void mostrarSectores(eSector[],int);


/** \brief
 * \param eEmpleado[] recibe el array de empleados
 * \param int el tamaño del array empleados
 * permite ordenar los empleados segun su id en orden ascendente
 */
void ordenarEmpleadosPorId(eEmpleado[],int);


/** \brief
 * \param eEmpleado[] recibe el array de empleados
 * \param int el tamaño del array empleados
 * permite ordenar la lista de empleados segun el apellido en orden ascendente
 */
void ordenarEmpleadosPorApellido(eEmpleado[],int);


/** \brief
 * \param [] eEmpleado recibe el array de empleados
 * \param int el tamaño del array empleados
 * \param eSector[] recibe el array de sectores
 * \param int el tamaño del array sectores
 * permite mostrar los empleados ordenados por sector
 */
void mostrarOrdenadoPorSector(eEmpleado [], int, eSector[], int);


/** \brief
 * \param eEmpleado[] recibe el array de empleados
 * \param int recibe el tamaño del array empleados
 * \return float devuelve el total acumulado de los salarios de los empleados
 */
float acumuladorSalario(eEmpleado[],int);


/** \brief
 * \param eEmpleado[] recibe el array de empleados
 * \param int recibe el tamaño del array empleados
 * \return float el promedio resultado de los sueldos de los empleados
 */
float promedioSalario(eEmpleado[],int);


/** \brief
 * \param eEmpleado[] recibe el array de empleados
 * \param int recibe el tamaño del array empleados
 * \param eSector[] recibe el array de sectores
 * \param int recibe el tamaño del array sectores
 * muestra el promedio de sueldos, los empleados que superan el promedio y la cantidad de los mismos
 */
void mostrarEmpleadosSuperadoresDelPromedio(eEmpleado[],int,eSector[],int);

