#include <stdio.h>
#define N 50
/*
    Funcion de Programa:
    *Tomar en cuenta que fin de archivo es un cero
*/

// Cuerpo principal
int main()
{
    // Files
    FILE *personas, *mayores, *mujeres, *hombres;

    // Aperturas de archivos
    personas = fopen("personas.txt", "r");
    mayores = fopen("mayores.txt", "w");
    hombres = fopen("hombres.txt", "w");
    mujeres = fopen("mujeres.txt", "w");

    // Entradas
    int cedula, edad, provincia;
    char sexo;
    char name[N];

    // Variables de control y salidas
    int men, women, total;

    float promedio, suma_edades;

    // Validación
    if (personas == NULL)
    {
        printf("Error\n");
    }
    else
    {

        // Reseteo
        men = 0;
        women = 0;
        total = 0;
        suma_edades = 0;

        while (fscanf(personas, "%d", &cedula) != EOF)
        {
            if (cedula == 0)
            {
                break;
            }
            // Leer los datos

            fscanf(personas, "\n");
            fscanf(personas, "%49[^\n]", name);
            fscanf(personas, "%d", &edad);
            fscanf(personas, " %c", &sexo);
            fscanf(personas, "%d", &provincia);

            total++;
            suma_edades += edad;

            if (edad >= 18)
            {
                fprintf(mayores, "%s\n", name);
            }

            if (sexo == 'M')
            {
                women++;
                fprintf(mujeres, "%s\n", name);
            }
            else if (sexo == 'H')
            {
                men++;
                fprintf(hombres, "%s\n", name);
            }
        }

        if (men > 0)
        {
            printf("Hombres: %d\n", men);
        }

        if (women > 0)
        {
            printf("Mujeres: %d\n", women);
        }

        if (total > 0)
        {
            promedio = suma_edades / total;
            printf("Promedio de edades: %.2f\n", promedio);
        }
    }

    // Close files
    fclose(personas);
    fclose(mayores);
    fclose(mujeres);
    fclose(hombres);

    return 0;
}