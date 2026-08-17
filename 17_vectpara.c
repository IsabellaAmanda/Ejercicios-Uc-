#include <stdio.h>
#define N 5

// Funciones
void r_Mat(int mat[][N], int n, FILE *fi);
void w_Mat(int mat[][N], int n, FILE *fe);
void sum_Mat_Fil_Col(int mat[][N], int n);

int main()
{
    // File
    FILE *e, *s;
    // Entradas
    int S[N][N], num;
    e = fopen("read.txt", "r");
    // Validacion
    if (e == NULL)
    {
        printf("Error en la lectura\n");
    }
    else
    { // Validamos que lee un solo numero y que el tam_real no sea menor a cero o mayor al tamaño máximo
        if (fscanf(e, "%d", &num) == 1 && num >= 0 && num <= N)
        {
            s = fopen("mat.txt", "w");
            r_Mat(S, num, e);
            w_Mat(S, num, s);
            printf("\n");
            sum_Mat_Fil_Col(S, num);
        }
        fclose(e);
        fclose(s);
    }
    return 0;
}
// Definiciones
void r_Mat(int mat[][N], int n, FILE *fi)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fscanf(fi, "%d", &mat[i][j]);
        }
    }
}
void w_Mat(int mat[][N], int n, FILE *fe)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fprintf(fe, "%3d ", mat[i][j]);
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
}
void sum_Mat_Fil_Col(int mat[][N], int n)
{
    int sum_fil, sum_col, i, j;
    int v1[N], v2[N];
    // Inicializar la suma de las filas

    for (i = 0; i < n; i++)
    {
        sum_fil = 0;
        // Inicializar la suma de la columnas
        for (j = 0; j < n; j++)
        {
            sum_fil += mat[i][j];
        }
        v1[i] = sum_fil;
    }

    for (j = 0; j < n; j++)
    {
        sum_col = 0;
        for (i = 0; i < n; i++)
        {
            sum_col += mat[i][j];
        }
        v2[j] = sum_col;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%3d ", mat[i][j]);
        }

        printf("%3d \n", v1[i]);
    }

    for (j = 0; j < n; j++)
    {
        printf("%3d ", v2[j]);
    }
    printf("\n");
}