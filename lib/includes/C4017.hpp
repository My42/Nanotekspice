//
// C4017.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita@epitech.eu
// Login   <vincy@epitech.net>
// 
// Started on  Tue Feb 28 12:30:23 2017 vincent.mesquita@epitech.eu
// Last update Sun Mar  5 16:56:40 2017 vincent.mesquita@epitech.eu
//

#ifndef C4017_HPP_
# define C4017_HPP_

#include <string>
#include "AComponent.hpp"

# define C4017_Q0	3
# define C4017_Q1	2
# define C4017_Q2	4
# define C4017_Q3	7
# define C4017_Q4	10
# define C4017_Q5	1
# define C4017_Q6	5
# define C4017_Q7	6
# define C4017_Q8	9
# define C4017_Q9	11
# define C4017_Q59	12
# define C4017_CP1	13
# define C4017_CP0	14
# define C4017_MR	15

namespace nts
{
  class C4017 : public AComponent
  {
  public:
    C4017(const std::string &name);
    C4017(const nts::C4017 &other);
    virtual ~C4017(void);

    nts::C4017			&operator=(const nts::C4017 &other);

    virtual nts::Tristate			Compute(size_t pin_num_this = 1);
    virtual void				Dump(void) const;

  private:
    std::vector<nts::Tristate*>		_outputs;
    size_t				_current;
    nts::Tristate			_last_clock_state;
  };
};

#endif /* !C4017_HPP_ */
