//
// OutputException.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Thu Feb  2 10:17:11 2017 vincent.mesquita
// Last update Mon Apr 17 17:39:12 2017 vincent.mesquita@epitech.eu
//

#ifndef OUTPUTEXCEPTION_HPP
# define OUTPUTEXCEPTION_HPP

#include <exception>
#include <string>
#include "IComponent.hpp"

namespace nts
{
  namespace exception
  {
    class BadOutputPinException : public std::exception
    {
    public:
      BadOutputPinException() throw();
      virtual ~BadOutputPinException() throw();
      virtual const char		*what() const throw();
    };

    class BadOutputLinkException : public std::exception
    {
    public:
      BadOutputLinkException(const nts::e_pin_type) throw();
      virtual ~BadOutputLinkException() throw();
      virtual const char		*what() const throw();

    private:
      nts::e_pin_type		_pin_type;
    };
  }
}

#endif /* !OUTPUTEXCEPTION */
