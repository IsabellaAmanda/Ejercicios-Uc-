#include <stdio.h>
#include <string.h>

// cuerpo principal
int main()
{
    // Entradas, acums y conts
    int band = 1, voltaje, consumo_kwh, total_atendidos = 0, tipo_110 = 0, tipo_220 = 0, total_energy = 0;
    float price_kwh = 0.0, month_kwh = 0.0, total_price = 0.0, price_user = 0.0;
    char planes;
    char ced[15];

    // Ciclo de control
    printf("Desea verificar su factura de electricidad? (1-si/0-no): ");
    scanf("%d", &band);
    do
    {
        // Ingresar el plan de electridad
        printf("Ingrese el plan de electricidad (A-Plan A,B-Plan B,C-Plan C ): ");
        scanf(" %c", &planes);

        // Ingresar datos del user
        do
        {
            printf("Ingrese el tipo de voltaje que tiene: ");
            scanf("%d", &voltaje);

        } while (voltaje != 110 && voltaje != 220);

        do
        {
            printf("Ingrese la cantidad de energia que consume kwh: ");
            scanf("%d", &consumo_kwh);

        } while (consumo_kwh < 0);

        do
        {
            printf("Ingrese su cedula de identidad: ");
            scanf("%s", ced);
        } while (strlen(ced) == 0);

        total_atendidos++;
        total_energy += consumo_kwh;

        switch (planes)
        {
        case 'A':

            price_kwh = 0.15;
            month_kwh = 5.00;

            break;
        case 'B':
            price_kwh = 0.12;
            month_kwh = 8.00;

            break;
        case 'C':
            price_kwh = 0.10;
            month_kwh = 10.00;

            break;
        default:
            printf("Opción invalida\n");
            price_kwh = 0.00;
            month_kwh = 0.00;
            break;
        }
        // Verificar cuántos user utilzan cada uno de los tipos energia
        if (voltaje == 110)
        {
            tipo_110++;
        }
        else if (voltaje == 220)
        {
            tipo_220++;
        }
        total_price = (consumo_kwh * price_kwh) + month_kwh;

        if (consumo_kwh < 100)
        {
            total_price = total_price * 0.95;
        }
        else if (consumo_kwh > 500)
        {
            total_price = total_price * 1.10;
        }

        // Mostrar la factura
        printf("---Factura cliente (CI:%s) ---\n", ced);
        printf("Voltaje: %d V - Plan %c\n", voltaje, planes);
        printf("Consumo: %d kwh\n", consumo_kwh);
        printf("Total a pagar por facturacion: $%.2f\n", total_price);

        price_user += total_price;

        if (!band)
        {
            break;
        }
        else
        {
            printf("Desea verificar su factura de electricidad? (1-si/0-no): ");
            scanf("%d", &band);
        }

    } while (band == 1);

    if (total_atendidos > 0)
    {
        printf("====Reporte general====\n");
        printf("Total de users atendidos: %d\n", total_atendidos);
        printf("User con voltaje 110 v : %d\n", tipo_110);
        printf("User con voltaje 220 v : %d\n", tipo_220);
        printf("Consumo total de enegia en KWH : %d\n", total_energy);
        printf("Total obtenido por facturacion: $%.2f\n", price_user);
    }
    return 0;
}

/*
Función y especificaciones:

*/