#include <stdio.h>

int main()
{
    // Entradas

    // Polinomio a y b
    int ax1, bx1, cx1, ax2, bx2, cx2;

    // Salidas {Coeficientes}

    // suma y resta
    int a1, b1, c1, a2, b2, c2;

    // multiplicacion
    int a, b, c, d, e;

    // Ingresar cada polinomio
    printf("\nIngresa los coeficientes del 1er polinomio (separado por espacio): ");
    scanf("%d %d %d", &ax1, &bx1, &cx1);

    printf("\nIngresa los coeficientes del 2do polinomio (separado por espacio): ");
    scanf("%d %d %d", &ax2, &bx2, &cx2);

    // suma
    a1 = ax1 + ax2;
    b1 = bx1 + bx2;
    c1 = cx1 + cx2;

    // resta
    a2 = ax1 - ax2;
    b2 = bx1 - bx2;
    c2 = cx1 - cx2;

    // multiplicacion
    a = (ax1 * ax2);

    b = (ax1 * bx1) + (bx1 * ax2);

    c = (ax1 * cx2) + (bx1 * bx2) + (cx1 * ax2);

    d = (bx1 * cx2) + (cx1 * bx2);

    e = (cx1 * cx2);

    // Mostrar salidas
    printf("\nSuma de polinomios: %dx^2 + %dx + %d\n", a1, b1, c1);
    printf("\nResta de polinomios: %dx^2 + %dx + %d\n", a2, b2, c2);
    printf("\nMultiplicación de polinomios: %dx^4 + %dx^3 + %dx^2 + %dx + %d\n\n", a, b, c, d, e);

    return 0;
}