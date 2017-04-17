//
// AComponent.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Fri Feb  3 13:49:22 2017 vincent.mesquita
// Last update Mon Apr 17 17:33:47 2017 vincent.mesquita@epitech.eu
//

#ifndef ACOMPONENT_HPP_
# define ACOMPONENT_HPP_

#include <vector>
#include <map>
#include "IComponent.hpp"
#include "PinException.hpp"

namespace nts
{
  class AComponent : public IComponent
  {
  public:
    AComponent(const std::string &name, const size_t nbr_of_pins);
    AComponent(const nts::AComponent &other);
    virtual ~AComponent(void);

    virtual nts::AComponent			&operator=(const nts::AComponent &);

    virtual Tristate			Compute(size_t pin_num_this = 1) = 0;
    virtual void				SetLink(size_t pin_num_this,
							nts::IComponent &component,
							size_t pin_num_target);
    virtual void				Dump(void) const;

    void					setPinValue(const size_t pin_num_this,
							    nts::Tristate *s);
    nts::e_pin_type				getPinType(const size_t pin_num_this = 1) const;
    nts::Tristate				getPinValue(const size_t pin_num_this = 1) const;
    nts::Tristate				*getPin(const size_t pin_num_this = 1) const;
    const std::string				&getName(void) const;

  protected:
    std::string					_name;
    size_t					_nbr_of_pins;
    std::vector<nts::Tristate*>			_pins;
    std::map<size_t,
	     std::vector<std::pair<size_t, IComponent*>>> _links;
    std::vector<nts::e_pin_type>		_pins_type;
    std::vector<std::pair<size_t, IComponent*>> _last_link;
    std::vector<bool>				_already_did;

    void					_setLink(size_t pin_num_this,
							 IComponent &IComponent,
							 size_t pin_num_target);
    nts::Tristate				_computeAllLinks(size_t pin_num_this);
    void					_checkPin(const size_t pin_num) const;
    void					_freeOutput(void);
    void					_initPins(nts::Tristate state);
  };
};

#endif /* !ACOMPONENT_HPP_ */
