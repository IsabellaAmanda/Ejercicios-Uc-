#include <stdio.h>

// cuerpo principal
int main()
{
    // Entradas
    int n;

    // salidas y variables de control
    float sum, pot, fact;

    // Ingresar el valos de n
    printf("Ingrese un número: ");
    scanf("%d", &n);

    // inicializar sumatoria
    sum = 0;

    for (int j = 2; j <= n; j++)
    {
        // inicializar pot
        pot = 1.0;
        for (int i = 1; i <= j + 1; i++)
        {
            pot *= 5;
            printf("%d\n", i);
            printf("Potencia  %.2f\n", pot);
        }

        // inicializar factorial
        fact = 1.0;
        for (int i = 1; i <= j; i++)
        {
            fact *= i;
            printf("%d\n", i);
            printf("Factorial %.2f\n", fact);
        }

        // incrementar sumatoria

        sum += (pot + j) / fact;
        printf("Sumatoria %d = %.2f\n", j, sum);
    }

    // Mostrar salida
    printf("Sumatoria = %.2f\n", sum);

    return 0;
}
