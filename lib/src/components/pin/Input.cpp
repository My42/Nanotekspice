//
// Input.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Mon Jan 30 12:22:06 2017 vincent.mesquita
// Last update Thu Mar  2 14:02:18 2017 vincent.mesquita@epitech.eu
//

#include "Input.hpp"

nts::Input::Input(const std::string &name, const std::string &value) : APin(name, value)
{
  this->_pins_type[1] = OUTPUT;
}

nts::Input::Input(const std::string &name, nts::Tristate value) : APin(name, value)
{
  this->_pins_type[1] = OUTPUT;
}

nts::Input::Input(const Input &other) : APin(other)
{
  this->_pins_type[1] = OUTPUT;
}

nts::Input::~Input(void) {}

void		nts::Input::Dump(void) const
{
  std::cout << "[Input : " << this->_name << "] = " << *(this->_pins[1])
	    << " (" << this->_pins[1] << ")" << std::endl;
}

void		nts::Input::SetLink(size_t pin_num_this,
				    nts::IComponent &component,
				    size_t pin_num_target)
{
  AComponent		*ac = (dynamic_cast<AComponent*>(&component));

  if (pin_num_this != 1)
    throw nts::exception::BadInputPinException();
  else if (this->_pins_type[pin_num_this] == ac->getPinType(pin_num_target))
    throw nts::exception::PinLinkageException();

  _setLink(pin_num_this, component, pin_num_target);
  
  ac->setPinValue(pin_num_target, this->_pins[pin_num_this]);
}
