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

#endif // MANIPULATION_FILE_H