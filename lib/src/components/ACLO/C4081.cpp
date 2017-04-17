//
// C4081.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Wed Feb  1 13:26:09 2017 vincent.mesquita
// Last update Wed Mar  1 02:15:57 2017 vincen_s
//

#include "C4081.hpp"

nts::C4081::C4081(const std::string &name) : ACLO(name)
{
  this->_lo = &LogicalOperators::AND;
}

nts::C4081::C4081(const C4081 &other) : ACLO(other) {}

nts::C4081::~C4081(void) {}

void			nts::C4081::Dump(void) const
{
  std::cout << "----- [C4081]" << _name << " -----" << std::endl;
  AComponent::Dump();
}
