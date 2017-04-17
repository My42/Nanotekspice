//
// nanotekspice.cpp for  in /home/florian/rendu/cpp_nanotekspice
// 
// Made by vincen_s
// Login   <florian@epitech.net>
// 
// Started on  Sun Mar  5 18:12:21 2017 vincen_s
// Last update Sun Mar  5 18:47:37 2017 vincen_s
//

# include "nanotekspice.hpp"

nts::Nanotekspice::Nanotekspice(int ac, char **av)
{
  int		i = 1;
  std::ifstream File;
  std::stringstream strStream;
  nts::t_ast_node *tree;

  checkopen(ac, av, File);
  strStream << File.rdbuf();
  parser.feed(strStream.str());
  File.close();
  tree = parser.createTree();
  if (ac > 2)
    {
      while (++i < ac)
	{
	  std::string	str1(av[i]);
	  parser.check_input(str1);
	}
    }
  parser.parseTree(*tree);
  parser.simulate();
  parser.display();
}

void		nts::Nanotekspice::checkopen(int ac, char **av, std::ifstream &File)
{
  if (ac <= 1)
    throw nts::exception::ParserException("Usage: " + std::string(av[0]) + "file input(s)=value ...");
  File.open(av[1]);
  if (!File.is_open())
    throw nts::exception::ParserException("can't open file");
}

void		nts::Nanotekspice::main_loop()
{
  std::string	input;
  std::map<std::string, std::function<void(void)>>	tab = {
    {"simulate", [&](void) -> void {this->parser.simulate(); }},
    {"display", [&](void) -> void {this->parser.display(); }},
    {"dump", [&](void) -> void {this->parser.dump(); }},
    {".help", [&](void) -> void {this->parser.help(); }},
    {"loop", [&](void) -> void {this->parser.loop(); }}
  };

  while (std::cin)
    {
      std::cout << "> ";
      if (std::getline(std::cin, input))
	{
	  if (tab[input] != NULL)
	    tab[input]();
	  else if (input.compare("exit") == 0)
	    return ;
	  else if (input.compare("") != 0)
	    parser.change_input(input);
	}
    }
  std::cout << std::endl;
}
