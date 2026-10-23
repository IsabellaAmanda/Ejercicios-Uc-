//(%d/%d) %c (%d/%d) leer asi
#include <stdio.h>

// registro
typedef struct
{
    int dem, num;
    char car;
} fracciones;

// Simplifica tanto númerador como denominador

void simplificar_fact(fracciones *f);
void sumar_fact(fracciones *result, fracciones *facc1, fracciones *facc2);
void resta_fact(fracciones *result, fracciones *facc1, fracciones *facc2);
void multi_fact(fracciones *result, fracciones *facc1, fracciones *facc2);
int si_esDivisible(fracciones *f);
void imprimir(FILE *f2, fracciones result);

int main()
{
    FILE *ent, *sal;
    ent = fopen("fracc.txt", "r");
    sal = fopen("operac.txt", "w");

    fracciones fac, fracc1, fracc2, resultado;
    if (ent == NULL)
    {
        printf("Error en el archivo");
    }
    else
    {
        while (fscanf(ent, "(%d/%d)", &fracc1.num, &fracc1.dem) == 2)
        {

            char siguiente;
            resultado = fracc1;
            while ((siguiente = fgetc(ent)) != EOF)
            {
                if (siguiente == '\n')
                    break;

                if (siguiente == '+' || siguiente == '-' || siguiente == '*' || siguiente == '\n')
                {
                    if (fscanf(ent, "(%d/%d)", &fracc2.num, &fracc2.dem) == 2)
                    {

                        switch (siguiente)
                        {
                        case '+':
                            sumar_fact(&resultado, &fracc1, &fracc2);

                            break;

                        case '-':
                            resta_fact(&resultado, &fracc1, &fracc2);
                            break;
                        case '*':
                            multi_fact(&resultado, &fracc1, &fracc2);
                            break;
                        default:
                            printf("Error\n");
                        }
                        // actualizamos
                        fracc1 = resultado;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            imprimir(sal, resultado);
        }
    }

    // printf("Ingrese una operción en el menú de fracciones: ");
    // scanf("%d", &opers);
    // operaciones_fracciones(&opers, fac);
    fclose(ent);
    fclose(sal);
    return 0;
}

// Debo aplicar como si fuera el mcd voy a descomponer termino a
// termino hasta que el resto sea sero y valor resultante del
// cosiente sea el resultado
void simplificar_fact(fracciones *f)
{
    int a = f->num;
    int b = f->dem;
    int resto;
    // Funcion de euclides

    int apos = (a < 0) ? -a : a;
    int bpos = (b < 0) ? -b : b;
    while (bpos > 0)
    {
        resto = apos % bpos;
        apos = bpos;
        bpos = resto;
    }
    int mcd = apos;
    // Simplifica tanto el denominador como numerador
    if (mcd > 0)
    {

        f->num = f->num / mcd;
        f->dem = f->dem / mcd;
    }
}
void sumar_fact(fracciones *result, fracciones *facc1, fracciones *facc2)
{
    int n1, n2, d1, d2;

    n1 = facc1->num;
    d1 = facc1->dem;
    n2 = facc2->num;
    d2 = facc2->dem;

    if (d1 == d2)
    {
        result->num = (n1 + n2);
        result->dem = d1;
    }
    else
    {

        result->num = (n1 * d2) + (n2 * d1);
        result->dem = (d1 * d2);
    }
    simplificar_fact(result);
}
void resta_fact(fracciones *result, fracciones *facc1, fracciones *facc2)
{
    int n1, n2, d1, d2;

    n1 = facc1->num;
    d1 = facc1->dem;
    n2 = facc2->num;
    d2 = facc2->dem;

    if (d1 == d2)
    {
        result->num = (n1 - n2);
        result->dem = d1;
    }
    else
    {

        result->num = (n1 * d2) - (n2 * d1);
        result->dem = (d1 * d2);
    }
    simplificar_fact(result);
}
// Procedimiento para multiplicar fracciones
void multi_fact(fracciones *result, fracciones *facc1, fracciones *facc2)
{
    int n1, n2, d1, d2;

    n1 = facc1->num;
    d1 = facc1->dem;
    n2 = facc2->num;
    d2 = facc2->dem;

    {
        result->num = (n1 * n2);
        result->dem = (d1 * d2);
    }
    simplificar_fact(result);
}

// Retorna verdadero si mi fracciones son divisibles
int si_esDivisible(fracciones *f)
{
    int band = 0;

    if (f->dem != 0 && f->num % f->dem == 0)
    {
        band = 1;
    }
    return band;
}
void imprimir(FILE *f2, fracciones result)
{
    if (si_esDivisible(&result) == 1)
    {
        int entero = result.num / result.dem;
        fprintf(f2, "=%d\n", entero);
    }
    else
    {
        fprintf(f2, "=%d/%d\n", result.num, result.dem);
    }
}