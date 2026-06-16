#include <stdio.h>

// cuerpo principal
int main()
{
    // Entradas
    int n, cont = 0;

    // Ingresar el número
    do
    {
        printf("\nIngrese el número: ");
        scanf("%d", &n);
    } while (n == 0); // validar que no ingresen el número cero ya que no cuenta en ninguno de los casos

    // Condiciones

    // Positivo
    if (n > 0)
        printf("\nEl número %d es positivo\n", n);

    // Negativo
    if (n < 0)
        printf("\nEl número %d es negativo\n", n);

    // Primo
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cont++;
    }

    if (cont == 2)
    {
        printf("\nEl número %d es primo\n", n);
    }
    else
    {
        printf("\nEl número %d no es primo\n", n);
    }

    // Par
    if (n % 2 == 0)
        printf("\nEl número %d es par\n", n);

    // Divisible entre 3
    if (n % 3 == 0)
        printf("\nEl número %d es divisible entre 3\n", n);

    // Divisible entre 5
    if (n % 5 == 0)
        printf("\nEl número %d es divisible entre 5\n\n", n);
    return 0;
}