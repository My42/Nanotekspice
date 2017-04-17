//
// True.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita@epitech.eu
// Login   <vincy@epitech.net>
// 
// Started on  Thu Mar  2 13:59:18 2017 vincent.mesquita@epitech.eu
// Last update Thu Mar  2 14:05:14 2017 vincent.mesquita@epitech.eu
//

#ifndef TRUE_HPP_
# define TRUE_HPP_

#include "Input.hpp"

namespace nts
{
  class True : public Input
  {
  public:
    True(const std::string &name);
    True(const True &other);
    virtual ~True(void);

    virtual void			setValue(nts::Tristate);
    virtual void			setValue(const std::string &);
  };
};

#endif /* !TRUE_HPP_ */
