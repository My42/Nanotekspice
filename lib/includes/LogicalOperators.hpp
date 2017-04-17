//
// LogicalOperators.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib/src/components/ACLO
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Wed Feb  1 14:04:26 2017 vincent.mesquita
// Last update Wed Feb  1 14:04:26 2017 vincent.mesquita
//

#ifndef LOGICALOPERATORS_HPP_
# define LOGICALOPERATORS_HPP_

#include "IComponent.hpp"

namespace nts
{
  class LogicalOperators
  {
  public:
    LogicalOperators(void) {};
    ~LogicalOperators(void) {};
    static nts::Tristate		AND(nts::Tristate a, nts::Tristate b);
    static nts::Tristate		NAND(nts::Tristate a, nts::Tristate b);
    static nts::Tristate		OR(nts::Tristate a, nts::Tristate b);
    static nts::Tristate		NOR(nts::Tristate a, nts::Tristate b);
    static nts::Tristate		XOR(nts::Tristate a, nts::Tristate b);
    static nts::Tristate		XNOR(nts::Tristate a, nts::Tristate b);
    static nts::Tristate		NOT(nts::Tristate a, nts::Tristate b = UNDEFINED);
  };
};
#endif /* !LOGICALOPERATORS_HPP_ */
