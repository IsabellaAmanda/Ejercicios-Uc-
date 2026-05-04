#include <stdio.h>

// cuerpo prinicipal del programa
int main()
{
    // entradda numeros positivos {4 numeros}
    int n1, n2, n3, n4;
    int pares = 0, sum_50_700 = 0, mayor = 0, cuadrado;
    float average;

    // ingresar datos

    do
    {
        printf("Ingrese el primer numero:\n");
        scanf("%d", &n1);

        printf("Ingrese el segundo numero:\n");
        scanf("%d", &n2);

        printf("Ingrese el tercer numero:\n");
        scanf("%d", &n3);

        printf("Ingrese el cuarto numero:\n");
        scanf("%d", &n4);

    } while (n1 < 0 || n2 < 0 || n3 < 0 || n4 < 0);

    // condicionales

    if (n1 % 2 == 0)
        pares++;

    if (n2 % 2 == 0)
        pares++;

    if (n3 % 2 == 0)
        pares++;

    if (n4 % 2 == 0)
        pares++;

    if ((n1 > n2 && n1 > n3 && n1 > n4))
    {

        mayor = n1;
    }
    else if ((n2 > n1 && n2 > n3 && n2 > n4))
    {
        mayor = n2;
    }
    else if ((n3 > n1 && n3 > n2 && n3 > n4))
    {
        mayor = n3;
    }
    else
    {
        mayor = n4;
    }

    if (n2 < n4 && n3 > n1)
        average = (n1 + n2 + n3 + n4) / 4.0;

    if ((n2 > n3) && (n3 >= 50 && n3 <= 700))
        sum_50_700 = n1 + n2 + n3 + n4;

    if (n1 % 2 == 0)
        cuadrado = n3 * n3;

    // imprimir resultados

    printf("Numeros pares: %d\n", pares);
    printf("El mayor es: %d\n", mayor);
    printf("La media es: %.2f\n", average);
    printf("Suma de numeros entre 50 y 700: %d\n", sum_50_700);
    printf("El n3 ^ 2 es: %d\n", cuadrado);
    return 0;
}