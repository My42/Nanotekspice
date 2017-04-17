//
// C4011.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
// 
// Made by vincent.mesquita
// Login   <vincy@epitech.net>
// 
// Started on  Wed Feb  1 11:42:02 2017 vincent.mesquita
// Last update Wed Feb  1 11:46:47 2017 vincent.mesquita
//

#ifndef C4011_HPP_
# define C4011_HPP_


#include "ACLO.hpp"

namespace nts
{
  class C4011 : public nts::ACLO
  {
  public:
    C4011(const std::string &name);
    C4011(const C4011 &);
    virtual ~C4011(void);

    virtual void				Dump(void) const;
  };
};


#endif /* !C4011_HPP_ */
