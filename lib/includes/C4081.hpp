//
// C4081.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Wed Feb  1 13:27:12 2017 vincent.mesquita
// Last update Wed Feb  1 13:27:27 2017 vincent.mesquita
//

#ifndef C4081_HP_
# define C4081_HP_

#include "ACLO.hpp"

namespace nts
{
  class C4081 : public nts::ACLO
  {
  public:
    C4081(const std::string &name);
    C4081(const C4081 &);
    virtual ~C4081(void);

    virtual void				Dump(void) const;
  };
};

#endif /* !C4081_HPP_ */
