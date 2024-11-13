// Módulo com funções para manipulação de clientes no sistema

#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <string.h> // Biblioteca com funções para tratamento de string
#include <stdlib.h> // Biblioteca para controlar o sistema
#include "display.h" // Módulo para manipulação visual do display da aplicação
#include "auth.h"       // Módulo com funções para manipulação de autenticação no sistema
#include "validators.h" // Módulo para validar campo de formulários
#include "manipulationFile.h" // Módulo com funções para manipulação de arquivos

extern const char titlePage[];

void registerClient();

#endif // CLIENT_H