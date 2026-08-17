#include <stdio.h>
#include <stdbool.h>
#define N 10
// Prototipos
void r_Vect(float mat[][N], int n, FILE *f1);
bool simetrica(float mat[][N], int n);
void w_Vect(float mat[][N], int n, FILE *f2);

int main()
{
    FILE *e, *s;

    float S[N][N];
    int tam;

    e = fopen("lect.txt", "r");

    if (e == NULL)
    {
        printf("Archivo vacio\n");
    }
    else
    {

        if (fscanf(e, "%d", &tam) == 1 && tam > 0 && tam < N)
        {
            s = fopen("simetrica.txt", "w");

            r_Vect(S, tam, e);

            if (simetrica(S, tam))
            {
                fprintf(s, "La matriz S es simetrica\n");
            }
            else
            {
                fprintf(s, "La matriz S no es simetrica\n");
            }

            w_Vect(S, tam, s);
        }
    }
    fclose(e);
    fclose(s);
    return 0;
}

void r_Vect(float mat[][N], int n, FILE *f1)
{

    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            /* code */
            fscanf(f1, "%f", &mat[i][j]);
        }
    }
}

bool simetrica(float mat[][N], int n)
{
    bool cumple = true;
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (mat[i][j] != mat[j][i])
            {
                cumple = false;
            }
        }
    }
    return cumple;
}

void w_Vect(float mat[][N], int n, FILE *f2)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            /* code */
            fprintf(f2, "%3.1f ", mat[i][j]);
            printf("%3.1f ", mat[i][j]);
        }
        fprintf(f2, "\n");
        printf("\n");
    }

    printf("\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            /* code */
            printf("\n[i%d,j%d] : %.1f\n", i + 1, j + 1, mat[i][j]);
            printf("\n[j%d,i%d] : %.1f\n", j + 1, i + 1, mat[j][i]);
        }
        fprintf(f2, "\n");
        printf("\n");
    }
}