#include <stdio.h>

// cuerpo principal
int main()
{
    // entradas -> 2 num reales y un operador char y una bandera para siga preguntando si quiere ver sobre otra operacion
    char op;
    float n1, n2;
    int band = 0;

    // ingresar datos

        do
    {
        printf("Ingrese el operador {+, -, *, /}: ");
        scanf(" %c", &op);
        // ingresar numeros
        printf("Ingrese los dos números: ");
        scanf("%f %f", &n1, &n2);

        switch (op)
        {
        case '+':
            /* Suma*/
            printf("La suma de %.2f + %.2f = %.2f", n1, n2, n1 + n2);
            break;
        case '-':
            /* Resta*/
            printf("La resta de %.2f - %.2f = %.2f", n1, n2, n1 - n2);
            break;
        case '*':
            /* Multi*/
            printf("La multiplicacion de %.2f * %.2f = %.2f", n1, n2, n1 * n2);
            break;
        case '/':
            /* Div*/
            if (n2 != 0)
            {
                printf("La división de %.2f / %.2f = %.2f", n1, n2, n1 / n2);
            }
            else
            {
                printf("La  división entre cero no existe\n");
            }

            break;
        default:

            printf("Error: operador incorrecto\n");
            break;
        }

        printf("\nDesea ingresar otra operación?\n(Si -> 1 ó no -> 0)\n");
        scanf("%d", &band);
    } while (band == 1);

    return 0;
}