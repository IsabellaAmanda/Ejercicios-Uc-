/**
    *4/10/2026
    * @file medico.c
    * @brief Este archivo contiene la definición de la estructura Paciente y funciones relacionadas con la

 */
#include <stdio.h>
#include <string.h>
#define MAX_PACIENTES 100
#define MAX 100
#define min 20
// Definimos un registro de información de pacientes
typedef struct
{
    char name[50];
    char Observaciones[100];
    char address[MAX];
    char phone[min];
    char ultimaCita[min];
    int tieneAlergia;
    int tieneSeguro;
} Paciente;

// Definir como almacenar los pacientes en un arreglo de registros
Paciente pacientes[MAX_PACIENTES];

// Funcion que carga los datos del paciente
void cargarDatosPaciente(int *numPacientes);

// Funciones que dado un nombre de paciente me de la ultima cita al medico
void mostrarUltimaCita(char *namespaciente, int numPact);

// Funcion que muestra todos los pacientes con alergias
void mostrarPacientesConAlergias(int numPact);

// Funcion que lista todos los pacientes con seguro
void mostrarPacientesConSeguro(int numPact);

int main()
{
    int numrecord;

    //*Ingreso el número de pacientes a registrar
    do
    {
        printf("Ingrese el número de pacientes registrados: ");
        scanf("%d", &numrecord);
    } while (numrecord < 0 || numrecord > MAX_PACIENTES);
    cargarDatosPaciente(&numrecord);

    printf("Ingrese el nombre del paciente para mostrar su última cita: ");
    char namespaciente[50];
    fgets(namespaciente, sizeof(namespaciente), stdin);
    namespaciente[strcspn(namespaciente, "\n")] = '\0';
    mostrarUltimaCita(namespaciente, numrecord);
    mostrarPacientesConAlergias(numrecord);
    mostrarPacientesConSeguro(numrecord);

    return 0;
}

// Definimos la funciones que vamos declaramos como prototipo arriba
void cargarDatosPaciente(int *numPacientes)
{
    int i;
    for (i = 0; i < (*numPacientes); i++)
    {
        // limpiar el buffer de entrada antes de leer cadenas, ya que scanf deja un salto de línea pendiente en el buffer
        while (getchar() != '\n')
            ;
        printf("Ingrese el nombre del paciente %d: ", i + 1);
        fgets(pacientes[i].name, sizeof(pacientes[i].name), stdin);
        // Eliminar el salto de lineal al final del fgets
        pacientes[i].name[strcspn(pacientes[i].name, "\n")] = '\0';
        printf("Ingrese la dirección del paciente %d: ", i + 1);
        fgets(pacientes[i].address, sizeof(pacientes[i].address), stdin);
        pacientes[i].address[strcspn(pacientes[i].address, "\n")] = '\0';
        printf("Ingrese el télefono del paciente %d: ", i + 1);
        fgets(pacientes[i].phone, sizeof(pacientes[i].phone), stdin);
        pacientes[i].phone[strcspn(pacientes[i].phone, "\n")] = '\0';
        printf("Ingrese la última cita que el paciente %d asistió: ", i + 1);
        fgets(pacientes[i].ultimaCita, sizeof(pacientes[i].ultimaCita), stdin);
        pacientes[i].ultimaCita[strcspn(pacientes[i].ultimaCita, "\n")] = '\0';

        // Con los datos siguientes no es necesario limpiar el buffer de entrada ya que estás leyendo enteros
        printf("Ingrese el si el paciente cuenta con alergías %d (1 para sí, 0 para no): ", i + 1);
        scanf("%d", &pacientes[i].tieneAlergia);
        printf("Ingrese el si el paciente cuenta con seguro %d (1 para sí, 0 para no): ", i + 1);
        scanf("%d", &pacientes[i].tieneSeguro);
        while (getchar() != '\n')
            ;

        // Limpiar el buffer de entrada antes de leer cadenas, ya que scanf deja un salto de línea penndiente en el buffer
        printf("Ingrese las observaciones del paciente %d: ", i + 1);
        fgets(pacientes[i].Observaciones, sizeof(pacientes[i].Observaciones), stdin);
        pacientes[i].Observaciones[strcspn(pacientes[i].Observaciones, "\n")] = '\0';
    }
}
void mostrarUltimaCita(char *namespaciente, int numPact)
{
    int i, encontrado = 0;
    for (i = 0; i < numPact; i++)
    {
        if (strcmp(pacientes[i].name, namespaciente) == 0)
        {
            printf("La última cita del paciente %s fue el %s\n", namespaciente, pacientes[i].ultimaCita);
            encontrado = 1;
        }
    }
    if (!encontrado)
    {
        printf("No se encontró el paciente %s en los registros.\n", namespaciente);
    }
}

void mostrarPacientesConAlergias(int numPact)
{
    int i;
    printf("Pacientes registrados con alergías:\n");
    for (i = 0; i < numPact; i++)
    {
        if (pacientes[i].tieneAlergia == 1)
        {
            printf("%s\n", pacientes[i].name);
        }
    }
}

void mostrarPacientesConSeguro(int numPact)
{
    int i;
    printf("Pacientes registrados con seguro:\n");
    for (i = 0; i < numPact; i++)
    {
        if (pacientes[i].tieneSeguro == 1)
        {
            printf("%s\n", pacientes[i].name);
            printf("%s\n", pacientes[i].address);
            printf("%s\n", pacientes[i].phone);
            printf("%s\n", pacientes[i].ultimaCita);
            printf("%d\n", pacientes[i].tieneAlergia);
            printf("%d\n", pacientes[i].tieneSeguro);
            printf("%s\n", pacientes[i].Observaciones);
        }
    }
}