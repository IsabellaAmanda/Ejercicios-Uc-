#include <stdio.h>

// Cuerpo principal
int main()
{
    // File
    FILE *c, *cum;

    // Aperturas de los archivos
    c = fopen("consecutivos.txt", "r");
    cum = fopen("sii.txt", "w");

    // Entradas, variables de control y salidas

    int encontrado, cumple;
    int penultimo;
    char car;

    // Validacion
    if (c == NULL)
    {
        printf("Error\n");
    }
    else
    {

        // Reseteo
        penultimo = EOF;
        encontrado = 1;
        cumple = 0;

        while ((car = fgetc(c)) != EOF)
        {
            /* code */
            if (car == '\n')
            {
                if (cumple == 1)
                {
                    fprintf(cum, "Tiene 3 caracteres consecutivos\n");
                }
                else
                {
                    fprintf(cum, "No tiene 3 caracteres consecutivos\n");
                }
                encontrado = 1;
                penultimo = EOF;
                cumple = 0;
            }
            else
            {

                if (car == penultimo && penultimo != EOF)
                {
                    encontrado++;

                    if (encontrado == 3)
                    {
                        cumple = 1;
                    }
                }
                else
                {

                    encontrado = 1;
                }
                penultimo = car;
            }
        }

        if (penultimo != EOF)
        {
            if (cumple == 1)
            {
                fprintf(cum, "Tiene 3 caracteres consecutivos\n");
            }
            else
            {
                fprintf(cum, "No tiene 3 caracteres consecutivos\n");
            }
        }
    }

    fclose(c);
    fclose(cum);

    return 0;
}