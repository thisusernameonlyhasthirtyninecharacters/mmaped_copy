#pragma once



/*
using argumentos = std::vector<std::string>;
struct comando {
	std::size_t numero_argumentos;
	std::function<void(argumentos)> f;
	comando(std::size_t n, std::function<void(argumentos)> fc) : numero_argumentos{ n }, f{ fc } {};
};
std::unordered_map<std::string, comando> comandos
{
	{"carrega", comando(1, [this]() {obtemCommandos(); })}
};


void call(const std::string& command, const argumentos& args) {

	*/


	/*

	std::string line;
std::getline(input, line);

std::string command;
std::vector<std::string> args;
std::istringstream iss{ line };
iss >> command;
for (std::string arg; iss >> std::quoted(arg); )
  args.push_back(std::move(arg));

thing.call(command, args);


		*/

	/*
		/////////////////////////////////////////////////////////////
	class command_map {
		struct command {
			std::size_t num_arguments;
			std::function<void(argumentos)> function;
		};
		// I assume you initialize this type in some way
		std::unordered_map<std::string, command> m_commands;

	public:
		// I'll throw (made-up) exceptions on failure here, but you could do whatever
		void call(const std::string& command, const argumentos& args) {
			if (auto it = m_commands.find(command); it != m_commands.end()) {
				if (args.size() == it->num_arguments)
					it->function(args);
				else
					throw CommandHasIncorrectArgsException(command, args, it->num_arguments);
			}
			else
				throw CommandNotFoundException(command);
		}
	};
	/////////////////////////////////////////////////////////////

	Comandos lista_comandos
	{
		{"carrega", std::make_tuple(1, [this]() { obtemCommandos(); }) },
		{"cria", std::make_tuple(2, []() {}) },
		{"conquista", std::make_tuple(1, []() {}) },
		{"passa", std::make_tuple(0, []() {}) },
		{"maisouro", std::make_tuple(0, []() {}) },
		{"maisprod", std::make_tuple(0, []() {}) },
		{"maismilitar", std::make_tuple(0, []() {}) },
		{"adquire", std::make_tuple(1, []() {}) },
		{"lista", std::make_tuple(0, []() {}) },
		{"lista", std::make_tuple(1, []() {}) },
		{"avanca", std::make_tuple(0, []() {}) },
		{"grava", std::make_tuple(1, []() {}) },
		{"ativa", std::make_tuple(1, []() {}) },
		{"apaga", std::make_tuple(1, []() {}) },
		{"toma", std::make_tuple(2, []() {}) },
		{"modifica", std::make_tuple(2, []() {}) },
		{"fevento", std::make_tuple(1, []() {}) }
	};

	*/
