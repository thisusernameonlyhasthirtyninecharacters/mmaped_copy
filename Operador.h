#pragma once
#include <utility>
#include <string>
#include <unordered_map>

#include "Token.h"



class Operador;

class Operador : public Token
{
public:
    Operador(char);
    Operador(std::string);

private:
    std::pair<char, std::string> par;
    using operador_par = decltype(par.first); // +, -, /, *
    using significado_par = decltype(par.second); // adicionar, subtrair, dividir, multiplicar


    inline static std::unordered_map<char, std::string> operadores_validos =
    {
        {'+', std::string{"adicionar"}},
        {'-', std::string{"subtrair"}},
        {'/', std::string{"dividir"}},
        {'*', std::string{"multiplicar"}}
    };
    
    inline static const std::string nome = "OPERADOR"; // nome do token

public:
    operador_par& operador = par.first;
    significado_par& significado = par.second;

    auto obtemNomeToken() -> std::string override;
};