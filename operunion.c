#include <stdio.h>
#define Max 100
// Definamos los arreglos de manera global, son de dimension real distinta
int A[Max], B[Max], X[Max];
void readElements(int *n, int *m)
{
    // Definamos el tamaño real de ambos arreglos
    do
    {
        printf("Ingrese los valores del vector A[%d]: ", Max);
        scanf("%d", n);
    } while (*n < 0 || *n > Max);
    for (int i = 0; i < *n; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &A[i]);
    }
    do
    {
        printf("Ingrese los valores del vector B[%d]: ", Max);
        scanf("%d", m);
    } while (*m < 0 || *m > Max);
    for (int i = 0; i < *m; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &B[i]);
    }
}
int busquedaSecuencial(int new, int aux[], int valor)
{
    int pos = -1;
    int i = 0;
    while (i < new && pos == -1)
    {
        if (aux[i] == valor)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}
void unionElements(int n, int m, int *nuevo)
{
    // nuevo tamaño real del arreglo union
    int tamX = n;

    for (int l = 0; l < n; l++)
    {
        X[l] = A[l];
    }

    for (int k = 0; k < m; k++)
    {
        if (busquedaSecuencial(tamX, X, B[k]) == -1)
        {
            X[tamX] = B[k];
            tamX++;
        }
    }
    *nuevo = tamX;
}
void intersElements(int n, int m, int *nuevo)
{
    int tamX = 0;

    for (int i = 0; i < n; i++)
    {
        //*Verifico que haya elementos en a que en b
        if (busquedaSecuencial(m, B, A[i]) != -1)
        {
            X[tamX] = A[i];
            tamX++;
        }
    }
    *nuevo = tamX;
}
void buscarElement(int n, int m, int *numbusqueda)
{
    printf("Ingrese el número que quiere buscar: ");
    scanf("%d", numbusqueda);
    //*Vericar si esta en el arreglo A ó B
    if (busquedaSecuencial(n, A, *numbusqueda) != -1 || busquedaSecuencial(m, B, *numbusqueda) != -1)
    {
        printf("El elemento %d SI esta dentro de uno de los VECTORES.\n", *numbusqueda);
    }
    else
    {
        printf("El elemento %d NO esta dentro de uno de los VECTORES.\n", *numbusqueda);
    }
}

int sonIguales(int n, int m)
{
    int iguales = 1;

    if (n != m)
    {
        iguales = 0;
    }
    //*Verifico si A esta en B
    if (iguales == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (busquedaSecuencial(m, B, A[i]) == -1)
            {
                //*Se ha encontrado un elemento que no esta contenido en B
                iguales = 0;
            }
        }
    }
    //*Verifico si B esta en A
    if (iguales == 1)
    {
        for (int i = 0; i < m; i++)
        {
            if (busquedaSecuencial(n, A, B[i]) == -1)
            {
                //*Se ha encontrado un elemento que no esta contenido en B
                iguales = 0;
            }
        }
    }

    return iguales;
}
void showElementos(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        printf("%3d ", A[i]);
    }
    for (int i = 0; i < m; i++)
    {
        printf("%3d ", B[i]);
    }
}
int main()
{
    int buscar, numA, numB, oper, tamnew;
    //*Leer los arreglos
    readElements(&numA, &numB);

    do
    {
        printf("\n============Menú de Operaciones Conjuntos===============\n");
        printf("1. Unión: \n2. Intersección: \n3.Buscar elementos: \n4. A == B.\n5. Salir: \n");
        scanf("%d", &oper);
        if (oper == 0)
            break;
        switch (oper)
        {
        case 1:
            unionElements(numA, numB, &tamnew);
            showElementos(numA, numB);

            break;
        case 2:
            intersElements(numA, numB, &tamnew);
            showElementos(numA, numB);
            break;

        case 3:

            buscarElement(numA, numB, &buscar);
            break;

        case 4:
            if (sonIguales(numA, numB))
            {
                printf("A c B && B c A\n");
            }
            else
            {
                printf("A != B\n");
            }
            break;
        case 5:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opción invalida.\n");
        }
    } while (oper != 5);

    return 0;
}