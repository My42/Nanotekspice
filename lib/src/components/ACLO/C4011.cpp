//
// C4011.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Wed Feb  1 11:15:45 2017 vincent.mesquita
// Last update Mon Feb  6 11:33:40 2017 vincent.mesquita
//

#include "C4011.hpp"

nts::C4011::C4011(const std::string &name) : ACLO(name)
{
  this->_lo = &LogicalOperators::NAND;
}

nts::C4011::C4011(const C4011 &other) : ACLO(other) {}

nts::C4011::~C4011(void) {}

void			nts::C4011::Dump(void) const
{
  std::cout << "----- [C4011]" << _name << " -----" << std::endl;
  AComponent::Dump();
}

