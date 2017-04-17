//
// OutputException.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Thu Feb  2 10:15:59 2017 vincent.mesquita
// Last update Thu Feb  2 10:16:13 2017 vincent.mesquita
//

#include "OutputException.hpp"

nts::exception::BadOutputPinException::BadOutputPinException() throw()
{
  
}

nts::exception::BadOutputPinException::~BadOutputPinException() throw()
{

}

const char		*nts::exception::BadOutputPinException::what() const throw()
{
  return ("Invalid pin number, Output has only one pin.");
}

nts::exception::BadOutputLinkException::BadOutputLinkException(nts::e_pin_type pin_type)
  throw()
{
  this->_pin_type = pin_type;
}

nts::exception::BadOutputLinkException::~BadOutputLinkException() throw()
{

}

const char		*nts::exception::BadOutputLinkException::what() const throw()
{
  if (this->_pin_type == OUTPUT)
    return ("It's useless to link an output on an input.");
  else
    return ("It's useless to link an input on an other one.");
}

