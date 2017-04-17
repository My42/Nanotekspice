//
// ACLO.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib/src/components/ACLO
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Wed Feb  1 10:47:04 2017 vincent.mesquita
// Last update Mon Feb  6 18:43:26 2017 vincent.mesquita
//

#ifndef ACLO_H_
# define ACLO_H_

#include <map>
#include <vector>
#include <functional>
#include <string>
#include <memory>
#include "IComponent.hpp"
#include "AComponent.hpp"
#include "APin.hpp"
#include "Input.hpp"
#include "Output.hpp"

namespace nts
{
  class ACLO : public nts::AComponent
  {
  public:
    ACLO(const std::string &name);
    ACLO(const ACLO &other);
    virtual ~ACLO(void);

    virtual ACLO				&operator=(const ACLO &);
    virtual nts::Tristate			Compute(size_t = 1);
    virtual void				Dump(void) const = 0;

  protected:
    std::map<size_t, std::pair<size_t, size_t>>	_compute_links;
    std::function<nts::Tristate(nts::Tristate,
				nts::Tristate)>	_lo;

    
    nts::Tristate				_operator(size_t pinA, size_t pinB);
  };
};

#endif /* !ACLO_H_ */
