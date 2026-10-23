#include <stdio.h>
#include <string.h>
#define M 50
#define Max 50

// Realizar el registro de vehiculos
typedef struct
{
    // Campos
    char marca[M];
    int num_cilindros;
    float precio;
} Vehiculos;

Vehiculos cars[Max];

void cargarDatosVehiculos(int *num)
{
    int i;
    for (i = 0; i < (*num); i++)
    {
        // Eliminar el salto de linea que me genera el scaf
        while (getchar() != '\n')
            ;
        printf("Ingrese la marca del vehículo: ");
        fgets(cars[i].marca, sizeof(cars[i].marca), stdin);
        cars[i].marca[strcspn(cars[i].marca, "\n")] = '\0';
        printf("Ingrese la cantidad de cílindros que tiene el vehículo: ");
        scanf("%d", &cars[i].num_cilindros);
        printf("Ingrese el precio del vehículo: ");
        scanf("%f", &cars[i].precio);
    }
}

void minprecioVehiculo(int n)
{
    int i, idx_min = -1, encontrado = 0;
    float min = 0.0;
    min = cars[0].precio;

    for (i = 0; i < n; i++)
    {

        if (cars[i].num_cilindros >= 6)
        {
            if (!encontrado || cars[i].precio < min)
            {
                min = cars[i].precio;
                idx_min = i;
                encontrado = 1;
            }
        }
    }
    if (encontrado)
    {
        printf("El vehículo con menor precio y que cumple con las reglas de los 6 cílindros es: \n");
        printf("El carro %s|Con menor precio %.2f| Con %d cilindros.\n", cars[idx_min].marca, cars[idx_min].precio, cars[idx_min].num_cilindros);
    }
}

int main()
{
    int tam;
    // validamos el tamaño real
    do
    {
        printf("Ingrese el número de vehiculos a procesar: ");
        scanf("%d", &tam);
    } while (tam < 1 || tam > Max);
    cargarDatosVehiculos(&tam);
    minprecioVehiculo(tam);
    return 0;
}
