#include "client.h"

void registerClient()
{
    char nomeResponsavel[100],
        nomeResponsavelAnterior[100],
        nomeEmpresa[100],
        nomeEmpresaAnterior[100],
        cnpj[20],
        cnpjAnterior[20],
        razaoSocial[100],
        razaoSocialAnterior[100],
        nomeFantasia[100],
        nomeFantasiaAnterior[100],
        telefone[20],
        telefoneAnterior[20],
        enderecoCompleto[200],
        enderecoCompletoAnterior[200],
        email[100],
        emailAnterior[100],
        dataAbertura[11],
        dataAberturaAnterior[11];
    int validRegister;

    system("cls");
    produceRows();
    printf("%s", titlePage);
    produceRows();
    printf("FORMULÁRIO DE REGISTRO DE CLIENTE\n");
    produceRows();

    do
    {
        printf("Informe o Nome do Responsável:");
        fgets(nomeResponsavel, 100, stdin);

        nomeResponsavel[strcspn(nomeResponsavel, "\n")] = '\0';
        strncpy(nomeResponsavelAnterior, nomeResponsavel, strlen(nomeResponsavel) + 1);

        if (strlen(nomeResponsavelAnterior) == 0)
        {
            printf("NOME DO RESPONSÁVEL INVÁLIDO!\n");
        }

    } while (strlen(nomeResponsavelAnterior) == 0);

    do
    {
        produceRows();
        printf("Informe o Nome da Empresa (ou Nome Fantasia):");
        fgets(nomeEmpresa, 100, stdin);

        nomeEmpresa[strcspn(nomeEmpresa, "\n")] = '\0';
        strncpy(nomeEmpresaAnterior, nomeEmpresa, strlen(nomeEmpresa) + 1);

        if (strlen(nomeEmpresaAnterior) == 0)
        {
            printf("NOME DA EMPRESA INVÁLIDO!\n");
        }

    } while (strlen(nomeEmpresaAnterior) == 0);

    do
    {
        produceRows();
        printf("Informe o CNPJ (XX.XXX.XXX/XXXX-XX):");
        fgets(cnpj, 20, stdin);

        cnpj[strcspn(cnpj, "\n")] = '\0';
        strncpy(cnpjAnterior, cnpj, strlen(cnpj) + 1);

    } while (validCNPJ(cnpjAnterior) == 0);

    do
    {
        produceRows();
        printf("Informe a Razão Social:");
        fgets(razaoSocial, 100, stdin);

        razaoSocial[strcspn(razaoSocial, "\n")] = '\0';
        strncpy(razaoSocialAnterior, razaoSocial, strlen(razaoSocial) + 1);

        if (strlen(razaoSocialAnterior) == 0)
        {
            printf("RAZÃO SOCIAL INVÁLIDA!\n");
        }

    } while (strlen(razaoSocialAnterior) == 0);

    do
    {
        produceRows();
        printf("Informe o Nome Fantasia:");
        fgets(nomeFantasia, 100, stdin);

        nomeFantasia[strcspn(nomeFantasia, "\n")] = '\0';
        strncpy(nomeFantasiaAnterior, nomeFantasia, strlen(nomeFantasia) + 1);

        if (strlen(nomeFantasiaAnterior) == 0)
        {
            printf("NOME FANTASIA INVÁLIDO!\n");
        }

    } while (strlen(nomeFantasiaAnterior) == 0);

    do
    {
        produceRows();
        printf("Informe o Telefone (XX)XXXXX-XXXX:");
        fgets(telefone, 20, stdin);

        telefone[strcspn(telefone, "\n")] = '\0';
        strncpy(telefoneAnterior, telefone, strlen(telefone) + 1);

    } while (validTel(telefoneAnterior) == 0);

    do
    {
        produceRows();
        printf("Informe o Endereço Completo:");
        fgets(enderecoCompleto, 200, stdin);

        enderecoCompleto[strcspn(enderecoCompleto, "\n")] = '\0';
        strncpy(enderecoCompletoAnterior, enderecoCompleto, strlen(enderecoCompleto) + 1);

        if (strlen(enderecoCompletoAnterior) == 0)
        {
            printf("ENDEREÇO INVÁLIDO!\n");
        }

    } while (strlen(enderecoCompletoAnterior) == 0);

    do
    {
        produceRows();
        printf("Informe o E-mail:");
        fgets(email, 100, stdin);

        email[strcspn(email, "\n")] = '\0';
        strncpy(emailAnterior, email, strlen(email) + 1);

    } while (validEmail(emailAnterior) == 0);

    do
    {
        produceRows();
        printf("Informe a Data de Abertura (dd/mm/aaaa):");
        fgets(dataAbertura, 12, stdin);

        dataAbertura[strcspn(dataAbertura, "\n")] = '\0';
        strncpy(dataAberturaAnterior, dataAbertura, strlen(dataAbertura) + 1);

    } while (validDate(dataAberturaAnterior, 1) == 0);

    validRegister = clientWriteJSON(nomeResponsavel,
                                    nomeEmpresa,
                                    cnpj,
                                    razaoSocial,
                                    nomeFantasia,
                                    telefone,
                                    enderecoCompleto,
                                    email,
                                    dataAbertura);

    if (validRegister == 1)
    {
        printf("Cliente registrado com sucesso!\n");
    }
    else
    {
        printf("ERRO AO REGISTRAR CLIENTE :(\n");
    }
}