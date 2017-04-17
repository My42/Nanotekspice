//
// False.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita@epitech.eu
// Login   <vincy@epitech.net>
// 
// Started on  Thu Mar  2 14:11:56 2017 vincent.mesquita@epitech.eu
// Last update Thu Mar  2 14:15:48 2017 vincent.mesquita@epitech.eu
//

#ifndef FALSE_HPP_
# define FALSE_HPP_

#include "Input.hpp"

namespace nts
{
  class False : public Input
  {
  public:
    False(const std::string &name);
    False(const False &other);
    virtual ~False(void);

    virtual void			setValue(nts::Tristate);
    virtual void			setValue(const std::string &);
  };
};

#endif /* !FALSE_HPP_ */
