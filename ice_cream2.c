#include <stdio.h>

// cuerpo principal del algoritmo
int main()
{
    int tipo, dias;
    int maxdays = 6;
    float salario = 0, pago_total = 0;

    // ingresar indentificador y dias trabajados
    printf("1 - Cajero (250,000 Bs)\n2 - Servidor (400,000 Bs)\n3 - Preparador de mezclas (450,000 Bs)\n4 - Mantenimiento (30,000 Bs)\n");
    printf("\nIngrese si tipo de empleado y los días que trabajo : ");

    if (scanf("%d %d", &tipo, &dias) != 2)
        printf("Error\n");

    if (dias > 0 && dias <= maxdays)
    {
        switch (tipo)
        {
        case 1:
            salario = 250000.0;
            break;
        case 2:
            salario = 400000.0;
            break;
        case 3:
            salario = 450000.0;
            break;
        case 4:
            salario = 30000.0;
            break;
        default:
            printf("Error\n");
            break;
        }

        // calculamos el pago total
        pago_total = (salario / maxdays) * dias;
    }
    else
    {
        printf("Error\n");
    }

    printf("\nEmpleado %d\n", tipo);
    printf("\nDías de trabajo: %d\n", dias);
    printf("\nPago mensual: %.2f\n", salario);
    printf("\nSalario: %.2f\n", pago_total);

    return 0;
}