#include <stdio.h>
#include <math.h>

// cuerpo principal

int main()
{
    // entradas
    char op;
    float a, b;
    // ingresar datos
    printf("\nIngrese los 2 numeros  (separados por espacio): ");
    scanf("%f %f", &a, &b);

    printf("\nIngrese la operacion a realizar (a-suma, b-resta, c-multiplicacion, d-divisor(div), e-dividendo(mod): ");
    scanf(" %c", &op);

    // verificar el operador seleccionado y se mostrara el resultado
    switch (op)
    {
    case 'a':
        printf("\nEl resultado de %.2f + %.2f es: %.2f\n", a, b, a + b);
        break;
    case 'b':
        printf("\nEl resultado de %.2f - %.2f es: %.2f\n", a, b, a - b);
        break;
    case 'c':
        printf("\nEl resultado de %.2f * %.2f es: %.2f\n", a, b, a * b);
        break;
    case 'd':
        if (b != 0)
        {
            printf("\nEl resultado de %.2f / %.2f es: %.2f\n", a, b, a / b);
        }
        else
        {
            printf("\nError\n");
        }
        break;
    case 'e':
        if (b != 0)
        {
            printf("\nEl resultado de %.2f %% %.2f es: %.2f\n", a, b, fmod(a, b));
        }
        else
        {
            printf("\nError\n");
        }
        break;
    default:
        printf("\nOperacion invalida\n");
    }
    return 0;
}