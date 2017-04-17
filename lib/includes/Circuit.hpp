/*
** Circuit.hpp for cpp_nanotekspice in /home/vincent.mesquita@epitech.eu/rendu/cpp_nanotekspice/Circuit.hpp
**
** Made by Vincent Mesquita
** Login   <vincent.mesquita@epitech.eu>
**
** Started on  Fri Jan 27 11:28:09 2017 Vincent Mesquita
// Last update Thu Mar  2 16:35:24 2017 vincent.mesquita@epitech.eu
*/
#ifndef CPP_NANOTEKSPICE_CIRCUIT_HPP
#define CPP_NANOTEKSPICE_CIRCUIT_HPP

#include <memory>
#include <vector>
#include "IComponent.hpp"

namespace crt
{
  class Circuit {
  public:
    Circuit();
    ~Circuit();
    Circuit(const Circuit &);

    Circuit                 				&operator=(const Circuit &);

    void 						setComponent(std::shared_ptr<nts::IComponent>);
  private:
    std::vector<std::shared_ptr<nts::IComponent>>	_components;
  };
};

#endif // !CPP_NANOTEKSPICE_CIRCUIT_HPP
