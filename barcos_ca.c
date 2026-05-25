/*
funcion del promagrama:
*Determinar que las caracteristicas del barco a elaborar se cumplan
*entradas:
*Largo {15 a 75 pies, incremento de 2 pies}
*Ancho {5 a 25 pies, incremento de 1 pie}
*Numero de camarotes {0 a 14}
*Motor , potencia {10, 20, 50, 100, 200, 500, 1000}
*salidas:
msje de restriccion o de insatisfaccion por no cumplir con las condiciones del barco
o el costo total del barco a elaborar si cumple con las condiciones del barco

*/
#include <stdio.h>

// cuerpo principal del programa

int main()
{

    // entradas del programa y otras variables de control
    float large, width, price_boat, price_hp, price_camarote, price_area, area, max_large, min_large;
    // bandera de control para validar más de una entrada
    int band = 1, num_camarotes, hp_motor, limite_camarotes, cumple = 1;

    // ciclo principal del programa
    printf("Desea elaborar un barco? (1 - si, 0 - no): ");
    if (scanf("%d", &band) != 1)
        printf("Error\n");

    while (band)
    {
        // resetear bandera
        cumple = 1;

        // ingresar datos del barco
        printf("\nIngrese el largo del barco (15 a 75 pies): ");
        if (scanf("%f", &large) != 1)
            printf("Error\n");

        printf("\nIngrese el ancho del barco (5 a 25 pies): ");
        if (scanf("%f", &width) != 1)
            printf("Error\n");

        printf("\nIngrese el número de camarotes del barco (0 a 14): ");
        if (scanf("%d", &num_camarotes) != 1)
            printf("Error\n");

        printf("\nIngrese la potencia del motor del barco (10, 20, 50, 100, 200, 500 y 1000): ");
        if (scanf("%d", &hp_motor) != 1)
            printf("Error\n");

        // validacion de las condiciones del barco

        // condicion de largo con respecto a su ancho

        min_large = (3 * width);
        if (large < min_large)
        {
            printf("\n El diseño solicitado es demasiodo ancho para su largo\n");
            cumple = 0;
        }
        max_large = (5 * width);
        if (large > max_large)
        {
            printf("\n El diseño solicitado es demasiodo angosto para su largo\n");
            cumple = 0;
        }

        // condiciones del motor
        area = (((0.6)) * (large * width));
        if (hp_motor > area)
        {
            printf("\nEl diseño solicitado posee un motor de mucha potencia\n");
            cumple = 0;
        }

        // condiciones cantidad de camarotes
        limite_camarotes = (large * width) * 0.01;
        if (num_camarotes < 0 || num_camarotes > 14)
        {
            printf("\nEl numero de camarotes debe estar en el rango prestablecido\n");
        }
        else if (num_camarotes > limite_camarotes)
        {
            printf("\nEl diseño solicitado posee demasiados camarotes con esas caracteristicasº\n");
            cumple = 0;
        }

        // bandera de salida para datos validos de diseño del barco
        if ((cumple))
        {
            // calculo del precio del barco
            price_area = (large * width) * 6125;
            price_camarote = num_camarotes * 29750;
            price_hp = hp_motor * 3600;
            price_boat = price_area + price_camarote + price_hp;
            printf("\nEl costo total del barco: %.2f Bs.\n", price_boat);
        }
        else
        {
            printf("\nCaracteristicas no acordes con lo ofrecido por la compañia\n");
        }

        // preguntar si quieren elaborar otro barco
        printf("\nDesea elaborar un barco? (1 - si, 0 - no): ");
        if (scanf("%d", &band) != 1)
            printf("Error\n");
    }

    return 0;
}
