#include <stdio.h>

// cuerpo principal

int main()
{
    // entradas
    int edad, estatura, viene_acompanado;

    // ingresar datos
    printf("\nIngrese su edad: ");
    scanf("%d", &edad);

    printf("\nIngrese su estatura (en cm): ");
    scanf("%d", &estatura);

    printf("\nViene acompañado? (1-si/0-no): ");
    scanf("%d", &viene_acompanado);

    // verificar condiciones {reglas}
    if (edad >= 10 && edad <= 90)
    {
        if (estatura < 120)
        {
            printf("\nNo puede subir.\n");
        }
        else if (estatura <= 140)
        {
            if (viene_acompanado)
            {
                printf("\nPuede subir acompañado.\n");
            }
            else
            {
                printf("\nNo puede subir solo.\n");
            }
        }
        else
        {
            printf("\nPuede subir solo.\n");
        }
    }
    else
    {
        printf("\nNo puede subir por su edad.\n");
    }

    return 0;
}