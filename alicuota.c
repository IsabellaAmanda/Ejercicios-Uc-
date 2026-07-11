#include <stdio.h>

// Cuerpo principal
int main()
{
    // Entradas
    int n;
    // Variables de control
    int dig, temp;
    // Salida
    int sum;

    // Ingresar datos
    do
    {
        printf("Ingrese un numero: ");
        scanf("%d", &n);
    } while (n <= 0);
    // reseteo
    sum = 0;
    temp = n;
    // Ciclos principal
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            sum += i;
    }

    // Verificar la suma alicuota perfecto, abundante o deficiente
    if (temp == sum)
    {
        printf("%d es Perfecto = %d\n", temp, sum);
    }
    else if (sum > temp)
    {
        printf("%d es Abundante = %d\n", temp, sum);
    }
    else if (sum < temp)
    {
        printf("%d es dificiente = %d\n", temp, sum);
    }
    else
    {
        printf("%d es ninguna de las anteriores\n", temp);
    }
    return 0;
}