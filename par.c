#include <stdio.h>

// cuerpo principal
int main()
{
    // Entradas
    int n;

    // Ingresar datos
    printf("\nIngrese el numero: ");
    scanf("%d", &n);

    // Condiciones
    if (n % 2 == 0)
    { // si el resto de div entre 2 es cero es par
        printf("\nEl número %d es par\n\n", n);
    }

    // si no cumple la condicion no entra y por ende no muestra nada
    return 0;
}