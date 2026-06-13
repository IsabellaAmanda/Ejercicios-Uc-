#include <stdio.h>

// cuerpo principal
int main()
{
    // Entradas
    float N, M, incremento;

    // ingresar datos
    printf("\nIngrese el precio del producto: ");
    scanf("%f", &N);

    printf("\nIngrese el porcentaje de incremento del producto: ");
    scanf("%f", &M);

    // calculo
    incremento = (N * (M / 100)) + N;

    // mpstrar salida
    printf("\nPrecio sin incremento: %.2f Bs. Ahora + incremento %.2f%% = %.2f Bs\n", N, M, incremento);

    return 0;
}