//
// parser.hpp for  in /home/kyx/rendu/cpp_nanotekspice/lib
// 
// Made by Florian Vincent
// Login   <kyx@epitech.net>
// 
// Started on  Thu Feb 16 11:26:54 2017 Florian Vincent
// Last update Sat Mar  4 12:46:43 2017 vincen_s
//

#ifndef PARSER_HPP
# define PARSER_HPP

# include <sstream>
# include <iostream>
# include <fstream>
# include <map>
# include <ComponentManager.hpp>
# include "cpp_nanotekspice_parser.hpp"
# include "ParserException.hpp"

# define CHIPSET_VECTOR _root->children->front()->children
# define LINK_VECTOR _root->children->back()->children
# define PARSER_VECTOR _root->children

# define COMPONENT_NAME i->lexeme.substr(i->lexeme.find_first_of(' ') + 1)
# define COMPONENT_TYPE i->lexeme.substr(0, i->lexeme.find_first_of(' '))
# define COMPONENT_VALUE i->value

# define LINK_NAME i->lexeme.substr(0, i->lexeme.find_first_of(':'))
# define PIN_TO_LINK i->lexeme.substr(i->lexeme.find_first_of(':') + 1)
# define LINK_NAME_END j->lexeme.substr(0, j->lexeme.find_first_of(':'))
# define PIN_TO_LINK_END j->lexeme.substr(j->lexeme.find_first_of(':') + 1)

namespace nts
{
  enum class	ParserState : int
    {
      NONE = 0,
      CHIPSET,
      CHIPSET_WAITNAME,
      LINKS,
      LINKS_WAITLINKS
    };

  class	Parser : public nts::IParser
  {
  public:
    virtual void feed(std::string const& input);
    virtual void parseTree(nts::t_ast_node& root);
    virtual nts::t_ast_node *createTree();
    virtual ~Parser();
    Parser();
    void	simulate();
    void	exit();
    void	display();
    void	dump();
    void	loop();
    void	help();
    void	change_input(std::string &input);
    void	check_input(std::string &av);
  private:
    std::string			*_input;
    ParserState			_state;
    nts::t_ast_node		*_root;
    std::map<std::string, nts::IComponent *>	_map;
    int		checkChar2(std::string const &a) const;
    int		checkChar(std::string const &a) const;
    int		check_chipset(std::string const &word);
    int		check_link(std::string const &word);
    void	check_line(std::string const &line);
    void	check_node(std::string const &node);
    void	chipsetParser(std::string const &word);
    void	linkParser(std::string const &word);
    int		check_init_input(void);
    void	checkInputOutputLink(void);
  };
}
#endif /* !PARSER_HPP */
