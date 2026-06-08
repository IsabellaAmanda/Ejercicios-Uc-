#include <stdio.h>
#include <string.h>

// cuerpo principal
int main()
{

    // Entrada
    float price_product;
    char trabajador[50];
    int diseng = 2, band = 1;

    // salidas
    float disenador, fabricante, distribuidor;

    // Ingresar datos

    printf("\nQuiere determinar la ganancia de los trabajadores (1-si/0-no)?: ");
    scanf("%d", &band);

    printf("\nIngrese el costo del producto: ");
    scanf("%f", &price_product);

    printf("\nIngrese el cargo del trabajador(diseñador,fabricante,distribuidor): ");
    scanf(" %[^\n]", trabajador);

    while (band)
    {
        // Reiniciar bandera
        band = 0;
        // Calcular ganancias
        if (strcmp(trabajador, "diseñador") == 0)
        {
            disenador = price_product * 0.25;
            printf("\nGanancias de los %d diseñadores: %.2f\n", diseng, disenador);
        }
        else if (strcmp(trabajador, "fabricante") == 0)
        {
            fabricante = price_product * 0.30;
            printf("\nGanancias fabricante: %.2f\n", fabricante);
        }
        else if (strcmp(trabajador, "distribuidor") == 0)
        {
            distribuidor = price_product * 0.20;
            printf("\nGanancias distribuidor: %.2f\n", distribuidor);
        }

        printf("\nQuiere determinar la ganancia de %s (1-si/0-no): ", trabajador);
        scanf("%d", &band);
        if (!band)
        {
            break;
        }
        else
        {
            printf("\nIngrese el costo del producto: ");
            scanf("%f", &price_product);

            printf("\nIngrese el cargo del trabajador(diseñador,fabricante,distribuidor): ");
            scanf(" %[^\n]", trabajador);
        }
    }

    return 0;
}

/*
 disenador = price_product * 0.25;
fabricante = price_product * 0.30;
distribuidor = price_product * 0.20;

// Salida
printf("\nGanancias diseñadores: %.2f\n", disenador);
printf("\nGanancias fabricante: %.2f\n", fabricante);
printf("\nGanancias distribuidor: %.2f\n", distribuidor);
*/

/*
 *Funcion del programa
 *Calcular las ganacias de un grupo de trabajadores
 *Entrada:
 * 2 diseñadores, 1 fabricante, 1 Distribuidor
 * Costo del producto
 * Datos de ganancias:
 *Diseñnadores {25% del costo del producto}
 *Fabricante {30% del costo del producto}
 *Distribuidor {20% del costo del producto}
 *Salida:
 *Ganancias de cada trabajador
 */
