/*
 *Programa para seleccionar operaciones básicas(Sum,resta,mult) en 2 matrices de igual dimension
 */
#include <stdio.h>
#define N 100
//*procs de funcs
void loadElemnets(int V[][N], int X[][N], int n);
int sumMats(int V[][N], int X[][N], int n);
int restMats(int V[][N], int X[][N], int n);
int multMats(int V[][N], int X[][N], int n);
void selectOper(int V[][N], int X[][N], int n, int *operador);
void showMats(int V[][N], int X[][N], int n);
//*Programa Principal
int main()
{
    int m1[N][N], m2[N][N];
    int num, oper;

    // Tamaño real
    printf("Ingrese los elementos de ambas matrices: ");
    if (scanf("%d", &num) == 1 && num >= 0 && num <= N)
    {
        loadElemnets(m1, m2, num);
        showMats(m1, m2, num);
        // pedir al user que seleccione un operador
        printf("Ingrese el operador de su gusto (1.Suma,2.Resta,3.Multiplicación): ");
        scanf("%d", &oper);
        selectOper(m1, m2, num, &oper);
        // Mostrar ambas matrices
    }
    return 0;
}
//??Definir mis funciones
void loadElemnets(int V[][N], int X[][N], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &V[i][j]);
            scanf("%d", &X[i][j]);
        }
    }
}
void showMats(int V[][N], int X[][N], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%2d ", V[i][j]);
        }
        printf("\n");
    }
    int l, m;
    for (l = 0; l < n; l++)
    {
        for (m = 0; m < n; m++)
        {
            printf("%2d ", X[l][m]);
        }
        printf("\n");
    }
}
int sumMats(int V[][N], int X[][N], int n)
{
    int i, j, sum;
    sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            sum += V[i][j] + X[i][j];
        }
    }
    return sum;
}
int restMats(int V[][N], int X[][N], int n)
{
    int i, j, rest;
    rest = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            rest -= V[i][j] + X[i][j];
        }
    }
    return rest;
}
int multMats(int V[][N], int X[][N], int n)
{
    int i, j, sum;
    sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            sum += V[i][j] * X[i][j];
        }
    }
    return sum;
}
void selectOper(int V[][N], int X[][N], int n, int *operador)
{
    int result;
    switch (*operador)
    {
    case 1:

        result = sumMats(V, X, n);
        printf("El resultado de V[i][j] + X[i][j] = %d\n", result);
        break;
    case 2:
        result = restMats(V, X, n);
        printf("El resultado de V[i][j] - X[i][j] = %d\n", result);

        break;
    case 3:
        result = multMats(V, X, n);
        printf("El resultado de V[i][j] * X[i][j] = %d\n", result);

        break;

    default:
        printf("Opcion invalida\n");
        break;
    }
}
