#include <stdio.h>

// cuerpo principal
int main()
{
    // Entradas
    FILE *in, *out;
    int n;

    // Apertura de archivos
    in = fopen("numeros.txt", "r");
    out = fopen("asteris.txt", "w");
    // validar que el archivo no este vacio

    if (in == NULL)
    {
        printf("El archivo esta vacio\n");
    }
    else
    {
        // recorrido y lectura
        while (fscanf(in, "%d", &n) == 1) // lee hasta que no haya mas valores cuando sea cero sale
        {
            // ciclo que controla la cantidad de asteriscos que se imprimiran
            for (int i = 1; i <= n; i++) // imprime hasta el tope del numero leido
            {
                fprintf(out, "*"); // va imprimiendo hasta que el iterador supere el valor del numero
                printf("*");
            }
            fprintf(out, "\n"); // va a la siguiente linea en el archivo
            printf("\n");       // va a la siguiente linea en la terminal
        }
    }

    // cerrar archivo
    fclose(in);
    fclose(out);
    return 0;
}