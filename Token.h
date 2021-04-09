#pragma once
#include <string>


class Token;

class Token
{
public:
    virtual auto obtemNomeToken()->std::string = 0;

private:
    std::string nome_token;
};