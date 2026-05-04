#include <stdio.h>

// cuerpo principal

int main()
{
    // entradas
    int anio;

    // pedir el anio al user
    printf("Ingrese el año: ");
    if (scanf("%d", &anio) != 1)
    {
        printf("Error\n");
    }

    if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
    {
        printf("El año %d es bisiesto.\n", anio);
    }
    else
    {
        printf("El año %d no es bisiesto.\n", anio);
    }
    return 0;
}