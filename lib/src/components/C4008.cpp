//
// C4008.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Wed Feb  8 11:03:30 2017 vincent.mesquita
// Last update Sun Mar  5 15:25:41 2017 vincent.mesquita@epitech.eu
//

#include "C4008.hpp"

nts::C4008::C4008(const std::string &name) : AComponent(name, 16)
{
  size_t			i;
  size_t			a;
  size_t			b;

  _nbr_of_carries = 5;
  _c1_pin = 9;
  _co_pin = 14;

  _pins_type[0] = VSS; // Doesn't exist
  _pins_type[1] = INPUT; // A4
  _pins_type[2] = INPUT; // B3
  _pins_type[3] = INPUT; // A3
  _pins_type[4] = INPUT; // B2
  _pins_type[5] = INPUT; // A2
  _pins_type[6] = INPUT; // B1
  _pins_type[7] = INPUT; // A1
  _pins_type[8] = VSS;
  _pins_type[9] = INPUT; // C1
  _pins_type[10] = OUTPUT; // S1
  _pins_type[11] = OUTPUT; // S2
  _pins_type[12] = OUTPUT; // S3
  _pins_type[13] = OUTPUT; // S4
  _pins_type[14] = OUTPUT; // C0
  _pins_type[15] = INPUT; // B4
  _pins_type[16] = VDD;

  _initPins(UNDEFINED);

  i = 10;
  a = 7;
  b = 6;
  while (i < 13)
    {
      _compute_links[i++] = std::make_pair(a, b);
      a -= 2;
      b -= 2;
    }
  _compute_links[13] = std::make_pair(1, 15);

  i = 1;
  _carries.push_back(FALSE);
  while (i++ <= _nbr_of_carries)
    _carries.push_back(UNDEFINED);

  _carry_links[10] = 1;
  _carry_links[11] = 2;
  _carry_links[12] = 3;
  _carry_links[13] = 4;
}

nts::C4008::C4008(const nts::C4008 &other) : AComponent(other),
					     _nbr_of_carries(other._nbr_of_carries),
					     _c1_pin(other._c1_pin),
					     _co_pin(other._co_pin),
					     _compute_links(other._compute_links),
					     _carries(other._carries),
					     _carry_links(other._carry_links) { }

nts::C4008::~C4008(void)
{
  this->_freeOutput();
}

nts::C4008			&nts::C4008::operator=(const nts::C4008 &other)
{
  if (this != &other)
    {
      AComponent::operator=(other);
      _nbr_of_carries = other._nbr_of_carries;
      _c1_pin = other._c1_pin;
      _co_pin = other._co_pin;
      _compute_links = other._compute_links;
      _carries = other._carries;
      _carry_links = other._carry_links;
    }
  return (*this);
}

nts::Tristate			nts::C4008::Compute(size_t pin_num_this)
{
  _checkPin(pin_num_this);
  if (!(_pins[pin_num_this]))
    return (UNDEFINED);
  if (_pins_type[pin_num_this] == INPUT)
    return (_computeAllLinks(pin_num_this));
  if (_pins_type[pin_num_this] == OUTPUT && pin_num_this != _co_pin)
    {
      Compute(_compute_links[pin_num_this].first);
      Compute(_compute_links[pin_num_this].second);
      _calculate(pin_num_this);
    }
  return (getPinValue(pin_num_this));
}

void				nts::C4008::Dump(void) const
{
  std::cout << "----- [C4008]" << _name << " -----" << std::endl;
  AComponent::Dump();
}

void				nts::C4008::_calculate(size_t pin_num_this)
{
  size_t			bit = _carry_links[pin_num_this];
  nts::Tristate			result = FALSE;
  nts::Tristate			*a = _pins[_compute_links[pin_num_this].first];
  nts::Tristate			*b = _pins[_compute_links[pin_num_this].second];

  if (!a || !b)
    return ;
  if (_carries[bit - 1] == UNDEFINED)
    _calculate(pin_num_this - 1);
  if (_pins[_c1_pin])
    _carries[0] = *(_pins[_c1_pin]);
  result = (nts::Tristate)((*a ^ *b) ^ _carries[bit - 1]);
  _carries[bit] = (nts::Tristate)((*a & *b)
					| (*a & _carries[bit - 1])
					| (*b & _carries[bit - 1]));
  *(_pins[pin_num_this]) = result;
  *(_pins[_co_pin]) = _carries[_nbr_of_carries - 1];
}
