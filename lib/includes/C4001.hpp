//
// C4001.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Wed Feb  1 11:42:56 2017 vincent.mesquita
// Last update Wed Feb  1 11:43:01 2017 vincent.mesquita
//

#ifndef C4001_HP_
# define C4001_HP_

#include "ACLO.hpp"

namespace nts
{
  class C4001 : public nts::ACLO
  {
  public:
    C4001(const std::string &name);
    C4001(const C4001 &);
    virtual ~C4001(void);

    virtual void				Dump(void) const;
  };
};

#endif /* !C4001_HPP_ */
