/*
 *te veo en la noche hermoso programa
 *Arrays, structs, mats, ordenamiento
 *Analisis de datos [5][12]
 */

#include <stdio.h>
#define N 10

// Pr a func y structs

// Registro de promociones
typedef struct
{
    int cod[10];
    int amount_users;
    int max_user;
    int min_users;
} Promocion;

Promocion stacks[5][N];

void read_Proms()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < N; j++)
        {

            printf("Ingrese el número de Usuarios: Año %d, Prom %d: ", i + 1, j + 1);
            scanf("%d", &stacks[i][j].amount_users);
            printf("Ingrese el codigo de los Usuarios registrados  Año %d, Prom %d: ", i + 1, j + 1);
            scanf("%d", &stacks[i][j].cod[j]);
        }
    }
}

void max_Prom(int *user)
{
    // inicializar
    int maximo = 0;

    // leer los datos para calcular el mayor user de todos
    for (int i = 0; i < 5; i++)
    {
        for (int k = 0; k < N; k++)
        {

            if (stacks[i][k].amount_users > maximo)
            {
                maximo = stacks[i][k].amount_users;
            }
        }
    }

    printf("Usuario con mayor cantidad de usuarios en el año: %d\n", maximo);
}
void bubble_Sort(int *n)
{
    *n = N;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < (*n); j++)
        {

            for (int l = 0; l < ((*n) - j - 1); l++)
            {
                /* Ordenamiento */
                if (stacks[i][j].cod[l] > stacks[i][j].cod[l + 1])
                {
                    int temp = stacks[i][j].cod[l];
                    stacks[i][j].cod[l] = stacks[i][j].cod[l + 1];
                    stacks[i][j].cod[l + 1] = temp;
                }
            }
        }
    }
}
int min_Users(int user)
{
    int minimo = 9999;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {

            if (stacks[i][j].amount_users < minimo)
            {
                minimo = stacks[i][j].amount_users;
            }
        }
    }
    return minimo;
}

void deleted_User(int *m)
{
    int min = min_Users(0);
    for (int i = 0; i < 5; i++)
    {
        for (int k = 0; k < N; k++)
        {

            bubble_Sort(m);
            int l = 0;
            while (l < (*m))
            {

                if (min_Users(stacks[i][k].amount_users))
                {
                    for (int s = l; s < (*m); s++)
                    {
                        stacks[i][s] = stacks[i][s + 1];
                    }
                    (*m)--;
                }
                else
                {
                    l++;
                }
            }
        }
    }
}
void write_Proms()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < N; j++)
        {

            printf("User restantes: %d. = > %d\n", j + 1, stacks[i][j].amount_users);
            printf("Código: %d. => %d\n", j + 1, stacks[i][j].cod[j]);
        }
    }
}

int main()
{

    int tam = N;
    read_Proms();
    int user = 0;
    max_Prom(&user);
    deleted_User(&tam);
    write_Proms();

    return 0;
}