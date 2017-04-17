//
// pin.hpp for cpp_nanotekspice
//
// Made by	Vincent Mesquita
// Login	vincent.mesquita@epitech.eu
//
// Started on	Mon Jan 30 11:28:13 2017 Vincent Mesquita
// Last update	Mon Jan 30 11:28:13 2017 Vincent Mesquita
//

#ifndef APIN_HPP_
# define APIN_HPP_

#include <string>
#include "IComponent.hpp"
#include "AComponent.hpp"

namespace nts
{
  
  class APin : public AComponent
  {
  public:
    APin(const std::string &name, const std::string &value);
    APin(const std::string &name, const nts::Tristate value);
    APin(const APin &);
    virtual			~APin();

    nts::APin			&operator=(const APin &);

    std::string			getName(void) const;
    nts::Tristate		getValue(void) const;
    
    void			setName(const std::string &);
    void			setValue(nts::Tristate);
    void			setValue(const std::string &);
    bool			haveLink(void);

    virtual nts::Tristate	Compute(size_t pin_num_this = 1);
    virtual void		SetLink(size_t pin_num_this,
					nts::IComponent &component,
					size_t pin_num_target) = 0;
    virtual void		Dump(void) const = 0;
  protected:
    nts::Tristate		_value;
  private:
    void			_init(void);
  };
};

#endif // !APIN_HPP_
