#include <stdio.h>
#include <stdbool.h>
#define MAX 20

void leerArray(int s[MAX], int *n)
{
    do
    {

        printf("Ingrese la cantidad de elementos reales del array: ");
        scanf("%d", n);
    } while (*n < 0 || *n > MAX);
    for (int i = 0; i < (*n); i++)
    {
        printf("%d \n", i + 1);
        scanf("%d", &s[i]);
    }
}
int maxSum(int sum[MAX], int n)
{
    int max = 0;
    for (int i = 0; i < (n); i++)
    {
        int suma = 0;
        int temp = sum[i];
        while (temp != 0)
        {
            // calcular la suma/
            int dig = temp % 10;
            suma += dig;
            temp /= 10;
        }
        if (suma > max)
            max = suma;
    }

    return max;
}
void imprimirArray(int s[MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%3d ", s[i]);
    }
    printf("\n");
}
int main()
{
    int sum[MAX], num, sumar;

    leerArray(sum, &num);
    sumar = maxSum(sum, num);
    printf("La suma mayor es: %d\n", sumar);
    imprimirArray(sum, num);
    return 0;
}