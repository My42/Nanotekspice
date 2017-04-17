//
// C4069.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib/src/components/ACLO
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Wed Feb  1 13:59:47 2017 vincent.mesquita
// Last update Mon Feb  6 11:37:12 2017 vincent.mesquita
//

#include "C4069.hpp"

nts::C4069::C4069(const std::string &name) : ACLO(name)
{
  this->_lo = &LogicalOperators::NOT;

  this->_pins_type[0] = VSS;
  this->_pins_type[1] = INPUT;
  this->_pins_type[2] = OUTPUT;
  this->_pins_type[3] = INPUT;
  this->_pins_type[4] = OUTPUT;
  this->_pins_type[5] = INPUT;
  this->_pins_type[6] = OUTPUT;
  this->_pins_type[7] = VSS;
  this->_pins_type[8] = OUTPUT;
  this->_pins_type[9] = INPUT;
  this->_pins_type[10] = OUTPUT;
  this->_pins_type[11] = INPUT;
  this->_pins_type[12] = OUTPUT;
  this->_pins_type[13] = INPUT;
  this->_pins_type[14] = VDD;

  this->_compute_links[2] = std::make_pair(1, 1);
  this->_compute_links[4] = std::make_pair(3, 3);
  this->_compute_links[6] = std::make_pair(5, 5);
  this->_compute_links[8] = std::make_pair(9, 9);
  this->_compute_links[10] = std::make_pair(11, 11);
  this->_compute_links[12] = std::make_pair(13, 13);
}

nts::C4069::C4069(const C4069 &other) : ACLO(other) {}

nts::C4069::~C4069(void) {}

void			nts::C4069::Dump(void) const
{
  std::cout << "----- [C4069]" << _name << " -----" << std::endl;
  AComponent::Dump();
}
