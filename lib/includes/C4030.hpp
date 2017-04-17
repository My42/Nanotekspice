//
// C4030.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Wed Feb  1 11:54:20 2017 vincent.mesquita
// Last update Wed Feb  1 11:54:51 2017 vincent.mesquita
//

#ifndef C4030_HP_
# define C4030_HP_

#include "ACLO.hpp"

namespace nts
{
  class C4030 : public nts::ACLO
  {
  public:
    C4030(const std::string &name);
    C4030(const C4030 &);
    virtual ~C4030(void);

    virtual void				Dump(void) const;
  };
};

#endif /* !C4030_HPP_ */
