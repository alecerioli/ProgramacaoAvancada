#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "sculptor.h"
#include <string>
#include <iostream>

/**
 * @brief A classe Interpreter
 * eh uma classe que interpreta um aquivo.txt com instrucoes para a criacao de figuras geometricas.
 */
class Interpreter{
public:
    /**
     * @brief Interpreter eh o contrutor da classe Interpreter.
     */
    Interpreter();
    /**
     * @brief Read eh um metodo da classe Interpreter que retorna um objeto Sculptor com todas
     * as instrucoes do arquivo.txt ja executadas nele.
     * @param filename : caminho do arquivo.txt que contem as intrucoes para criacao e configuracao do Sculptor.
     * @return : um objeto Sculptor.
     */
    Sculptor Read(const char *filename);
};

#endif // INTERPRETER_H
