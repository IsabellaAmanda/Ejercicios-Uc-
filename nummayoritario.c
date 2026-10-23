#include <stdio.h>
#define MAX 50

// Prototipo
int numMayoritario(int v[], int cont);
int main()
{
    int n[MAX];
    int num;
    int mayor;
    FILE *f_ent, *f_sal;
    // Apertura de archivos
    f_ent = fopen("mayor.txt", "r");
    f_sal = fopen("sal_mayor.txt", "w");
    // validacion del archivo de entrada
    if (f_ent == NULL)
    {
        return -1;
    }
    else
    {
        while (fscanf(f_ent, "%d", &num) != EOF)
        {
            // ciclo interno
            for (int i = 0; i < num; i++)
            {
                fscanf(f_ent, "%d", &n[i]);
                mayor = numMayoritario(n, num);
            }
            fprintf(f_sal, "%d\n", mayor);
        }
    }
    fclose(f_ent);
    fclose(f_sal);
    return 0;
}
// Definicion de la funcion
int numMayoritario(int v[], int cont)
{
    int aux;
    int contador;
    for (int i = 0; i < cont; i++)
    {
        contador = 0;
        for (int j = 0; j < cont; j++)
        {
            if (v[i] == v[j])
            {
                aux = v[i];

                contador++;
            }
        }
        if (contador > 1)
        {
            return aux;
        }
    }
}