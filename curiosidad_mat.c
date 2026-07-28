#include <stdio.h>

// Cuerpo principal
int main()
{
    // Files
    FILE *cuadrados_inv;

    // Abrir archivo
    cuadrados_inv = fopen("cuadrados.txt", "w");
    // Entradas
    int n;

    // Variables de control
    int temp, dig, i;

    // Salidas
    int invertido, cuadrado, cuadrado_invertido;

    i = 1;
    printf("Quiere ingresar un número (1 = si / 0 = no): ");
    scanf("%d", &i);
    // While
    while (i == 1)
    {
        // Validar que el numero sea posito
        do
        {
            printf("Ingrese un numero: ");
            scanf("%d", &n);
        } while (n <= 0);

        // Resetear
        temp = n;
        invertido = 0;

        //  Ciclos para invertir el numero
        while (temp > 0)
        {
            dig = temp % 10;
            invertido = (invertido * 10) + dig;

            temp /= 10;
        }

        cuadrado = n * n;

        // Volver a resetear
        temp = cuadrado;
        cuadrado_invertido = 0;
        // i = 1;

        while (temp > 0)
        {
            dig = temp % 10;
            cuadrado_invertido = (cuadrado_invertido * 10) + dig;
            // i *= 10;
            temp /= 10;
        }

        fprintf(cuadrados_inv, "%d  %d  %d  %d\n", n, invertido, cuadrado, cuadrado_invertido);
        printf("%d  %d  %d  %d\n", n, invertido, cuadrado, cuadrado_invertido);

        if (!i)
        {
            break;
        }
        else
        {
            printf("Quiere ingresar un número (1 = si / 0 = no): ");
            scanf("%d", &i);
        }
    }
    fclose(cuadrados_inv);

    return 0;
}