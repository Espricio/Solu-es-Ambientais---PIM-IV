#include "manipulationFile.h"

int employeeWriteJSON(
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

    FILE *file = fopen("data/dataEmployee.json", "r+");

    // Cria um array JSON para armazenar funcionários
    cJSON *root = NULL;
    cJSON *funcionariosArray = NULL;

    // Verifica se o arquivo não está vazio e faz a leitura
    if (file != NULL)
    {
        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        fseek(file, 0, SEEK_SET);

        if (file_size > 0)
        {
            char *json_string = (char *)malloc(file_size + 1);
            fread(json_string, 1, file_size, file);
            json_string[file_size] = '\0';
            fclose(file);

            root = cJSON_Parse(json_string);
            free(json_string);
        }
        else
        {
            fclose(file);                            // Arquivo vazio
            root = cJSON_CreateObject();             // Cria o objeto principal
            funcionariosArray = cJSON_CreateArray(); // Cria o array de funcionários
            cJSON_AddItemToObject(root, "funcionarios", funcionariosArray);
        }
    }

    if (root == NULL)
    {
        root = cJSON_CreateObject();             // Cria o objeto principal
        funcionariosArray = cJSON_CreateArray(); // Cria o array de funcionários
        cJSON_AddItemToObject(root, "funcionarios", funcionariosArray);
    }
    else
    {
        // Se já existe, acessa o array de funcionários
        funcionariosArray = cJSON_GetObjectItem(root, "funcionarios");
        if (!cJSON_IsArray(funcionariosArray))
        {
            funcionariosArray = cJSON_CreateArray();
            cJSON_AddItemToObject(root, "funcionarios", funcionariosArray);
        }
    }

    int idFunc = cJSON_GetArraySize(funcionariosArray) + 1;

    cJSON *newEmployee = cJSON_CreateObject();

    cJSON_AddNumberToObject(newEmployee, "idFunc", idFunc);
    cJSON_AddStringToObject(newEmployee, "nomecompleto", nomecompleto);
    cJSON_AddStringToObject(newEmployee, "dataNascimento", dataNascimento);
    cJSON_AddStringToObject(newEmployee, "cpf", cpf);
    cJSON_AddStringToObject(newEmployee, "enderecoCompleto", enderecoCompleto);
    cJSON_AddStringToObject(newEmployee, "telefone", telefone);
    cJSON_AddStringToObject(newEmployee, "email", email);
    cJSON_AddStringToObject(newEmployee, "estadoCivil", estadoCivil);
    cJSON_AddStringToObject(newEmployee, "nacionalidade", nacionalidade);
    cJSON_AddStringToObject(newEmployee, "cargo", cargo);
    cJSON_AddStringToObject(newEmployee, "dataAdmissao", dataAdmissao);
    cJSON_AddStringToObject(newEmployee, "departamento", departamento);
    cJSON_AddStringToObject(newEmployee, "senhaCriptografada", senhaCriptografada);
    cJSON_AddNumberToObject(newEmployee, "salario", salario);

    cJSON_AddItemToArray(funcionariosArray, newEmployee);

    char *json_string = cJSON_Print(root);

    if (json_string == NULL)
    {
        cJSON_Delete(root);
        return 0;
    }

    // Reabre o arquivo em modo "w+" para sobrescrever os dados
    file = fopen("data/dataEmployee.json", "w");
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

int employeeReadEmail(const char *email)
{
    FILE *file = fopen("data/dataEmployee.json", "r");

    if (file == NULL)
    {
        perror("Erro:");
        return 0;
    }

    // Move o cursor para o final do arquivo para obter o tamanho
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Aloca memória para armazenar o conteúdo JSON
    char *json_string = (char *)malloc(file_size + 1);
    if (json_string == NULL)
    {
        fclose(file);
        perror("Erro:");
        return 0;
    }

    // Lê o conteúdo do arquivo JSON
    fread(json_string, 1, file_size, file);
    json_string[file_size] = '\0';

    fclose(file);

    // Faz o parse do JSON
    cJSON *root = cJSON_Parse(json_string);
    if (root == NULL)
    {
        free(json_string);
        perror("Erro:");
        return 0;
    }

    // Obtém o array de funcionários
    cJSON *funcionariosArray = cJSON_GetObjectItem(root, "funcionarios");
    if (!cJSON_IsArray(funcionariosArray))
    {
        cJSON_Delete(root);
        free(json_string);
        perror("Erro:");
        return 0;
    }

    // Procura pelo funcionário com o email
    int array_size = cJSON_GetArraySize(funcionariosArray);
    int found = 0;
    for (int i = 0; i < array_size; i++)
    {
        cJSON *employee = cJSON_GetArrayItem(funcionariosArray, i);
        cJSON *employeeEmail = cJSON_GetObjectItem(employee, "email");

        if (employeeEmail != NULL && cJSON_IsString(employeeEmail) && strcmp(employeeEmail->valuestring, email) == 0)
        {
            found = 1;
            break;
        }
    }

    cJSON_Delete(root);
    free(json_string);

    return found;
}

int employeeReadPassword(const char *email, const char *password)
{
    FILE *file = fopen("data/dataEmployee.json", "r");

    if (file == NULL)
    {
        perror("Erro:");
        return 0;
    }

    // Move o cursor para o final do arquivo para obter o tamanho
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Aloca memória para armazenar o conteúdo JSON
    char *json_string = (char *)malloc(file_size + 1);
    if (json_string == NULL)
    {
        fclose(file);
        perror("Erro:");
        return 0;
    }

    // Lê o conteúdo do arquivo JSON
    fread(json_string, 1, file_size, file);
    json_string[file_size] = '\0';

    fclose(file);

    // Faz o parse do JSON
    cJSON *root = cJSON_Parse(json_string);
    if (root == NULL)
    {
        free(json_string);
        perror("Erro:");
        return 0;
    }

    // Obtém o array de funcionários
    cJSON *funcionariosArray = cJSON_GetObjectItem(root, "funcionarios");
    if (!cJSON_IsArray(funcionariosArray))
    {
        cJSON_Delete(root);
        free(json_string);
        perror("Erro:");
        return 0;
    }

    // Procura pelo funcionário com o email
    int array_size = cJSON_GetArraySize(funcionariosArray);
    int found = 0;
    for (int i = 0; i < array_size; i++)
    {
        cJSON *employee = cJSON_GetArrayItem(funcionariosArray, i);
        cJSON *employeeEmail = cJSON_GetObjectItem(employee, "email");
        cJSON *employeePassword = cJSON_GetObjectItem(employee, "senhaCriptografada");

        if ((employeeEmail != NULL && cJSON_IsString(employeeEmail) && strcmp(employeeEmail->valuestring, email) == 0) && (employeePassword != NULL && cJSON_IsString(employeePassword) && strcmp(employeePassword->valuestring, password) == 0))
        {
            found = 1;
            break;
        }
    }

    cJSON_Delete(root);
    free(json_string);

    return found;
}

int clientWriteJSON(
    char nomeResponsavel[100],
    char nomeEmpresa[100],
    char cnpj[19],           
    char razaoSocial[100],
    char nomeFantasia[100],
    char telefone[20],
    char enderecoCompleto[200],
    char email[100],
    char dataAbertura[11]   
){
    FILE *file = fopen("data/dataClient.json", "r+");

    // Cria um array JSON para armazenar clientes
    cJSON *root = NULL;
    cJSON *clientesArray = NULL;

    // Verifica se o arquivo não está vazio e faz a leitura
    if (file != NULL)
    {
        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        fseek(file, 0, SEEK_SET);

        if (file_size > 0)
        {
            char *json_string = (char *)malloc(file_size + 1);
            fread(json_string, 1, file_size, file);
            json_string[file_size] = '\0';
            fclose(file);

            root = cJSON_Parse(json_string);
            free(json_string);
        }
        else
        {
            fclose(file);                            // Arquivo vazio
            root = cJSON_CreateObject();             // Cria o objeto principal
            clientesArray = cJSON_CreateArray();     // Cria o array de clientes
            cJSON_AddItemToObject(root, "clientes", clientesArray);
        }
    }

    if (root == NULL)
    {
        root = cJSON_CreateObject();             // Cria o objeto principal
        clientesArray = cJSON_CreateArray();     // Cria o array de clientes
        cJSON_AddItemToObject(root, "clientes", clientesArray);
    }
    else
    {
        // Se já existe, acessa o array de clientes
        clientesArray = cJSON_GetObjectItem(root, "clientes");
        if (!cJSON_IsArray(clientesArray))
        {
            clientesArray = cJSON_CreateArray();
            cJSON_AddItemToObject(root, "clientes", clientesArray);
        }
    }

    int idClient = cJSON_GetArraySize(clientesArray) + 1;

    cJSON *newClient = cJSON_CreateObject();

    cJSON_AddNumberToObject(newClient, "idClient", idClient);
    cJSON_AddStringToObject(newClient, "nomeResponsavel", nomeResponsavel);
    cJSON_AddStringToObject(newClient, "nomeEmpresa", nomeEmpresa);
    cJSON_AddStringToObject(newClient, "cnpj", cnpj);
    cJSON_AddStringToObject(newClient, "razaoSocial", razaoSocial);
    cJSON_AddStringToObject(newClient, "nomeFantasia", nomeFantasia);
    cJSON_AddStringToObject(newClient, "telefone", telefone);
    cJSON_AddStringToObject(newClient, "enderecoCompleto", enderecoCompleto);
    cJSON_AddStringToObject(newClient, "email", email);
    cJSON_AddStringToObject(newClient, "dataAbertura", dataAbertura);

    cJSON_AddItemToArray(clientesArray, newClient);

    char *json_string = cJSON_Print(root);

    if (json_string == NULL)
    {
        cJSON_Delete(root);
        return 0;
    }

    // Reabre o arquivo em modo "w+" para sobrescrever os dados
    file = fopen("data/dataClient.json", "w");
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

int clientReadCNPJ(const char *cnpj)
{
    FILE *file = fopen("data/dataClient.json", "r");

    if (file == NULL)
    {
        perror("Erro:");
        return 0;
    }

    // Move o cursor para o final do arquivo para obter o tamanho
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Aloca memória para armazenar o conteúdo JSON
    char *json_string = (char *)malloc(file_size + 1);
    if (json_string == NULL)
    {
        fclose(file);
        perror("Erro:");
        return 0;
    }

    // Lê o conteúdo do arquivo JSON
    fread(json_string, 1, file_size, file);
    json_string[file_size] = '\0';

    fclose(file);

    // Faz o parse do JSON
    cJSON *root = cJSON_Parse(json_string);
    if (root == NULL)
    {
        free(json_string);
        perror("Erro:");
        return 0;
    }

    // Obtém o array de funcionários
    cJSON *clientesArray = cJSON_GetObjectItem(root, "Clientes");
    if (!cJSON_IsArray(clientesArray))
    {
        cJSON_Delete(root);
        free(json_string);
        perror("Erro:");
        return 0;
    }

    // Procura pelo funcionário com o email
    int array_size = cJSON_GetArraySize(clientesArray);
    int found = 0;
    for (int i = 0; i < array_size; i++)
    {
        cJSON *client = cJSON_GetArrayItem(clientesArray, i);
        cJSON *clientCNPJ = cJSON_GetObjectItem(client, "cnpj");

        if (clientCNPJ != NULL && cJSON_IsString(clientCNPJ) && strcmp(clientCNPJ->valuestring, cnpj) == 0)
        {
            found = 1;
            break;
        }
    }

    cJSON_Delete(root);
    free(json_string);

    return found;
}

char* clientReadName(const char *cnpj){
    FILE *file = fopen("data/dataClient.json", "r");

    if (file == NULL)
    {
        perror("Erro:");
        return 0;
    }

    // Move o cursor para o final do arquivo para obter o tamanho
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Aloca memória para armazenar o conteúdo JSON
    char *json_string = (char *)malloc(file_size + 1);
    if (json_string == NULL)
    {
        fclose(file);
        perror("Erro:");
        return 0;
    }

    // Lê o conteúdo do arquivo JSON
    fread(json_string, 1, file_size, file);
    json_string[file_size] = '\0';

    fclose(file);

    // Faz o parse do JSON
    cJSON *root = cJSON_Parse(json_string);
    if (root == NULL)
    {
        free(json_string);
        perror("Erro:");
        return 0;
    }

    // Obtém o array de funcionários
    cJSON *clientesArray = cJSON_GetObjectItem(root, "Clientes");
    if (!cJSON_IsArray(clientesArray))
    {
        cJSON_Delete(root);
        free(json_string);
        perror("Erro:");
        return 0;
    }

    // Procura pelo funcionário com o email
    int array_size = cJSON_GetArraySize(clientesArray);
    static char clientName[100];
    for (int i = 0; i < array_size; i++)
    {
        cJSON *client = cJSON_GetArrayItem(clientesArray, i);
        cJSON *clientCNPJ = cJSON_GetObjectItem(client, "cnpj");
        cJSON *clientNameJSON = cJSON_GetObjectItem(client, "nomeEmpresa");

        if (clientCNPJ != NULL && cJSON_IsString(clientCNPJ) && strcmp(clientCNPJ->valuestring, cnpj) == 0)
        {
            strncpy(clientName, clientNameJSON->valuestring, strlen(clientNameJSON->valuestring) + 1);
            break;
        }
    }

    cJSON_Delete(root);
    free(json_string);

    return clientName;
}

int residueWriteJSON(
    char cnpj[20],
    char dataRegistro[11],
    int monitores,
    int cpus,
    int perifericos,
    int impressoras,
    int pcis,
    int telefones,
    int roteadores,
    double cabosEfios,
    double baterias,
    double diversos
) {
    FILE *file = fopen("data/dataResidue.json", "r+");
    cJSON *root = NULL;
    cJSON *residuosArray = NULL;

    // Verifica se o arquivo não está vazio e faz a leitura
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        fseek(file, 0, SEEK_SET);

        if (file_size > 0) {
            char *json_string = (char *)malloc(file_size + 1);
            fread(json_string, 1, file_size, file);
            json_string[file_size] = '\0';
            fclose(file);

            root = cJSON_Parse(json_string);
            free(json_string);
        } else {
            fclose(file);
            root = cJSON_CreateObject();
            residuosArray = cJSON_CreateArray();
            cJSON_AddItemToObject(root, "residuos", residuosArray);
        }
    }

    if (root == NULL) {
        root = cJSON_CreateObject();
        residuosArray = cJSON_CreateArray();
        cJSON_AddItemToObject(root, "residuos", residuosArray);
    } else {
        residuosArray = cJSON_GetObjectItem(root, "residuos");
        if (!cJSON_IsArray(residuosArray)) {
            residuosArray = cJSON_CreateArray();
            cJSON_AddItemToObject(root, "residuos", residuosArray);
        }
    }

    int idResiduo = cJSON_GetArraySize(residuosArray) + 1;
    cJSON *newResidue = cJSON_CreateObject();
    cJSON_AddNumberToObject(newResidue, "idResiduo", idResiduo);
    cJSON_AddStringToObject(newResidue, "cnpj", cnpj);
    cJSON_AddStringToObject(newResidue, "dataRegistro", dataRegistro);
    cJSON_AddNumberToObject(newResidue, "monitores", monitores);
    cJSON_AddNumberToObject(newResidue, "cpus", cpus);
    cJSON_AddNumberToObject(newResidue, "perifericos", perifericos);
    cJSON_AddNumberToObject(newResidue, "impressoras", impressoras);
    cJSON_AddNumberToObject(newResidue, "pcis", pcis);
    cJSON_AddNumberToObject(newResidue, "telefones", telefones);
    cJSON_AddNumberToObject(newResidue, "roteadores", roteadores);
    cJSON_AddNumberToObject(newResidue, "cabosEfios", cabosEfios);
    cJSON_AddNumberToObject(newResidue, "baterias", baterias);
    cJSON_AddNumberToObject(newResidue, "diversos", diversos);

    cJSON_AddItemToArray(residuosArray, newResidue);

    char *json_string = cJSON_Print(root);
    if (json_string == NULL) {
        cJSON_Delete(root);
        return 0;
    }

    file = fopen("data/dataResidue.json", "w");
    if (file == NULL) {
        free(json_string);
        cJSON_Delete(root);
        return 0;
    }

    fprintf(file, "%s\n", json_string);
    fclose(file);

    free(json_string);
    cJSON_Delete(root);

    return 1;
}
