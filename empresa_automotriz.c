/*
Función del programa:
Determinar la estadisticas durante las ventas durante 3 meses
*Determinar;
    *Total de ganancias c/u vendedor durante 3 meses
    *Total de autos vendidos en la empresa en los 3 meses
    *Porcentaje de autos familiares
    *Por mes en estudio, det el cod del vendedor con mayor cantidad de autos vendidos
    *
*/

#include <stdio.h>
#include <string.h>
#define vendido 10000.00
// cuerpo principal del programa

int main()
{
    // entradas
    int mes, vendedor, band = 1;
    char tipo[20];
    float price, sales1 = 0, sales2 = 0, sales3 = 0, average;

    // contadores y acumuladores
    int total = 0;
    int max_sale, max_vendedor, familiar = 0;

    // Contadores para determinar los autos vendidos dependiendo del vendedor
    int auto_ven1, auto_ven2, auto_ven3;

    // ciclos principal del programa, 3 meses de ventas
    for (mes = 1; mes <= 3; mes++)
    {
        // actualizar contadores
        auto_ven1 = 0;
        auto_ven2 = 0;
        auto_ven3 = 0;

        // preguntar si hay comprador
        printf("\nHay alguna persona por adquisición de vehículo (1 = si / 0 = no)?: ");
        if (scanf("%d", &band) != 1)
            printf("Error\n");

        while (band)
        {

            total++;

            // ingreso de datos de compra
            printf("\nIngrese tipo de auto (familiar o lujo), precio y código del vendedor (1, 2, 3): ");
            if (scanf(" %s %f %d", tipo, &price, &vendedor) != 3)
                printf("Error\n");

            if (vendedor == 1)
            {
                auto_ven1++;
                sales1 += price * vendido;
            }
            else if (vendedor == 2)
            {
                auto_ven2++;
                sales2 += price * vendido;
            }
            else if (vendedor == 3)
            {
                auto_ven3++;
                sales3 += price * vendido;
            }
            else
            {
                printf("Codigo invalido\n");
            }

            if (strcmp(tipo, "familiar") == 0)
                familiar++;

            printf("\nHay alguna persona por adquisición de vehículo (1 = si / 0 = no)?: ");
            if (scanf("%d", &band) != 1)
                printf("Error\n");
        }

        // calculo de mayor vendedor por mes respectivamente
        max_sale = -1;
        max_sale = 0;
        if (auto_ven1 > max_sale)
        {
            max_sale = auto_ven1;
            max_vendedor = 1;
        }

        if (auto_ven2 > max_sale)
        {
            max_sale = auto_ven2;
            max_vendedor = 2;
        }

        if (auto_ven3 > max_sale)
        {
            max_sale = auto_ven3;
            max_vendedor = 3;
        }

        if (max_sale > 0)
        {
            printf("\nEl vendedor %d es el mayor vendedor de autos del mes %d: Total %d\n", max_vendedor, mes, max_sale);
        }
        else
        {
            printf("\nNo hubo carros vendidos\n");
        }
    }

    // mostrar estadisticas y calcular porcentajes
    sales1 *= 1.02;
    sales2 *= 1.02;
    sales3 *= 1.02;

    printf("\nGanancias vendedor 001: %.2f\n", sales1);
    printf("\nGanancias vendedor 002: %.2f\n", sales2);
    printf("\nGanancias vendedor 003: %.2f\n", sales3);

    printf("\nTotal de autos vendidos durante los 3 meses: %d\n", total);

    if (total > 0)
    {
        average = ((float)familiar / total) * 100;
        printf("\nTotal de autos familiares vendidos: %.2f%%\n", average);
    }
    else
    {
        printf("Error\n");
    }

    return 0;
}