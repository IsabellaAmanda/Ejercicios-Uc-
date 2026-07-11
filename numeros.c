#include <stdio.h>

// Cuerpo principal
int main()
{
    // Files
    FILE *numeros, *primo;
    // Open Files
    numeros = fopen("num.txt", "r");
    primo = fopen("primos.txt", "w");
    // Entradas
    int numero;
    // Variables de control
    int cont;
    // Salidas

    // Validar archivos
    if (numeros == NULL)
    {
        printf("Error\n");
    }
    else
    {
        // Ciclo de control (hasta fin de archivo)

        while (fscanf(numeros, "%d", &numero) == 1)
        {

            cont = 0;
            for (int i = 2; i < numero; i++)
            {
                if (numero % i == 0)
                {
                    cont = 1;
                }
            }

            if (cont == 0)
            {
                fprintf(primo, "%d\n", numero);
                printf("%d\n", numero);
            }
        }

        fclose(numeros);
        fclose(primo);
    }

    return 0;
}