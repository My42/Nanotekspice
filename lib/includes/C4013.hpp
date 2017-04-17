//
// C4013.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Fri Feb 10 11:57:12 2017 vincent.mesquita
// Last update Fri Feb 10 16:52:25 2017 vincent.mesquita
//

#ifndef C4013_HPP_
# define C4013_HPP_

#include <string>
#include <functional>
#include "AComponent.hpp"
#include "LogicalOperators.hpp"

namespace nts
{
  class C4013 : public AComponent
  {
  public:
    C4013(const std::string &name);
    C4013(const nts::C4013 &other);
    virtual ~C4013(void);

    nts::C4013					&operator=(const nts::C4013 &other);
    
    virtual nts::Tristate			Compute(size_t pin_num_this = 1);
    virtual void				Dump(void) const;

  private:
    std::map<size_t, std::vector<size_t>>	_compute_links;
    std::map<size_t, size_t>			_Q_links;
    int						_clock_index;
    int						_reset_index;
    int						_data_index;
    int						_set_index;

    void					_computeInputs(size_t pin_num_this);
    void					_calculate(size_t pin_num_this);
    void					_truth_table1(size_t pin_num_this);
    void					_truth_table2(size_t pin_num_this);
    void					_truth_table3(size_t pin_num_this);
    void					_truth_table4(size_t pin_num_this);
    std::map<std::pair<nts::Tristate, nts::Tristate>,
	     std::function<void(size_t)>>	_fptr_tab;
  };
}
#endif /* !C4013_HPP_ */
