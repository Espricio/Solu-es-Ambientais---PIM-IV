// Módulo com funções para manipulação de funcionários no sistema

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <stdio.h>
#include <string.h> // Biblioteca com funções para tratamento de string
#include <stdlib.h> // Biblioteca para controlar o sistema
#include "display.h" // Módulo para manipulação visual do display da aplicação
#include "auth.h"       // Módulo com funções para manipulação de autenticação no sistema
#include "validators.h" // Módulo para validar campo de formulários
#include "manipulationFile.h" // Módulo com funções para manipulação de arquivos

extern const char titlePage[];

void registerEmployee();

#endif // EMPLOYEE_H