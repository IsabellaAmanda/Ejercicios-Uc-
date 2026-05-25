/*
 * api.c
 *Funciones del programa llevar las estadisticas de la materia API
 *calcular estas estadisticas:
 *prom de notas por alumnos de n parciales
 *name del alumnno con mayor nota
 *name del alumno con menor nota
 *Prom de la materia en general
 */

#include <stdio.h>
#include <string.h>

// cuerpo principal del programa
int main()
{
    // entrda de datos
    int n, i;
    char name[50], name_max[50], name_min[50];
    float nota, nota_max = -1, nota_min = 999, acum, prom, prom_alumnos = 0, suma = 0;
    int band = 0, total = 0;

    // preguntar si hay alumnos para ingresar
    printf("\nHay alumnos para ingresar? (1-si, 0-no): ");
    if (scanf("%d", &band) != 1)
        printf("Error\n");
    printf("\nIngrese la cantidad de parciales para cada alumno: ");
    if (scanf("%d", &n) != 1)
        printf("Error\n");

    // ciclo de control principal del programa
    while (band)
    {

        total++;

        printf("\nIngrese el nombre del alumno: ");
        if (scanf(" %s", name) != 1)
            printf("Error\n");
        acum = 0; // reiniciar acumulador para cada alumno
        for (i = 0; i < n; i++)
        {
            // ingresar nota del alumno

            printf("Ingrese la nota del alumno: ");
            if (scanf("%f", &nota) != 1)
                printf("Error\n");

            acum += nota;
        }

        // calcular prom por alumno
        prom_alumnos = acum / n;
        suma += prom_alumnos;
        printf("\nPromedio del alumno %s: %.2f\n", name, prom_alumnos);

        // calcula prom con la mayor nota
        if (prom_alumnos > nota_max)
        {
            nota_max = prom_alumnos;

            // usameos strcpy para copiar el nombre del alumno con la mayor nota
            strcpy(name_max, name);
        }
        // calcula menor nota
        if (prom_alumnos < nota_min)
        {
            nota_min = prom_alumnos;

            // usameos strcpy para copiar el nombre del alumno con la menor nota
            strcpy(name_min, name);
        }

        printf("\nHay alumnos para ingresar? (1-si, 0-no): ");
        if (scanf("%d", &band) != 1)
            printf("Error\n");
    }

    // promedio de la materia en general
    if (total > 0)
    {
        prom = suma / total;
        printf("\nMayor nota: %.2f, Alumno: %s\n", nota_max, name_max);
        printf("\nMenor nota: %.2f, Alumno: %s\n", nota_min, name_min);
        printf("\nPromedio de la materia API: %.2f\n", prom);
    }
    else
    {
        printf("\nNo se ingresaron alumnos\n");
    }

    return 0;
}