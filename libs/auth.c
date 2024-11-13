#include "auth.h"

void authentication()
{
    char emailAccess[100], emailAccessAnterior[100], passwordAccess[20], encrypted[20];
    int emailJSON = 0, encryptedJSON = 0;

    produceRows();

    do
    {
        produceRows();
        printf("LOGIN\n");
        produceRows();
        printf("E-MAIL:");

        fgets(emailAccess, 100, stdin);

        emailAccess[strcspn(emailAccess, "\n")] = '\0';
        strncpy(emailAccessAnterior, emailAccess, strlen(emailAccess) + 1);

        emailJSON = employeeReadEmail(emailAccessAnterior);

        printf("SENHA:");
        collectionPassword(passwordAccess);

        encryptPassword(passwordAccess, encrypted);

        encryptedJSON = employeeReadPassword(emailAccessAnterior, encrypted);

        if (emailJSON == 0)
        {
            printf("E-MAIL INVÁLIDO!\n");
        }

        if (encryptedJSON == 0)
        {
            printf("SENHA INVÁLIDA!\n");
        }

    } while (emailJSON == 0 || encryptedJSON == 0);
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