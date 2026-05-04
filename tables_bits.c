#include <stdio.h>
#include <math.h>

// cuerpo principal del programa
// funcion del programa crear una tabla de conversion de bits

int main()
{
    // variables de entrada y salida
    // entradas
    double EB, B, MB, TB, GB, YB;

    // variable de seleccion de la tabla a crear
    int conversion, stop = 0;

    do
    {
        // pedir al user el numero de bits correspondiente
        printf("Ingrese una opcion de conversion:\n1. EB a MB\n2. B a TB\n3. Cantidad de GB que contine 7 EB\n4. Cantidad de YB que contiene 9000 GB\n5. Salir\n");
        scanf("%d", &conversion);

        switch (conversion)
        {
        case 1:
            /* code */
            printf("Ingrese el numero de EB: ");
            scanf("%lf", &EB);
            MB = EB * pow(1000, 4);

            // resultado
            printf("%2.2lf EB son : %.2e MB\n", EB, MB);
            break;
        case 2:
            /* code */
            printf("Ingrese el numero de B: ");
            scanf("%lf", &B);
            TB = B / pow(1000, 4);

            // resultado
            printf("%2.2lf B son : %.2e TB\n", B, TB);
            break;
        case 3:
            /* code */
            EB = 7;
            GB = EB * pow(1000, 3);
            printf("7 EB son : %.2e GB\n", GB);
            break;
        case 4:
            /* code */
            GB = 9000;
            YB = GB / pow(1000, 5);
            printf("9000 GB son : %.2e YB\n", YB);
            break;
        case 5:
            printf("Saliendo del programa...\n");

            break;
        default:
            printf("Opcion no valida...\n");
            break;
        }

        printf("Quiere elegir otra opcion? (1/stop, 0/Salir):\n");
        scanf("%d", &stop);

    } while (stop == 1);
    return 0;
}