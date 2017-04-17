//
// C4040.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Mon Feb  6 13:41:34 2017 vincent.mesquita
// Last update Wed Mar  1 16:14:46 2017 vincent.mesquita@epitech.eu
//

#ifndef C4040_HPP_
# define C4040_HPP_

#include <string>
#include "AComponent.hpp"

namespace nts
{
  class C4040 : public AComponent
  {
  public:
    C4040(const std::string &name);
    C4040(const C4040 &other);
    virtual ~C4040(void);

    nts::C4040					&operator=(const C4040 &other);

    virtual nts::Tristate			Compute(size_t pin_num_this = 1);
    virtual void				Dump(void) const;

  private:
    std::vector<nts::Tristate*>			_number;
    size_t					_nbr_of_bits;
    nts::Tristate				_last_clock_state;
    bool					_already_calculated;
    int						_clock_index;
    int						_reset_index;
    
    void					_reset(size_t begin = 0);
    void					_calculate(void);
  };
};

#endif /* !C4040_HPP_ */
