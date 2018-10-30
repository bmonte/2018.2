#include "../include/file.h"
#include <system_error>   // std::system_error

//Constructor
File::File(std::string f_input_path, std::string f_output_path){
  try{f_input.open(f_input_path);}
  catch( const std::ios_base::failure &err ){}
  try{f_output.open(f_output_path);}
  catch( const std::ios_base::failure &err ){}
}
//Destructor
File::~File(){
  f_input.close();
  f_output.close();
}
//Support methods
bool File::is_eof(void){
  return not f_input.good() or not f_input.is_open();
}
//Input method
std::string File::read_file(){
  std::string line;

  std::getline(f_input, line);

  return line;
}
