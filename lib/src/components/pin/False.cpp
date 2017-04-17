//
// False.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita@epitech.eu
// Login   <vincy@epitech.net>
// 
// Started on  Thu Mar  2 14:16:01 2017 vincent.mesquita@epitech.eu
// Last update Thu Mar  2 16:45:27 2017 vincen_s
//

#include "False.hpp"

nts::False::False(const std::string &name) : Input(name, FALSE) { }

nts::False::False(const False &other) : Input(other) { }

nts::False::~False(void) { }

void			nts::False::setValue(nts::Tristate) { }

void			nts::False::setValue(const std::string &) {
  std::cerr << "Not able to change False's value" << std::endl;
}
