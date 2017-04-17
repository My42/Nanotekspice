//
// ComponentManager.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Mon Feb  6 22:13:56 2017 vincent.mesquita
// Last update Sun Mar  5 16:35:39 2017 vincent.mesquita@epitech.eu
//

#include "ComponentManager.hpp"
#include "ComponentManagerException.hpp"

nts::ComponentManager::ComponentManager(void)
{
  _component_name = "unnamed";

  _components = {
    {"4001", [&](auto e) -> IComponent* { return(this->create4001(e)); }},
    {"4008", [&](auto e) -> IComponent* { return(this->create4008(e)); }},
    {"4011", [&](auto e) -> IComponent* { return(this->create4011(e)); }},
    {"4013", [&](auto e) -> IComponent* { return(this->create4013(e)); }},
    {"4017", [&](auto e) -> IComponent* { return(this->create4017(e)); }},
    {"4030", [&](auto e) -> IComponent* { return(this->create4030(e)); }},
    {"4040", [&](auto e) -> IComponent* { return(this->create4040(e)); }},
    {"4069", [&](auto e) -> IComponent* { return(this->create4069(e)); }},
    {"4071", [&](auto e) -> IComponent* { return(this->create4071(e)); }},
    {"4081", [&](auto e) -> IComponent* { return(this->create4081(e)); }},
    {"4514", [&](auto e) -> IComponent* { return(this->create4514(e)); }},
    {"input", [&](auto e) -> IComponent* { return(this->createInput(e)); }},
    {"output", [&](auto e) -> IComponent* { return(this->createOutput(e)); }},
    {"true", [&](auto e) -> IComponent* { return(this->createTrue(e)); }},
    {"false", [&](auto e) -> IComponent* { return(this->createFalse(e)); }},
    {"clock", [&](auto e) -> IComponent* { return(this->createClock(e)); }},
  };
}

nts::ComponentManager::ComponentManager(const nts::ComponentManager &other)
  : _components(other._components) { }

nts::ComponentManager::~ComponentManager(void) { }

nts::ComponentManager	&nts::ComponentManager::operator=(const nts::ComponentManager &other)
{
  if (this != &other)
    this->_components = other._components;
  return (*this);
}

nts::IComponent		*nts::ComponentManager::createComponent(const std::string &type,
								const std::string &value)
{
  try {
    return ((this->_components[type])(value));
  } catch (const std::exception &e) {
    throw nts::exception::ComponentNotFoundException(type);
    return (NULL);
  }
}

nts::IComponent		*nts::ComponentManager::createClock(const std::string &value) const
{
  return (new Clock(this->_component_name, value));
}

nts::IComponent		*nts::ComponentManager::createTrue(const std::string &) const
{
  return (new True(this->_component_name));
}

nts::IComponent		*nts::ComponentManager::createFalse(const std::string &) const
{
  return (new False(this->_component_name));
}

nts::IComponent		*nts::ComponentManager::createOutput(const std::string &) const
{
  return (new Output(this->_component_name));
}

nts::IComponent		*nts::ComponentManager::createInput(const std::string &value) const
{
  return (new Input(this->_component_name, value));
}

nts::IComponent		*nts::ComponentManager::create4001(const std::string &) const
{
  return (new C4001(this->_component_name));
}

nts::IComponent		*nts::ComponentManager::create4008(const std::string &) const
{
  return (new C4008(this->_component_name));
}

nts::IComponent		*nts::ComponentManager::create4011(const std::string &) const
{
  return (new C4011(this->_component_name));
}

nts::IComponent		*nts::ComponentManager::create4013(const std::string &) const
{
  return (new C4013(this->_component_name));
}

nts::IComponent		*nts::ComponentManager::create4017(const std::string &) const
{
  return (new C4017(this->_component_name));
}

nts::IComponent		*nts::ComponentManager::create4030(const std::string &) const
{
  return (new C4030(this->_component_name));
}

nts::IComponent		*nts::ComponentManager::create4040(const std::string &) const
{
  return (new C4040(this->_component_name));
}

nts::IComponent		*nts::ComponentManager::create4069(const std::string &) const
{
  return (new C4069(this->_component_name));
}

nts::IComponent		*nts::ComponentManager::create4071(const std::string &) const
{
  return (new C4071(this->_component_name));
}

nts::IComponent		*nts::ComponentManager::create4081(const std::string &) const
{
  return (new C4081(this->_component_name));
}

nts::IComponent		*nts::ComponentManager::create4514(const std::string &) const
{
  return (new C4514(this->_component_name));
}
