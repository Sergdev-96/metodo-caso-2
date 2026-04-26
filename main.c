#include <stdio.h>
#include <stdlib.h>

#define MAX 10

/* Variables globales */
int codigo[MAX];
float precio[MAX];

/* Tipo de estado de la reparacion */
enum TipoEstado {Pendiente, Finalizada};
enum TipoEstado estado[MAX];

char texto[20];
int total = 0;

/* Prototipos */
void menu();
void agregarReparacion();
void eliminarReparacion();
void buscarReparacion();
void listarReparaciones();

int main()
{
    int opcion;

    do
    {
        menu();
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                agregarReparacion();
                break;

            case 2:
                eliminarReparacion();
                break;

            case 3:
                buscarReparacion();
                break;

            case 4:
                listarReparaciones();
                break;

            case 5:
                printf("\nSaliendo del programa...\n");
                break;

            default:
                printf("\nOpcion no valida.\n");
        }

    } while(opcion != 5);

    return 0;
}

/* Mostrar menu principal */
void menu()
{
    printf("\n--- SOLUCIONES AUTOMOTRICES ---\n");
    printf("1. Agregar Reparacion\n");
    printf("2. Eliminar Reparacion\n");
    printf("3. Buscar Reparacion\n");
    printf("4. Listar Reparaciones\n");
    printf("5. Salir\n");
    printf("Seleccione una opcion: ");
}

/* Agregar nueva reparacion */
void agregarReparacion()
{
    if(total < MAX)
    {
        printf("\nIntroduzca codigo: ");
        scanf("%d", &codigo[total]);

        printf("Introduzca precio: ");
        scanf("%s", texto);

        /* Convertimos texto a numero */
        sscanf(texto, "%f", &precio[total]);

        printf("Estado (0 Pendiente / 1 Finalizada): ");
        scanf("%d", &estado[total]);

        total++;

        printf("Reparacion agregada correctamente.\n");
    }
    else
    {
        printf("No hay espacio disponible.\n");
    }
}

/* Eliminar reparacion por codigo */
void eliminarReparacion()
{
    int codigoBuscado;
    int i;

    printf("\nIntroduzca codigo a eliminar: ");
    scanf("%d", &codigoBuscado);

    for(i = 0; i < total; i++)
    {
        if(codigo[i] == codigoBuscado)
        {
            codigo[i] = 0;
            precio[i] = 0;
            estado[i] = Pendiente;

            printf("Reparacion eliminada.\n");
            return;
        }
    }

    printf("Codigo no encontrado.\n");
}

/* Buscar una reparacion */
void buscarReparacion()
{
    int codigoBuscado;
    int i;

    printf("\nIntroduzca codigo a buscar: ");
    scanf("%d", &codigoBuscado);

    for(i = 0; i < total; i++)
    {
        if(codigo[i] == codigoBuscado)
        {
            printf("Codigo: %d\n", codigo[i]);
            printf("Precio: %.2f euros\n", precio[i]);

            if(estado[i] == Pendiente)
                printf("Estado: Pendiente\n");
            else
                printf("Estado: Finalizada\n");

            return;
        }
    }

    printf("Codigo no encontrado.\n");
}

/* Mostrar todas las reparaciones */
void listarReparaciones()
{
    int i;

    if(total == 0)
    {
        printf("\nNo hay reparaciones registradas.\n");
    }
    else
    {
        printf("\n--- LISTADO DE REPARACIONES ---\n");

        for(i = 0; i < total; i++)
        {
            if(codigo[i] != 0)
            {
                printf("Codigo: %d\n", codigo[i]);
                printf("Precio: %.2f euros\n", precio[i]);

                if(estado[i] == Pendiente)
                    printf("Estado: Pendiente\n");
                else
                    printf("Estado: Finalizada\n");

                printf("----------------------\n");
            }
        }
    }
}
