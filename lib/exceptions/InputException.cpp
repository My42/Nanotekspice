//
// InputException.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib/exceptions
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Sun Jan 29 03:43:15 2017 vincent.mesquita
// Last update Thu Feb  2 10:14:45 2017 vincent.mesquita
//

#include "InputException.hpp"

nts::exception::BadInputPinException::BadInputPinException() throw()
{
  
}

nts::exception::BadInputPinException::~BadInputPinException() throw()
{

}

const char		*nts::exception::BadInputPinException::what() const throw()
{
  return ("Invalid pin number, Input has only one pin.");
}

nts::exception::BadInputLinkException::BadInputLinkException(nts::e_pin_type pin_type)
  throw()
{
  this->_pin_type = pin_type;
}

nts::exception::BadInputLinkException::~BadInputLinkException() throw()
{

}

const char		*nts::exception::BadInputLinkException::what() const throw()
{
  if (this->_pin_type == OUTPUT)
    return ("It's useless to link an output on an input.");
  else
    return ("It's useless to link an input on an other one.");
}

