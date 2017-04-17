//
// True.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita@epitech.eu
// Login   <vincy@epitech.net>
// 
// Started on  Thu Mar  2 13:51:22 2017 vincent.mesquita@epitech.eu
// Last update Thu Mar  2 15:16:08 2017 vincen_s
//

#include "True.hpp"

nts::True::True(const std::string &name) : Input(name, TRUE) { }

nts::True::True(const True &other) : Input(other) { }

nts::True::~True(void) { }

void			nts::True::setValue(nts::Tristate) { }

void			nts::True::setValue(const std::string &) {
  std::cerr << "Not able to change True's value" << std::endl;
}
