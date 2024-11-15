#include "employee.h"

void registerEmployee()
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
            printf("SALÁRIO INVÁLIDO!\n");
        }

    } while (salario <= 0);

    setbuf(stdin, NULL);

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
        printf("Senha de acesso deve conter no mínimo:\n Uma letra MAIÚSCULA\n Uma letra minúscula\n Um dígito numérico\n 8 caracteres e no máximo 18\nInforme a senha de acesso:");
        collectionPassword(senhaAcesso);

    } while (validPassword(senhaAcesso) == 0);

    encryptPassword(senhaAcesso, senhaCriptografada);

    validRegister = employeeWriteJSON(nomecompleto,
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
        system("pause");
    }
    else
    {
        printf("ERRO AO CADASTRAR FUNCIONÁRIO :(\n");
        system("pause");
    }
}