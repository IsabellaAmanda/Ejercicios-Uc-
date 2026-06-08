#include <stdio.h>
#define MILLA 1.85325

// cuerpo principal

int main()
{
    // entrada
    float millas;

    // salida
    float Km;

    // Ingresar entrada
    printf("\nIngrese la cantidad de millas: ");
    scanf("%f", &millas);

    Km = millas * MILLA;

    // Mostrar salida
    printf("\nLa cantidad %.2f millas = %.2f Km\n", millas, Km);
    return 0;
}