/*
 *Leer la mat por cols
 *Calcular el max value
 *Det las pos valor iguales al max y escribirlos
 *Mod la mat de tal manera que cada elemnt sea mult por el mx value
 *Mostrar mat orig y mod
 */
#include <stdio.h>
#define MAX 100
//??VAR GLOBALs
int O[MAX][MAX], Mod[MAX][MAX];
//??PROCS A FUNCs
void loadColsElemnts(int n);
void showMatOriginal(int n);
int maxMatValor(int n);
void busquedaMaxPos(int valor, int m);
void modificarValorMat(int mat, int max);
//*PROGRAM Principal
int main()
{
    int tam, maximo;
    //*Ingresar la cantidad de elementos reales de la mat y validamos que no supere el tam real
    printf("Ingrese el tamaño real de la matriz: ");
    if (scanf("%d", &tam) == 1 && tam >= 0 && tam <= MAX)
    {
        loadColsElemnts(tam);
        showMatOriginal(tam);
        maximo = maxMatValor(tam);
        printf("Elemento mayor de la mat O[%d][%d]: %d\n", MAX, MAX, maximo);
        busquedaMaxPos(maximo, tam);
        modificarValorMat(tam, maximo);
    }
    else
    {
        printf("El tamaño real no puede ser mayor al tamaño máximo definido\n");
    }
    return 0;
}
//??DEF de FUNCs
void loadColsElemnts(int n)
{
    int i, j;
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%d", &O[i][j]);
        }
    }
}
void showMatOriginal(int n)
{
    int i, j;
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            printf("%2d ", O[i][j]);
        }
        printf("\n");
    }
}
int maxMatValor(int n)
{
    int i, j, maxi;
    maxi = O[0][0];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (O[i][j] > maxi)
            {
                maxi = O[i][j];
            }
        }
    }
    return maxi;
}
void busquedaMaxPos(int valor, int m)
{
    int i, j;
    int existe;
    existe = 0;
    //*Buscar el mayor
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (O[i][j] == valor)
            {
                printf("O[%d][%d]\n", i + 1, j + 1);
            }
        }
    }
}
void modificarValorMat(int mat, int max)
{
    int i, j;
    max = maxMatValor(mat);

    for (i = 0; i < mat; i++)
    {
        for (j = 0; j < mat; j++)
        {
            Mod[i][j] = max * O[i][j];

            printf("%2d ", Mod[i][j]);
        }
        printf("\n");
    }
}