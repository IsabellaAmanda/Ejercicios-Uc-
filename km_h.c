#include <stdio.h>

// cuerpo principal
int main()
{
    // Entrada
    int m_s;
    // Salida
    int k_h;

    // Ingresar velocidad
    printf("\nIngrese la velocidad en m/s: ");
    scanf("%d", &m_s);

    k_h = (float)m_s * 3.6;
    // Mostrar salida
    printf("\n%d M/S a K/H = %d K/H\n", m_s, k_h);

    return 0;
}

/*
Función del programa
Transformar la velocidad de m/s a km/h
Entrada:
*La velocidad en relacion a los m/s
Salida:
*La transformación en km/h
*/