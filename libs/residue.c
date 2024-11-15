#include "residue.h"

void registerResidue()
{
    char nomeEmpresa[100],
        cnpj[20],
        cnpjAnterior[20],
        dataRegistro[11];

    int monitores = 0,
        cpus = 0,
        perifericos = 0,
        impressoras = 0,
        pcis = 0,
        telefones = 0,
        roteadores = 0;

    double cabosEfios = 0,
           baterias = 0,
           diversos = 0;

    int validRegister;

    system("cls");
    produceRows();
    printf("%s", titlePage);
    produceRows();
    printf("FORMULÁRIO DE REGISTRO DE RESÍDUOS ELETRÔNICOS\n");
    produceRows();

    do
    {
        produceRows();
        printf("Informe o CNPJ da Empresa (XX.XXX.XXX/XXXX-XX):");
        fgets(cnpj, 20, stdin);

        cnpj[strcspn(cnpj, "\n")] = '\0';
        strncpy(cnpjAnterior, cnpj, strlen(cnpj) + 1);

        if (clientReadCNPJ(cnpjAnterior) == 0)
        {
            printf("CNPJ NÃO CADASTRADO!\n");
        }

    } while (validCNPJ(cnpjAnterior) == 0 || clientReadCNPJ(cnpjAnterior) == 0);

    strncpy(nomeEmpresa, clientReadName(cnpjAnterior), strlen(clientReadName(cnpjAnterior)) + 1);

    strncpy(dataRegistro, getTodayDate(), strlen(getTodayDate()) + 1);

    do
    {
        produceRows();
        printf("INFORME EM UNIDADES\n MONITORES da %s que foram tratados em %s:", nomeEmpresa, dataRegistro);
        scanf("%d", &monitores);

        if (monitores < 0)
        {
            printf("NÃO PODE SER NEGATIVO!\n");
        }

    } while (monitores < 0);
    setbuf(stdin, NULL);

    do
    {
        produceRows();
        printf(" CPUS da %s que foram tratadas em %s:", nomeEmpresa, dataRegistro);
        scanf("%d", &cpus);

        if (cpus < 0)
        {
            printf("NÃO PODE SER NEGATIVO!\n");
        }

    } while (cpus < 0);
    setbuf(stdin, NULL);

    do
    {
        produceRows();
        printf(" PERIFÉRICOS da %s que foram tratados em %s:", nomeEmpresa, dataRegistro);
        scanf("%d", &perifericos);

        if (perifericos < 0)
        {
            printf("NÃO PODE SER NEGATIVO!\n");
        }

    } while (perifericos < 0);
    setbuf(stdin, NULL);

    do
    {
        produceRows();
        printf(" IMPRESSORAS da %s que foram tratadas em %s:", nomeEmpresa, dataRegistro);
        scanf("%d", &impressoras);

        if (impressoras < 0)
        {
            printf("NÃO PODE SER NEGATIVO!\n");
        }

    } while (impressoras < 0);
    setbuf(stdin, NULL);

    do
    {
        produceRows();
        printf(" PCIs da %s que foram tratadas em %s:", nomeEmpresa, dataRegistro);
        scanf("%d", &pcis);

        if (impressoras < 0)
        {
            printf("NÃO PODE SER NEGATIVO!\n");
        }

    } while (pcis < 0);
    setbuf(stdin, NULL);

    do
    {
        produceRows();
        printf(" TELEFONES da %s que foram tratados em %s:", nomeEmpresa, dataRegistro);
        scanf("%d", &telefones);

        if (telefones < 0)
        {
            printf("NÃO PODE SER NEGATIVO!\n");
        }

    } while (telefones < 0);
    setbuf(stdin, NULL);

    do
    {
        produceRows();
        printf(" ROTEADORES da %s que foram tratados em %s:", nomeEmpresa, dataRegistro);
        scanf("%d", &roteadores);

        if (roteadores < 0)
        {
            printf("NÃO PODE SER NEGATIVO!\n");
        }

    } while (roteadores < 0);
    setbuf(stdin, NULL);

    do
    {
        produceRows();
        printf("INFORME O PESO\n CABOS E FIOS (em kg) da %s que foram tratados em %s:", nomeEmpresa, dataRegistro);
        scanf("%lf", &cabosEfios);

        cabosEfios = round(cabosEfios * 100) / 100;

        if (cabosEfios < 0)
        {
            printf("NÃO PODE SER NEGATIVO!\n");
        }

    } while (cabosEfios < 0);
    setbuf(stdin, NULL);

    do
    {
        produceRows();
        printf(" BATERIAS (em kg) da %s que foram tratadas em %s:", nomeEmpresa, dataRegistro);
        scanf("%lf", &baterias);

        baterias = round(baterias * 100) / 100;

        if (baterias < 0)
        {
            printf("NÃO PODE SER NEGATIVO!\n");
        }

    } while (baterias < 0);
    setbuf(stdin, NULL);

    do
    {
        produceRows();
        printf(" DIVERSOS (em kg) da %s que foram tratados em %s:", nomeEmpresa, dataRegistro);
        scanf("%lf", &diversos);

        diversos = round(diversos * 100) / 100;

        if (diversos < 0)
        {
            printf("NÃO PODE SER NEGATIVO!\n");
        }

    } while (diversos < 0);
    setbuf(stdin, NULL);

    validRegister = residueWriteJSON(cnpj,
                                     dataRegistro,
                                     monitores,
                                     cpus,
                                     perifericos,
                                     impressoras,
                                     pcis,
                                     telefones,
                                     roteadores,
                                     cabosEfios,
                                     baterias,
                                     diversos);

    if (validRegister == 1)
    {
        printf("Registrado com sucesso!\n");
        system("pause");
    }
    else
    {
        printf("ERRO AO REGISTRAR RESÍDUO :(\n");
        system("pause");
    }
}

void listResidue()
{

    system("cls");
    produceRows();
    printf("%s", titlePage);
    produceRows();
    printf("LISTA DE CLIENTES COM RESÍDUOS REGISTRADOS\n");
    produceRows();

    int choice, validReport = 0;

    cJSON *residues = residueRead();

    if (!cJSON_IsArray(residues))
    {
        printf("Erro ao ler resíduos.\n");
        return;
    }

    int array_size = cJSON_GetArraySize(residues);

    char printedCNPJs[array_size][20]; // Declara um array para armazenar os CNPJs já impressos, com um tamanho de 20 caracteres para cada CNPJ
    int printedCount = 0;              // Inicializa uma variável para contar o número de CNPJs já impressos

    // Itera sobre todos os registros de resíduos
    for (int i = 0; i < array_size; i++)
    {
        // Obtém o objeto "resíduo" da lista de resíduos
        cJSON *residue = cJSON_GetArrayItem(residues, i);

        // Obtém o valor do campo "cnpj" dentro do objeto "resíduo"
        cJSON *clientCNPJ = cJSON_GetObjectItem(residue, "cnpj");

        if (clientCNPJ != NULL) // Verifica se o CNPJ foi encontrado no objeto "resíduo"
        {
            if (printedCount == 0) // Se nenhum CNPJ foi impresso ainda
            {
                // Imprime o primeiro CNPJ e o nome do cliente associado
                printf("%d | %s - %s\n", printedCount + 1, clientReadName(clientCNPJ->valuestring), clientCNPJ->valuestring);

                // Armazena o CNPJ impresso no array "printedCNPJs"
                strncpy(printedCNPJs[printedCount], clientCNPJ->valuestring, strlen(clientCNPJ->valuestring) + 1);

                // Incrementa o contador de CNPJs impressos
                printedCount++;
            }
            else // Se já houve CNPJs impressos
            {
                // Verifica se o CNPJ atual já foi impresso antes
                for (int j = 0; j < printedCount; j++)
                {
                    // Se o CNPJ atual não corresponde a nenhum dos já impressos
                    if (strcmp(clientCNPJ->valuestring, printedCNPJs[j]) != 0)
                    {
                        // Imprime o novo CNPJ e o nome do cliente associado
                        printf("%d | %s - %s\n", printedCount + 1, clientReadName(clientCNPJ->valuestring), clientCNPJ->valuestring);

                        // Armazena o novo CNPJ impresso no array "printedCNPJs"
                        strncpy(printedCNPJs[printedCount], clientCNPJ->valuestring, strlen(clientCNPJ->valuestring) + 1);

                        // Incrementa o contador de CNPJs impressos
                        printedCount++;
                    }
                }
            }
        }
    }

    cJSON_Delete(residues);

    do
    {

        printf("\nEscolha um cliente para gerar relatório:");
        scanf("%d", &choice);
        setbuf(stdin, NULL);

        if (choice < 1 || choice > printedCount)
        {
            printf("Opção Inválida!");
        }

    } while (choice < 1 || choice > printedCount);

    validReport = generateIndividualReport(printedCNPJs[choice - 1]);

    if (validReport == 0)
    {
        printf("Não foi possível gerar o relatório! :(\n");
        system("pause");
    }
    
}
