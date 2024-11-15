// MÓDULO PARA CÓDIGOS DE MANIPULAÇÃO DE ARQUIVOS

#ifndef MANIPULATION_FILE_H
#define MANIPULATION_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

int employeeWriteJSON(
    char nomecompleto[100],
    char dataNascimento[11],
    char cpf[13],
    char enderecoCompleto[200],
    char telefone[20],
    char email[100],
    char estadoCivil[20],
    char nacionalidade[50],
    char cargo[50],
    char dataAdmissao[11],
    char departamento[50],
    char senhaCriptografada[20],
    float salario);
int employeeReadEmail(const char *email);
int employeeReadPassword(const char *email, const char *password);

int clientWriteJSON(
    char nomeResponsavel[100],
    char nomeEmpresa[100],
    char cnpj[19],           
    char razaoSocial[100],
    char nomeFantasia[100],
    char telefone[20],
    char enderecoCompleto[200],
    char email[100],
    char dataAbertura[11]   
);
int clientReadCNPJ(const char *cnpj);
char* clientReadName(const char *cnpj);

int residueWriteJSON(
    char cnpj[20],
    char dataRegistro[11],
    int monitores,
    int cpus,
    int perifericos,
    int impressoras,
    int pcis,
    int telefones,
    int roteadores,
    double cabosEfios,
    double baterias,
    double diversos
);

cJSON *residueRead();

int generateIndividualReport(const char *cnpj);
int generateGeneralReport();

#endif // MANIPULATION_FILE_H