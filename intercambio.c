#include <stdio.h>

// Cuerpo principal
int main()
{

    // Entradas
    int a, b;

    // Ingresar números
    printf("Ingrese el 1er valor: ");
    scanf("%d", &a);

    printf("Ingrese el 2do valor: ");
    scanf("%d", &b);

    printf("Valores iniciales:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    // Lógica sin variables temporales
    a = a + b;
    b = a - b;
    a = a - b;

    // Montrar salida
    printf("Valores intercambiados:\n");
    printf("A vale ahora: %d\n", a);
    printf("B vale ahora: %d\n", b);

    return 0;
}
/*Función del programa:
    *Tengo 2 números y se quiere intercambiar sus valores
    sin el uso e una variable adicional

    *Entradas:
    *Los 2 números enteros

    *Salida:
    *El intercambio de los  2 números


*/