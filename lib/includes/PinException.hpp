//
// PinException.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Fri Feb  3 20:05:55 2017 vincent.mesquita
// Last update Mon Apr 17 17:38:23 2017 vincent.mesquita@epitech.eu
//

#ifndef PINEXCEPTION_H_
# define PINEXCEPTION_H_

# include <exception>
# include <string>
# include "IComponent.hpp"

namespace nts
{
  namespace exception
  {
  class PinLinkageException : public std::exception
  {
  public:
    PinLinkageException(void) throw();
    virtual ~PinLinkageException() throw();
    virtual const char		*what() const throw();
  };

  class PinNumberException : public std::exception
  {
  public:
    PinNumberException(size_t pin_num, const std::string &name) throw();
    virtual ~PinNumberException() throw();
    virtual const char		*what() const throw();

  private:
    std::string			_str;
  };

  class PinUseException : public std::exception
  {
  public:
    PinUseException(const nts::e_pin_type &type, const std::string &name) throw();
    virtual ~PinUseException() throw();
    virtual const char		*what() const throw();

  private:
    std::string			_str;
  };
  }
};

#endif /* !PINEXCEPTION_H_ */
