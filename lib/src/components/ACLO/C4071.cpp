//
// C4071.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Wed Feb  1 13:17:56 2017 vincent.mesquita
// Last update Mon Feb  6 11:34:35 2017 vincent.mesquita
//

#include "C4071.hpp"

nts::C4071::C4071(const std::string &name) : ACLO(name)
{
  this->_lo = &LogicalOperators::OR;
}

nts::C4071::C4071(const C4071 &other) : ACLO(other) {}

nts::C4071::~C4071(void) {}

void			nts::C4071::Dump(void) const
{
  std::cout << "----- [C4071]" << _name << " -----" << std::endl;
  AComponent::Dump();
}
