#include "empleados.h"

int menuDeOpciones(char mensaje[],int primeraOpcion, int ultimaOpcion)
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);
    while(opcion>ultimaOpcion||opcion<primeraOpcion)
        {
        printf("\nOPCION INEXISTENTE.\n\nVuelva a elegir una opcion: ");
        scanf("%d", &opcion);
        }

    return opcion;
}

void inicializarEmpleados(eEmpleado lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado = LIBRE;
    }
}

void hardcodearDatosEmpleados(eEmpleado lista[], int tam)
{
    int i;
    int IDs[]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    char nombres[][51]= {"Marcos","Maria","Carlos","Pedro","Diego","Mateo","Ivan","Yoel","David","Jose","Juan","Maximiliano","Bruno","Rafael","Carla"};
    char apellidos[][51]= {"Montana","Rodriguez","Montaner","Casares","Ongania","Palacios","Sentado","Abad","Luna","Lopez","Gomez","Perez","Diaz","Nadal","Sandri"};
    float sueldos[]= {22000,22000,15000,4000,21000,6000,20000,50000,10000,5000,30000,8000,9000,13000,25000};
    int sector[]={1,2,3,1,2,2,1,3,3,3,2,2,1,1,3};

    for(i=0; i<tam; i++)
    {
        lista[i].id = IDs[i];
        strcpy(lista[i].nombre, nombres[i]);
        strcpy(lista[i].apellido, apellidos[i]);
        lista[i].sueldo = sueldos[i];
        lista[i].estado = OCUPADO;
        lista[i].idSector = sector[i];
    }
}

void hardcodearSectores(eSector sectores[],int tam)
{
    int i;
    int idSectores[]={1,2,3};
    char descripcionSectores[][20]={" Contabilidad ","   Sistemas   ","     RRHH     "};
    float valorSectores[]={100,200,150};


    for(i=0; i<tam; i++)
    {
        sectores[i].idSector=idSectores[i];
        strcpy(sectores[i].descripcion,descripcionSectores[i]);
        sectores[i].valor=valorSectores[i];
    }
}

int buscarLibre(eEmpleado lista[], int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int idAutoIncremental(eEmpleado lista[], int tam)
{
    int retorno = 0;
    int i;
    if(tam > 0 && lista != NULL)
    {
        for(i=0; i<tam; i++)
        {
            if(lista[i].estado == 1)
            {
                if(lista[i].id > retorno)
                {
                    retorno = lista[i].id;
                }
            }
        }
    }
    return retorno+1;
}

void cargarEmpleado(eEmpleado lista[],eSector sectores[], int tam, int ts)
{
    int i;

    i = buscarLibre(lista, tam);

    if(i!=-1)
    {
        pedirCadena("nombre",lista[i].nombre,50);
        pedirCadena("apellido",lista[i].apellido,50);
        printf("Ingrese salario: $");
        scanf("%f",&lista[i].sueldo);
        printf("\n");
        mostrarSectores(sectores,3);
        printf("Ingrese sector:");
        scanf("%d",&lista[i].idSector);
        lista[i].id=idAutoIncremental(lista,tam);
        lista[i].estado=OCUPADO;
        system("cls");
        printf("\n\n::::::::::::::::::::::::::::\n");
        printf(" EMPLEADO CARGADO CON EXITO\n");
        printf("::::::::::::::::::::::::::::\n\n");
        system("pause");
        system("cls");
    }
    else
    {
        printf("No hay espacio");
    }
}

int buscarEmpleado(eEmpleado empleado[], int tam, int id)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(empleado[i].estado==OCUPADO && empleado[i].id== id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void borrarEmpleado(eEmpleado lista[], int tam, int ID)
{

    int i;
    int loEncontro = 0;
    int aux;
    printf("Ingrese ID del empleado a dar de baja: ");
    scanf("%d", &ID);

    for(i=0; i<tam; i++)
    {
        if(ID == lista[i].id&&lista[i].estado==OCUPADO)
        {

            printf("\n");
            aux=pedirEntero(":\n1.CONTINUAR.\n2.CANCELAR.\n\nSu opcion",1,2);
            if(aux==1)
            {
                lista[i].estado = LIBRE;
                system("cls");
                printf("\n\n::::::::::::::::::::::::::\n");
                printf("EMPLEADO BORRADO CON EXITO\n");
                printf("::::::::::::::::::::::::::\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                printf("\n\n::::::::::::::::::::::::::\n");
                printf("BORRAR EMPLEADO CANCELADO\n");
                printf("::::::::::::::::::::::::::\n\n");
                system("pause");
                system("cls");
            }

            loEncontro = 1;
            break;//modifcar
        }
    }


    if(loEncontro==0)
    {
        system("cls");
        printf("\n\n:::::::::::::::::::::::::::::\n");
        printf("NO EXISTE EMPLEADO CON TAL ID\n");
        printf(":::::::::::::::::::::::::::::\n\n");
        system("pause");
        system("cls");
    }

}

void modificar(eEmpleado lista[], int tam,eSector sectores[],int ts)
{

    int i;
    int ID;
    char auxCadena[51];
    int auxEntero;
    int auxSector;
    float auxFlotante=0;
    int loEncontro = 0;
    int opcion;

    printf("\nIngrese ID del empleado a modificar: ");
    scanf("%d", &ID);

    for(i=0; i<tam; i++)
    {
        if(ID == lista[i].id&&lista[i].estado==OCUPADO)
        {
            printf("\n");
            opcion=pedirEntero("alguna de las siguientes opciones:\n\n1.Modificar nombre.\n2.Modificar apellido.\n3.Modificar salario.\n4.Modificar sector.\n\nSu opcion",1,4);
            switch(opcion)
            {
            case 1:
                printf("\n");
                pedirCadena("nuevo nombre",auxCadena,50);
                printf("\n");
                auxEntero=pedirEntero(":\n1.PARA CONTINUAR.\n2.PARA CANCELAR.\n\nSu opcion",1,2);
                if(auxEntero==1)
                {
                    system("cls");
                    strcpy(lista[i].nombre,auxCadena);
                    printf("\n\n:::::::::::::::::::::::::::");
                    printf("\nNOMBRE MODIFICADO CON EXITO");
                    printf("\n:::::::::::::::::::::::::::\n\n");
                }
                else
                {
                    printf("\n\n:::::::::::::::::::::::::::");
                    printf("\nMODIFICACION CANCELADA");
                    printf("\n:::::::::::::::::::::::::::\n\n");
                }
                break;

            case 2:

                printf("\n");
                pedirCadena("nuevo apellido",auxCadena,50);
                printf("\n");
                auxEntero=pedirEntero(":\n1.PARA CONTINUAR.\n2.PARA CANCELAR.\n\nSu opcion",1,2);
                if(auxEntero==1)
                {
                    system("cls");
                    strcpy(lista[i].apellido,auxCadena);
                    printf("\n\n:::::::::::::::::::::::::::::");
                    printf("\nAPELLIDO MODIFICADO CON EXITO");
                    printf("\n:::::::::::::::::::::::::::::\n\n");
                }
                else
                {
                    printf("\n\n:::::::::::::::::::::::::::");
                    printf("\nMODIFICACION CANCELADA");
                    printf("\n:::::::::::::::::::::::::::\n\n");
                }
                break;

            case 3:
                printf("\n");
                pedirFlotante("nuevo salario: $",auxFlotante);
                printf("\n");
                auxEntero=pedirEntero(":\n1.PARA CONTINUAR.\n2.PARA CANCELAR.\n\nSu opcion",1,2);
                if(auxEntero==1)
                {
                    system("cls");
                    lista[i].sueldo=auxFlotante;
                    printf("\n\n:::::::::::::::::::::::::::::");
                    printf("\nSUELDO MODIFICADO CON EXITO");
                    printf("\n:::::::::::::::::::::::::::::\n\n");
                }
                else
                {
                    printf("\n\n:::::::::::::::::::::::::::");
                    printf("\nMODIFICACION CANCELADA");
                    printf("\n:::::::::::::::::::::::::::\n\n");
                }
                break;

            case 4:
                mostrarSectores(sectores,ts);
                printf("\n");
                auxSector=pedirEntero("nuevo sector",1,3);
                printf("\n");
                auxEntero=pedirEntero(":\n1.PARA CONTINUAR.\n2.PARA CANCELAR.\n\nSu opcion",1,2);
                if(auxEntero==1)
                {
                    system("cls");
                    lista[i].idSector=auxSector;
                    printf("\n\n:::::::::::::::::::::::::::::");
                    printf("\nSUELDO MODIFICADO CON EXITO");
                    printf("\n:::::::::::::::::::::::::::::\n\n");
                }
                else
                {
                    printf("\n\n:::::::::::::::::::::::::::");
                    printf("\nMODIFICACION CANCELADA");
                    printf("\n:::::::::::::::::::::::::::\n\n");
                }
            }

            loEncontro = 1;

            break;
        }

    }
    if(loEncontro==0)
    {
        system("cls");
        printf("\n\n:::::::::::::::::::::::::::::\n");
        printf("NO EXISTE EMPLEADO CON TAL ID\n");
        printf(":::::::::::::::::::::::::::::\n\n");
    }
}

void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int ts)
{

    char descripcionSector[20];
    int i;

    for(i=0; i<ts; i++)
    {
        if(unEmpleado.idSector==sectores[i].idSector)
        {
            strcpy(descripcionSector, sectores[i].descripcion);
            break;
        }
    }

    printf("%4d %15s %15s    $%10.2f  %15s\n", unEmpleado.id,unEmpleado.apellido, unEmpleado.nombre, unEmpleado.sueldo,descripcionSector);

}

void mostrarListaEmpleados(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    int i;
    printf("\n   ID\t    APELLIDO\t      NOMBRE\t     SUELDO\t   SECTOR\n\n");
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            mostrarEmpleado(lista[i], sectores, ts);
        }

    }
}

void mostrarSectores(eSector sectores[], int ts)
{
int i;
for(i=0;i<ts;i++)
    {
        printf("%d.\t%s\n",sectores[i].idSector,sectores[i].descripcion);
    }
}

void ordenarEmpleadosPorId(eEmpleado lista[],int tam)
{
    int i;
    int j;

    eEmpleado auxiliar;

    for(i=0; i<tam-1; i++)
   {
       for(j=i+1; j<tam; j++)
       {
            if(lista[i].id>lista[j].id)
            {
                auxiliar=lista[i];
                lista[i]=lista[j];
                lista[j]=auxiliar;
            }
        }
    }
}

void ordenarEmpleadosPorApellido(eEmpleado lista[],int tam)
{
    int i;
    int j;

    eEmpleado auxiliar;

    for(i=0; i<tam-1; i++)
   {
       for(j=i+1; j<tam; j++)
       {
            if(strcmp(lista[i].apellido,lista[j].apellido)>0)
            {
                auxiliar=lista[i];
                lista[i]=lista[j];
                lista[j]=auxiliar;
            }
        }
    }
}

void mostrarOrdenadoPorSector(eEmpleado empleados[], int tam, eSector sectores[], int ts)
{

    system("cls");
    printf("\n   ID\t    APELLIDO\t      NOMBRE\t     SUELDO\t   SECTOR\n\n");

    for(int i=0; i <ts; i++)
    {
        for(int j=0; j < tam; j++)
        {
            if( (empleados[j].idSector == sectores[i].idSector) && (empleados[j].estado==OCUPADO))
            {
                mostrarEmpleado(empleados[j], sectores,ts);
            }
        }
        printf("\n");
    }
}

float acumuladorSalario(eEmpleado lista[],int tam)
 {
     int i;
     float acumulador=0;

     for(i=0;i<tam;i++)
     {
        if(lista[i].estado==OCUPADO)
        {
            acumulador=lista[i].sueldo+acumulador;
        }
     }
     return acumulador;
 }

float promedioSalario(eEmpleado lista[],int tam)
{
    int i;
    int contador=0;
    int promedio;
    int total;

    total=acumuladorSalario(lista,tam);

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            contador++;
        }
    }
    promedio=total/contador;

    return promedio;

}

void mostrarEmpleadosSuperadoresDelPromedio(eEmpleado lista[],int tam,eSector sectores[], int ts)
{
    int i;
    float promedio;
    float total;
    int contador;

    promedio=promedioSalario(lista, tam);
    total=acumuladorSalario(lista,tam);

    for(i=0; i<tam; i++)
    {
        if(lista[i].sueldo>promedio&&lista[i].estado==OCUPADO)
        {
            contador++;
        }
    }

    printf("\nEl total acumulado de salarios es $%.2f.\n\nEl promedio de salarios es $%.2f.\n\n%d EMPLEADOS SUPERAN EL PROMEDIO: \n",total,promedio,contador);
    printf("\n   ID\t    APELLIDO\t      NOMBRE\t     SUELDO\t   SECTOR\n\n");
    for(i=0; i<tam; i++)
    {
        if(lista[i].sueldo>promedio&&lista[i].estado==OCUPADO)
        {

            mostrarEmpleado(lista[i],sectores,ts);
        }
    }
}

