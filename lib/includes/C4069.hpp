//
// C4069.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib/src/components/ACLO
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Wed Feb  1 14:14:06 2017 vincent.mesquita
// Last update Wed Feb  1 14:14:24 2017 vincent.mesquita
//

#ifndef C4069_HP_
# define C4069_HP_

#include "ACLO.hpp"

namespace nts
{
  class C4069 : public nts::ACLO
  {
  public:
    C4069(const std::string &name);
    C4069(const C4069 &);
    virtual ~C4069(void);

    virtual void				Dump(void) const;
  };
};

#endif /* !C4069_HPP_ */
