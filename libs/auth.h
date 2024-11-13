//Módulo com funções para manipulação de autenticação no sistema

#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include <stdio.h>
#include <conio.h>  // Biblioteca necessária para getch()
#include <string.h> // Biblioteca com funções para tratamento de string
#include <ctype.h>  // Biblioteca com funções para tratamento de caracteres
#include "display.h" // Módulo para manipulação visual do display da aplicação
#include "manipulationFile.h" // Módulo com funções para manipulação de arquivos

void authentication();
void collectionPassword(char senha[]);
void encryptPassword(char password[20], char encrypted[20]);

#endif // AUTHENTICATOR_H