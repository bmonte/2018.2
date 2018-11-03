#include "../include/operations.h"

value_t Operation::get_precedence(character m_character){
  switch(m_character[0]){
        case '^' : return 3;
        case '*' :
        case '/' :
        case '%' : return 2;
        case '+' :
        case '-' : return 1;
        case '(' : return 0;
        default  : assert( false );  return -1;
    }
}

bool Operation::precedence(character C1, character C2){
  int p_c1 = get_precedence(C1);
	int p_c2 = get_precedence(C2);

    if(p_c1 > p_c2){
    	return true;

	}else if(p_c1 < p_c2){
		return false;

	}else{
    	if(right_association(C1)) return false;
    	return true;

    }
}

std::vector<Token> Operation::infix_to_postfix(std::vector<Token> infix){
	std::vector<Token> postfix; // output Token vector

  std::stack<Token> stack;	// auxiliar stack

	for(auto token : infix){
		if(is_operand(token)){						// if it's an operand, goes straight to output vector
			postfix.emplace_back(token);

		}else if(is_open_scope(token.value)){	// if it's an opening scope, goes to the auxiliar stack
			stack.push(token);

		}else if(is_close_scope(token.value)){	// if it's a closing scope, pushs the expressions terms to the output
			while(!is_open_scope(stack.top().value)){
				postfix.emplace_back(stack.top());
				stack.pop();
			}
			stack.pop();

		}else if(is_operator(token)){				// if it's an operator, replace it
			while(!stack.empty() && precedence(stack.top().value, token.value)){
				postfix.emplace_back(stack.top());
				stack.pop();
			}
			stack.push(token);

		}else{
		}
	}

	while(!stack.empty()){
		postfix.emplace_back(stack.top());
		stack.pop();
	}

	return postfix;
}
