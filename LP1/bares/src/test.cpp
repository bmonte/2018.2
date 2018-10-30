#include <iostream>
#include <iomanip>
#include <vector>

#include "../include/parser.h"
#include "../include/file.h"

void print_error_msg( const Parser::ResultType & result, std::string str )
{
    std::string error_indicator( str.size()+1, ' ');

    // Have we got a parsing error?
    error_indicator[result.at_col] = '^';
    switch ( result.type )
    {
        case Parser::ResultType::UNEXPECTED_END_OF_EXPRESSION:
            std::cout << ">>> Unexpected end of input at column (" << result.at_col << ")!\n";
            break;
        case Parser::ResultType::ILL_FORMED_INTEGER:
            std::cout << ">>> Ill formed integer at column (" << result.at_col << ")!\n";
            break;
        case Parser::ResultType::MISSING_TERM:
            std::cout << ">>> Missing <term> at column (" << result.at_col << ")!\n";
            break;
        case Parser::ResultType::EXTRANEOUS_SYMBOL:
            std::cout << ">>> Extraneous symbol after valid expression found at column (" << result.at_col << ")!\n";
            break;
        case Parser::ResultType::INTEGER_OUT_OF_RANGE:
            std::cout << ">>> Integer constant out of range beginning at column (" << result.at_col << ")!\n";
            break;
        case Parser::ResultType::MISSING_CLOSE_SCOPE:
            std::cout << ">>> Missing closing \")\" at column(" << result.at_col << ")!\n";
            break;
        default:
            std::cout << ">>> Unhandled error found!\n";
            break;
    }

    std::cout << "\"" << str << "\"\n";
    std::cout << " " << error_indicator << std::endl;
}


int main(int argc, char const *argv[])
{
      File my_file(argv[1], argv[2]); //Instancia um arquivo.
    Parser my_parser; // Instancia um parser.

    std::string expression;

    while (not my_file.is_eof()) {
      expression = my_file.read_file();
      // Fazer o parsing desta expressão.
      auto result = my_parser.parse( expression );
      // Preparar cabeçalho da saida.
      std::cout << std::setfill('=') << std::setw(80) << "\n";
      std::cout << std::setfill(' ') << ">>> Parsing \"" << expression << "\"\n";
      // Se deu pau, imprimir a mensagem adequada.
      if ( result.type != Parser::ResultType::OK )
          print_error_msg( result, expression );
      else
          std::cout << ">>> Expression SUCCESSFULLY parsed!\n";

       // Recuperar a lista de tokens.
      auto lista = my_parser.get_tokens();
      std::cout << ">>> Tokens: { ";
      std::copy( lista.begin(), lista.end(),
              std::ostream_iterator< Token >(std::cout, " ") );
      std::cout << "}\n";
      std::cout << std::endl;
    }

  /*  // Tentar analisar cada expressão da lista.
    for( const auto & expr : expressions )
    {
        // Fazer o parsing desta expressão.
        auto result = my_parser.parse( expr );
        // Preparar cabeçalho da saida.
        std::cout << std::setfill('=') << std::setw(80) << "\n";
        std::cout << std::setfill(' ') << ">>> Parsing \"" << expr << "\"\n";
        // Se deu pau, imprimir a mensagem adequada.
        if ( result.type != Parser::ResultType::OK )
            print_error_msg( result, expr );
        else
            std::cout << ">>> Expression SUCCESSFULLY parsed!\n";

         // Recuperar a lista de tokens.
        auto lista = my_parser.get_tokens();
        std::cout << ">>> Tokens: { ";
        std::copy( lista.begin(), lista.end(),
                std::ostream_iterator< Token >(std::cout, " ") );
        std::cout << "}\n";
        std::cout << std::endl;
    }*/



    std::cout << "\n>>> Normal exiting...\n";

    return EXIT_SUCCESS;
}
