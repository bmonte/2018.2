#include <iostream>
#include <iomanip>
#include <vector>

#include "../include/parser.h"
#include "../include/file.h"
#include "../include/operations.h"

std::string print_error_msg( const Parser::ResultType & result)
{
  std::string str;
    // Have we got a parsing error?
    switch ( result.type )
    {
        case Parser::ResultType::UNEXPECTED_END_OF_EXPRESSION:
            str = "Unexpected end of input at column (" + std::to_string(result.at_col) + ")!";
            break;
        case Parser::ResultType::ILL_FORMED_INTEGER:
            str = "Ill formed integer at column (" + std::to_string(result.at_col) + ")!";
            break;
        case Parser::ResultType::MISSING_TERM:
            str = "Missing <term> at column (" + std::to_string(result.at_col) + ")!";
            break;
        case Parser::ResultType::EXTRANEOUS_SYMBOL:
            str = "Extraneous symbol after valid expression found at column (" + std::to_string(result.at_col) + ")!";
            break;
        //5. Integer constant out of range beginning at column (n)!
        case Parser::ResultType::INTEGER_OUT_OF_RANGE:
            str = "Integer constant out of range beginning at column (" + std::to_string(result.at_col) + ")!";
            break;
        case Parser::ResultType::MISSING_CLOSE_SCOPE:
            str = "Missing closing \")\" at column (" + std::to_string(result.at_col) + ")!";
            break;
        case Parser::ResultType::DIVISION_BY_ZERO:
            str = "Division by zero!";
            break;
        case Parser::ResultType::NUMERIC_OVERFLOW:
            str = "Numeric overflow error!";
            break;
        default:
            str = "Unhandled error found!";
            break;
    }
 return str;
}


int main(int argc, char const *argv[])
{
  if (argc == 3) {
    File my_file(argv[1], argv[2]); //Instancia um arquivo.
    Parser my_parser;          // Parser object
    Operation my_operation;    // Evaluator object

    std::vector<Token> postfix; // stores the result of the infix to postfix process

    std::string expression;

  while (not my_file.is_eof()) {
    expression = my_file.read_file();
    auto parse = my_parser.parse(expression);
    if(parse.type != Parser::ResultType::OK)
      my_file.write_file(print_error_msg(parse));
    else
    {
      postfix = my_operation.infix_to_postfix(my_parser.get_tokens());
      auto result = my_operation.execute_postfix(postfix);
      auto execute_result = my_operation.get_result();
        if(execute_result.type != Parser::ResultType::OK)
          my_file.write_file(print_error_msg(execute_result));
        else
          my_file.write_file(std::to_string(result));
    }
   }
  } else {
    std::cout << ">>> Runtime Error!" << '\n';
    std::cout << ">>> Try: ./Bares <input_file> [output_file]" << '\n';
    std::cout << ">>> Closing..." << '\n';
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

    return EXIT_SUCCESS;
}
