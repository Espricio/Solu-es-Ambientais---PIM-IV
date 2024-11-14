#include "display.h"

void produceRows()
{
    for (int i = 1; i <= 50; i++)
    {
        printf("*");
    }
    printf("\n");
}

char* getTodayDate() {
    // Aloca espaço para a data no formato "dd/mm/yyyy" + '\0'
    static char dataFormatada[11];

    // Obtém o tempo atual
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Formata a data como "dd/mm/yyyy"
    snprintf(dataFormatada, sizeof(dataFormatada), "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    return dataFormatada;
}