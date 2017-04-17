//
// IComponent.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Thu Jan 26 20:54:09 2017 vincent.mesquita
// Last update Wed Mar  1 15:22:01 2017 vincent.mesquita@epitech.eu
//

#ifndef __ICOMPONENT_HPP__
# define __ICOMPONENT_HPP__

#include <iostream>
#include <memory>

namespace nts
{
  enum Tristate
    {
      UNDEFINED = (-true),
      TRUE = true,
      FALSE = false
    };

# define RISING_EDGE	TRUE
# define FALLING_EDGE	FALSE

  enum e_pin_type
    {
      OUTPUT = 0,
      INPUT,
      VSS,
      VDD
    };

  class APin;
  class Input;
  class Output;

  class IComponent
    {
    public:
      /// Compute value of the precised pin
      virtual nts::Tristate Compute(size_t pin_num_this = 1) = 0;
      /// Useful to link IComponent together
      virtual void SetLink(size_t pin_num_this,
			   nts::IComponent &component,
			   size_t pin_num_target) = 0;
      ///// Print on terminal the name of the component and
      //// the state of every pin of the current component
      /// The output won’t be tested, but it may help you
      // as a trace.
      virtual void Dump(void) const = 0;
      virtual ~IComponent(void) { }

      // virtual void		SetInput(size_t, std::shared_ptr<Input>) = 0;
      // virtual void		SetOutput(size_t, std::shared_ptr<Output>) = 0;
      // virtual void		SetAPin(size_t, std::shared_ptr<APin>) = 0;
    };
}
#endif // __ICOMPONENT_HPP__
