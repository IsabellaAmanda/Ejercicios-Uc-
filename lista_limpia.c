#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    FILE *list, *blacklist, *cleanlist;

    list = fopen("list.txt", "r");
    cleanlist = fopen("cleanlist.txt", "w");
    char invitadoblack[20];
    char invitadoclean[20];
    bool encontrado;

    if (list == NULL)
    {
        printf("Error en el archivo de entrada\n");
    }
    else
    {
        // leemosla lista general
        while (fscanf(list, "%19s", invitadoclean) == 1)
        {
            encontrado = false;
            blacklist = fopen("blacklist.txt", "r");
            if (blacklist != NULL)
            {
                // buscamos el nombre actual en la lista negra
                while (fscanf(blacklist, "%19s", invitadoblack) == 1)
                {
                    if (strcmp(invitadoclean, invitadoblack) == 0)
                    {
                        encontrado = true;
                        break; // encontrado salimos
                    }
                }
                fclose(blacklist);
            }
            // si no fue encontrado lo guardamos en la lista depurada
            if (!encontrado)
            {
                fprintf(cleanlist, "%s\n", invitadoclean);
            }
        }
        fclose(list);
        fclose(cleanlist);
    }

    return 0;
}