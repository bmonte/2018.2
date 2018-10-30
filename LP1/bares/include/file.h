#ifndef _FILE_H_
#define _FILE_H_

#include<iostream> //cout, cin
#include<string> // std::string
#include<fstream>
#include<sstream> //std::ifstream, std::ofstream

class File{
	public:
    //==== Special methods
    /// Default constructor
    File(std::string, std::string);
    File(void) = delete;
    /// Default destructor
    ~File();
    //=== Support methods.
    bool is_eof(void);//Checks whether we reached the "end of file".
    //=== In/Out methods.
    std::string read_file(void);
    void write_file(std::string);
  private:
    //==== Private members.
    std::ifstream f_input; //!<
    std::ofstream f_output; //!<

};

#endif
