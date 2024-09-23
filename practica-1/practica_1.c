/*
    Práctica 1 - Algorítmos Bioinspirados
    Juan Manuel Alvarado Sandoval 5BM1
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Definir una variable para 'mem' que apuntará a una ubicación específica.
    int var_mem = 2;     // Suponemos que 'mem' comienza con el valor 2, la posición de la instrucción actual (según Mitchell).
    int *mem = &var_mem; // 'mem' es un puntero que apunta a la dirección de var_mem.

    // L es la siguiente posición a la que apunta mem.
    int L = *mem + 1; // L se establece como mem + 1, por lo tanto, L = 3.

    // Nombre del archivo fuente
    char *filename = __FILE__;
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error al abrir el archivo %s\n", filename);
        return 1;
    }

    char line[256];
    int current_line = 1; // Contador para rastrear la línea actual

    // Imprimir las primeras dos líneas del programa
    printf("program copy\n");
    printf("L = mem + 1;\n");

    // Leer e imprimir cada línea del archivo fuente, comenzando desde la línea 3
    while (fgets(line, sizeof(line), file))
    {
        // Empezar a copiar desde la línea 3 en adelante
        if (current_line >= 3)
        {
            // Imprimir la línea actual del código fuente
            printf("%s", line);

            // Calcular e imprimir el cubo de L para cada línea copiada
            int cube = L * L * L; // Calcular el cubo de L
            printf("printf(\"Cubo de L (%%d) es: %%d\\n\", %d, %d);\n", L, cube);
            L++;
        }
        current_line++;
    }

    // Imprimir "end" para finalizar la copia
    printf("end\n");

    fclose(file);
    return 0;
}
