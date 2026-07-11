#include <stdio.h>

// Cuerpo principal

int main()
{
    // Archivos
    FILE *enteros, *potencias;

    // Open files
    enteros = fopen("enteros.txt", "r");
    potencias = fopen("potencias.txt", "w");

    // Entradas
    int n, m, num;

    // Validar archivos
    if (enteros == NULL)
    {
        printf("Error\n");
    }
    else
    {
        // Leer el primer número n m

        fscanf(enteros, "%d %d", &n, &m);
        for (int k = 1; k <= m; k++)
        {
            fprintf(potencias, "x**%d ", k);
            printf("x**%d ", k);
        }
        fprintf(potencias, "\n");
        printf("\n");

        for (int i = 0; i < n; i++)
        {

            int pot = 1;
            fscanf(enteros, "%d", &num);
            for (int j = 1; j <= m; j++)
            {
                pot *= num;
                fprintf(potencias, "%d ", pot);
                printf("%d ", pot);
            }

            fprintf(potencias, "\n");
            printf("\n");
        }
    }

    fclose(enteros);
    fclose(potencias);

    return 0;
}