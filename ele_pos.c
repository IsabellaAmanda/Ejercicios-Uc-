#include <stdio.h>

// Funciones
void Read_Vec(int n, FILE *f1, float nums, float v[]);
int Elem_Pos(int n, int pos, float nums, float v[]);
void Write_Vec(int n, FILE *f2, float nums, float v[]);

int main()
{

    // Arch
    FILE *r, *v;

    // Entradas
    int n, pos;

    float num;
    int positive;

    r = fopen("positivos.txt", "r");

    if (r == NULL)
    {
        printf("Error\n");
    }
    else
    {
        pos = 0;
        v = fopen("pos.txt", "w");

        fscanf(r, "%d", &n);

        float posi[n];

        Read_Vec(n, r, num, posi);
        positive = Elem_Pos(n, pos, num, posi);
        Write_Vec(n, v, num, posi);

        fprintf(v, "%d\n", positive);
        printf("Tiene %d Positivos\n", positive);
    }

    fclose(r);
    fclose(v);

    return 0;
}

// Def Func

void Read_Vec(int n, FILE *f1, float nums, float v[])
{

    int i;

    for (i = 0; i < n; i++)
    {

        fscanf(f1, "%f", &v[i]);
    }
}
int Elem_Pos(int n, int pos, float nums, float v[])
{

    for (int i = 0; i < n; i++)
    {
        if (v[i] > 0)
            pos++;
    }

    return pos;
}
void Write_Vec(int n, FILE *f2, float nums, float v[])
{
    int i;

    for (i = 0; i < n; i++)
    {

        fprintf(f2, "NRO %d = [%f]\n", i + 1, v[i]);
        printf("NRO %d = [%.2f]\n", i + 1, v[i]);
    }
}
