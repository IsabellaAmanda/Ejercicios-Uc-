#include <stdio.h>

// Cuerpo principal

int main()
{
    // Files
    FILE *valores, *raices;

    // Apertura de archivos
    valores = fopen("valores.txt", "r");
    raices = fopen("raicess.txt", "w");
    // Entradas
    float a, b, c;

    // Variables de control
    float discriminante;

    // Ciclo de control
    while (fscanf(valores, "%f %f %f", &a, &b, &c) == 3)
    {

        discriminante = (b * b) - 4 * a * c;

        if (discriminante > 0)
        {
            fprintf(raices, "Tiene dos raices reales\n");
            printf("Tiene dos raices reales\n");
        }
        else if (discriminante == 0)
        {
            fprintf(raices, "Tiene una raiz real\n");
            printf("Tiene una raiz real\n");
        }
        else if (discriminante < 0)
        {
            fprintf(raices, "No tiene raices reales\n");
            printf("No tiene raices reales\n");
        }
    }

    fclose(valores);
    fclose(raices);

    return 0;
}