#include "validators.h"

// Validador para datas no formato "DD/MM/AAAA"
int validDate(char date[11], int later) // parâmetro later é usado caso a data não possa ser posterior ao dia atual.
{
    int day, month, year;

    if (strlen(date) != 10 || date[2] != '/' || date[5] != '/')
    {
        printf("FORMATO DE DATA INVÁLIDO!\n");
        return 0;
    }

    sscanf(date, "%2d/%2d/%4d", &day, &month, &year);

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

    int daysInMonth[] = {31, 28 + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day < 1 || day > daysInMonth[month - 1])
    {
        printf("DIA INVÁLIDO!\n");
        return 0;
    }

    if (later == 1)
    {
        time_t now;
        struct tm *current;
        time(&now);
        current = localtime(&now);

        if (year > (current->tm_year + 1900) ||
            (year == (current->tm_year + 1900) && month > (current->tm_mon + 1)) ||
            (year == (current->tm_year + 1900) && month == (current->tm_mon + 1) && day > current->tm_mday))
        {
            printf("A DATA NÃO PODE SER SUPERIOR À DATA ATUAL!\n");
            return 0;
        }
    }

    return 1;
}

// Validador para CPF no formato "XXX.XXX.XXX-XX"
int validCPF(char cpf[13])
{
    int dig[11], somaDig = 0, restoDig, i, j = 0, igualdade;

    if (strlen(cpf) != 14 || cpf[3] != '.' || cpf[7] != '.' || cpf[11] != '-')
    {
        printf("FORMATO DE CPF INVÁLIDO!\n");
        return 0;
    }

    for (i = 0; i < 14; i++)
    {
        if (cpf[i] != '.' && cpf[i] != '-')
        {
            if (!isdigit(cpf[i]))
            {
                printf("FORMATO DE CPF INVÁLIDO!\n Somente dígitos são permitidos.\n");
                return 0;
            }
            dig[j++] = cpf[i] - '0';
        }
    }

    for (i = 0; i < 10; i++)
    {
        if (dig[i] == dig[i + 1])
        {
            igualdade = 1;
        }else{
            igualdade = 0;
        }
    }

    if (igualdade == 1)
    {
        printf("CPF INVÁLIDO***!\n");
        return 0;
    }

    for (i = 0; i < 9; i++)
    {
        somaDig += dig[i] * (10 - i);
    }

    restoDig = (somaDig * 10) % 11;

    if (restoDig != dig[9])
    {
        printf("CPF INVÁLIDO*!\n");
        return 0;
    }

    for (i = 0, somaDig = 0; i < 10; i++)
    {
        somaDig += dig[i] * (11 - i);
    }

    restoDig = (somaDig * 10) % 11;

    if (restoDig != dig[10])
    {
        printf("CPF INVÁLIDO**!\n");
        return 0;
    }

    return 1;
}

int validCNPJ(char cnpj[20]){
    int dig[14], somaDig = 0, restoDig, i, j = 0, igualdade;

    if (strlen(cnpj) != 18 || cnpj[2] != '.' || cnpj[6] != '.' || cnpj[10] != '/' || cnpj[15] != '-')
    {
        printf("FORMATO DE CNPJ INVÁLIDO!\n");
        return 0;
    }

    for (i = 0; i < 18; i++)
    {
        if (cnpj[i] != '.' && cnpj[i] != '/' && cnpj[i] != '-')
        {
            if (!isdigit(cnpj[i]))
            {
                printf("FORMATO DE CNPJ INVÁLIDO! Somente dígitos são permitidos.\n");
                return 0;
            }
            dig[j++] = cnpj[i] - '0';
        }
    }

    for (i = 0; i < 12; i++) {
        if (dig[i] == dig[i + 1]) {
            igualdade = 1;
        } else {
            igualdade = 0;
        }
    }

    if (igualdade == 1) {
        printf("CNPJ INVÁLIDO!\n");
        return 0;
    }

    somaDig = 0;
    int peso1[12] = {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    for (i = 0; i < 12; i++) {
        somaDig += dig[i] * peso1[i];
    }

    restoDig = somaDig % 11;
    if (restoDig < 2) {
        if (restoDig != dig[12]) {
            printf("CNPJ INVÁLIDO!\n");
            return 0;
        }
    } else {
        if ((11 - restoDig) != dig[12]) {
            printf("CNPJ INVÁLIDO!\n");
            return 0;
        }
    }

    somaDig = 0;
    int peso2[13] = {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    for (i = 0; i < 13; i++) {
        somaDig += dig[i] * peso2[i];
    }

    restoDig = somaDig % 11;
    if (restoDig < 2) {
        if (restoDig != dig[13]) {
            printf("CNPJ INVÁLIDO!\n");
            return 0;
        }
    } else {
        if ((11 - restoDig) != dig[13]) {
            printf("CNPJ INVÁLIDO!\n");
            return 0;
        }
    }

    return 1;

}

// Validador para telefone no formato "(XX)XXXXX-XXXX"
int validTel(char tel[15])
{
    if (strlen(tel) != 14 || tel[0] != '(' || tel[3] != ')' || tel[9] != '-')
    {
        printf("FORMATO DE TELEFONE INVÁLIDO!\n");
        return 0;
    }

    for (int i = 1; i < 14; i++)
    {
        if (tel[i] != '(' && tel[i] != ')' && tel[i] != '-')
        {
            if (!isdigit(tel[i]))
            {
                printf("FORMATO DE TELEFONE INVÁLIDO! Somente dígitos são permitidos.\n");
                return 0;
            }
        }
    }

    return 1;
}

// Validador para e-mails
int validEmail(char email[])
{
    int len = strlen(email), amountArroba = 0, positionArroba = -1, amountPoint = 0;

    if (len < 6)
    {
        printf("FORMATO DE E-MAIL INVÁLIDO!\n");
        return 0;
    }

    for (int i = 0; i < len; i++)
    {

        if (isspace(email[i]))
        {
            printf("E-MAIL NÃO PODE CONTER ESPAÇOS!\n");
            return 0;
        }

        if (email[i] == '@')
        {
            positionArroba = i;
            amountArroba++;
            if (amountArroba > 1)
            {
                printf("E-MAIL NÃO PODE CONTER MAIS DE UM '@'!\n");
                return 0;
            }
        }

        if (email[i] == '.' && positionArroba != -1 && i > positionArroba + 1)
        {
            amountPoint++;
        }
    }

    if (amountArroba != 1 || amountPoint < 1 || positionArroba < 1 || positionArroba >= len - 3)
    {
        printf("FORMATO DE E-MAIL INVÁLIDO!\n");
        return 0;
    }

    if (email[len - 1] == '.')
    {
        printf("FORMATO DE E-MAIL INVÁLIDO!\n");
        return 0;
    }

    if (employeeReadEmail(email) == 1 || clientReadEmail(email) == 1)
    {
        printf("E-MAIL JÁ CADASTRADO!\n");
        return 0;
    }
    
    return 1;
}

int validPassword(char password[])
{
    int charCapital = 0, charLowercase = 0, charNum = 0;
    int len = strlen(password);

    if (len < 8 || len > 18)
    {
        printf("A SENHA DEVE CONTER NO MÍNIMO 8 CARACTERES E NO MÁXIMO 18!\n");
        return 0;
    }

    for (int i = 0; i < len; i++)
    {
        if (isupper(password[i]))
        {
            charCapital = 1;
        }
        else if (islower(password[i]))
        {
            charLowercase = 1;
        }
        else if (isdigit(password[i]))
        {
            charNum = 1;
        }
    }

    if (charCapital < 1)
    {
        printf("A SENHA DEVE CONTER NO MÍNIMO UM LETRA MAIÚSCULA!\n");
        return 0;
    }

    if (charLowercase < 1)
    {
        printf("A SENHA DEVE CONTER NO MÍNIMO UM LETRA minúscula!\n");
        return 0;
    }

    if (charNum < 1)
    {
        printf("A SENHA DEVE CONTER NO MÍNIMO UM NÚMERO!\n");
        return 0;
    }

    return 1;
}