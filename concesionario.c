#include <stdio.h>

// Cuerpo prinicipal
int main()
{
    // Files
    FILE *concesionario, *comision;

    // Open files
    concesionario = fopen("concesionario.txt", "r");
    comision = fopen("comision.txt", "w");

    // Entradas
    int tipo;
    float precio, venta = 0.0;

    // VaLidacion de los archivos
    if (concesionario == NULL)
    {
        printf("Error\n");
    }
    else
    {
        // Ciclo hasta fin de archivo
        while (fscanf(concesionario, "%d %f", &tipo, &precio) == 2)
        {

            if (tipo == 1)
            {
                venta = precio * 0.05;
                if (venta >= 5000.00)
                {
                    venta = 5000.00;
                }
                else
                {
                    venta = precio * 0.05;
                }
            }
            else if (tipo == 2)
            {
                venta = precio * 0.07;

                if (venta <= 700)
                {
                    venta = 700.00;
                }
                else
                {
                    venta = precio * 0.07;
                }
            }

            // salida
            fprintf(comision, "%.2f\n", venta);
            printf("%.2f\n", venta);
        }

        fclose(concesionario);
        fclose(comision);
    }
    return 0;
}