#include <stdio.h>
#include <math.h>

// Cuerpo principal

int main()
{
    // Files
    FILE *j, *t, *p;

    // Aperturas
    j = fopen("juego.txt", "r");
    t = fopen("tiros.txt", "r");
    p = fopen("puntuacion.txt", "w");

    // Entradas, salidas y variables de control
    int orig_x, orig_y, pts, punt1, punt2;
    char play1[10], play2[10];

    // Validacion
    if (j == NULL || t == NULL)
    {
        printf("Error\n");
    }
    else
    {

        // Reseteo
        punt1 = 0;
        punt2 = 0;
        // Player Nro 1

        // Punt de origen

        fscanf(j, "%d %d", &orig_x, &orig_y);
        // printf("%d %d", &orig_x, &orig_y);

        // Leer nomre y cant de tiros
        fscanf(j, "%s %d", play1, &pts);
        // printf(" %9[^\n] %d", play1, &pts);

        for (int i = 1; i <= pts; i++)
        {
            int x, y;
            // Leer primera posiciones de x y en la diana
            fscanf(t, "%d %d", &x, &y);
            printf("%d %d\n", x, y);

            // printf("%d %d\n", &x, &y);

            // Calcular distacia
            float dist = sqrt(pow(x - orig_x, 2) + pow(y - orig_y, 2));

            // Ecaluaciones de puntos del jugador

            if (dist <= 1)
            {
                punt1 += 10;
            }
            else if (dist <= 2)
            {
                punt1 -= 1;
            }
            else if (dist <= 5)
            {
                punt1 += 5;
            }
            else if (dist <= 6)
            {
                punt1 -= 1;
            }
            else if (dist <= 10)
            {
                punt1 += 1;
            }
            else if (dist <= 11)
            {
                punt1 -= 1;
            }
        }

        // Player Nro 2

        // Punt de origen

        // Leer nombre y cant de tiros
        fscanf(j, "%s %d", play2, &pts);
        // printf(" %9[^\n] %d", play2, &pts);

        for (int i = 1; i <= pts; i++)
        {
            int x, y;
            // Leer primera posiciones de x y en la diana
            fscanf(t, "%d %d", &x, &y);
            printf("%d %d\n", x, y);

            // printf("%d %d\n", &x, &y);

            // Calcular distacia
            float dist = sqrt(pow(x - orig_x, 2) + pow(y - orig_y, 2));

            // Ecaluaciones de puntos del jugador

            if (dist <= 1)
            {
                punt2 += 10;
            }
            else if (dist <= 2)
            {
                punt2 -= 1;
            }
            else if (dist <= 5)
            {
                punt2 += 5;
            }
            else if (dist <= 6)
            {
                punt2 -= 1;
            }
            else if (dist <= 10)
            {
                punt2 += 1;
            }
            else if (dist <= 11)
            {
                punt2 -= 1;
            }
        }

        // Imprimir puntuaciones
        fprintf(p, "%s %d\n", play1, punt1);
        printf("%s %d\n", play1, punt1);
        fprintf(p, "%s %d\n", play2, punt2);
        printf("%s %d\n", play2, punt2);

        // Evaluar quien fue el mejor jugador
        if (punt1 > punt2)
        {
            fprintf(p, "Felicidades %s, has ganado\n", play1);
            printf("Felicidades %s, has ganado\n", play1);
        }
        else if (punt1 < punt2)
        {
            fprintf(p, "Felicidades %s, has ganado\n", play2);
            printf("Felicidades %s, has ganado\n", play2);
        }
        else
        {
            fprintf(p, "Felicidades %s y %s, han empatado\n", play1, play2);
            printf("Felicidades %s y %s, han empatado\n", play1, play2);
        }
    }

    fclose(j);
    fclose(t);
    fclose(p);

    return 0;
}