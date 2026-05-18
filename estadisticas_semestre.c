/*
 * estadisticas_semestre.c
 *Programa que calcula el prom de las materias del 1 er semestre de la carrera de computacion
 *por materia calcularÑ
 *promedio de notas
 *aprobados
 *reprobados
 *materia con mayor cantidad de reprobados
 */

#include <stdio.h>

// cuerpo principal

int main()
{

    // definir variables de entrada
    float nota;
    char materia;
    int band = 1;
    int aprobados1 = 0, aprobados2 = 0, aprobados3 = 0, reprobados1 = 0, reprobados2 = 0, reprobados3 = 0, max_reprobados = -1;
    int mat_1 = 0, mat_2 = 0, mat_3 = 0;
    // acumuladores para cada materia
    float acum1 = 0, acum2 = 0, acum3 = 0, total = 0;
    float prom1 = 0.0, prom2 = 0.0, prom3 = 0.0, suma_prom = 0.0;

    // preguntar si hay nota para ingresar de alguna materia
    printf("\nHay una nota ingresada para alguna materia del 1er semestre de computacion: ");
    if (scanf("%d", &band) != 1)
        printf("Error\n");

    // ciclo de control principal del programa
    while (band)
    {
        // pedir la materia y nota

        printf("\nIngrese la materia (E-elementos, C-calculo, D-dhd) y la nota:");
        if (scanf(" %c %f", &materia, &nota) != 2)
            printf("Error\n");

        switch (materia)
        {
        case 'E':
            acum1 += nota;
            mat_1++;
            total++;

            if (nota >= 9.5)
                aprobados1++;
            else
                reprobados1++;
            /* code */
            break;
        case 'C':
            acum2 += nota;
            mat_2++;
            total++;
            if (nota >= 9.5)
                aprobados2++;
            else
                reprobados2++;
            /* code */
            break;
        case 'D':
            acum3 += nota;
            mat_3++;
            total++;

            if (nota >= 9.5)
                aprobados3++;
            else
                reprobados3++;
            /* code */
            break;
        default:
            printf("Materia no encontrada\n");
            break;
        }

        printf("\nHay una nota ingresada para alguna materia del 1er semestre de computacion: ");
        if (scanf("%d", &band) != 1)
            printf("Error\n");
    }

    // calcular mayor cantidad de reprobados
    max_reprobados = reprobados1; // inicializar con el valor de la primera materia
    printf("\nMateria con mayor cantidad de reprobados: ");
    if (reprobados1 > max_reprobados)
    {
        max_reprobados = reprobados1;
        printf("Elementos Discretos : %d\n", max_reprobados);
    }
    if (reprobados2 > max_reprobados)
    {
        max_reprobados = reprobados2;
        printf("Calculo : %d\n", max_reprobados);
    }
    if (reprobados3 > max_reprobados)
    {
        max_reprobados = reprobados3;
        printf("DHD : %d\n", max_reprobados);
    }

    // calcular promedios
    if (mat_1 > 0)
    {
        prom1 = acum1 / mat_1;
        printf("Promedio - Elementos Discretos: %.2f\n", prom1);
    }

    if (mat_2 > 0)
    {
        prom2 = acum2 / mat_2;
        printf("Promedio - Calculo: %.2f\n", prom2);
    }

    if (mat_3 > 0)
    {
        prom3 = acum3 / mat_3;
        printf("Promedio - DHD: %.2f\n", prom3);
    }

    // PROMEDIO 1 ER SEMESTRE
    if (total > 0)
    {
        suma_prom = (acum1 + acum2 + acum3) / total;
        printf("Promedio - 1er Semestre {Computacion}: %.2f\n", suma_prom);
    }

    // Estadisticas finales
    printf("\nEstadisticas finales:\n");

    printf("Aprobados - Elementos Discretos: %d\n", aprobados1);
    printf("Reprobados - Elementos Discretos: %d\n", reprobados1);

    printf("Aprobados - Calculo: %d\n", aprobados2);
    printf("Reprobados - Calculo: %d\n", reprobados2);

    printf("Aprobados - DHD: %d\n", aprobados3);
    printf("Reprobados - DHD: %d\n", reprobados3);

    return 0;
}