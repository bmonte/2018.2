# Introdução

Este é um programa **BARES (Basic ARithmetic Expression Evaluator based on Stacks)**, ele é capaz de receber expressões aritméticas simples e resolve-las, para isso a gramática **EBNF (Extended Backus-Naur Form)** é usada.

# Gramática EBNF

		<expression>       :=   <term>, { ( "+" | "-" | "*" | "/" | "%" | "^" ), <term> };
    <term>             :=   "(", <expression>, ")" | <integer>;
    <integer>          :=   0 | [ "-" ], <natural_number>;
    <natural_number>   :=   <digit_excl_zero>, {<digit>};
    <digit_excl_zero>  :=   "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9";
    <digit>            :=   "0" | <digit_excl_zero>;

# Compilação e execução

Para gerar o arquivo **BARES** executavel:
> $ make

Para rodar o arquivo gerado anteriormente:
> $ ./Bares <input_file> [output_file]

# Tratamento de erros

1. **Integer constant out of range beginning at column (n)!**
2. **Missing <term> at column (n)!**
3. **Extraneous symbol after valid expression found at column (n)!**
4. **Ill formed integer at column (n)!**
5. **Missing closing ”)” at column (n)!**
6. **Unexpected end of expression at column (n)!**
7. **Division by zero!**
8. **Numeric overflow error!**

# Implementações futuras

O programa apresenta pequenos "erros" com o tratamento de erros, sendo eles:

	* A expresão "---3", por exemplo, é tratada como *Ill formed integer* no lugar de "-3";
	* Algumas expressões são tratadas como *Missing <term>* no lugar de *Ill formed integer*.

**Developed by Brunno Monte (bmonte@outlook.com).
