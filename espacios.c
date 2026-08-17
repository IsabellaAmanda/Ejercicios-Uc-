#include <stdio.h>

/*
Cree un programa que sume todos los números de un archivo que se encuentran separados
por comas
*/

// Cuerpo principal

int main()
{

    // Files
    FILE *n, *c;

    // Aperturas
    n = fopen("coma.txt", "r");
    c = fopen("con.txt", "w");

    int num, sum;
    char coma;

    // Validacion
    if (n == NULL)
    {
        printf("Error\n");
    }
    else
    {

        sum = 0;

        // Ciclo prinical
        while (fscanf(n, "%d%c", &num, &coma) != EOF)
        {
            sum += num;

            if (coma == ',')
            {

                continue;
            }
        }

        printf("%d\n", sum);
    }
}