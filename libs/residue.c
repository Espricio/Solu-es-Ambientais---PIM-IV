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
    }
    else
    {
        printf("ERRO AO REGISTRAR RESÍDUO :(\n");
    }
}