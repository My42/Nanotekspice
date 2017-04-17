//
// ParserException.hpp for  in /home/florian/rendu/cpp_nanotekspice
// 
// Made by vincen_s
// Login   <florian@epitech.net>
// 
// Started on  Fri Mar  3 13:12:08 2017 vincen_s
// Last update Mon Apr 17 17:40:39 2017 vincent.mesquita@epitech.eu
//

#ifndef PARSEREXCEPTION_H_
# define PARSEREXCEPTION_H_

# include <exception>
# include <string>
# include "IComponent.hpp"

namespace nts
{
  namespace exception
  {
    class ParserException : public std::exception
    {
    private:
      std::string		_e;
    public:
      ParserException(std::string const &exception) throw();
      virtual ~ParserException() throw();
      virtual const char		*what() const throw();
    };
  }
}

#endif /* !PARSEREXCEPTION_H_ */
