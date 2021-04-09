#include <iostream>
#include <string>
#include <cassert>

//#include "MyTuple.h"
//#include "Fibonacci.h"

#include "Header.h"


/*
auto real_function(int a, double b) -> void{
    std::cout << a << ' ' << b << '\n';
}


int main() {
    Command c;
    c.register_function("a", real_function);
    c.call_function("a", 1, 2.0);  // works
    // not implemented, but probably nice
    //c.call_function_sig<void(int, double)>("a", 1, 2);

    int x = 10;
    c.register_function<void()>("b", [x] { std::cout << "x: " << x << '\n'; });
    c.call_function("b");
}
*/

#include <iterator>
#include <algorithm>


#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string


#include  <unordered_map>
#include <functional>

#include "mmaped_copy.h"



int main()//int argc, char ** argv)
{
    std::string input_path;
    std::string output_path;

    std::cout << "Input file path: ";

    std::cin >> input_path;

    std::cout << "Output file path: ";

    std::cin >> output_path;
    
    try 
    { 
        N::F<std::size_t> a(input_path, output_path); 
        a.original_offset = 1234;

        a.calculate_offset(N::rounding_fn::floor);


        std::cout << "original = " << a.original_offset << std::endl;
        std::cout << "aligned = " << a.aligned_offset << std::endl;

        a.original_offset = 1234;

        a.calculate_offset(N::rounding_fn::ceil);


        std::cout << "original = " << a.original_offset << std::endl;
        std::cout << "aligned = " << a.aligned_offset << std::endl;

        //a.fmmap();
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
}


/*
int main()
{

    std::string input1 = "5 + 2 + 3 - 4 ( 6 * 7 / ( 2 - 8 ) )";

    std::cout << "Original string:" << std::endl;
    std::cout << input1 << std::endl << std::endl;

    std::istringstream parser (input1);

    std::vector<std::string> tokens;
    std::string aux;
    while (parser >> aux)
    {
        tokens.push_back(aux);
    }


    std::cout << "Parsed string:" << std::endl;
    for (auto i : tokens)
    {
        try {
            std::stod(i);
            // construimos um Token de número
            std::cout << "NUM "; // mockup
        }
        catch(...)
        {
            // não é um número

            std::cout << i << " ";
        }
    }
    std::cout << std::endl;



    /*
    
    PASSO UM: DIVIDIR O INPUT EM TOKENS

    TOKENS PODEM SER:
        
        -> NÚMEROS
        -> OPERADORES (+,-,*,/)
        -> SCOPES (, )'S        
        
 
}

   */















