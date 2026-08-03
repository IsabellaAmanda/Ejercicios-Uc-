#include <stdio.h>

// Cuerpo principal
int main()
{

    // Files
    FILE *n, *inv;

    // Aperturas de archivos
    n = fopen("caract.txt", "r");
    inv = fopen("inv.txt", "w");

    // Entradas,variables de control y salidas
    int num, cont_lineas;

    // Validacion
    if (n == NULL)
    {
        printf("Error\n");
    }
    else
    {

        // Reseteo
        cont_lineas = 0;
        // Ciclo para contar la cantidad de lineas
        while (fscanf(n, "%d", &num) == 1)
        {
            cont_lineas++;
        }

        printf("Cont : %d\n", cont_lineas);
        // Ciclo de control para imprimir del ultimo al primer num
        for (int i = cont_lineas; i > 0; i--)
        {
            rewind(n);
            for (int j = 1; j <= i; j++)
            {

                // Imprimimos el numero
                // Del ultimo al primero
                fscanf(n, "%d", &num);
            }
            fprintf(inv, "%d\n", num);
            printf("%d\n", num);
        }

        // Cerramos los archivos
        fclose(n);
        fclose(inv);
    }
    return 0;
}