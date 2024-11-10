#include "manipulationFile.h"

void createJSON()
{
    cJSON *root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "nome", "João");
    cJSON_AddNumberToObject(root, "idade", 30);

    // Converter para string
    char *string = cJSON_Print(root);
    printf("%s\n", string);
}