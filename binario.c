#include <stdio.h>

// Prototipos
int num_binario(int bin);
int main()
{
    int num, binario;
    printf("Ingres un número en binario (Ej:10): ");
    scanf("%d", &num);
    binario = num_binario(num);
    printf("El número %d en decimal es %d.\n", num, binario);
    return 0;
}
// Def
int num_binario(int bin)
{
    int decimal = 0;
    int base = 1;
    while (bin > 0)
    {
        int dig = bin % 10;    // obtener el ult dig de der a izq
        decimal += dig * base; // conversion del número a decimal
        base *= 2;             // incrementamos la base de 2 en 2
        bin /= 10;             // actulizamos el número para proximo ciclo
    }
    return decimal;
}