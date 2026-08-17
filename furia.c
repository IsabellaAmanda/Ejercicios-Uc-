#include <stdio.h>

int main()
{

    // FILE
    FILE *c, *f;

    // Entrada
    char car, move, previo = 0, actual = 0;

    // Apertura
    c = fopen("combate.txt", "r");

    // Validacion

    if (c == NULL)
    {
        printf("Hola\n");
    }
    else
    {
        // Usamos leer el segundo carater como Gancho, Golpe y Guardia tienen la misma G, y Codo solo hay una C y P, solo hay una p, hacemos otra lectura y comparamos

        f = fopen("furia.txt", "w");
        // Salidas
        int especial = 0, furia = 0, bloqueos = 0;
        char move = EOF;
        while ((car = fgetc(c)) != EOF)
        {

            move = EOF;
            previo = 0;
            // printf("%c", car);
            if (car == '\n' || car == ' ')
                continue;

            if (car == 'G')
            { // gancho

                // Segunda lectura
                char pen = fgetc(c);

                if (pen == 'a')
                {
                    move = 'G'; // gancho
                    previo = 2;
                    printf("%c", move);
                }
                else if (pen == 'o')
                {
                    move = 'L'; // Golpe
                    previo = 1;
                    printf("%c", move);
                }
                else if (pen == 'u')
                {
                    move = 'U';
                    previo = 0;
                    printf("%c", move);
                }
            }
            else if (car == 'P')
            {
                // Patada
                move = 'P';
                previo = 2;
                printf("%c", move);
            }
            else if (car == 'C')
            {
                // Codo
                move = 'C';
                previo = 1;
                printf("%c", move);
            }

            // Regla del combo

            if (previo == 2)
            {

                if (actual == 2)
                {

                    furia += 4;
                }
                else
                {
                    furia += 2;
                }
            }
            else if (previo == 1)
            {

                if (actual == 1)
                {

                    furia += 2;
                }
                else
                {
                    furia += 1;
                }
            }
            else if (move == 'U')
            {

                bloqueos += 1;
            }

            actual = previo;

            // Regla de Desborde
            printf("%d\n", furia);

            if (furia >= 10)
            {
                especial += 1;
                furia = 0;
                actual = 0;
            }
        }

        fprintf(f, "%d", bloqueos);
        printf("%d", bloqueos);
        fprintf(f, "%d", especial);
        printf("%d", especial);
        fprintf(f, "%d", furia);
        printf("%d", furia);

        if (especial >= 3)
        {

            fprintf(f, " [DOMINACION]\n");
            printf(" [DOMINACION]\n");
        }
        else if (furia >= 1)
        {
            fprintf(f, " [VICTORIA POR FURIA]\n");
            printf("[VICTORIA POR FURIA]\n");
        }
        else
        {

            fprintf(f, "[SIN ESPECIALES]\n");
            printf("[SIN ESPECIALES]\n");
        }
    }
    printf("\n");

    fclose(c);
    fclose(f);

    return 0;
}