//
// PinException.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Fri Feb  3 20:05:35 2017 vincent.mesquita
// Last update Sat Mar  4 12:03:37 2017 vincent.mesquita@epitech.eu
//

#include "PinException.hpp"

nts::exception::PinLinkageException::PinLinkageException(void) throw() { }

nts::exception::PinLinkageException::~PinLinkageException(void) throw() { }

const char		*nts::exception::PinLinkageException::what(void) const throw()
{
  return ("linkage error.");
}

nts::exception::PinNumberException::PinNumberException(size_t pin_num,
						       const std::string &name) throw()
{
  this->_str = "[" + name + "] The Pin ";
  this->_str += std::to_string(pin_num);
  this->_str += " doesn't exist.";
}

nts::exception::PinNumberException::~PinNumberException(void) throw() { }

const char		*nts::exception::PinNumberException::what(void) const throw()
{
  return (this->_str.c_str());
}

nts::exception::PinUseException::PinUseException(const nts::e_pin_type &type,
						 const std::string &name) throw()
{
  this->_str = "[" + name +"] " + ((type == VSS) ? "VSS" : "VDD")
    + " pin has no effect, you can't use it.";
}

nts::exception::PinUseException::~PinUseException(void) throw() { }

const char		*nts::exception::PinUseException::what(void) const throw()
{
  return (this->_str.c_str());
}
