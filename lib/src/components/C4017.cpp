//
// C4017.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita@epitech.eu
// Login   <vincy@epitech.net>
// 
// Started on  Tue Feb 28 13:43:09 2017 vincent.mesquita@epitech.eu
// Last update Sun Mar  5 17:21:14 2017 vincent.mesquita@epitech.eu
//

#include "C4017.hpp"

nts::C4017::C4017(const std::string &name) : AComponent(name, 15)
{
  _pins_type[0] = VSS; // Doesn't exist
  _pins_type[1] = OUTPUT; // Q5
  _pins_type[2] = OUTPUT; // Q1
  _pins_type[3] = OUTPUT; // Q0
  _pins_type[4] = OUTPUT; // Q2
  _pins_type[5] = OUTPUT; // Q6
  _pins_type[6] = OUTPUT; // Q7
  _pins_type[7] = OUTPUT; // Q3
  _pins_type[8] = VSS; // Doesn't exist
  _pins_type[9] = OUTPUT; // Q8
  _pins_type[10] = OUTPUT; // Q4
  _pins_type[11] = OUTPUT; // Q9
  _pins_type[12] = OUTPUT; // Q59
  _pins_type[13] = INPUT; // CP1
  _pins_type[14] = INPUT; // CP0
  _pins_type[15] = INPUT; // MR;

  _initPins(FALSE);
  _outputs = {_pins[C4017_Q0], _pins[C4017_Q1], _pins[C4017_Q2], _pins[C4017_Q3],
	      _pins[C4017_Q4], _pins[C4017_Q5], _pins[C4017_Q6], _pins[C4017_Q7],
	      _pins[C4017_Q8], _pins[C4017_Q9]};
  _current = 0;
  _last_clock_state = UNDEFINED;
}

nts::C4017::C4017(const nts::C4017 &other) : AComponent(other)
{
  _outputs = other._outputs;
  _current = other._current;
}

nts::C4017::~C4017(void)
{
  _freeOutput();
}

nts::C4017			&nts::C4017::operator=(const nts::C4017 &other)
{
  if (this != &other)
    {
      AComponent::operator=(other);
      _outputs = other._outputs;
      _current = other._current;
    }
  return (*this);
}

nts::Tristate			nts::C4017::Compute(size_t pin_num_this)
{
  _checkPin(pin_num_this);
  if (getPinValue(C4017_MR) == TRUE)
    {
      *(_outputs[_current]) = FALSE;
      *(_pins[C4017_Q59]) = TRUE;
      *(_pins[C4017_Q0]) = TRUE;
      _current = 0;
      return (getPinValue(pin_num_this));
    }
  else if (_pins_type[pin_num_this] == INPUT)
    return (_computeAllLinks(pin_num_this));
  Compute(C4017_CP0);
  Compute(C4017_MR);
  if (_pins_type[pin_num_this] == OUTPUT && getPinValue(C4017_CP0) != _last_clock_state)
    {
      *(_outputs[_current]) = FALSE;
      if (getPinValue(C4017_CP0) == FALLING_EDGE)
	_current = (_current + 1) % _outputs.size();
      *(_outputs[_current]) = TRUE;
      *(_pins[C4017_Q59]) = ((_current < 5) ? (TRUE) : (FALSE));
      _last_clock_state = getPinValue(C4017_CP0);
    }
  return (getPinValue(pin_num_this));
}

void				nts::C4017::Dump(void) const
{
  std::cout << "----- [C4017]" << _name << " -----" << std::endl;
  AComponent::Dump();
}
