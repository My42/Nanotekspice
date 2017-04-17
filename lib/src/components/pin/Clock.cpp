//
// Clock.cpp for  in /home/florian/rendu/cpp_nanotekspice
// 
// Made by vincen_s
// Login   <florian@epitech.net>
// 
// Started on  Thu Mar  2 15:25:05 2017 vincen_s
// Last update Fri Mar  3 11:44:13 2017 vincen_s
//

#include "Clock.hpp"

nts::Clock::Clock(const std::string &name, const std::string &value) : Input(name, value)
{}

nts::Clock::Clock(const Clock &other) : Input(other)
{}

nts::Clock::~Clock(void) {}

void			nts::Clock::Dump(void) const
{
  std::cout << "[Clock : " << this->_name << "] = ";
  if (this->_pins[1] != NULL)
    std::cout << *(this->_pins[1])
      	      << " (" << this->_pins[1] << ")" << std::endl;
  else
    std::cout << "NULL" << std::endl;
}

void			nts::Clock::Inverse()
{
  if (this->_pins[1] != NULL)
    {
      if (*(this->_pins[1]) == TRUE)
	this->setValue("0");
      else if (*(this->_pins[1]) == FALSE)
	this->setValue("1");
    }
}
