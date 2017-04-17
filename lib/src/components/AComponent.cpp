
//
// AComponent.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib/src/components
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Fri Feb  3 15:15:49 2017 vincent.mesquita
// Last update Fri Mar  3 20:58:46 2017 vincent.mesquita@epitech.eu
//

#include "AComponent.hpp"

nts::AComponent::AComponent(const std::string &name,
			    const size_t nbr_of_pins)
  : _name(name), _nbr_of_pins(nbr_of_pins), _last_link()
{
  _pins.reserve(_nbr_of_pins + 1);
  _pins_type.reserve(_nbr_of_pins + 1);
}

nts::AComponent::AComponent(const nts::AComponent &other)
  : _name(other._name),
    _nbr_of_pins(other._nbr_of_pins),
    _pins(other._pins),
    _pins_type(other._pins_type),
    _last_link(other._last_link)
{ }

nts::AComponent::~AComponent(void) { }

nts::AComponent			&nts::AComponent::operator=(const nts::AComponent &other)
{
  if (this != &other)
    {
      _name = other._name;
      _nbr_of_pins = other._nbr_of_pins;
      _pins = other._pins;
      _pins_type = other._pins_type;
    }
  return (*this);
}

void				nts::AComponent::setPinValue(const size_t pin_num_this,
							     nts::Tristate *s)
{
  _checkPin(pin_num_this);
  _pins[pin_num_this] = s;
}

nts::e_pin_type			nts::AComponent::getPinType(const size_t pin_num_this) const
{
  _checkPin(pin_num_this);
  return (_pins_type[pin_num_this]);
}

nts::Tristate			nts::AComponent::getPinValue(const size_t pin_num_this) const
{
  nts::Tristate			state;

  _checkPin(pin_num_this);
  state = ((_pins[pin_num_this]) ? (*_pins[pin_num_this]) : (UNDEFINED));
  return (state);
}

const std::string		&nts::AComponent::getName(void) const
{
  return (_name);
}

nts::Tristate			*nts::AComponent::getPin(const size_t pin_num_this) const
{
  if (pin_num_this < 1 || pin_num_this > _nbr_of_pins)
    throw nts::exception::PinNumberException(pin_num_this, _name);
  return (_pins[pin_num_this]);
}

void				nts::AComponent::Dump(void) const
{
  size_t			i = 0;

  for (auto ptr : _pins)
    {
      if (i != 0 && _pins_type[i] != VSS)
	{
	  std::cout << "[" << i << "] = ";
	  if (ptr != NULL)
	    std::cout << *ptr <<" ("<< ptr << ")" << std::endl;
	  else
	    std::cout << "NULL" << std::endl;
	}
      i += 1;
    }
}

void				nts::AComponent::SetLink(size_t pin_num_this,
							 nts::IComponent &component,
							 size_t pin_num_target)
{
  nts::AComponent		*ac = dynamic_cast<nts::AComponent*>(&component);
  nts::AComponent		*t_ac = dynamic_cast<nts::AComponent*>(this);

  if (pin_num_this == 0 || pin_num_this > _nbr_of_pins)
    throw nts::exception::PinNumberException(pin_num_this, _name);
  else if (_pins_type[pin_num_this] == ac->getPinType(pin_num_target))
    throw nts::exception::PinLinkageException();

  _setLink(pin_num_this, component, pin_num_target);

  if (_pins_type[pin_num_this] == OUTPUT)
    {
      if (_pins[pin_num_this] == NULL)
	_pins[pin_num_this] = new nts::Tristate(UNDEFINED);
      ac->setPinValue(pin_num_target, _pins[pin_num_this]);
    }
  else if (_pins_type[pin_num_this] == INPUT)
    {
      if (ac->getPin(pin_num_target) == NULL)
      	ac->setPinValue(pin_num_target, new nts::Tristate(UNDEFINED));
      t_ac->setPinValue(pin_num_this, ac->getPin(pin_num_target));
    }
}

void				nts::AComponent::_setLink(size_t pin_num_this,
							  IComponent &component,
							  size_t pin_num_target)
{
  std::pair<size_t, IComponent* >p
    = std::make_pair(pin_num_target, &component);
  for (auto it : _last_link)
    if (p == it)
      return ;
  _last_link.push_back(p);
  _links[pin_num_this].push_back(p);
  component.SetLink(pin_num_target, *this, pin_num_this);
}

nts::Tristate			nts::AComponent::_computeAllLinks(size_t pin_num_this)
{
  unsigned int			i = 0;

  if (_already_did[pin_num_this] == false)
    {
      _already_did[pin_num_this] = true;
      for (auto it : _links[pin_num_this])
	{
	  (it.second)->Compute(it.first);
	  i += 1;
	}
      _already_did[pin_num_this] = false;
    }
  return ((_pins[pin_num_this]) ? (*(_pins[pin_num_this])) : (UNDEFINED));
}

void				nts::AComponent::_checkPin(const size_t pin_num) const
{
  if (pin_num < 1 || pin_num > _nbr_of_pins)
    throw nts::exception::PinNumberException(pin_num, _name);
  if (_pins_type[pin_num] == VSS || _pins_type[pin_num] == VDD)
    throw nts::exception::PinUseException(_pins_type[pin_num], _name);
}

void				nts::AComponent::_freeOutput(void)
{
  size_t			i = 0;

  for (auto it : _pins)
    {
      if (_pins_type[i] == OUTPUT && it)
	delete it;
      i += 1;
    }
}

void				nts::AComponent::_initPins(nts::Tristate state)
{
  size_t			i = 0;

  while (i <= _nbr_of_pins)
    {
      _already_did.push_back(false);
      if (_pins_type[i] == OUTPUT)
	_pins.push_back(new nts::Tristate(state));
      else
	_pins.push_back(NULL);
      i += 1;
    }
}
