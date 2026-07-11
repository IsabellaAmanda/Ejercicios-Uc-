#include <stdio.h>

// Cuerpo principal
int main()
{
    // Puntero a los files
    FILE *input, *output;

    // apertura de los files
    input = fopen("claves.txt", "r");
    output = fopen("output.txt", "w");

    // Entradas
    int clave;

    // Variables de control
    int dig, encriptar;
    // Salida
    int encrip, j;

    // ciclo principal

    if (input == NULL)
    {
        printf("Error en el archivo\n");
    }
    else
    {
        while (fscanf(input, "%d", &clave) == 1)
        {

            // Encriptar la clave
            // dig = 0;
            encrip = 0;
            j = 1;
            for (int i = 0; i < 3; i++)
            {
                dig = clave % 10;
                encriptar = (dig + 5) % 10;

                // printf("%d", encriptar);
                encrip += encriptar * j;
                // printf("%d\n", encrip);
                j *= 10;
                clave /= 10;
            }

            fprintf(output, "%03d\n", encrip);
            printf("%03d\n", encrip);
        }
    }

    // Cerrar los files
    fclose(input);
    fclose(output);
    return 0;
}
/*
Funcion del programa:
    Este programa se encarga de encriptar claves que tiene desde 0 a 999 {es decir, hasa 3 dig},
    y la encripta.
    Entradas:
        Clave
    Salida:
        Clave encriptada
*/