#include <stdio.h>
#include <stdlib.h> // Biblioteca para controlar o sistema
#include <locale.h> // Biblioteca para
#include <conio.h>  // Biblioteca necessária para getch()
#include <string.h> // Biblioteca com funções para tratamento de string

const char titlePage[] = "Startup de Soluções Ambientais\n"; // Constante global que contém o título da aplicação

int startMenu();                                             // Menu Inicial da Aplicação
void registerOfficial();                                     // Função de registro de funcionários
void produceRows();                                          // Produz linhas para separar os conteúdos
void collectionPassword(char senha[]);                       // Coleta a senha ocultando os caracteres com *
void encryptPassword(char password[20], char encrypted[20]); // Função que criptografa usando a cifra de César
int validDate(char date[]);                                  // Função que valida entrada de datas
int validCPF(char cpf[]);                                    // Função que valida entrada de CPF

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    system("chcp 65001"); // Configura o terminal para UTF-8
    system("cls");

    validCPF("489.379.458-27");

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
    char nomecompleto[100], dataNascimento[11], cpf[13], enderecoCompleto[200], telefone[20], email[100], estadoCivil[20], nacionalidade[50], cargo[50], dataAdmissao[11], departamento[50], senhaAcesso[20];
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
        printf("Informe a data de nascimento(dd/mm/aaaa):");
        scanf("%s", &dataNascimento);
    } while (validDate(dataNascimento) == 0);

    do
    {
        produceRows();
        printf("Informe o CPF (000.000.000-00):");
        scanf("%s", &cpf);
    } while (validCPF(cpf) == 0);
}

void produceRows()
{
    for (int i = 1; i <= 50; i++)
    {
        printf("*");
    }
    printf("\n");
}

int validDate(char date[])
{
    int day, month, year;

    if (strlen(date) != 10 || date[2] != '/' || date[5] != '/')
    {
        printf("FORMATO DE DATA INVÁLIDO!\n");
        return 0;
    }

    sscanf(date, "%d/%d/%d", &day, &month, &year);

    if (year < 1900)
    {
        printf("SOMENTE ANOS MAIORES QUE 1900!\n");
        return 0;
    }

    if (month < 1 || month > 12)
    {
        printf("MÊS INVÁLIDO!\n");
        return 0;
    }

    int daysInMonth[] = {31, 28 + (year % 4 == 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day < 1 || day > daysInMonth[month - 1])
    {
        printf("DIA INVÁLIDO!\n");
        return 0;
    }

    return 1;
}

int validCPF(char cpf[13])
{
    int dig[9], somaDig, restoDig, i, j = 0;

    if (strlen(cpf) != 14 || cpf[3] != '.' || cpf[7] != '.' || cpf[11] != '-')
    {
        printf("FORMATO DE CPF INVÁLIDO!\n");
        return 0;
    }

    for(i = 0; i<=10; i++){
        if(cpf[i] != '.' && cpf[i] != '-'){
            dig[j] = cpf[i] - '0';
            j++;
        }
    }

    // dig[9] = ("%d%d",cpf[12],cpf[13]);

    system("pause");

    i=10;

    // while (i >= 1)
    // {
    //     somaDig += dig[j] * i;
    //     i--;

    //     if (j != 3 && j != 7)
    //     {
    //         j++;
    //     }
    //     else
    //     {
    //         j += 2;
    //     }
    // }

    // printf("%d",somaDig);
    // restoDig = (somaDig*10) % 11;

    // if (restoDig)
    // {
    //     /* code */
    // }
    
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
