#pragma once
#include <utility>
#include <string>
#include <unordered_map>

#include "Token.h"

class Scope;

class Scope
{
public:
    Scope(char);

private:
    std::pair<char, std::string> par;
    using operador_par = decltype(par.first); // (, )
    using significado_par = decltype(par.second); // 


    inline static std::unordered_map<char, std::string> operadores_validos =
    {   // repensar a forma de implementação disto.
        {'(', std::string{""}},
        {')', std::string{""}}
    };

    inline static const std::string nome = "SCOPE"; // nome do token

public:
    operador_par& operador = par.first;
    significado_par& significado = par.second;
};