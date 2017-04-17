//
// main.cpp for  in /home/kyx/rendu/cpp_nanotekspice/lib
// 
// Made by Florian Vincent
// Login   <kyx@epitech.net>
// 
// Started on  Sat Feb 18 12:43:35 2017 Florian Vincent
// Last update Sun Mar  5 20:43:20 2017 vincent.mesquita@epitech.eu
//

#include "nanotekspice.hpp"

int		main(int ac, char **av)
{
  try {
    nts::Nanotekspice	nanotekspice(ac, av);
    nanotekspice.main_loop();
  } catch (std::exception const &e) {
    std::cerr << e.what() << std::endl;
  }
  return (0);
}
