//
// Clock.hpp for  in /home/florian/rendu/cpp_nanotekspice
// 
// Made by vincen_s
// Login   <florian@epitech.net>
// 
// Started on  Thu Mar  2 15:40:40 2017 vincen_s
// Last update Fri Mar  3 11:44:02 2017 vincen_s
//

#ifndef CLOCK_HPP_
# define CLOCK_HPP_

#include <functional>
#include "APin.hpp"
#include "Input.hpp"
#include "IComponent.hpp"
#include "LogicalOperators.hpp"

namespace nts
{
  class Clock : public Input
  {
  public:
    Clock(const std::string &name, const std::string &value);
    Clock(const Clock &other);
    virtual ~Clock(void);
    virtual void	Dump(void) const;
    void		Inverse();
  };
};

#endif /* !CLOCK_HPP_ */
