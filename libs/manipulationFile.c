#include "manipulationFile.h"

#define MAX_JSON_SIZE 1024

int officialWriteJSON(
    char nomecompleto[100],
    char dataNascimento[11],
    char cpf[13],
    char enderecoCompleto[200],
    char telefone[20],
    char email[100],
    char estadoCivil[20],
    char nacionalidade[50],
    char cargo[50],
    char dataAdmissao[11],
    char departamento[50],
    char senhaCriptografada[20],
    float salario)
{
    cJSON *root = cJSON_CreateObject();

    cJSON_AddStringToObject(root, "nomecompleto", nomecompleto);
    cJSON_AddStringToObject(root, "dataNascimento", dataNascimento);
    cJSON_AddStringToObject(root, "cpf", cpf);
    cJSON_AddStringToObject(root, "enderecoCompleto", enderecoCompleto);
    cJSON_AddStringToObject(root, "telefone", telefone);
    cJSON_AddStringToObject(root, "email", email);
    cJSON_AddStringToObject(root, "estadoCivil", estadoCivil);
    cJSON_AddStringToObject(root, "nacionalidade", nacionalidade);
    cJSON_AddStringToObject(root, "cargo", cargo);
    cJSON_AddStringToObject(root, "dataAdmissao", dataAdmissao);
    cJSON_AddStringToObject(root, "departamento", departamento);
    cJSON_AddStringToObject(root, "senhaCriptografada", senhaCriptografada);
    cJSON_AddNumberToObject(root, "salario", salario);

    char *json_string = cJSON_Print(root);

    if (json_string == NULL)
    {
        cJSON_Delete(root);
        return 0;
    }

    FILE *file = fopen("dataOfficial.json", "w");
    if (file == NULL)
    {
        free(json_string);
        cJSON_Delete(root);
        return 0;
    }

    // Escrever a string JSON no arquivo
    fprintf(file, "%s\n", json_string);

    // Fechar o arquivo
    fclose(file);

    // Limpar a memória
    free(json_string);
    cJSON_Delete(root);

    return 1;
}

char *officialReadJSON(const char *key)
{
    FILE *file = fopen("dataOfficial.json", "r");

    if (file == NULL)
    {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *json_string = (char *)malloc(file_size + 1);
    if (json_string == NULL)
    {
        fclose(file);
        return NULL;
    }

    fread(json_string, 1, file_size, file);
    json_string[file_size] = '\0';

    fclose(file);

    cJSON *root = cJSON_Parse(json_string);
    if (root == NULL)
    {
        printf("Erro ao analisar o arquivo JSON\n");
        free(json_string);
        return NULL;
    }

    cJSON *item = cJSON_GetObjectItem(root, key);
    if (item == NULL)
    {
        cJSON_Delete(root);
        free(json_string);
        return NULL;
    }

    char *value = (char *)malloc(strlen(item->valuestring) + 1);
    if (value != NULL)
    {
        strcpy(value, item->valuestring);
    }

    cJSON_Delete(root);
    free(json_string);

    return value;
}