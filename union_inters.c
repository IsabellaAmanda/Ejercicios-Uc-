#include <stdio.h>

// cuerpo principal del programa

int main()
{
    // intervalos cerrados
    int Li1, Ls1, Li2, Ls2;

    // calcular la union e interseccion de los intervalos
    // ingresar intervalos
    printf("Ingrese el primer intervalo [Li1, Ls1]: \n");
    scanf("%d %d", &Li1, &Ls1);

    printf("Ingrese el segundo intervalo [Li2, Ls2]: \n");
    scanf("%d %d", &Li2, &Ls2);

    // calcular la union e la interseccion

    if ((Ls1 >= Li2) && ((Li1 <= Li2 && Ls1 <= Ls2) || (Ls2 <= Li1 && Ls2 <= Ls1)))
    {
        printf("Los intervalos si presentan unio e interseccion\n");
    }
    else
    {
        if ((Ls1 >= Li2))
        {
            printf("Presenta union pero no interseccion\n");
        }
        else if ((Li1 <= Li2 && Ls1 <= Ls2) || (Ls2 <= Li1 && Ls2 <= Ls1))
        {
            printf("Presenta interseccion pero no uinion\n");
        }
        else
        {
            printf("No presenta union ni interseccion\n");
        }
    }
    return 0;
}