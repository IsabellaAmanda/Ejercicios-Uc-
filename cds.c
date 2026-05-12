#include <stdio.h>
#define Porcent 0.0825
// entradas numeros de cds a vender, salida total a pagar para el cliente y ganancia total obtenido por el vendedor

// cuerpo principal

int main()
{
    // entradas
    int amount_cvs;
    float pay_total, ganancias, price = 0;

    // ingresar la cantidad de productos a vender
    do
    {
        printf("Ingrese la cantidad de Cvs a comprar: ");

        scanf("%d", &amount_cvs);

    } while (amount_cvs <= 0);

    // evaluar condicionales
    if (amount_cvs <= 12)
    {
        price = 2.0;
    }
    else if (amount_cvs <= 48)
    {
        price = 0.95;
    }
    else if (amount_cvs <= 99)
    {
        price = 0.90;
    }
    else
    {
        price = 0.75;
    }

    // calculemos el precio que debe
    pay_total = price * amount_cvs;

    // calculemos las ganancias del vendedor
    ganancias = pay_total * Porcent;

    // mostrar salidas
    printf("\nRecibo de pago:\n");
    printf("\nPago total a pagar %.2f Bs\n", pay_total);
    printf("\nGanancias del vendedor %.2f Bs\n", ganancias);
    return 0;
}