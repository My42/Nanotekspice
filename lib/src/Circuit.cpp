/*
** Circuit.cpp for cpp_nanotekspice in /home/vincent.mesquita@epitech.eu/rendu/cpp_nanotekspice/Circuit.cpp
**
** Made by Vincent Mesquita
** Login   <vincent.mesquita@epitech.eu>
**
** Started on  Fri Jan 27 11:28:09 2017 Vincent Mesquita
// Last update	Sun Jan 29 16:55:00 2017 Vincent Mesquita
*/

#include "Circuit.hpp"

crt::Circuit::Circuit()
{

}

crt::Circuit::Circuit(const Circuit &o) : _components(o._components)
{

}

crt::Circuit::~Circuit()
{

}

crt::Circuit 		&crt::Circuit::operator=(const Circuit &o)
{
  if (this !=&o)
    {
      this->_components = o._components;
    }
  return (*this);
}

void 			crt::Circuit::setComponent(std::shared_ptr<nts::IComponent> ptr)
{
  this->_components.push_back(ptr);
}
