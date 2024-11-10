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

void readJSON()
{
    char json_data[MAX_JSON_SIZE];

    // Abrir o arquivo JSON
    FILE *file = fopen("dados.json", "r");
    if (file == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo para leitura\n");
    }

    size_t len = fread(json_data, 1, MAX_JSON_SIZE - 1, file);
    json_data[len] = '\0';

    fclose(file);

    cJSON *root = cJSON_Parse(json_data);

    cJSON *nome = cJSON_GetObjectItem(root, "nome");
    cJSON *idade = cJSON_GetObjectItem(root, "idade");
    cJSON *cidade = cJSON_GetObjectItem(root, "cidade");

    printf("Nome: %s\n", nome->valuestring);
    printf("Idade: %d\n", idade->valueint);
    printf("Cidade: %s\n", cidade->valuestring);

    cJSON_Delete(root);
}