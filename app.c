#include <stdio.h>
#include <stdlib.h> // Biblioteca para controlar o sistema
#include <locale.h>
#include <conio.h>      // Biblioteca necessária para getch()
#include <string.h>     // Biblioteca com funções para tratamento de string
#include <ctype.h>      // Biblioteca com funções para tratamento de caracteres
#include "libs/validators.h" // Módulo para validar campo de formulários
#include "libs/manipulationFile.h" // Módulo para manipular arquivos

const char titlePage[] = "Startup de Soluções Ambientais\n"; // Constante global que contém o título da aplicação

int startMenu();                                             // Menu Inicial da Aplicação
void registerOfficial();                                     // Função de registro de funcionários
void produceRows();                                          // Produz linhas para separar os conteúdos
void collectionPassword(char senha[]);                       // Coleta a senha ocultando os caracteres com *
void encryptPassword(char password[20], char encrypted[20]); // Função que criptografa usando a cifra de César

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    system("chcp 65001"); // Configura o terminal para UTF-8
    system("cls");

    createJSON();
    system("pause");

    produceRows();
    printf("%s", titlePage);
    produceRows();

    char emailAccess[100], passwordAccess[20], encrypted[20];

    printf("LOGIN\n");
    produceRows();
    printf("EMAIL:");
    scanf("%s", &emailAccess);
    printf("SENHA:");
    collectionPassword(passwordAccess);

    encryptPassword(passwordAccess, encrypted);

    int choice; // Variável para escolha dentro do menu

    do
    {
        choice = startMenu();
    } while (choice != 3);

    return 0;
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
    char nomecompleto[100], dataNascimento[11], cpf[13], enderecoCompleto[200], telefone[20], email[100], estadoCivil[20], nacionalidade[50], cargo[50], dataAdmissao[11], departamento[50], senhaAcesso[20], senhaCriptografada[20];
    float salario;

    system("cls");
    produceRows();
    printf("%s", titlePage);
    produceRows();
    printf("FORMULÁRIO DE REGISTRO DE FUNCIONÁRIOS\n");
    produceRows();

    printf("Informe o Nome Completo:");
    scanf("%s", &nomecompleto);

    do
    {
        produceRows();
        printf("Informe a data de nascimento (dd/mm/aaaa):");
        scanf("%s", &dataNascimento);
    } while (validDate(dataNascimento, 1) == 0);

    do
    {
        produceRows();
        printf("Informe o CPF (XXX.XXXX.XXX-XX):");
        scanf("%s", &cpf);
    } while (validCPF(cpf) == 0);

    produceRows();
    printf("Informe o Endereço Completo:");
    scanf("%s", &enderecoCompleto);

    do
    {
        produceRows();
        printf("Informe o Telefone (XX)XXXXX-XXXX:");
        scanf("%s", &telefone);
    } while (validTel(telefone) == 0);

    do
    {
        produceRows();
        printf("Informe o E-mail:");
        scanf("%s", &email);
    } while (validEmail(email) == 0);

    produceRows();
    printf("Informe o Estado Civil:");
    scanf("%s", &estadoCivil);

    produceRows();
    printf("Informe a Nacionalidade:");
    scanf("%s", &nacionalidade);

    produceRows();
    printf("Informe o Cargo:");
    scanf("%s", &cargo);

    do
    {
        produceRows();
        printf("Informe a Data de Admissão (dd/mm/aaaa):");
        scanf("%s", &dataAdmissao);
    } while (validDate(dataAdmissao, 1) == 0);

    produceRows();
    printf("Informe o Departamento:");
    scanf("%s", &departamento);

    do
    {
        produceRows();
        printf("Informe o Salário em R$:");
        scanf("%f", &salario);

        if (salario<=0)
        {
            printf("SALÁRIO INVÁLIDO!");
        }
        
    } while (salario <= 0);

    do
    {
        produceRows();
        printf("Senha de acesso deve conter no mínimo:\n Uma letra MAIÚSCULA\n Uma letra minúscula\n Um dígito numérico\n Um caracter especial\n 8 caracteres e no máximo 18\n Informe a senha de acesso:");
        collectionPassword(senhaAcesso);
    } while (validPassword(senhaAcesso) == 0);

    encryptPassword(senhaAcesso, senhaCriptografada);
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
    for (int i = 0; password[i] != '\0'; i++)
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
}
