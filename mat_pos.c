#include <stdio.h>

// Funciones
void Read_Vec(int n, FILE *f1, float v[n][n]);
int Elem_Pos(int n, float v[n][n]);
void Write_Vec(int n, FILE *f2, float v[n][n]);

int main()
{

    // Arch
    FILE *r, *v;

    // Entradas
    int n;
    int positive;

    r = fopen("pos_mat.txt", "r");

    if (r == NULL)
    {
        printf("Error\n");
    }
    else
    {
        v = fopen("pos_m.txt", "w");

        fscanf(r, "%d", &n);

        float posi[n][n];

        Read_Vec(n, r, posi);
        positive = Elem_Pos(n, posi);
        Write_Vec(n, v, posi);

        fprintf(v, "%d\n", positive);
        printf("Tiene %d Positivos\n", positive);
    }

    fclose(r);
    fclose(v);

    return 0;
}

// Def Func

void Read_Vec(int n, FILE *f1, float v[n][n])
{

    int i, j;

    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n; j++)
        {

            fscanf(f1, "%f", &v[i][j]);
        }
    }
}
int Elem_Pos(int n, float v[n][n])
{
    int pos = 0;
    for (int i = 0; i < n; i++)

    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] > 0)
                pos++;
        }
    }

    return pos;
}
void Write_Vec(int n, FILE *f2, float v[n][n])
{
    int i, j;

    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n; j++)
        {
            fprintf(f2, "%8.2f ", v[i][j]);
            printf("%8.2f ", v[i][j]);
        }

        fprintf(f2, "\n");
        printf("\n");
    }
}
