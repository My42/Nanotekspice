//
// ParserException.cpp for  in /home/florian/rendu/cpp_nanotekspice
// 
// Made by vincen_s
// Login   <florian@epitech.net>
// 
// Started on  Fri Mar  3 13:20:41 2017 vincen_s
// Last update Fri Mar  3 13:51:57 2017 vincen_s
//

# include "ParserException.hpp"

nts::exception::ParserException::ParserException(std::string const &exception) throw() : _e(exception)
{}

nts::exception::ParserException::~ParserException() throw()
{}

const char		*nts::exception::ParserException::what() const throw()
{
  return (_e.c_str());
}
