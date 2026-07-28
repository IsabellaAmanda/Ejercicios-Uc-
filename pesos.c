#include <stdio.h>

// Cuerpo principal

int main()
{
    // Files
    FILE *ent1, *ent2, *sal;

    // Apertura
    ent1 = fopen("almacen.txt", "r");
    ent2 = fopen("peso_deseado.txt", "r");
    sal = fopen("camion.txt", "w");

    // Entrada
    int item, existe, cont, cont2;
    float item_peso, peso, suma, prom;
    char name;

    // Validacion
    if (ent1 == NULL)
    {
        printf("Error\n");
    }
    else
    {
        cont = 0;
        while ((name = fgetc(ent1)) != '\n' && name != EOF)
        {

            cont++;
        }

        existe = 0;

        if (ent2 != NULL)
        {

            if (fscanf(ent2, "%f", &peso) == 1)
            {
                existe = 1;
            }
            fclose(ent2);
        }

        // Caso de que exista

        if (existe)
        {

            while (fscanf(ent1, "%d-%f", &item, &item_peso) == 2 && cont)
            {

                if (item_peso <= peso && existe == 1)
                {
                    fprintf(sal, "%d-%.2f\n", item, item_peso);
                    printf("%d-%.2f\n", item, item_peso);
                }
                else
                {
                    printf("No existe el peso deseaso\n");
                }
            }
        }
        else
        {

            while (fscanf(ent1, "%d-%f", &item, &item_peso) == 2 && cont)
            {

                cont2++;
                suma += item_peso;

                prom = suma / cont2;
                peso = prom;
                if (item_peso <= prom && existe == 0)
                {
                    fprintf(sal, "%d-%.2f\n", item, item_peso);
                    printf("%d-%.2f\n", item, item_peso);
                }
            }
        }

        fclose(ent1);
        fclose(sal);
    }

    return 0;
}
