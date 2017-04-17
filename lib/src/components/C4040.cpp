//
// C4040.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Mon Feb  6 13:41:21 2017 vincent.mesquita
// Last update Sat Mar  4 12:33:07 2017 vincent.mesquita@epitech.eu
//

#include "C4040.hpp"

nts::C4040::C4040(const std::string &name) : AComponent(name, 16)
{
  _nbr_of_bits = 12;
  _last_clock_state = RISING_EDGE;
  _already_calculated = false;
  _clock_index = 10;
  _reset_index = 11;

  _pins_type[0] = VSS; // Doesn't exist
  _pins_type[1] = OUTPUT; // Q12
  _pins_type[2] = OUTPUT; // Q6
  _pins_type[3] = OUTPUT; // Q5
  _pins_type[4] = OUTPUT; // Q7
  _pins_type[5] = OUTPUT; // Q4
  _pins_type[6] = OUTPUT; // Q3
  _pins_type[7] = OUTPUT; // Q2
  _pins_type[8] = VSS;
  _pins_type[9] = OUTPUT; // Q1
  _pins_type[10] = INPUT; // C
  _pins_type[11] = INPUT; // R
  _pins_type[12] = OUTPUT; // Q9
  _pins_type[13] = OUTPUT; // Q8
  _pins_type[14] = OUTPUT; // Q10
  _pins_type[15] = OUTPUT; // Q11
  _pins_type[16] = VDD;

  _initPins(FALSE);

  _number.push_back(_pins[1]); // Q12
  _number.push_back(_pins[15]); // Q11
  _number.push_back(_pins[14]); // Q10
  _number.push_back(_pins[12]); // Q9
  _number.push_back(_pins[13]); // Q8
  _number.push_back(_pins[4]); // Q7
  _number.push_back(_pins[2]); // Q6
  _number.push_back(_pins[3]); // Q5
  _number.push_back(_pins[5]); // Q4
  _number.push_back(_pins[6]); // Q3
  _number.push_back(_pins[7]); // Q2
  _number.push_back(_pins[9]); // Q1
}

nts::C4040::C4040(const nts::C4040 &other) : AComponent(other),
					     _number(other._number),
					     _nbr_of_bits(other._nbr_of_bits),
					     _last_clock_state(other._last_clock_state),
					     _already_calculated(other._already_calculated)
{ }

nts::C4040::~C4040(void)
{
  _freeOutput();
}

nts::C4040			&nts::C4040::operator=(const nts::C4040 &other)
{
  if (this != &other)
    {
      nts::AComponent::operator=(other);
      _number = other._number;
      _nbr_of_bits = other._nbr_of_bits;
      _last_clock_state = other._last_clock_state;
      _already_calculated = other._already_calculated;
    }
  return (*this);
}

nts::Tristate			nts::C4040::Compute(size_t pin_num_this)
{
  _checkPin(pin_num_this);
  if (!(_pins[pin_num_this]))
    return (UNDEFINED);
  if (_pins_type[pin_num_this] == INPUT)
    {
      nts::Tristate	state = _computeAllLinks(pin_num_this);
      if (getPinValue(_clock_index) != _last_clock_state)
	return (state);
    }
  Compute(_reset_index);
  Compute(_clock_index);
  if (getPinValue(_reset_index) == RISING_EDGE)
    {
      _reset();
      return (FALSE);
    }
  if (_already_calculated == FALSE
      && getPinValue(_clock_index) == FALLING_EDGE)
    {
      _calculate();
      _already_calculated = TRUE;
    }
  _last_clock_state = getPinValue(_clock_index);
  return (*(_pins[pin_num_this]));
}

void				nts::C4040::Dump(void) const
{
  std::cout << "----- [C4040]" << _name << " -----" << std::endl;
  AComponent::Dump();
  for (auto bit : _number)
    {
      std::cout << *bit;
    }
  std::cout << std::endl;
}

void				nts::C4040::_reset(size_t begin)
{
  size_t			i = 0;

  for (auto bit : _number)
    {
      if (i >= begin)
	*bit = FALSE;
      i += 1;
    }
}

void				nts::C4040::_calculate(void)
{
  size_t			i = _nbr_of_bits - 1;

  while (i < _nbr_of_bits && *(_number[i]) == TRUE)
    i -= 1;
  if (i > _nbr_of_bits)
    _reset();
  else
    {
      _reset(i);
      *(_number[i]) = TRUE;
    }
}
