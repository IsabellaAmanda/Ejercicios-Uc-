#include <stdio.h>
#include <string.h>

// Cuerpo principal
int main()
{
    // Files
    FILE *m, *t, *msj;

    // aperturas de archivos
    m = fopen("morse.txt", "r");
    t = fopen("traduc.txt", "r");

    // Entradas
    char morse[20], trans[20], temp[20];
    char letra;
    int encontrado = 0, c;

    // Validacion del archivo

    if (m == NULL || t == NULL)
    {
        printf("Error\n");
    }
    else
    {
        msj = fopen("mensaje.txt", "w");
        // Lectura del archivo a traducir
        while (fscanf(m, "%19s", morse) != EOF)
        {

            rewind(t);
            encontrado = 0;

            if (strcmp(morse, "-..-.-") == 0)
            {
                fprintf(msj, " ");
                printf(" ");

                encontrado = 1;
            }
            else if (strcmp(morse, ".-.-.-") == 0)
            {
                fprintf(msj, ".");
                printf(".");

                encontrado = 1;
            }

            while (!encontrado && fscanf(t, "%s %s", temp, trans) != EOF)
            {
                if (strcmp(morse, trans) == 0)
                {
                    letra = temp[0];
                    fprintf(msj, "%c", letra);
                    printf("%c", letra);
                    encontrado = 1;
                }
            }

            // --- DETECCIÓN EXACTA DEL SALTO DE LÍNEA ---
            // Leemos los espacios/saltos inmediatos en morse.txt
            while ((c = fgetc(m)) != EOF)
            {
                if (c == '\n')
                {
                    fprintf(msj, "\n");
                    printf("\n");
                    break;
                }
                else if (c != ' ' && c != '\r' && c != '\t')
                {
                    // Si encontramos el inicio del siguiente token Morse, lo devolvemos al flujo de lectura
                    ungetc(c, m);
                    break;
                }
            }
        }
    }

    fclose(m);
    fclose(t);
    fclose(msj);
    return 0;
}
