//
// C4013.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Fri Feb 10 11:57:01 2017 vincent.mesquita
// Last update Sun Mar  5 16:23:44 2017 vincent.mesquita@epitech.eu
//

#include "C4013.hpp"

nts::C4013::C4013(const std::string &name) : AComponent(name, 14)
{
  _clock_index = 0;
  _reset_index = 1;
  _data_index = 2;
  _set_index = 3;

  _pins_type[0] = VSS; // Doesn't exist
  _pins_type[1] = OUTPUT; // Q1
  _pins_type[2] = OUTPUT; // _Q1
  _pins_type[3] = INPUT; // CLOCK 1
  _pins_type[4] = INPUT; // RESET 1
  _pins_type[5] = INPUT; // DATA 1
  _pins_type[6] = INPUT; // SET 1
  _pins_type[7] = VSS;
  _pins_type[8] = INPUT; // SET 2
  _pins_type[9] = INPUT; // DATE 2
  _pins_type[10] = INPUT; // RESET 2
  _pins_type[11] = INPUT; // CLOCK 2
  _pins_type[12] = OUTPUT; // Q2
  _pins_type[13] = OUTPUT; // _Q2
  _pins_type[14] = VDD;

  _initPins(UNDEFINED);
  
  _compute_links[1] = {3, 4, 5, 6};
  _compute_links[2] = {3, 4, 5, 6};
  _compute_links[12] = {11, 10, 9, 8};
  _compute_links[13] = {11, 10, 9, 8};

  _Q_links[1] = 2;
  _Q_links[2] = 1;
  _Q_links[12] = 13;
  _Q_links[13] = 12;

  _fptr_tab = {
    {std::make_pair(FALSE, FALSE), [&](auto pin_num_this) -> void {this->_truth_table1(pin_num_this);}},
    {std::make_pair(TRUE, FALSE), [&](auto pin_num_this) -> void {this->_truth_table2(pin_num_this);}},
    {std::make_pair(FALSE, TRUE), [&](auto pin_num_this) -> void {this->_truth_table3(pin_num_this);}},
    {std::make_pair(TRUE, TRUE), [&](auto pin_num_this) -> void {this->_truth_table4(pin_num_this);}}
  };
}

nts::C4013::C4013(const nts::C4013 &other) : AComponent(other),
					     _compute_links(other._compute_links),
					     _Q_links(other._Q_links),
					     _clock_index(other._clock_index),
					     _reset_index(other._reset_index),
					     _data_index(other._data_index),
					     _set_index(other._set_index)
{

}

nts::C4013::~C4013(void)
{
  _freeOutput();
}

nts::C4013			&nts::C4013::operator=(const nts::C4013 &other)
{
  if (this != &other)
    {
      AComponent::operator=(other);
      _compute_links = other._compute_links;
      _Q_links = other._Q_links;
      _clock_index = other._clock_index;
      _reset_index = other._reset_index;
      _data_index = other._data_index;
      _set_index = other._set_index;
    }
  return (*this);
}

void				nts::C4013::Dump(void) const
{
  std::cout << "----- [C4013]" << _name << " -----" << std::endl;
  AComponent::Dump();
}

nts::Tristate			nts::C4013::Compute(size_t pin_num_this)
{
  _checkPin(pin_num_this);
  if (_pins_type[pin_num_this] == INPUT)
    return (_computeAllLinks(pin_num_this));
  _computeInputs(pin_num_this);
  if (_pins_type[pin_num_this] == OUTPUT)
    _calculate(pin_num_this);
  return (UNDEFINED);
}

void				nts::C4013::_computeInputs(size_t pin_num_this)
{
  for (auto it : _compute_links[pin_num_this])
    _computeAllLinks(it);
}

void				nts::C4013::_calculate(size_t pin_num_this)
{
  std::vector<size_t>		inputs = _compute_links[pin_num_this];
  nts::Tristate			reset = getPinValue(inputs[_reset_index]);
  nts::Tristate			set = getPinValue(inputs[_set_index]);

  _fptr_tab[std::make_pair(reset, set)](pin_num_this);
}

void				nts::C4013::_truth_table1(size_t pin_num_this)
{
  if (pin_num_this == 2 || pin_num_this == 12)
    pin_num_this = _Q_links[pin_num_this];
  std::vector<size_t>		inputs = _compute_links[pin_num_this];
  nts::Tristate			clock = getPinValue(inputs[_clock_index]);
  nts::Tristate			data = getPinValue(inputs[_data_index]);

  if (clock == RISING_EDGE)
    {
      *(_pins[pin_num_this]) = data;
      *(_pins[_Q_links[pin_num_this]]) = LogicalOperators::NOT(data);
    }
}

void				nts::C4013::_truth_table2(size_t pin_num_this)
{
  *(_pins[pin_num_this]) = FALSE;
  *(_pins[_Q_links[pin_num_this]]) = TRUE;
}

void				nts::C4013::_truth_table3(size_t pin_num_this)
{
  *(_pins[pin_num_this]) = TRUE;
  *(_pins[_Q_links[pin_num_this]]) = FALSE;
}

void				nts::C4013::_truth_table4(size_t pin_num_this)
{
  *(_pins[pin_num_this]) = TRUE;
  *(_pins[_Q_links[pin_num_this]]) = TRUE;
}
