#include <stdio.h>
#include <stdbool.h>
#define Max 100
void readElements(int A[], int *n)
{
    do
    {
        /* code */

        printf("Ingrese la cantidad de elementos del vector: ");
        scanf("%d", n);

    } while (*n < 0 || *n > Max);
    for (int i = 0; i < *n; i++)
    {
        /* code */
        printf("%d:\n", i + 1);
        scanf("%d", &A[i]);
    }
}
bool sumaMitad(int A[], int n)
{
    int mitad1, mitad2;
    // Suma de la primera mitad
    mitad1 = 0;
    for (int i = 0; i < (n / 2); i++)
    {
        /* code */
        mitad1 += A[i];
    }
    mitad2 = 0;
    // Suma segunda mitad
    for (int i = (n + 1) / 2; i <= n - 1; i++)
    {
        mitad2 += A[i];
    }
    bool igual = true;
    if (mitad1 != mitad2)
    {
        igual = false;
    }
    return igual;
}
void showElements(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d: %2d\n", i + 1, A[i]);
    }
}

int main()
{
    int a[Max];
    int num;
    readElements(a, &num);
    if (sumaMitad(a, num))
    {
        printf("Las 2 mitades del arreglo son iguales.\n");
    }
    else
    {
        printf("Ambas mitades son diferentes.\n");
    }
    showElements(a, num);
}