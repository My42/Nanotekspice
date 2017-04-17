//
// C4008.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Wed Feb  8 11:04:06 2017 vincent.mesquita
// Last update Tue Feb 28 13:42:06 2017 vincent.mesquita@epitech.eu
//

#ifndef C4008_HPP_
# define C4008_HPP_

#include <string>
#include <map>
#include "AComponent.hpp"


namespace nts
{
  class C4008 : public AComponent
  {
  public:
    C4008(const std::string &name);
    C4008(const nts::C4008 &other);
    virtual ~C4008(void);

    nts::C4008					&operator=(const nts::C4008 &other);

    virtual nts::Tristate			Compute(size_t pin_num_this = 1);
    virtual void				Dump(void) const;
  private:
    size_t					_nbr_of_carries;
    size_t					_c1_pin;
    size_t					_co_pin;
    std::map<size_t, std::pair<size_t, size_t>> _compute_links;
    std::vector<nts::Tristate>			_carries;
    std::map<size_t, size_t>			_carry_links;

    void					_calculate(size_t pin_num_this);
  };
};

#endif /* !C4008_HPP_ */
