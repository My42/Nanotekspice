//
// parser.cpp for  in /home/kyx/rendu/cpp_nanotekspice/lib
// 
// Made by Florian Vincent
// Login   <kyx@epitech.net>
// 
// Started on  Sat Feb 18 10:14:28 2017 Florian Vincent
// Last update Mon Apr 17 17:48:50 2017 vincent.mesquita@epitech.eu
//

#include "parser.hpp"

nts::Parser::Parser() : _input(new std::string("")), _state(ParserState::NONE),
			_root(new t_ast_node(NULL))
{
  // "4094");
  // "4801"); ---> Not yet
  // "2716");
}

nts::Parser::~Parser()
{
  delete _input;
  for (auto i : _map)
    delete i.second;
  if (PARSER_VECTOR)
    {
      for (auto i : *PARSER_VECTOR)
	{
	  for (auto y : *i->children)
	    {
	      delete y->children;
	      delete y;
	    }
	  delete i->children;
	  delete i;
	}
      delete PARSER_VECTOR;
    }
  delete _root;
}

void			nts::Parser::check_input(std::string &av)
{
  nts::t_ast_node	*input = NULL;
  std::string		name = av.substr(0, av.find_first_of('='));
  std::string		value = av.substr(av.find_first_of('=') + 1);

  if (name.compare(av) == 0 || name.size() == av.size())
    throw nts::exception::ParserException("Syntax error in input declaration : " + name);
  for (auto i : *CHIPSET_VECTOR)
    if (name.compare(COMPONENT_NAME) == 0)
      {
	if (COMPONENT_TYPE.compare("input") == 0)
	  {
	    input = i;
	    if ((input->value = value).compare("1") && input->value.compare("0"))
	      throw nts::exception::ParserException("Invalid value " + value +
						    " in Input declaration : " + name);
	    break ;
	  }
	else if (COMPONENT_TYPE.compare("clock") == 0)
	  {
	    input = i;
	    if (value.compare("1") == 0)
	      input->value = "0";
	    else if (value.compare("0") == 0)
	      input->value = "1";
	    else
	      throw nts::exception::ParserException("Invalid value " + value +
						    " in Clock declaration : " + name);
	    break ;
	  }
	else
	  throw nts::exception::ParserException(COMPONENT_NAME + " is not input");
      }
  if (input == NULL)
    throw nts::exception::ParserException(name + " is undeclared");
}

void		nts::Parser::change_input(std::string &input)
{
  std::string		name = input.substr(0, input.find_first_of('='));
  std::string		value = input.substr(input.find_first_of('=') + 1);
  Input			*a;

  if (name.compare(input) == 0 || name.size() == input.size())
    std::cerr << "Syntax Error use .help" << std::endl;
  else if (_map[name] == NULL)
    std::cerr << "Component " + name + " is undeclared" << std::endl;
  else if ((a = dynamic_cast<Input *>(_map[name])) == NULL || dynamic_cast<Clock *>(_map[name]) != NULL)
    std::cerr << "You can only change input value's" << std::endl;
  else if (value.compare("1") && value.compare("0"))
    std::cerr << "Input take only 0 or 1" << std::endl;
  else 
    a->setValue(value);
}

int		nts::Parser::checkChar2(std::string const &a) const
{
  unsigned int		i = -1;

  while (a[++i] && i < a.size())
    if (a[i] == ':')
      return (1);
  return (0);
}

void		nts::Parser::chipsetParser(std::string const &word)
{
  if (this->_state == ParserState::CHIPSET)
    {
      t_ast_node	*new_component = (new t_ast_node(new std::vector<t_ast_node*>));
      new_component->lexeme = word;
      new_component->type = nts::ASTNodeType::COMPONENT;
      CHIPSET_VECTOR->push_back(new_component);
      this->_state = ParserState::CHIPSET_WAITNAME;
    }
  else if (this->_state == ParserState::CHIPSET_WAITNAME)
    {
      if (checkChar2(word))
	throw nts::exception::ParserException("Invalid character in " + word);
      for(auto i : *CHIPSET_VECTOR)
	if (word.compare(COMPONENT_NAME) == 0 && i->lexeme.size() != word.size())
	  throw nts::exception::ParserException("Redefinition of " + word);
      CHIPSET_VECTOR->back()->lexeme.append(" " + word);
      this->_state = ParserState::CHIPSET;
    }
}

void		nts::Parser::check_node(std::string const &compo)
{
  std::string str = compo.substr(0, compo.find_first_of(':'));

  if (str.compare(compo) == 0)
    throw nts::exception::ParserException(compo + " Invalid Link syntax");
  for (auto i : *CHIPSET_VECTOR)
    if (str.compare(COMPONENT_NAME) == 0)
      return ;
  throw nts::exception::ParserException(compo + " is undeclared");
}

void		nts::Parser::linkParser(std::string const &word)
{
  if (this->_state == ParserState::LINKS)
    {
      check_node(word);
      t_ast_node	*new_link = (new t_ast_node(new std::vector<t_ast_node*>));
      new_link->lexeme = word;
      new_link->type = nts::ASTNodeType::LINK;
      new_link->value = word.substr(0, word.find_first_of(':'));
      LINK_VECTOR->push_back(new_link);
      this->_state = ParserState::LINKS_WAITLINKS;
    }
  else if (this->_state == ParserState::LINKS_WAITLINKS)
    {
      check_node(word);
      t_ast_node	*new_link = (new t_ast_node(new std::vector<t_ast_node*>));
      new_link->lexeme = word;
      new_link->type = nts::ASTNodeType::LINK_END;
      new_link->value = word.substr(0, word.find_first_of(':'));
      LINK_VECTOR->push_back(new_link);
      this->_state = ParserState::LINKS;
    }
}

int		nts::Parser::check_chipset(std::string const &word)
{
  if (word.compare(".chipsets:") == 0)
    {
      if (this->_state == ParserState::CHIPSET_WAITNAME)
	throw nts::exception::ParserException("Invalid name : " + word);
      if (this->_state == ParserState::NONE)
	{
	  t_ast_node	*new_chipset = (new t_ast_node(new std::vector<t_ast_node*>));
	  this->_state = ParserState::CHIPSET;
	  new_chipset->lexeme = word;
	  new_chipset->type = nts::ASTNodeType::SECTION;
	  new_chipset->value = "";
	  PARSER_VECTOR->push_back(new_chipset);
	  return (1);
	}
      else
	throw nts::exception::ParserException("Invalid redefinition of .chipsets");
    }
  return (0);
}

int		nts::Parser::check_link(std::string const &word)
{
  if (word.compare(".links:") == 0)
    {
      if (this->_state == ParserState::CHIPSET)
	{
	  t_ast_node	*new_link = (new t_ast_node(new std::vector<t_ast_node*>));
	  this->_state = ParserState::LINKS;
	  new_link->lexeme = word;
	  new_link->type = nts::ASTNodeType::SECTION;
	  new_link->value = "";
	  PARSER_VECTOR->push_back(new_link);
	  return (1);
	}
      else
	throw nts::exception::ParserException("Invalid declaration of .links");
    }
  return (0);
}

int		nts::Parser::checkChar(std::string const &a) const
{
  unsigned int		i = -1;

  while (a[++i] && i < a.size())
    if (!((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z') ||
	  (a[i] >= '0' && a[i] <= '9') || a[i] == '.' || a[i] == ':' || a[i] == '_' ||
	  a[i] == '-'))
      return (1);
  return (0);
}

void		nts::Parser::check_line(std::string const &line)
{
  std::stringstream	stream;
  std::string		word;

  if (line[0] == '#')
    return ;
  stream.str(line);
  while (stream >> word)
    {
      if (word[0] == '#')
	break ;
      if (!(check_chipset(word) || check_link(word)))
	{
	  if (checkChar(word))
	    throw nts::exception::ParserException("Invalid character in " + word);
	  chipsetParser(word);
	  linkParser(word);
	}
    }
}

int		nts::Parser::check_init_input(void)
{
  for (auto i : *CHIPSET_VECTOR)
    if ((COMPONENT_TYPE.compare("input") == 0 || COMPONENT_TYPE.compare("clock") == 0)
	&& COMPONENT_VALUE == "")
      throw nts::exception::ParserException(COMPONENT_NAME + " is unitialised");
  return (1);
}

void		nts::Parser::checkInputOutputLink(void)
{
  Input		*a;
  Output	*b;

  for (auto j : _map)
    if ((a = (dynamic_cast<Input *>(j.second))) != NULL && a->haveLink())
      throw nts::exception::ParserException("Input " + j.first + " don't have any links");
  for (auto j : _map)
    if ((b = (dynamic_cast<Output *>(j.second))) != NULL && b->haveLink())
      throw nts::exception::ParserException("Output " + j.first + " don't have any links");
}

void		nts::Parser::parseTree(t_ast_node& rot)
{
  nts::ComponentManager				man;

  (void)rot;
  check_init_input();
  for (auto i : *CHIPSET_VECTOR)
    _map[COMPONENT_NAME.c_str()] = man.createComponent(COMPONENT_TYPE, COMPONENT_VALUE);
  nts::t_ast_node *i = LINK_VECTOR->front();
  for (auto j : *LINK_VECTOR)
    {
      if (j->type == nts::ASTNodeType::LINK_END)
	{
	  _map[LINK_NAME.c_str()]->SetLink(std::atoi(PIN_TO_LINK.c_str()), *_map[LINK_NAME_END],
					   std::atoi(PIN_TO_LINK_END.c_str()));
	  j++;
	}
      i = j;
    }
  checkInputOutputLink();
  return ;
}

void		nts::Parser::feed(std::string const& input)
{
  this->_input->append(" " + input);
}

nts::t_ast_node	*nts::Parser::createTree()
{
  std::string		line;
  std::istringstream	iss(this->_input->c_str());
  std::vector<t_ast_node*>	*children(new std::vector<t_ast_node*>);

  PARSER_VECTOR = children;
  while (std::getline(iss, line))
    check_line(line);
  if (this->_root->children->size() != 2 || LINK_VECTOR->size() == 0 || CHIPSET_VECTOR->size() == 0)
    throw nts::exception::ParserException(".chipsets or .links section missing");
  return (this->_root);
}

void		nts::Parser::loop()
{
  while (168)
    this->simulate();
}

void		nts::Parser::help()
{
  std::cout << "The function are: \n>" << " display          It prints on stdout the value of all outputs sorted by name.\n> simulate         It launches a simulation.\n> loop             Simulate without prompting again until SIGINT. \n> dump             Call the Dump method of every IComponent\n> input=value      It changes the value of an input.\n> exit             It closes the program." << std::endl;
}

void		nts::Parser::simulate()
{
  Clock		*a;

  for (auto j : _map)
    if ((a = dynamic_cast<Clock *>(j.second)) != NULL)
      a->Inverse();
  for (auto j : _map)
    if ((dynamic_cast<Output *>(j.second)) != NULL)
      j.second->Compute();
}

void		nts::Parser::display()
{
  Output	*a;

  for (auto j : _map)
    {
      if ((a = dynamic_cast<Output *>(j.second)) != NULL)
	{
	  std::cout << j.first << "=";
	  if (a->getValue() != UNDEFINED)
	    std::cout << a->getValue() << std::endl;
	  else
	    std::cout << "U" << std::endl;
	}
    }
}

void		nts::Parser::dump()
{
  for (auto j : _map)
    j.second->Dump();
}
