#include <stdio.h>
#include <string.h>
#define MAX 100

// Cuerpo principal
int main()
{
    // Files
    FILE *p, *l;

    // Aperturas
    p = fopen("pala.txt", "r");
    l = fopen("long.txt", "w");

    // Entradas
    char palabra[MAX], max_word[100] = " ";
    int len, max_len;
    // Validacion

    if (p == NULL)
    {
        perror("ERROR\n");
    }
    else
    {

        len = 0;
        max_len = 0;
        // Ciclo
        while (fscanf(p, " %99[^\n]", palabra) != EOF)
        {
            printf("%s\n", palabra);

            len = strlen(palabra);

            if (len > max_len)
            {
                max_len = len;
                strcpy(max_word, palabra);
            }
        }

        if (max_len > 0)
        {
            printf("%s %d\n", max_word, max_len);
            fprintf(l, "%s %d\n", max_word, max_len);
        }

        fclose(p);
        fclose(l);
    }
}

/*Funcion del programa
Cree un programa que lea un archivo llamado entrada.txt y retorne la palabra que tenga la mayor
longitud junto a la cantidad de caracteres necesarios para representarla. Las palabras del archivo
tendrán un máximo de 100 caracteres

* Usar strlen y strcpy
*/