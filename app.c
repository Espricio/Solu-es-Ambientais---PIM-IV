#include <stdio.h>
#include <stdlib.h> // Biblioteca para controlar o sistema
#include <locale.h>
#include <conio.h>                 // Biblioteca necessária para getch()
#include <string.h>                // Biblioteca com funções para tratamento de string
#include <ctype.h>                 // Biblioteca com funções para tratamento de caracteres
#include "libs/validators.h"       // Módulo para validar campo de formulários
#include "libs/manipulationFile.h" // Módulo para manipular arquivos

const char titlePage[] = "Startup de Soluções Ambientais\n"; // Constante global que contém o título da aplicação

void authentication();                                       // Função para verificar Login
int startMenu();                                             // Menu Inicial da Aplicação
void registerOfficial();                                     // Função de registro de funcionários
void produceRows();                                          // Produz linhas para separar os conteúdos
void collectionPassword(char senha[]);                       // Coleta a senha ocultando os caracteres com *
void encryptPassword(char password[20], char encrypted[20]); // Função que criptografa usando a cifra de César

int main()
{
    setlocale(LC_ALL, "PT-BR");
    system("chcp 65001"); // Configura o terminal para UTF-8
    system("cls");

    produceRows();
    printf("%s", titlePage);

    authentication();

    int choice; // Variável para escolha dentro do menu

    do
    {
        choice = startMenu();
    } while (choice != 3);

    return 0;
}

void authentication()
{
    char emailAccess[100], emailAccessAnterior[100], passwordAccess[20], encrypted[20];
    char emailJSON[100], encryptedJSON[20];
    int validPassword = 0;

    do
    {
        produceRows();
        printf("LOGIN\n");
        produceRows();
        printf("E-MAIL:");

        fgets(emailAccess, 100, stdin);
        emailAccess[strcspn(emailAccess, "\n")] = '\0';
        strncpy(emailAccessAnterior, emailAccess, strlen(emailAccess) + 1);

        strncpy(emailJSON, officialReadJSON("email"), strlen(officialReadJSON("email")) + 1);

        printf("SENHA:");
        collectionPassword(passwordAccess);

        encryptPassword(passwordAccess, encrypted);

        strncpy(encryptedJSON, officialReadJSON("senhaCriptografada"), strlen(officialReadJSON("senhaCriptografada")) + 1);

        if (strcmp(emailAccess, emailJSON) != 0)
        {
            printf("E-MAIL INVÁLIDO!\n");
        }

        if (strcmp(encrypted, encryptedJSON) != 0)
        {
            printf("SENHA INVÁLIDA!\n");
        }

    } while (strcmp(emailAccess, emailJSON) != 0 || strcmp(encrypted, encryptedJSON) != 0);
}

int startMenu()
{
    char startMenu[] = "MENU INICIAL\n 1 - CADASTRAR CLIENTE\n 2 - CADASTRAR FUNCIONÁRIO\n 3 - FINALIZAR\n";
    int choice;
    system("cls");

    produceRows();
    printf("%s", titlePage);
    produceRows();
    printf("%s", startMenu);
    produceRows();

    printf("Escolha uma opção:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        /* code */
        return 1;
    case 2:
        registerOfficial();
        return 2;
    case 3:
        printf("ATÉ LOGO!\n");
        return 3;
    default:
        system("cls");
        printf("OPÇÃO INVÁLIDA!\n");
        return choice;
    }
}

void registerOfficial()
{
    char nomecompleto[100],
        nomecompletoAnterior[100],
        dataNascimento[11],
        dataNascimentoAnterior[11],
        cpf[15],
        cpfAnterior[15],
        enderecoCompleto[200],
        enderecoCompletoAnterior[200],
        telefone[20],
        telefoneAnterior[20],
        email[100],
        emailAnterior[100],
        estadoCivil[20],
        estadoCivilAnterior[20],
        nacionalidade[50],
        nacionalidadeAnterior[50],
        cargo[50],
        cargoAnterior[50],
        dataAdmissao[11],
        dataAdmissaoAnterior[11],
        departamento[50],
        departamentoAnterior[50],
        senhaAcesso[20],
        senhaCriptografada[20];
    float salario;
    int validRegister;

    system("cls");
    produceRows();
    printf("%s", titlePage);
    produceRows();
    printf("FORMULÁRIO DE REGISTRO DE FUNCIONÁRIOS\n");
    produceRows();

    do
    {
        printf("Informe o Nome Completo:");
        fgets(nomecompleto, 100, stdin);

        nomecompleto[strcspn(nomecompleto, "\n")] = '\0';
        strncpy(nomecompletoAnterior, nomecompleto, strlen(nomecompleto) + 1);

        if (strlen(nomecompletoAnterior) == 0)
        {
            printf("NOME INVÁLIDO!\n");
        }

    } while (strlen(nomecompletoAnterior) == 0);

    do
    {
        produceRows();
        printf("Informe a Data de Nascimento (dd/mm/aaaa):");
        fgets(dataNascimento, 12, stdin);

        dataNascimento[strcspn(dataNascimento, "\n")] = '\0';
        strncpy(dataNascimentoAnterior, dataNascimento, strlen(dataNascimento) + 1);

    } while (validDate(dataNascimentoAnterior, 1) == 0);

    do
    {
        produceRows();
        printf("Informe o CPF (XXX.XXX.XXX-XX):");
        fgets(cpf, 16, stdin);

        cpf[strcspn(cpf, "\n")] = '\0';
        strncpy(cpfAnterior, cpf, strlen(cpf) + 1);

    } while (validCPF(cpfAnterior) == 0);

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
        printf("Informe o Telefone (XX)XXXXX-XXXX:");
        fgets(telefone, 20, stdin);

        telefone[strcspn(telefone, "\n")] = '\0';
        strncpy(telefoneAnterior, telefone, strlen(telefone) + 1);

    } while (validTel(telefoneAnterior) == 0);

    do
    {
        produceRows();
        printf("Informe o E-mail:");
        fgets(email, 100, stdin);

        email[strcspn(email, "\n")] = '\0';
        strncpy(emailAnterior, email, strlen(email) + 1);

    } while (validEmail(emailAnterior) == 0);

    produceRows();
    printf("Informe o Estado Civil:");
    fgets(estadoCivil, 20, stdin);

    estadoCivil[strcspn(estadoCivil, "\n")] = '\0';
    strncpy(estadoCivilAnterior, estadoCivil, strlen(estadoCivil) + 1);

    produceRows();
    printf("Informe a Nacionalidade:");
    fgets(nacionalidade, 50, stdin);

    nacionalidade[strcspn(nacionalidade, "\n")] = '\0';
    strncpy(nacionalidadeAnterior, nacionalidade, strlen(nacionalidade) + 1);

    do
    {
        produceRows();
        printf("Informe o Cargo:");
        fgets(cargo, 50, stdin);

        cargo[strcspn(cargo, "\n")] = '\0';
        strncpy(cargoAnterior, cargo, strlen(cargo) + 1);

        if (strlen(cargoAnterior) == 0)
        {
            printf("CARGO INVÁLIDO!\n");
        }

    } while (strlen(cargoAnterior) == 0);

    do
    {
        produceRows();
        printf("Informe a Data de Admissão (dd/mm/aaaa):");
        fgets(dataAdmissao, 12, stdin);

        dataAdmissao[strcspn(dataAdmissao, "\n")] = '\0';
        strncpy(dataAdmissaoAnterior, dataAdmissao, strlen(dataAdmissao) + 1);

    } while (validDate(dataAdmissaoAnterior, 1) == 0);

    do
    {
        produceRows();
        printf("Informe o Departamento:");
        fgets(departamento, 50, stdin);

        departamento[strcspn(departamento, "\n")] = '\0';
        strncpy(departamentoAnterior, departamento, strlen(departamento) + 1);

        if (strlen(departamentoAnterior) == 0)
        {
            printf("DEPARTAMENTO INVÁLIDO!\n");
        }

    } while (strlen(departamentoAnterior) == 0);

    do
    {
        produceRows();
        printf("Informe o Salário em R$:");
        scanf("%f", &salario);

        if (salario <= 0)
        {
            printf("SALÁRIO INVÁLIDO!");
        }

    } while (salario <= 0);

    do
    {
        produceRows();
        printf("Senha de acesso deve conter no mínimo:\n Uma letra MAIÚSCULA\n Uma letra minúscula\n Um dígito numérico\n 8 caracteres e no máximo 18\nInforme a senha de acesso:");
        collectionPassword(senhaAcesso);

    } while (validPassword(senhaAcesso) == 0);

    encryptPassword(senhaAcesso, senhaCriptografada);

    validRegister = officialWriteJSON(nomecompleto,
                                      dataNascimento,
                                      cpf,
                                      enderecoCompleto,
                                      telefone,
                                      email,
                                      estadoCivil,
                                      nacionalidade,
                                      cargo,
                                      dataAdmissao,
                                      departamento,
                                      senhaCriptografada,
                                      salario);

    if (validRegister == 1)
    {
        printf("Funcionário cadastrado com sucesso!\n");
    }
    else
    {
        printf("ERRO AO CADASTRAR FUNCIONÁRIO :(\n");
    }
}

void produceRows()
{
    for (int i = 1; i <= 50; i++)
    {
        printf("*");
    }
    printf("\n");
}

void collectionPassword(char senha[])
{
    int i = 0;
    char ch;

    while ((ch = getch()) != 13 && i < 19) // 13 é o código ASCII para Enter
    {
        if (ch == '\b' && i > 0) // Trata o backspace
        {
            i--;             // Remove o último caractere da senha
            printf("\b \b"); // Apaga o asterisco e move o cursor para a posição correta
        }
        else if (ch != '\b')
        {
            senha[i++] = ch; // Armazena o caractere na senha
            printf("*");
        }
    }
    senha[i] = '\0'; // Adiciona o terminador de string
    printf("\n");
}

void encryptPassword(char password[20], char encrypted[20])
{
    int const shift = 7;
    int i;
    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z') // Verifica se o caractere é uma letra maiúscula
        {
            encrypted[i] = ((password[i] - 'A' + shift) % 26) + 'A';
        }
        else if (password[i] >= 'a' && password[i] <= 'z') // Verifica se o caractere é uma letra minúscula
        {
            encrypted[i] = ((password[i] - 'a' + shift) % 26) + 'a';
        }
        else // Copia caracteres não alfabéticos sem alteração
        {
            encrypted[i] = password[i] + shift;
        }
    }
    encrypted[i] = '\0';
}
