#include <stdio.h>
#define MAX_SENSORES 50

// Simulacion modular de telemetrica y monitoreo climático
// Realizar un registro sensor
typedef struct
{
    /* data */
    int idSensor;           /*Direccion del sensor*/
    char tipoNodo;          /*'A':Altitud, 'S': Superficie, 'M': Maritimo*/
    float lecturas[5];      /*Array de 5 lecturas consecutivas de temperatura*/
    int numLecturasValidas; /*Cantidad de lecturas procesadas en el arreglo (<=5)*/
    float promedio;         /*Promedio calculado de las lecturas válidas*/
    int estadoOperativo;    /*1:Normal,0:Alerta*/
} Sensor;

// Protipo cargarSensores, recibe el archvio, la estructura sensor, y la cantidad de sensores validos
void cargarSensores(FILE *f1, Sensor sensor[], int *cantSensores);
void procesarLecturas(Sensor sensor[], int cantSensores, int *cantAlt, int *cantSup, int *cantMart);
void GenerarReporte(FILE *F2, Sensor sensor[], int cantSensores, int cantAlt, int cantSup, int cantMart);

int main()
{
    FILE *ent, *sal;
    // Aperturas de los archivos;
    ent = fopen("telematria.txt", "r");
    sal = fopen("resumen_telematria", "w");
    Sensor s[MAX_SENSORES];
    int sensores;
    int alt, sup, mart;

    // Validemos los archivos
    if (ent == NULL)
    {
        return -1;
    }
    else
    {
        // validaciones
        fscanf(ent, "%d", &sensores);
        if (sensores > 0 && sensores < MAX_SENSORES)
        {
            // Llamar a cargarSensores
            cargarSensores(ent, s, &sensores);
            /*Inicializar contadores*/
            procesarLecturas(s, sensores, &alt, &sup, &mart);
            // aperturar archivo de salida
            GenerarReporte(sal, s, sensores, alt, sup, mart);
        }
    }
    fclose(ent);
    fclose(sal);

    return 0;
}
// Definiciones
void cargarSensores(FILE *f1, Sensor sensor[], int *cantSensores)
{
    int i, j;
    // recorremos el stact de sensores
    for (i = 0; i < (*cantSensores); i++)
    {
        // ler datos id,tiponodo, nunvalido
        fscanf(f1, "%d %c %d", &sensor[i].idSensor, &sensor[i].tipoNodo, &sensor[i].numLecturasValidas);

        for (j = 0; j < sensor[i].numLecturasValidas; j++)
        {
            fscanf(f1, "%f", &sensor[i].lecturas[j]);
        }
    }
}
void procesarLecturas(Sensor sensor[], int cantSensores, int *cantAlt, int *cantSup, int *cantMart)
{
    int i, j, alerta;
    float sum;
    // recorremos el stact de sensores
    *cantAlt = 0;
    *cantSup = 0;
    *cantMart = 0;
    for (i = 0; i < cantSensores; i++)
    {
        // ler datos id,tiponodo, nunvalido
        sum = 0.0;
        alerta = 0;
        for (j = 0; j < sensor[i].numLecturasValidas; j++)
        {

            sum += sensor[i].lecturas[j];
            if (sensor[i].lecturas[i] > 45.0)
            {
                alerta = 1;
            }
        }

        if (sum > 0)
        {
            sensor[i].promedio = sum / sensor[i].numLecturasValidas;
        }
        if (sensor[i].promedio > 38.0 || alerta == 1)
        {
            sensor[i].estadoOperativo = 0; // alerta
            if (sensor[i].tipoNodo == 'A')
            {
                (*cantAlt)++;
            }
            else if (sensor[i].tipoNodo == 'S')
            {
                (*cantSup)++;
            }
            else if (sensor[i].tipoNodo == 'M')
            {
                (*cantMart)++;
            }
        }
    }
}
void GenerarReporte(FILE *F2, Sensor sensor[], int cantSensores, int cantAlt, int cantSup, int cantMart)
{
    int i, j;
    fprintf(F2, "==================================================\n");
    fprintf(F2, "REPORTE DE MONITOREO DE TELEMETRÍA\n");
    fprintf(F2, "==================================================\n");
    fprintf(F2, "ID\tTIPO\tPROMEDIO\tPROMEDIO(°C)\tESTADO\n");
    fprintf(F2, "--------------------------------------------------\n");
    for (i = 0; i < cantSensores; i++)
    {
        // ler datos id,tiponodo, nunvalido
        // fprintf(F2, "%d %c %d", &sensor[i].idSensor, &sensor[i].tipoNodo, &sensor[i].numLecturasValidas);

        char *name;
        if (sensor[i].tipoNodo == 'A')
        {
            name = "Altitud";
        }
        else if (sensor[i].tipoNodo == 'S')
        {
            name = "Superficie";
        }
        else if (sensor[i].tipoNodo == 'M')
        {
            name = "Maritima";
        }
        // Operador ternario
        char *estado = (sensor[i].estadoOperativo == 0) ? "NORMAL" : "ALERTA";
        fprintf(F2, "%d\t%s\t%.2f\t%s\n", sensor[i].idSensor, name, sensor[i].promedio, estado);
    }
    // Resumen final
    fprintf(F2, "-------------------------------------------------\n");
    fprintf(F2, "RESUMEN DE ALERTAS POR TIPO DE NODO:\n");
    fprintf(F2, "- Altitud: %d alerta(s)\n", cantAlt);
    fprintf(F2, "- Superficie: %d alerta(s)\n", cantSup);
    fprintf(F2, "- Maritimas: %d alerta(s)\n", cantMart);
    fprintf(F2, "==================================================\n");
}