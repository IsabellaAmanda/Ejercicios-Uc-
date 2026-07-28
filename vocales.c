#include <stdio.h>
#include <ctype.h>

// Cuerpo principal
int main()
{

    // Files
    FILE *p, *v;

    // Aperturas
    p = fopen("palabras.txt", "r");
    v = fopen("vocales.txt", "w");

    // Entradas, variables de control y salidas
    char vowels;
    int cont;

    // validacion
    if (p == NULL)
    {
        printf("Error\n");
    }
    else
    {

        cont = 0;
        // Ciclo de control
        while ((vowels = fgetc(p)))
        {
            char jose = tolower(vowels);
            if (vowels == '\n')
            {
                fprintf(v, "%d\n", cont);
                printf("%d\n", cont);
                cont = 0;
            }
            else
            {
                if (jose == 'a' || jose == 'e' || jose == 'i' || jose == 'o' || jose == 'u')
                {
                    cont++;
                }
                else if (vowels == EOF)
                {
                    fprintf(v, "%d\n", cont);
                    printf("%d\n", cont);
                    break;
                }
            }
        }

        fclose(p);
        fclose(v);
    }

    return 0;
}