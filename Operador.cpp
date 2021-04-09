#include "Operador.h"


// CONSTRUTORES
Operador::Operador(char)
{

}

Operador::Operador(std::string)
{

}
///////////////


auto Operador::obtemNomeToken()->std::string
{
	return this->nome;
}