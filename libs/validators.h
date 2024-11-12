// MÓDULO PARA CÓDIGOS DE VALIDAÇÃO DE FORMULÁRIOS

#ifndef VALIDATORS_H
#define VALIDATORS_H

#include <stdio.h>
#include <time.h>   // Biblioteca com funções para tratamento de tempo
#include <conio.h>  // Biblioteca necessária para getch()
#include <string.h> // Biblioteca com funções para tratamento de string
#include <ctype.h>  // Biblioteca com funções para tratamento de caracteres
#include "manipulationFile.h" // Módulo com funções para manipulação de arquivos

int validDate(char date[11], int later);
int validCPF(char cpf[13]);
int validTel(char tel[15]);
int validEmail(char email[]);
int validPassword(char password[]);

#endif // VALIDATORS_H
