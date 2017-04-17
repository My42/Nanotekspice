//
// input.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Mon Jan 30 12:15:09 2017 vincent.mesquita
// Last update Wed Mar  1 14:36:58 2017 vincen_s
//

#ifndef INPUT_HPP_
# define INPUT_HPP_

#include "APin.hpp"
#include "Output.hpp"
#include "IComponent.hpp"
#include "InputException.hpp"

namespace nts
{
  class Input : public APin
  {
  public:
    Input(const std::string &name, const std::string &value);
    Input(const std::string &name, nts::Tristate value);
    Input(const Input &);
    virtual ~Input(void);

    virtual void	SetLink(size_t pin_num_this,
				nts::IComponent &component,
				size_t pin_num_target);
    virtual void	Dump(void) const;
  };
};

#endif /* !INPUT_HPP_ */
