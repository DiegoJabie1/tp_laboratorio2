#include <stdlib.h>
#include "empleados.h"
#include "string.h"
#define T 1000
#define TS 3

int main()
{
    int opcion;
    int opcionAux;

    eEmpleado lista[T];
    inicializarEmpleados(lista,T);
    eSector sectores[TS];

    hardcodearDatosEmpleados(lista,15);
    hardcodearSectores(sectores,TS);


    do
    {
        printf("--DIEGO EMPLEADOS--\n");
        opcion = menuDeOpciones("\n  MENU\n\n1. Alta.\n2. Modificacion.\n3. Baja\n4. Informar.\n5. Salir.\n\nElija una opcion: ",1,5);
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("\n1.MENU DE ALTA\n\n");
            cargarEmpleado(lista, sectores,  T, TS);
            break;

        case 2:
            system("cls");
            printf("\n2.MENU DE MODIFICACION\n\n");
            ordenarEmpleadosPorId(lista,T);
            mostrarListaEmpleados(lista,T,sectores,TS);
            modificar(lista, T, sectores,TS);
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            printf("\n3.MENU DE BAJA\n\n");
            ordenarEmpleadosPorId(lista,T);
            mostrarListaEmpleados(lista,T,sectores,TS);
            printf("\n");
            borrarEmpleado(lista, T, TS);
            break;

        case 4:
            system("cls");
            printf("\n4.MENU DE INFORMES\n\n");
            opcionAux=pedirEntero("opcion:\n\n1. Listado de los empleados ordenados alfabeticamente por apellido y sector.\n2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n\nSu opcion",1,2);
            if(opcionAux==1)
                {
                ordenarEmpleadosPorApellido(lista,T);
                mostrarOrdenadoPorSector(lista,T,sectores,TS);
                printf("\n\n");
                system("pause");
                system("cls");
                }
            else
                {
                mostrarEmpleadosSuperadoresDelPromedio(lista,T,sectores,TS);
                printf("\n\n");
                system("pause");
                system("cls");
                }
            break;

        }
    }
    while(opcion!=5);

    system("cls");
    printf("\n\n::::::::::::::::::::::::::::\n");
    printf("USTED HA SALIDO DEL PROGRAMA.");
    printf("\n::::::::::::::::::::::::::::\n\n");
    system("pause");

    return 0;
}
