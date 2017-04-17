//
// ComponentManagerException.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita@epitech.eu
// Login   <vincy@epitech.net>
// 
// Started on  Thu Mar  2 15:26:28 2017 vincent.mesquita@epitech.eu
// Last update Fri Mar  3 11:25:11 2017 vincent.mesquita@epitech.eu
//

#include "ComponentManagerException.hpp"

nts::exception::ComponentNotFoundException::ComponentNotFoundException(const std::string &name) throw()
{
  this->_msg = "The component \"" + name + "\" doesn't exist.";
}

nts::exception::ComponentNotFoundException::~ComponentNotFoundException(void) throw() { }

const char		*nts::exception::ComponentNotFoundException::what(void) const throw()
{
  return (this->_msg.c_str());
}
