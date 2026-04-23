// librerias
#include <stdio.h>
#define Lote 12

// cuerpo principal del algoritmo
int main()
{
    double costo_total = 0.0, venta_total, precio_unitario, margen_ganancia, ganancia;
    double ingrediente;

    int i;

    printf("Ingrese la cantidad de ingredientes:\n");

    i = 0;
    do
    {
        if (ingrediente > 0)
        {
            i++;

            printf("Ingrese el costo del ingrediente %d:\n", i + 1);
            scanf("%lf", &ingrediente);
        }
        else
        {
            i = 0;
        }
        costo_total += ingrediente;

        printf("Ingrese cero para finalizar:\n");
        scanf("%lf", &ingrediente);
    } while (ingrediente != 0);

    do
    {
        printf("Ingrese el precio de venta por unidad:\n");
        scanf("%lf", &precio_unitario);
    } while (precio_unitario < 0);

    venta_total = (precio_unitario * Lote);
    ganancia = (venta_total - costo_total);

    if (venta_total > 0)
    {
        margen_ganancia = (ganancia / venta_total) * 100;
    }
    else
    {
        margen_ganancia = 0.0;
    }
    printf("Costo total: %.2lf\nGanancias de venta: %.2lf\nMargen de ganancia: %.2lf%%\n", costo_total, ganancia, margen_ganancia);
    if (margen_ganancia < 30)
    {
        printf("Alerta: Bajo nivel de ganancia.\n");
    }
    else
    {
        printf("Nivel de ganacia normal.\n");
    }
    return 0;
}