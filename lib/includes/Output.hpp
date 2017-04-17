//
// Output.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Mon Jan 30 12:29:31 2017 vincent.mesquita
// Last update Thu Mar  2 14:52:16 2017 vincent.mesquita@epitech.eu
//

#ifndef OUTPUT_HPP_
# define OUTPUT_HPP_

#include <functional>
#include "OutputException.hpp"
#include "APin.hpp"
#include "Input.hpp"
#include "IComponent.hpp"
#include "LogicalOperators.hpp"

namespace nts
{
  class Output : public APin
  {
  public:
    Output(const std::string &name);
    Output(const std::string &name, const std::string &value);
    Output(const std::string &name, const nts::Tristate &value);
    Output(const Output &other);
    virtual ~Output(void);
    
    virtual void	SetLink(size_t pin_num_this,
				nts::IComponent &component,
				size_t pin_num_target);
    virtual nts::Tristate Compute(size_t pin_num_this = 1);
    virtual void	Dump(void) const;
  };
};

#endif /* !OUTPUT_HPP_ */
