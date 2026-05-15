#include <stdio.h>
#define Monto 0.6
#define Plus 0.1
/*
Funcion del programa:
Determinar el cobro de estacionamiento por las cantidad de horas en el mismo
si dura 60 min exactos en la entrada y salida se multiplica el total de horas por 0.60 bs
si pasan 15 de la hora se le hace un incremento de 0.10 bs al cobro normal del ticket de
estacionamiento.
*/

// int main {cuepo principal de programa}
int main()
{
    // entradas son 6 {contando la bandera}
    int band = 1;
    int HE, ME, HS, MS;
    // hora de entrada {indica si am o pm}
    char TE, TS;

    // otras variables de control
    int h_entrada, h_salida, h_total;
    // salida monto a cancelar por el cobro de estacionamiento
    float price_ticket, total = 0;

    // verificar si hay carros entradando
    printf("Hay un carro entrando al estacionamiento {si = 1/no = 0}: ");
    if (scanf("%d", &band) != 1)
        printf("Error\n");

    // ciclo principal del programa
    while (band)
    {
        // ingresar hora de entrada y salida durante un dia 23 hoaras con 59
        printf("\nIngrese la hora en que entro al estacionamiento (HH:MM) A = AM o P = PM: ");
        if (scanf("%d:%d %c", &HE, &ME, &TE) != 3)
            printf("Error\n");

        printf("\nIngrese la hora en que salio del estacionamiento (HH:MM) A = AM o P = PM: ");
        if (scanf("%d:%d %c", &HS, &MS, &TS) != 3)
            printf("Error\n");

        if (TE == 'P' && HE < 12)
        {
            HE += 12;
        }
        else
        {
            h_entrada = 0;
        }

        if (TE == 'P' && HS < 12)
        {
            HS += 12;
        }
        else
        {
            HS = 0;
        }

        h_entrada = (HE * 60) + ME;
        h_salida = (HS * 60) + MS;

        h_total = h_salida - h_entrada;

        if (h_total < 0)
        {
            h_total = h_total + 1440;
        }
        price_ticket = h_total * Monto;

        // condiciones
        if (h_total >= 75)
        {
            total = price_ticket + Plus;
            printf("\nTotal a pagar + incremento: %.2f Bs\n", total);
        }
        else
        {
            total = price_ticket;
            printf("\nEl total a pagar es: %.2f Bs\n", total);
        }

        printf("\nQuiere verificar que otro carro haya entrado al estacionamiento? {si = 1/no = 0}: ");
        if (scanf("%d", &band) != 1)
            printf("Error\n");
    }

    return 0;
}