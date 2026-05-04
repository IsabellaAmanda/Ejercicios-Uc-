#include <stdio.h>

// cuerpo principal

int main()
{
    // entradas
    float x1, x2, y1, y2;
    float A, B;
    // float minX, maxX, minY, maxY;

    // ingreso de coordenadas por el user
    printf("Ingrese el primer punto (x1, y1): ");
    if (scanf("%f %f", &x1, &y1) != 2)
        printf("Error\n");

    printf("Ingrese el segundo punto (x2, y2): ");
    if (scanf("%f %f", &x2, &y2) != 2)
        printf("Error\n");

    // ingresar el punto a, b
    printf("Ingrese el punto (A, b): ");
    if (scanf("%f %f", &A, &B) != 2)
        printf("Error\n");

    // verificar el nuevo punto esta dentro o en el borde

    if (((A > x1 && A < x2) || (A > x2 && A < x1)) && ((B > y1 && B < y2) || (B > y2 && B < y1)))
    {
        printf("El punto (%.2f, %.2f) esta dentro del rectangulo\n", A, B);
    }
    else if (((A == x1 || A == x2) && ((B >= y1 && B <= y2) || (B >= y2 && B <= y1))) || ((B == y1 || B == y2) && ((A >= x1 && A <= x2) || (A >= x2 && A <= x1))))
    {
        printf("El punto (%.2f, %.2f) esta en el borde del rectangulo\n", A, B);
    }
    else
    {
        printf("El punto (%.2f, %.2f) esta fuera del rectangulo\n", A, B);
    }
    return 0;
}