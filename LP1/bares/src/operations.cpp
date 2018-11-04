#include "../include/operations.h"

value_t Operation::set_precedence(character m_character){
  switch(m_character[0]){
        case '(' : return 0;
        case '+' :
        case '-' : return 1;
        case '*' :
        case '/' :
        case '%' : return 2;
        case '^' : return 3;
        default  : assert(false); return -1;
    }
}

bool Operation::precedence(character C1, character C2){
  int  first_operator_precedence,  second_operator_precedence;

  first_operator_precedence = set_precedence(C1);
  second_operator_precedence = set_precedence(C2);

  if (first_operator_precedence > second_operator_precedence) return true;
  else if (first_operator_precedence < second_operator_precedence) return false;
  else
  {
    if (right_association(C1)) return true;
    return false;
    }
}

std::vector<Token> Operation::infix_to_postfix(std::vector<Token> infix){
  std::stack<Token> stack;
  std::vector<Token> postfix;

	for(auto token : infix){
		if(is_operand(token))
    {
			postfix.emplace_back(token);

		}else if(is_open_scope(token.value))
    {
			stack.push(token);
		}else if(is_close_scope(token.value))
    {
			while(not is_open_scope(stack.top().value))
      {
				postfix.emplace_back(stack.top());
				stack.pop();
			}
			stack.pop();

		}else if(is_operator(token))
    {
			while(not stack.empty() and precedence(stack.top().value, token.value)){
				postfix.emplace_back(stack.top());
				stack.pop();
			}
			stack.push(token);
		}else{
      // Do nothing.
		}
	}

	while(not stack.empty()){
		postfix.emplace_back(stack.top());
		stack.pop();
	}

	return postfix;

  /**Codigo baseado no feito em sala de aula:
  std::string inflix_to_postfix( std::string infix) {
	std::stack< symbol > s; // pilha auxiliar para converter de infixo p/ posfixo.

	std::string postfix; // vai conter a expressao de saaida do formato posfixo.

	//percorrer cada elemento de entrada.
	for( auto c : inflix) {
		//tratar cada token de acordo com seu valor.
		if( is_operand(c) ) // operando vai para a saida diretamente.
			posfix += c;
		else if (is_opening_scope(c))
			s.push(c); // vai para pilha sem levar em consideracao quem está por
		else if (is_closing_scope(c)) {
			// enquanto nao encontrar o "irmao" ')' na pilha, (re)mova
			// todos os operadores que lá estão para a saida.
			while( not is_closing_scope( s.top() ) ) {
				postfix += s.top();
				s.pop();
			}
			// lembre-se de jogar fora o ')' que esta no topo.
			s.pop();
		}
		else if ( is_operator(c)) { //+, -,*,%, /, ^
			while( not s.empty() and has_higher_or_eq_precedence( s.top(), c)) {
				// remover elementos da pilha para saida.
				postfix += s.top();
				s.pop();
			}
			// lembre que o que chega sempre entra na pilha (fica em espera).
			s.push(c); //vai pro topo da pilha.
		}
		else { //espaco em branco

		// Do nothing.
		}
	}

	//lembrar de descarregar os poeradores pendentes na pilha, se existirem.
	while( not s.empty() ) {
		postfix += s
	}
}
  */
}

value_t Operation::execute(value_t v1, value_t v2, character c){
  switch (c[0]){
		case '^' :	return pow(v1, v2);
		case '*' :	return v1 * v2;
		case '/' :	if(v2 == 0){ result = Parser::ResultType(Parser::ResultType::DIVISION_BY_ZERO);
						return -1;
					}
					return v1 / v2;
		case '%' :	if(v2 == 0){ result = Parser::ResultType(Parser::ResultType::DIVISION_BY_ZERO);
						return -1;
					}
					return v1 % v2;
		case '+' : 	return v1 + v2;
		case '-' : return v1 - v2;
		default	 : assert(false); return -1;
}
/*Codigo baseado em:
	switch (op) {
		case'^' : return po(v1, v2);
		case'*' : return v1*v2;
		case '/' : if(v2==0)  throw std::sruntime_error("Divisao por zero!");
		return v1/v2;
		case '%': if(v2==0) throw std::sruntime_error("Divisao por zero!");
		return v1%v2;
		case'+' : return v1+v2;
		case'-' : return v1-v2;
		default: assert (false); return -1
	}*/
}

value_t Operation::execute_postfix(std::vector<Token> postfix){
	result = Parser::ResultType(Parser::ResultType::OK);	// defines the Result result as OK by default
	std::stack<value_t> stack;			// stores the results of the operations

	for(auto token : postfix){
		if(is_operand(token)){
			stack.push(std::stoi(token.value));
		}else if(is_operator(token)){
			auto v2 = stack.top();
			stack.pop();
			auto v1 = stack.top();
			stack.pop();
			auto final_result = execute(v1, v2, token.value);
			if(final_result < -32768 || final_result > 32767){
				result = Parser::ResultType(Parser::ResultType::NUMERIC_OVERFLOW);
				stack.push(-1);
			}else{
				stack.push(final_result);
			}
		}else{
			assert( false );
		}
	}
	return stack.top();
}
/*Codigo baseado em:
  value_type evaluate_postfix( std::string postfix) {
	std::stack< value_type > s;

	// percorrer a fila de simbolos, um por um.
	for (auto c: postfix) {
		if ( is_operand (c) ) {
			s.push( char2integer(c))
		}
		else if (is_operator(c) ) {
			value_type op2 = s.top();
			s.pop();
			value_type op1 = s.top();
			s.pop();
			value_type rsult = execute_operator(op1, op2, c);
			s.push( result );
		}
	}

	return s.top(); // o resultado deve estar no topo da pilha.
}*/
