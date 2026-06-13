#include <stdio.h>

// Cuerpo principal
int main()
{

    // Entrada y variables de control
    int num, dig, temp;
    int invertido;

    // Ingresar datos y validar
    do
    {
        printf("\nIngresar un numero entero: ");
        scanf("%d", &num);
    } while (num < 1000 || num > 9999);

    // Inicializacion
    invertido = 0;
    temp = num;
    // Ciclo de control
    for (int i = 0; i < 4; i++)
    {
        dig = num % 10;
        invertido = (invertido * 10) + dig;
        num /= 10;
    }

    // Mostrar salida
    printf("\n%d=%d\n", temp, invertido);

    return 0;
}

/*
Funcion principal del programa
    *Separar un numero de cuatro dig e invertirlo
    *Entrada:
    *Num de cuatro dig
    *Salida:
    *Numero Invertido
    *Concideraciones:
    *Validar que el numero tenga 4 dig
    *Usar div y mod
    *Usar ciclo for parque sabemos la cantidad de dig {iter}
*/