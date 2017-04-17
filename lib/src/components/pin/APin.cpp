//
// APin.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Mon Jan 30 12:06:05 2017 vincent.mesquita
// Last update Fri Mar  3 23:21:32 2017 vincent.mesquita@epitech.eu
//

#include "APin.hpp"

nts::APin::APin(const std::string &name, const std::string &value) : AComponent(name, 1)
{
  _init();
  setValue(value);
}

nts::APin::APin(const std::string &name, const nts::Tristate value) : AComponent(name, 1)
{
  _init();
  this->_value = value;
}

nts::APin::APin(const APin &other) : AComponent(other)
{
  _init();
  this->_value = other._value;
}

void			nts::APin::_init(void)
{
  size_t i = 0;

  _already_did.push_back(false);
  _already_did.push_back(false);
  while (i < this->_nbr_of_pins + 1)
    this->_pins[i++] = NULL;
  this->_pins_type.reserve(this->_nbr_of_pins + 1);
  this->_pins_type[0] = VSS;
  this->_pins[1] = &(this->_value);
}

nts::APin::~APin() {}

nts::APin		&nts::APin::operator=(const APin &other)
{
  if (this != &other)
    {
      AComponent::operator=(other);
      this->_value = other._value;
    }
  return (*this);
}

std::string		nts::APin::getName(void) const
{
  return (this->_name);
}

nts::Tristate		nts::APin::getValue(void) const
{
  return ((this->_pins[1]) ? (*(this->_pins[1])) : (UNDEFINED));
}

void			nts::APin::setName(const std::string &name)
{
  this->_name = name;
}

void			nts::APin::setValue(nts::Tristate value)
{
  if (_pins[1])
    *(this->_pins[1]) = value;
}

void			nts::APin::setValue(const std::string &value)
{
  if (_pins[1])
    {
      if (value == "1")
	*(this->_pins[1]) = nts::TRUE;
      else if (value == "0")
	*(this->_pins[1]) = nts::FALSE;
      else
	*(this->_pins[1]) = nts::UNDEFINED;
    }
}

nts::Tristate		nts::APin::Compute(size_t pin_num_this)
{
  if (pin_num_this != 1)
    return (UNDEFINED);
  return ((this->_pins[1]) ? (*(this->_pins[1])) : (UNDEFINED));
}

bool			nts::APin::haveLink(void)
{
  return (this->_links.empty());
}
