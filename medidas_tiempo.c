#include <stdio.h>

// cuerpo principal
int main()
{
    // entradas
    int ss;
    // salidas
    int SS, MM, HH;
    // Ingresar datos
    printf("\nIngrese el numero de segundos: ");
    scanf("%d", &ss);

    // transformar a HH:MM:SS
    HH = ss / 3600;
    MM = (ss % 3600) / 60;
    SS = ss % 60;

    // Mostrar salida
    printf("\nLos %d sg equivalen a %d:%d:%d\n", ss, HH, MM, SS);

    return 0;
}