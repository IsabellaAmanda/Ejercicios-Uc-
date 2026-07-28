#include <stdio.h>

// Cuerpo principal

int main()
{
    // Files
    FILE *ent, *sal;

    // Apertura de archivo
    ent = fopen("estudiantes.txt", "r");
    sal = fopen("salidas_estudents.txt", "w");

    // Entrada
    int n, m, cedula;

    float nota;

    char materia[50];

    // Salidas y variables de control
    int aprob, reprob, cedula_max;

    float prom, max, sum;

    // Validación del archivo
    if (ent == NULL)
    {
        printf("Error\n");
    }
    else
    {
        // Ciclo de n materias
        fscanf(ent, "%d", &n);
        for (int i = 1; i <= n; i++)
        {
            // Reseteo
            prom = 0.0;
            reprob = 0;
            aprob = 0;
            max = 0.0;
            sum = 0.0;
            // Leemos la materia
            fscanf(ent, " %49[^\n]", materia);

            // leer la cantidad de notas
            fscanf(ent, "%d", &m);

            // Ciclo de m notas
            for (int j = 1; j <= m; j++)
            {

                // Leer cedula y la nota
                fscanf(ent, "%d %f", &cedula, &nota);

                if (nota >= 10.00)
                {
                    aprob++;
                }
                else
                {
                    reprob++;
                }

                if (nota > max)
                {
                    max = nota;
                    cedula_max = cedula;
                }

                sum += nota;
            }

            // Promedio
            prom = sum / m;

            // Mostrar salidas
            fprintf(sal, "Materia: %s\n", materia);
            fprintf(sal, "Promedio de notas: %.2f\n", prom);
            fprintf(sal, "Número de aprobados: %d\n", aprob);
            fprintf(sal, "Número de reprobados: %d\n", reprob);
            fprintf(sal, "Estudiante con mayor nota: %d\n", cedula_max);
            fprintf(sal, "\n");
        }
        fclose(ent);
        fclose(sal);
    }

    return 0;
}