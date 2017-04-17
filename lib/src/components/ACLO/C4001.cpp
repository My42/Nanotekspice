//
// C4001.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Wed Feb  1 11:16:25 2017 vincent.mesquita
// Last update Wed Mar  1 00:20:46 2017 vincen_s
//

#include "C4001.hpp"

nts::C4001::C4001(const std::string &name) : ACLO(name)
{
  this->_lo = &LogicalOperators::NOR;
}

nts::C4001::C4001(const C4001 &other) : ACLO(other) {}

nts::C4001::~C4001(void) {}

void			nts::C4001::Dump(void) const
{
  std::cout << "----- [C4001]" << _name << " -----" << std::endl;
  AComponent::Dump();
}
