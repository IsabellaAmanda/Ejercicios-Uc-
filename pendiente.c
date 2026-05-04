#include <stdio.h>

// cuerpo principal del programa

int main()
{
    // variables pedidad al user {4}
    float x1, x2, y1, y2, m;

    // pedir al user los valores de las coordenadas

    printf("Ingrese las coodenadas del primer punto (x1, y1): ");
    if (scanf("%f %f", &x1, &y1) != 2)
    {
        printf("Error\n");
    }

    printf("Ingrese las coodenadas del segundo punto (x2, y2): ");
    if (scanf("%f %f", &x2, &y2) != 2)
    {
        printf("Error\n");
    }

    // calcular la pendiente de la recta que pasa por esos dos puntos
    m = (y2 - y1) / (x2 - x1);

    // imprimir el resultado
    printf("La pendiente de la recta que pasa por los puntos (%.2f, %.2f) y (%.2f, %.2f) es: %.2f\n", x1, y1, x2, y2, m);

    return 0;
}