//
// LogicalOperators.cpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Mon Jan 30 17:30:53 2017 vincent.mesquita
// Last update Thu Mar  2 20:35:58 2017 vincent.mesquita@epitech.eu
//

#include "LogicalOperators.hpp"

nts::Tristate		nts::LogicalOperators::AND(nts::Tristate a,
						   nts::Tristate b)
{
  if (a == UNDEFINED || b == UNDEFINED)
    return (nts::UNDEFINED);
  else
    return ((nts::Tristate)(a && b));
}

nts::Tristate		nts::LogicalOperators::NAND(nts::Tristate a,
						    nts::Tristate b)
{
  nts::Tristate state;

  state = nts::LogicalOperators::AND(a, b);
  return (((state == UNDEFINED) ? (UNDEFINED) : ((nts::Tristate)!state)));
}

nts::Tristate		nts::LogicalOperators::OR(nts::Tristate a,
						  nts::Tristate b)
{
  if (a == TRUE)
    return (a);
  else if (a == UNDEFINED || b == UNDEFINED)
    return (nts::UNDEFINED);
  else
    return ((nts::Tristate)(a || b));
}

nts::Tristate		nts::LogicalOperators::NOR(nts::Tristate a,
						   nts::Tristate b)
{
  nts::Tristate state;

  state = nts::LogicalOperators::OR(a, b);
  return (((state == UNDEFINED) ? (UNDEFINED) : ((nts::Tristate)!state)));
}

nts::Tristate		nts::LogicalOperators::XOR(nts::Tristate a,
						   nts::Tristate b)
{
  if (a == UNDEFINED || b == UNDEFINED)
    return (nts::UNDEFINED);
  else
    return ((nts::Tristate)(a ^ b));
}

nts::Tristate		nts::LogicalOperators::XNOR(nts::Tristate a,
						    nts::Tristate b)
{
  nts::Tristate state;

  state = nts::LogicalOperators::XOR(a, b);
  return (((state == UNDEFINED) ? (UNDEFINED) : ((nts::Tristate)!state)));
}

nts::Tristate		nts::LogicalOperators::NOT(nts::Tristate a,
						   nts::Tristate)
{
  if (a == UNDEFINED)
    return (nts::UNDEFINED);
  else
    return ((nts::Tristate)!a);
}
