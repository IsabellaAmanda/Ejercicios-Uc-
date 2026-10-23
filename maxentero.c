#include <stdio.h>

// prototipo
int max_entero(int n1, int n2, int n3);
int main()
{
    int num1, num2, num3, max;

    // Ingreso de números
    printf("Ingrese el 1er número: ");
    scanf("%d", &num1);
    printf("Ingrese el 2do número: ");
    scanf("%d", &num2);
    printf("Ingrese el 3er número: ");
    scanf("%d", &num3);
    max = max_entero(num1, num2, num3);
    printf("El número mayor es: %d\n", max);

    return 0;
}
// Def
int max_entero(int n1, int n2, int n3)
{
    int mayor = n1;

    if (n2 > mayor)
        mayor = n2;

    if (n3 > mayor)
        mayor = n3;

    return mayor;
}
