#include <stdio.h>
// Cuerpo principal
int main()
{
    // Entradas
    int n;

    // Variables de control
    int dig, expo, temp;

    // Salida
    int amstrong;

    // Ingresar número y validar
    do
    {
        printf("Ingrese un número: ");
        scanf("%d", &n);
    } while (n <= 0);

    // Contar dígitos del número
    temp = n;
    expo = 0;

    // Contar digitos del número
    while (temp > 0)
    {
        expo++;
        temp /= 10;
    }
    printf("Expo: %d\n", expo);

    // Actualizamos, receteamos e inicializamos variables
    amstrong = 0;
    temp = n;

    // Ciclo para elebar al número
    while (temp > 0)
    {
        // separamos en dig
        dig = temp % 10;
        // Receteamos variables de potencia
        int pot = 1;

        for (int i = 1; i <= expo; i++)
        {
            pot *= dig;
            printf("%der : %d\n", i, pot);
        }

        // Actualizamos el valor de amstrong
        amstrong += pot;
        printf("Amstrong = %d\n", amstrong);
        // actaualizamos el valor del número
        temp /= 10;
    }
    // printf("%d = %d\n", temp_3, amstrong);

    // Verificamos si es un número Amstrong
    if (n == amstrong)
    {
        printf("%d es un número Amstrong.\n", n);
    }
    else
    {
        printf("%d no es un número Amstrong.\n", n);
    }

    return 0;
}
/*
    Función del programa:
    *Determinar el número amstrong:
    Entradas:
    *Un número entero
    Salida:
    *Si el número original es igual al número separado en dig elebado
    a la cantidad de dig se determinara que es un número Amstrong.
    Algoritmo en lenguaje natural:
    * Ingreso el número entero {validemos que no ingrese un número negativo}
    *Uso un while para determinar cuando dig tiene mi número.
    *Separo el numero y cada dig lo voy elebando a
    la cantidad de dig que tenga mi número.
    *Después comparar con un condicional si el número original = al número separado y elebado.
    *Si son iguales es un número Amstrong.

*/