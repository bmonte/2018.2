#ifndef _OPERATIONS_H_
#define _OPERATIONS_H_

#include <iostream>		// std::cin, std::cout
#include <string>		// std::string, std::stoi
#include <vector>		// std::vector
#include <cmath>		// pow
#include <stack> 		// std::stack
#include <cassert>  // assert

#include "token.h"		// Token struct
#include "parser.h"	// Parser struct

//==== Aliases
using value_t = int;
using character = std::string;

class Operation{
  public:
    //==== Special methods
    /// Default constructor
    Operation(void) = default;
    Operation(const Operation &) = delete;
    /// Default destructor
    ~Operation(void) = default;
    //==== Get and Set methods
    Parser::ResultType get_result(void){return result;}
    value_t set_precedence(character);
    //==== Conversion methods
    std::vector<Token> infix_to_postfix(std::vector<Token>);
    value_t evaluate_postfix(std::vector<Token>);
    //Support method
    bool is_operator(Token m_token){return m_token.type == Token::token_t::OPERATOR;}
    bool is_operand(Token m_token){return m_token.type == Token::token_t::OPERAND;}
    bool is_open_scope(character m_character){return m_character == "(";}
    bool is_close_scope(character m_character){return m_character == ")";}
    bool right_association(character m_character){return m_character == "^";}
    bool precedence(character, character);
    value_t execute(value_t, value_t, character);
    value_t execute_postfix(std::vector<Token>);

  private:
    //==== Private members
    Parser::ResultType result;
};

#endif
