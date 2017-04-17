//
// C4071.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Wed Feb  1 13:19:19 2017 vincent.mesquita
// Last update Wed Feb  1 13:19:43 2017 vincent.mesquita
//

#ifndef C4071_HP_
# define C4071_HP_

#include "ACLO.hpp"

namespace nts
{
  class C4071 : public nts::ACLO
  {
  public:
    C4071(const std::string &name);
    C4071(const C4071 &);
    virtual ~C4071(void);

    virtual void				Dump(void) const;
  };
};

#endif /* !C4071_HPP_ */
