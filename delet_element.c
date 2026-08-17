#include <stdio.h>
#define M 10
// Variables globales
int V[M], X[M];
// Funcionees
void read_V(int m, FILE *f)
{
    // Lectura de los elementos
    for (int i = 0; i < m; i++)
    {
        fscanf(f, "%d", &V[i]);
    }
    // Leer el vector número 2
    for (int i = 0; i < m; i++)
    {
        fscanf(f, "%d", &X[i]);
    }
}
void wirte_V(int m, FILE *f1)
{
    // Mostrar los vectores antes de ser modificados
    printf("Primer Vector V[%d]\n", M);
    for (int i = 0; i < m; i++)
    {
        fprintf(f1, "%d ", V[i]);
        printf("%2d ", V[i]);
    }
    fprintf(f1, "\n");
    printf("\n");
    // Leer el vector número 2
    printf("Segundo Vector X[%d]\n", M);
    for (int i = 0; i < m; i++)
    {
        fprintf(f1, "%2d ", X[i]);
        printf("%2d ", X[i]);
    }
    printf("\n");
}
int busquedaElementX(int valor, int m)
{
    int existe = 0, i;
    for (i = 0; i < m; i++)
    {
        if (X[i] == valor)
        {
            existe = 1;
        }
    }
    return existe;
}
void eliminarElemento(int *n)
{
    int i = 0;
    while (i < (*n))
    {
        if (busquedaElementX(V[i], *n))
        {

            for (int j = i; j < (*n); j++)
            {
                V[j] = V[j + 1];
            }
            (*n)--; // actualliza la posicion del arreglo
        }
        else
        {
            i++;
        }
    }
    /* code */
}

int main()
{
    // Files
    FILE *v1, *salida;
    // Varibles
    int tam;
    // Apertura de entrada
    v1 = fopen("lee.txt", "r");
    // Validar archivo
    if (v1 == NULL)
    {
        printf("Error de archivo de entrada\n");
    }
    else
    {

        if (fscanf(v1, "%d", &tam) == 1 && tam >= 0 && tam <= M)
        {
            // Apertura de salida
            salida = fopen("eliminado.txt", "w");
            read_V(tam, v1);
            wirte_V(tam, salida);
            eliminarElemento(&tam);
            printf("Vector V[%d] actualizado:\n", tam);

            for (int i = 0; i < tam; i++)
            {
                printf("%2d ", V[i]);
            }
            printf("\n");
        }

        fclose(v1);
    }
    fclose(salida);
    return 0;
}
