#include <stdio.h>

/*
Funcion principal del programa:
Es simular el funcionamiento de un telecajero, las entradas principales
son el monto que quiere dispensar el user, tres distintas nominaciones
que el usuario quiera, empezando del monto mas grande al mas pequenio,
si no hay mas denominaciones de algun tipo se mostrara un mensaje de
error.
*/

// int main {cuerpo prinicipal del programa}

int main()
{
    // entradas 4 {el monto a dispensar, las 3 denominaciones}
    int monto, den_1, den_2, den_3, cantidad = 0;
    // una bandera para preguntar si hay otro usuario por dispensar
    int band = 1;

    // preguntar si un user por dispensar dinero

    printf("Hay un usuario que quiera dispensar dinero: ");
    if (scanf("%d", &band) != 1)
        printf("Error\n");

    // ciclo de control principal del programa
    while (band)
    {

        // ingresar el monto y el tipo de denominacion desde la mas grande a la más pequeña
        printf("\nIngrese el monto que quiere dispensar: ");
        if (scanf("%d", &monto) != 1)
            printf("Error\n");

        // ingrese las denominaciones desde la más grande hasta la menor denominación
        printf("\nIngrese las 3 denominaciones (de mayor a menor): ");
        if (scanf("%d %d %d", &den_1, &den_2, &den_3) != 3)
            printf("Error\n");

        // evaluar condiciones
        if (monto >= den_1)
        {
            cantidad = monto / den_1;

            printf("n- %d billetes de %d Bs, ", cantidad, den_1);

            monto = monto % den_1;
        }
        else
        {
            printf("\n0 billetes %d Bs.\n", den_1);
        }

        if (monto >= den_2)
        {
            cantidad = monto / den_2;
            printf("n- %d billetes de %d Bs, ", cantidad, den_2);

            monto = monto % den_2;
        }
        else
        {
            printf("\n0 billetes %d Bs.\n", den_2);
        }

        if (monto >= den_3)
        {
            cantidad = monto / den_3;
            printf("n- %d billetes de %d Bs.\n", cantidad, den_3);

            monto = monto % den_3;
        }
        else
        {
            if (monto > 0)
            {
                printf("\nNo hay denominaciones para el monto restante de %d Bs.\n", monto);
            }
        }

        printf("\nHay un nuevo usuario en el telecajero?(si = 1, 0 = no): ");
        if (scanf("%d", &band) != 1)
            printf("Error\n");
    }
    return 0;
}