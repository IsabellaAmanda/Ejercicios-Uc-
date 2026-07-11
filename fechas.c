#include <stdio.h>
#define ANIO_ACTUAL 2010
#define MES_ACTUAL 05
#define DIA_ACTUAL 27

// Cuerpo principal
int main()
{
    // Files
    FILE *entrada, *salida;

    // Apertura de files
    entrada = fopen("fechas.txt", "r");
    salida = fopen("salida.txt", "w");

    // Entrada
    int dia, mes, anio, n;

    // Variables de control
    // Salida
    int edad;

    // Validar file
    if (entrada == NULL)
    {
        printf("Error\n");
    }
    else
    {
        // Ciclo de control
        fscanf(entrada, "%d", &n);
        for (int i = 0; i < n; i++)
        {
            // Leer las fechas
            fscanf(entrada, "%d %d %d", &dia, &mes, &anio);
            // Calcular edad
            edad = ANIO_ACTUAL - anio;
            if (mes > MES_ACTUAL)
            {
                edad--;
            }
            else if (mes == MES_ACTUAL && dia > DIA_ACTUAL)
            {
                edad--;
            }

            fprintf(salida, "%d\n", edad);
            printf("%d\n", edad);
        }
    }

    // cerrar files
    fclose(entrada);
    fclose(salida);

    return 0;
}