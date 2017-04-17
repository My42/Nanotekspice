//
// C4030.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Wed Feb  1 11:52:50 2017 vincent.mesquita
// Last update Mon Feb  6 11:33:50 2017 vincent.mesquita
//

#include "C4030.hpp"

nts::C4030::C4030(const std::string &name) : ACLO(name)
{
  this->_lo = &LogicalOperators::XOR;
}

nts::C4030::C4030(const C4030 &other) : ACLO(other) {}

nts::C4030::~C4030(void) {}

void			nts::C4030::Dump(void) const
{
  std::cout << "----- [C4030]" << _name << " -----" << std::endl;
  AComponent::Dump();
}
