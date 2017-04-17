//
// InputException.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib/exceptions
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Sun Jan 29 03:43:38 2017 vincent.mesquita
// Last update Mon Apr 17 17:39:45 2017 vincent.mesquita@epitech.eu
//

#ifndef INPUTEXCEPTION_HPP
# define INPUTEXCEPTION_HPP

# include <exception>
# include <string>
# include "IComponent.hpp"

namespace nts
{
  namespace exception
  {
    class BadInputPinException : public std::exception
    {
    public:
      BadInputPinException() throw();
      virtual ~BadInputPinException() throw();
      virtual const char		*what() const throw();
    };

    class BadInputLinkException : public std::exception
    {
    public:
      BadInputLinkException(const nts::e_pin_type) throw();
      virtual ~BadInputLinkException() throw();
      virtual const char		*what() const throw();

    private:
      nts::e_pin_type		_pin_type;
    };
  }
}

#endif /* !INPUTEXCEPTION */
