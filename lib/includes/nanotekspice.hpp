//
// nanotekspice.hpp for  in /home/florian/rendu/cpp_nanotekspice
// 
// Made by vincen_s
// Login   <florian@epitech.net>
// 
// Started on  Sun Mar  5 18:16:05 2017 vincen_s
// Last update Sun Mar  5 18:52:28 2017 vincen_s
//

#ifndef NANOTEKSPICE_H_
# define NANOTEKSPICE_H_

# include "parser.hpp"

namespace nts
{
  class Nanotekspice
  {
  public:
    Nanotekspice(int ac, char **av);
    void		main_loop();
    void	checkopen(int ac, char **av, std::ifstream &File);
    ~Nanotekspice(void) {}

  private:
    nts::Parser		parser;
  };
};

#endif /* !NANOTEKSPICE_H_ */
