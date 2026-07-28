#include <stdio.h>

// Cuerpo principal
int main()
{
    // Files
    FILE *ent, *sal;

    // Apertura de files
    ent = fopen("transacciones.txt", "r");
    sal = fopen("resumen.txt", "w");

    // Entradas
    float amount, umbral;
    char name;

    // Salidas y variables de control
    float saldo_total, min, maximo;
    int cont_t;

    // Validacion

    if (ent == NULL)
    {
        printf("Error\n");
    }
    else
    {

        int cantidad_lineas = 0;
        while ((name = fgetc(ent)) != '\n' && name != EOF)
        {

            cantidad_lineas++;
        }

        printf("Minimo de transaccion: ");
        scanf("%f", &umbral);

        saldo_total = 0.0;
        cont_t = 0;
        min = 999999.99;
        maximo = 0.0;
        while (fscanf(ent, "%f", &amount) == 1)
        {

            if (amount <= umbral)
            {

                saldo_total += amount;
                cont_t++;

                if (amount > maximo)
                {

                    maximo = amount;
                }

                if (amount < min && amount >= 0)
                {
                    min = amount;
                }
            }
            else
            {
                printf("El valor de la transacciones es mayor al permitido\n");
            }
        }
        printf("%.2f\n", maximo);
        printf("%.2f\n", min);
        printf("---RESUMEN---:\n");
        printf("Transacciones: %d\n", cont_t);
        printf("Saldo acumulado: %.2f\n", saldo_total);
    }

    fclose(ent);
    fclose(sal);

    return 0;
}