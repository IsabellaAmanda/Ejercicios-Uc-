#include <stdio.h>

// Cuerpo principal

/*Funcion principal:
    Es un menú interactivo donde eliges tu pizza y el tipo de pizza, genera la factura,
    si no quirese mas, te mostrara la factura final.
*/
int main()
{
    // Entradas
    int comidas, tipos;

    // Variables de control
    int cantidad = 0, band = 1;

    // salidas

    float price = 0.0, incremento = 0.0, total = 0.0, iva, price_total;

    // ciclo de control principal
    printf("Desea comer en nuestro pizzeria? (1-si/0-no): ");
    scanf("%d", &band);

    do
    {
        do
        {
            printf("Ingrese la pizza que desea (1.Pizza Hawaina, 2.Pizza Americana, 3.Pizza Napolitana, 4.Tequeños, 5.Refrescos): ");
            scanf("%d", &comidas);

        } while (comidas != 1 && comidas != 2 && comidas != 3 && comidas != 4 && comidas != 5);

        do
        {
            printf("Ingrese el tipo de pizza (1.Casual, 2.Familiar): ");
            scanf("%d", &tipos);

        } while (tipos != 1 && tipos != 2);

        switch (comidas)
        {
        case 1:
            if (tipos == 1)
            {
                price = 2300.00;
            }
            else if (tipos == 2)
            {
                price = 2600.00;
            }
            break;
        case 2:
            if (tipos == 1)
            {
                price = 2000.00;
            }
            else if (tipos == 2)
            {
                price = 2300.00;
            }
            break;
        case 3:
            if (tipos == 1)
            {
                price = 2010.00;
            }
            else if (tipos == 2)
            {
                price = 2100.00;
            }
            break;
        case 4:
            if (tipos == 1)
            {
                price = 700.00;
            }
            else if (tipos == 2)
            {
                price = 1000.00;
            }
            break;
        case 5:
            if (tipos == 1)
            {
                price = 600.00;
            }
            else if (tipos == 2)
            {
                price = 0.0;
            }
            break;
        default:
            printf("Opción invalida.\n");
        }

        if (comidas == 1 || comidas == 2 || comidas == 3)
        {

            // se le agrega el precio de la caja de la pizza
            total += price + 60;
        }
        else
        {
            // si no elige pizza, solo se le agraga el precio a el pepido
            total += price;
        }

        cantidad++;

        printf("Total: $%.2f\n", total);

        if (!band)
        {
            break;
        }
        else
        {
            printf("Desea comer en nuestro pizzeria? (1-si/0-no): ");
            scanf("%d", &band);
        }

    } while (band == 1);

    if (cantidad > 0)
    {
        iva = total * 0.03;
        price_total = total + iva;
        printf("Factura total: $%.2f\n", price_total);
    }

    return 0;
}