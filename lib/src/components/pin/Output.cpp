//
// Output.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Mon Jan 30 12:30:03 2017 vincent.mesquita
// Last update Fri Mar  3 20:49:08 2017 vincent.mesquita@epitech.eu
//

#include "Output.hpp"

nts::Output::Output(const std::string &name)
  : APin(name, UNDEFINED)
{
  this->_pins_type[1] = INPUT;
}

nts::Output::Output(const std::string &name, const std::string &value) : APin(name, value)
{
  this->_pins_type[1] = INPUT;
}

nts::Output::Output(const std::string &name, const nts::Tristate &value)
  : APin(name, value)
{
  this->_pins_type[1] = INPUT;
}

nts::Output::Output(const Output &other) : APin(other)
{
  this->_pins_type[1] = INPUT;
}

nts::Output::~Output(void) {}

void			nts::Output::Dump(void) const
{
  std::cout << "[Output : " << this->_name << "] = ";
  if (this->_pins[1] != NULL)
    std::cout << *(this->_pins[1])
      	      << " (" << this->_pins[1] << ")" << std::endl;
  else
    std::cout << "NULL" << std::endl;
}

void			nts::Output::SetLink(size_t pin_num_this,
					     nts::IComponent &component,
					     size_t pin_num_target)
{
  AComponent		*ac = (dynamic_cast<AComponent*>(&component));
  nts::Tristate		*state;

  if (pin_num_this != 1)
    throw nts::exception::BadOutputPinException();
  else if (this->_pins_type[pin_num_this] == ac->getPinType(pin_num_target))
    throw nts::exception::PinLinkageException();

  _setLink(pin_num_this, component, pin_num_target);
  
  if (!(state = ac->getPin(pin_num_target)))
    ac->setPinValue(pin_num_target, new nts::Tristate(UNDEFINED));
  this->_pins[1] = ac->getPin(pin_num_target);
}

nts::Tristate		nts::Output::Compute(size_t pin_num_this)
{
  _computeAllLinks(pin_num_this);
  return (APin::Compute(pin_num_this));
}
