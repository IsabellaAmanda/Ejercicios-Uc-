#include <stdio.h>
#include <ctype.h>

// Cuerpo principal
int main()
{
    // Files
    FILE *m, *min;

    // Aperturas de archivos
    m = fopen("mayusculas.txt", "r");
    min = fopen("minusculas.txt", "w");

    // Entradas, varibles de control y salidas
    char car, may;
    int cumple;

    // Validacion
    if (m == NULL)
    {
        printf("Error\n");
    }
    else
    {
        // Reseteo

        while ((car = fgetc(m)) != EOF)
        {

            // Si encontramos salto de linea
            if (car == '\n')
            {

                fprintf(min, "\n");
            }
            else
            {

                if (islower(car))
                {

                    may = toupper(car);
                    fprintf(min, "%c", may);
                }
                else
                {
                    // Si ya esta en mayuscula imprimos el caracter sin cambiar
                    fprintf(min, "%c", car);
                }
            }
        }

        fclose(m);
        fclose(min);
    }
    return 0;
}