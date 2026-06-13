#include <stdio.h>

// Cuerpo principal
int main()
{
    // Entrada y variables de control
    int num, dig, temp;
    // Salida
    int sum;

    // Ingresar datos y validar
    do
    {
        printf("\nIngrese un numero entero: ");
        scanf("%d", &num);
    } while (num < 100 || num > 999);

    // inicializar varible
    sum = 0;
    temp = num;
    // Ciclo principal
    for (int i = 0; i < 3; i++)
    {
        // separar en dig
        dig = num % 10;
        sum += dig;
        num /= 10;
    }

    // mostrar salida
    printf("\n%d=%d\n", temp, sum);

    return 0;
}

/*
funcion del programa:
    *Separar un numero en sus digitos y calcular la suma de sus digitos.
    *Entrada:
    *Num de 3 digitos
    *Salida:
    *Suma de los digitos
    *Concideraciones:
    *Validar que el num tenga 3 dig
    *Usar div y mod
    *Usar un ciclo for ya que conocemos la cantidad de dig
*/