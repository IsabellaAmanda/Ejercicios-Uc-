#include <stdio.h>

// Cuerpo principal

int main()
{

    // File
    FILE *ent, *sal;

    // Aperturas de archivos
    ent = fopen("encontrado.txt", "r");
    sal = fopen("te_encontre.txt", "w");

    // Entradas
    char c;
    int penultimo, ultimo;

    // Validacion

    if (ent == NULL)
    {
        printf("Error\n");
    }
    else
    {

        // Reseteo
        penultimo = EOF;
        ultimo = EOF;
        // Ciclo de control

        while ((c = fgetc(ent)) != EOF)
        {
            /* code */
            if (c == '\n')
            {

                if (penultimo != EOF)
                {
                    fprintf(sal, "%c\n", penultimo);
                }
                else
                {
                    fprintf(sal, "INVALIDO");
                }
                penultimo = EOF;
                ultimo = EOF;
            }
            else
            {
                penultimo = ultimo;
                ultimo = c;
            }
        }

        if (ultimo != EOF)
        {
            if (penultimo != EOF)
            {
                fprintf(sal, "%c\n", penultimo);
            }
            else
            {
                fprintf(sal, "INVALIDO");
            }
        }
    }

    fclose(ent);
    fclose(sal);
}
