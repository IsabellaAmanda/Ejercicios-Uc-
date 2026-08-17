#include <stdio.h>

// Cuerpo principal
int main()
{
    // Files
    FILE *w, *s;

    // Aperturas
    w = fopen("source.txt", "r");
    s = fopen("wrap.txt", "w");

    // Entradas, salidas y variables de control
    char c;
    int cont;

    // Validacion
    if (w == NULL)
    {
        printf("Error\n");
    }
    else
    {
        cont = 0;
        // Recorrer caracter por caracter
        while ((c = fgetc(w)) != EOF)
        {
            // Condicion del salto
            if (c == '\n')
            {
                // Salto de linea original -> Reinicia el párrafo sin sangria
                fputc('\n', s);
                putchar('\n');
                cont = 0;
            }
            else
            {

                cont++;
                if (cont == 80)
                {
                    fprintf(s, "\n    ");
                    printf("\n    ");
                    cont = 4;
                }
                else
                {
                    fprintf(s, "%c", c);
                    printf("%c", c);
                    cont;
                }
            }
        }
        printf("\n");

        fclose(w);
        fclose(s);
    }
    return 0;
}