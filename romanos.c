#include <stdio.h>

// Cuerpo principal
int main()
{
    // Entradas
    int num;

    // validar el número
    do
    {
        printf("\nIngrese un  numero: ");
        scanf("%d", &num);

    } while (num < 1 || num > 1000);

    // ciclo principal

    while (num >= 1000)
    {
        printf("M");

        num -= 1000;
    }

    while (num >= 900)
    {
        printf("CM");

        num -= 900;
    }

    while (num >= 500)
    {
        printf("D");

        num -= 500;
    }

    while (num >= 400)
    {
        printf("CD");

        num -= 400;
    }

    while (num >= 100)
    {
        printf("C");

        num -= 100;
    }

    while (num >= 90)
    {
        printf("XC");

        num -= 90;
    }

    while (num >= 50)
    {
        printf("L");

        num -= 50;
    }

    while (num >= 40)
    {
        printf("XL");

        num -= 40;
    }

    while (num >= 10)
    {
        printf("X");

        num -= 10;
    }

    while (num >= 9)
    {
        printf("IX");

        num -= 9;
    }

    while (num >= 5)
    {
        printf("V");

        num -= 5;
    }

    while (num >= 4)
    {
        printf("IV");

        num -= 4;
    }

    while (num >= 1)
    {
        printf("I");

        num -= 1;
    }

    printf("\n\n");
    return 0;
}
/*funcion del programa:
    *Elaborar un programa que dado un número entre 1 y 1000 escriba su representación
    en números romanos
    *Entrada:
    *Un número entre 1 y 1000 (validar eso con un do while();)
    *Salida:
    *Un mensaje con transformación en números romanos
*/