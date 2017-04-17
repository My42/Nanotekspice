//
// ComponentManager.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Mon Feb  6 22:15:05 2017 vincent.mesquita
// Last update Sun Mar  5 16:35:15 2017 vincent.mesquita@epitech.eu
//

#ifndef COMPONENTMANAGER_HPP_
# define COMPONENTMANAGER_HPP_

# include <map>
# include <string>
# include "IComponent.hpp"
# include "C4001.hpp"
# include "C4008.hpp"
# include "C4011.hpp"
# include "C4013.hpp"
# include "C4017.hpp"
# include "C4030.hpp"
# include "C4040.hpp"
# include "C4069.hpp"
# include "C4071.hpp"
# include "C4081.hpp"
# include "C4514.hpp"
# include "True.hpp"
# include "False.hpp"
# include "Clock.hpp"

namespace nts
{
  class ComponentManager
  {
  public:
    ComponentManager(void);
    ComponentManager(const ComponentManager &other);
    ~ComponentManager(void);

    ComponentManager			&operator=(const ComponentManager &other);
    IComponent				*createComponent(const std::string &type,
							 const std::string &value = "");
  private:
    std::map<std::string,
    	     std::function<nts::IComponent*(const std::string&)>> _components;
    std::string				_component_name;

    nts::IComponent			*create4001(const std::string &value) const;
    nts::IComponent			*create4008(const std::string &value) const;
    nts::IComponent			*create4011(const std::string &value) const;
    nts::IComponent			*create4013(const std::string &value) const;
    nts::IComponent			*create4017(const std::string &value) const;
    nts::IComponent			*create4030(const std::string &value) const;
    nts::IComponent			*create4040(const std::string &value) const;
    nts::IComponent			*create4069(const std::string &value) const;
    nts::IComponent			*create4071(const std::string &value) const;
    nts::IComponent			*create4081(const std::string &value) const;
    nts::IComponent			*create4514(const std::string &value) const;
    nts::IComponent			*createOutput(const std::string &value) const;
    nts::IComponent			*createInput(const std::string &value) const;
    nts::IComponent			*createTrue(const std::string &) const;
    nts::IComponent			*createFalse(const std::string &) const;
    nts::IComponent			*createClock(const std::string &) const;
  };
}

#endif /* !COMPONENTMANAGER_HPP_ */
