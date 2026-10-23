/*
 *ALgoritmo para determinar la suma de la diagonal principal de una matriz de 7 x 7
 */
#include <stdio.h>
#define N 7

// procs
void loadElements(int m[][N], int n);
int sumDiagonalPrincipal(int m[][N], int n);
void showElements(int m[][N], int n);

int main()
{
    int num;
    int S[N][N];

    //??Ingresar la cantidad de elementos reales que tendra la matriz y validar que
    //??el tamaño real no sea superado por el tamaño maximo que puede ocupar mi arreglo
    // printf("Ingrese la cantidad de elementos de la matriz: ");
    if (scanf("%d", &num) == 1 && num >= 0 && num <= N)
    {
        //*Cargar los elementos
        //*Mostrar el resultado de la suma de la diagonal principal
        //*Mostrar la matriz completa con sus elementos
        loadElements(S, num);
        printf("La suma de la diagonal principal es: %d\n", sumDiagonalPrincipal(S, num));
        showElements(S, num);
    }
    return 0;
}
// Definiciones
void loadElements(int m[][N], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
}
int sumDiagonalPrincipal(int m[][N], int n)
{
    int i, diagonal;
    diagonal = 0;
    for (i = 0; i < n; i++)
    {
        diagonal += m[i][i];
    }
    return diagonal;
}

void showElements(int m[][N], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%2d ", m[i][j]);
        }
        printf("\n");
    }
}