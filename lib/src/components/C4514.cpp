//
// C4514.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Tue Feb  7 13:11:53 2017 vincent.mesquita
// Last update Fri Mar  3 21:00:31 2017 vincent.mesquita@epitech.eu
//

#include "C4514.hpp"

nts::C4514::C4514(const std::string &name) : AComponent(name, 24)
{
  size_t i;

  _nbr_of_outputs = 16;
  _nbr_of_inputs = 4;
  _strobe = -1;

  _pins_type[0] = VSS; // Doesn't exist
  _pins_type[1] = INPUT; // STROBE
  _pins_type[2] = INPUT; // A
  _pins_type[3] = INPUT; // B
  _pins_type[4] = OUTPUT; // S7
  _pins_type[5] = OUTPUT; // S6
  _pins_type[6] = OUTPUT; // S5
  _pins_type[7] = OUTPUT; // S4
  _pins_type[8] = OUTPUT; // S3
  _pins_type[9] = OUTPUT; // S1
  _pins_type[10] = OUTPUT; // S2
  _pins_type[11] = OUTPUT; // S0
  _pins_type[12] = VSS;
  _pins_type[13] = OUTPUT; // S13
  _pins_type[14] = OUTPUT; // S12
  _pins_type[15] = OUTPUT; // S15
  _pins_type[16] = OUTPUT; // S14
  _pins_type[17] = OUTPUT; // S9
  _pins_type[18] = OUTPUT; // S8
  _pins_type[19] = OUTPUT; // S11
  _pins_type[20] = OUTPUT; // S10
  _pins_type[21] = INPUT; // C
  _pins_type[22] = INPUT; // D
  _pins_type[23] = INPUT;
  _pins_type[24] = VDD;

  _initPins(FALSE);

  i = 0;
  while (i < _nbr_of_outputs)
    {
      _selected_output.push_back(NULL);
      i += 1;
    }

  i = 0;
  while (i < _nbr_of_inputs)
    {
      _input.push_back(NULL);
      i += 1;
    }

  _selected_output[0] = _pins[11];
  _selected_output[1] = _pins[9];
  _selected_output[2] = _pins[10];
  _selected_output[3] = _pins[8];
  _selected_output[4] = _pins[7];
  _selected_output[5] = _pins[6];
  _selected_output[6] = _pins[5];
  _selected_output[7] = _pins[4];
  _selected_output[8] = _pins[18];
  _selected_output[9] = _pins[17];
  _selected_output[10] = _pins[20];
  _selected_output[11] = _pins[19];
  _selected_output[12] = _pins[14];
  _selected_output[13] = _pins[13];
  _selected_output[14] = _pins[16];
  _selected_output[15] = _pins[15];
}

nts::C4514::C4514(const nts::C4514 &other) : AComponent(other),
					     _selected_output(other._selected_output),
					     _nbr_of_outputs(other._nbr_of_outputs),
					     _nbr_of_inputs(other._nbr_of_inputs),
					     _input(other._input),
					     _strobe(other._strobe)
{ }

nts::C4514::~C4514(void)
{
  this->_freeOutput();
}

nts::C4514		&nts::C4514::operator=(const C4514 &other)
{
  if (this != &other)
    {
      AComponent::operator=(other);
      _selected_output = other._selected_output;
      _nbr_of_outputs = other._nbr_of_outputs;
      _nbr_of_inputs = other._nbr_of_inputs;
      _input = other._input;
      _strobe = other._strobe;
    }
  return (*this);
}

void			nts::C4514::Dump(void) const
{
  std::cout << "----- [C4514]" << _name << " -----" << std::endl;
  AComponent::Dump();
}

nts::Tristate		nts::C4514::Compute(size_t pin_num_this)
{
  _checkPin(pin_num_this);
  if (_pins_type[pin_num_this] == INPUT)
    return (_computeAllLinks(pin_num_this));
  Compute(C4514_STROBE);
  Compute(C4514_A);
  Compute(C4514_B);
  Compute(C4514_C);
  Compute(C4514_D);
  Compute(C4514_INHIBIT);
  if (_pins_type[pin_num_this] == OUTPUT)
    {
      if (_strobe != -1 && getPinValue(C4514_STROBE) == TRUE)
	*(_selected_output[_strobe]) = TRUE;
      else
	_which_output();
    }
  return (getPinValue(pin_num_this));
}

void			nts::C4514::_which_output(void)
{
  size_t		i = _nbr_of_inputs - 1;
  size_t		sx = 0;
  size_t		pow = 0;

  _input[0] = _pins[C4514_D];
  _input[1] = _pins[C4514_C];
  _input[2] = _pins[C4514_B];
  _input[3] = _pins[C4514_A];
  _reset();
  if (getPinValue(C4514_INHIBIT) != TRUE)
    {
      while (i < _input.size())
	{
	  if (_input[i] && *(_input[i]) == TRUE)
	    sx += std::pow(2, pow);
	  i -= 1;
	  pow += 1;
	}
      *(_selected_output[sx]) = TRUE;
      _strobe = sx;
    }
}

void			nts::C4514::_reset(void)
{
  for (auto ptr : _selected_output)
    *ptr = FALSE;
}
