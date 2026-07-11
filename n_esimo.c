#include <stdio.h>

// Cuerpo principal
int main()
{
    // Entradas
    int n;

    // Variable de control
    int cumple, cont, cont1 = 2;

    // Salida

    // Ingresar datos y validar
    do
    {
        printf("Ingrese un número: ");
        scanf("%d", &n);
    } while (n <= 0);

    cont = 0;
    // Ciclo principal
    while (cont < n)
    {
        cumple = 1;

        for (int i = 2; i < cont1; i++)
        {
            if (cont1 % i == 0)
            {
                printf("%d no es primo\n", i);
                // si se activa significa que no es primo
                cumple = 0;
            }
        }

        // Si la bandera no se activa, incrementamos la cantidad de numeros primos
        if (cumple == 1)
        {
            cont++;
        }

        // Si el numero inicial no a superado al valor del numero ingremos verificamos el siguiente
        if (cont < n)
        {
            cont1++;
        }
    }
    printf("El %d-esimo  número  primo es : %d\n", n, cont1);
    return 0;
}

/*
    Función del programa
    *Realizar un programa que pida un n-número, e imprima el n-esimo número primo
*/