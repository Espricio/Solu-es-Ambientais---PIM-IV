#include <stdio.h>
#include <stdlib.h> // Biblioteca para controlar o sistema
#include <locale.h>
#include "libs/display.h"    // Módulo para manipulação visual do display da aplicação
#include "libs/auth.h"       // Módulo com funções para manipulação de autenticação no sistema
#include "libs/validators.h" // Módulo para validar campo de formulários
#include "libs/employee.h"   // Módulo com funções para manipulação de funcionários no sistema
#include "libs/client.h"     // Módulo com funções para manipulação de clientes no sistema
#include "libs/residue.h"    // Módulo com funções para manipulação de resíduos no sistema

int startMenu(); // Menu Inicial da Aplicação

const char titlePage[] = "STARTUP DE SOLUÇÕES AMBIENTAIS\n"; // Constante global que contém o título da aplicação

int main()
{
    setlocale(LC_ALL, "PT-BR");
    system("chcp 65001"); // Configura o terminal para UTF-8
    system("cls");

    produceRows();
    produceRows();
    printf("%s", titlePage);

    authentication();

    int choice; // Variável para escolha dentro do menu

    do
    {
        choice = startMenu();
    } while (choice != 6);

    return 0;
}

int startMenu()
{
    char startMenu[] = "MENU INICIAL\n 1 - CADASTRAR CLIENTE\n 2 - CADASTRAR FUNCIONÁRIO\n 3 - REGISTRAR RESÍDUOS AMBIENTAIS\n 4 - GERAR RELATÓRIO INDIVIDUAL DE RESÍDUOS\n 5 - GERAR RELATÓRIO GERAL DE RESÍDUOS\n 6 - FINALIZAR\n";
    int choice;
    system("cls");

    produceRows();
    produceRows();
    printf("%s", titlePage);
    produceRows();
    produceRows();
    printf("%s", startMenu);
    produceRows();

    printf("Escolha uma opção:");
    scanf("%d", &choice);
    setbuf(stdin, NULL);

    switch (choice)
    {
    case 1:
        registerClient();
        return 1;
    case 2:
        registerEmployee();
        return 2;
    case 3:
        registerResidue();
        return 3;
    case 4:
        listResidue();
        return 4;
    case 5:
        generateGeneralReport();
        return 5;
    case 6:
        printf("ATÉ LOGO!\n");
        return 6;
    default:
        system("cls");
        printf("OPÇÃO INVÁLIDA!\n");
        return choice;
    }
}
