//
// ACLO.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib/src/components/ACLO
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Wed Feb  1 10:47:08 2017 vincent.mesquita
// Last update Fri Mar  3 20:59:45 2017 vincent.mesquita@epitech.eu
//

#include "ACLO.hpp"

nts::ACLO::ACLO(const std::string &name) : AComponent(name, 14)
{
  this->_pins_type[0] = VSS; // Doesn't exist
  this->_pins_type[1] = INPUT;
  this->_pins_type[2] = INPUT;
  this->_pins_type[3] = OUTPUT;
  this->_pins_type[4] = OUTPUT;
  this->_pins_type[5] = INPUT;
  this->_pins_type[6] = INPUT;
  this->_pins_type[7] = VSS;
  this->_pins_type[8] = INPUT;
  this->_pins_type[9] = INPUT;
  this->_pins_type[10] = OUTPUT;
  this->_pins_type[11] = OUTPUT;
  this->_pins_type[12] = INPUT;
  this->_pins_type[13] = INPUT;
  this->_pins_type[14] = VDD;

  _initPins(UNDEFINED);
  
  this->_compute_links[3] = std::make_pair(1, 2);
  this->_compute_links[4] = std::make_pair(5, 6);
  this->_compute_links[10] = std::make_pair(8, 9);
  this->_compute_links[11] = std::make_pair(12, 13);
}

nts::ACLO::ACLO(const ACLO &other) : AComponent(other)
{
  this->_compute_links = other._compute_links;
  this->_lo = other._lo;
}

nts::ACLO::~ACLO(void)
{
  this->_freeOutput();
}

nts::ACLO		&nts::ACLO::operator=(const ACLO &other)
{
  if (this != &other)
    {
      AComponent::operator=(other); //A check
      this->_compute_links = other._compute_links;
      this->_lo = other._lo;
    }
  return (*this);
}

nts::Tristate		nts::ACLO::Compute(size_t pin_num_this)
{
  nts::Tristate		state = UNDEFINED;

  _checkPin(pin_num_this);
  if (this->_pins[pin_num_this])
    {
      if (this->_pins_type[pin_num_this] == INPUT)
	return (_computeAllLinks(pin_num_this));

      // std::cout << "firt = " << this->_compute_links[pin_num_this].first << " second = " << this->_compute_links[pin_num_this].second << std::endl << std::endl;;
      this->Compute(this->_compute_links[pin_num_this].first);
      this->Compute(this->_compute_links[pin_num_this].second);

      std::pair<size_t, size_t> p = this->_compute_links[pin_num_this];
      state = _operator(p.first, p.second);
      *(this->_pins[pin_num_this]) = state;
    }
  return (state);
}

nts::Tristate		nts::ACLO::_operator(size_t pinA, size_t pinB)
{
  if (this->_pins[pinA] == NULL || this->_pins[pinB] == NULL)
    return (UNDEFINED);
  return (this->_lo(*(this->_pins[pinA]),
  		    *(this->_pins[pinB])));
}
