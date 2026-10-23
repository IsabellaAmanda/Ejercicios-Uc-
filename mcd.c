#include <stdio.h>

// Prototipo
int num_mcd(int a, int b);

int main()
{
    int n1, n2, mcd;

    // Ingresar datos
    do
    {
        printf("Ingrese un número para el 1er valor: ");
        scanf("%d", &n1);
    } while (n1 <= 0);
    do
    {
        printf("Ingrese un número para el 2do valor: ");
        scanf("%d", &n2);
    } while (n2 <= 0);

    mcd = num_mcd(n1, n2);
    printf("El MCD de %d y %d es: %d\n", n1, n2, mcd);
    return 0;
}
// Def
int num_mcd(int a, int b)
{
    int resto;

    while (b > 0)
    {
        resto = a % b; // calculo el ressiduo
        a = b;         // el seg num pasa a ser el primero
        b = resto;     // el rest pasa a ser el seg num
    }
    return a; // el mcd quede guardado en a
}
