#pragma once
#include "Error.h"
#include <fstream>
class Compiler
{
public:
    Compiler();
    ~Compiler();
    bool checkFile();
    bool lexical();
    void remake();
    std::string getError() { return error.getError(); }

private:
    const std::string pathFile{"MarkUp.txt"};
    const std::string pathResult{"CppUi.txt"};
    Error error;
    std::ifstream fin;
    std::string parcingString;
    std::string resultString;
    size_t line{0};
};
