#include <stdio.h>

// Cuerpo principal

int main()
{
    // Files
    FILE *venta, *promedios;

    // Aperturas de archivos
    venta = fopen("ventas.txt", "r");
    promedios = fopen("promedios.txt", "w");

    // Entradas
    int n, m;
    float sale, sum_sale, prom = 0.0;

    // Validacion del archivo
    if (venta == NULL)
    {
        printf("No existe el archivo.\n");
    }
    else
    {
        // Leer la cantidad dias

        fscanf(venta, "%d", &n);
        for (int i = 1; i <= n; i++)
        {

            // Recetear
            sum_sale = 0;
            // Leemos la cantidad de ventas por dia
            fscanf(venta, "%d", &m);
            for (int j = 1; j <= m; j++)
            {
                // Leer cada una
                fscanf(venta, "%f", &sale);
                sum_sale += sale;
            }

            // Calculo de promedio
            prom = sum_sale / m;
            fprintf(promedios, "Dia %d: %.2f\n", i, prom);
            printf("Dia %d: %.2f\n", i, prom);
        }

        // Cerrar files
        fclose(venta);
        fclose(promedios);
    }

    return 0;
}
