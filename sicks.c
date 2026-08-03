#include <stdio.h>

// Cuerpo principal

int main()
{
    // Files
    FILE *s, *e, *p;

    // Apert
    s = fopen("estud.txt", "r");
    e = fopen("enfermos.txt", "w");
    p = fopen("peligro.txt", "w");

    // Entm contrl, sal
    int ced, item;
    char id;

    int alto, bajo, estable, peligro, max_id, min_id, min, max, cont;

    float sumas, prom;

    // Validacion
    if (s == NULL)
    {
        printf("Error\n");
    }
    else
    {

        // Reseteo
        alto = 0;
        bajo = 0;
        estable = 0;
        peligro = 0;
        sumas = 0.0;
        max_id = 0;
        min_id = 0;

        min = 100000;
        max = 0;

        cont = 0;

        while (fscanf(s, "%d %c", &ced, &id) == 2)
        {

            if (id == 'V')
            {
                fscanf(s, "%d", &item);
                cont++;
                sumas += item;
                if (item >= 1 && item <= 15)
                {
                    bajo++;
                }
                else if (item <= 30)
                {
                    estable++;
                }
                else if (item <= 60)
                {
                    alto++;
                }
                else
                {
                    peligro++;
                    fprintf(p, "%d\n", item);
                }

                if (item > max)
                {
                    max = item;
                    max_id = ced;
                }

                if (item < min)
                {
                    min = item;
                    min_id = ced;
                }
            }
            else
            {
                if (id == 'N')
                {
                    item = 0;
                    continue;
                }
            }
        }

        // Salidas

        if (cont > 0)
        {

            prom = (float)sumas / cont;

            printf("RESUMEN:\n");
            printf("Bajo: %d\n", bajo);
            printf("Estable: %d\n", estable);
            printf("Alto: %d\n", alto);
            printf("Peligro: %d\n", peligro);
            printf("---------------------\n");
            printf("Total: %d\n", cont);
            printf("Promedio: %.2f\n", prom);
            printf("Mayor contagio: (ID: %d)\n", max_id);
            printf("Menor contagio: (ID: %d)\n", min_id);

            fprintf(e, "RESUMEN:\n");
            fprintf(e, "Bajo: %d\n", bajo);
            fprintf(e, "Estable: %d\n", estable);
            fprintf(e, "Alto: %d\n", alto);
            fprintf(e, "Peligro: %d\n", peligro);
            fprintf(e, "---------------------\n");
            fprintf(e, "Total: %d\n", cont);
            fprintf(e, "Promedio: %.2f\n", prom);
            fprintf(e, "Mayor contagio: (ID: %d)\n", max_id);
            fprintf(e, "Menor contagio: (ID: %d)\n", min_id);
        }
        else
        {
            printf("No esta enfermo\n");
        }
    }
    fclose(s);
    fclose(e);
    fclose(p);

    return 0;
}