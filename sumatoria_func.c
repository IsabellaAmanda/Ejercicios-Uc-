#include <stdio.h>

// Funciones
float Potencia(int base, int expo);
float Factorial(int num);
void Sumatoria(int numero);

// cuerpo principal
int main()
{
    // Entradas
    int n;

    // Ingresar el valos de n
    printf("Ingrese un número: ");
    scanf("%d", &n);

    Sumatoria(n);

    return 0;
}

// Definiciones
float Potencia(int base, int expo)
{
    float pot = 1.0;

    for (int i = 1; i <= expo; i++)
    {
        pot *= base;
    }
    return pot;
}

float Factorial(int num)
{
    float fact = 1.0;
    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }

    return fact;
}

void Sumatoria(int numero)
{
    float pote, facto, sum;

    // inicializar
    sum = 0;

    for (int j = 2; j <= numero; j++)
    {

        pote = Potencia(5, j + 1);

        facto = Factorial(j);

        sum += (pote + j) / facto;
        printf("Sumatoria %d = %.2f\n", j, sum);
    }

    // Mostrar salida
    printf("Sumatoria = %.2f\n", sum);
}