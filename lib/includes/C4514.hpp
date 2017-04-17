//
// C4514.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Tue Feb  7 13:23:10 2017 vincent.mesquita
// Last update Fri Mar  3 13:16:00 2017 vincent.mesquita@epitech.eu
//

#ifndef C4514_HPP_
# define C4514_HPP_

# include <vector>
# include <cmath>
# include "AComponent.hpp"

# define C4514_A		2
# define C4514_B		3
# define C4514_C		21
# define C4514_D		22
# define C4514_STROBE		1
# define C4514_INHIBIT		23

namespace nts
{
  class C4514 : public AComponent
  {
  public:
    C4514(const std::string &name);
    C4514(const C4514 &other);
    virtual ~C4514();

    nts::C4514					&operator=(const C4514 &other);

    virtual nts::Tristate			Compute(size_t pin_num_this = 1);
    virtual void				Dump(void) const;
  private:
    std::vector<nts::Tristate *>		_selected_output;
    size_t					_nbr_of_outputs;
    size_t					_nbr_of_inputs;
    std::vector<nts::Tristate *>		_input;
    int						_strobe;

    void					_which_output(void);
    void					_reset(void);
  };
};

#endif /* !C4514_HPP_ */
