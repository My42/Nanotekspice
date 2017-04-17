//
// ComponentManagerException.hpp for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
// 
// Made by vincent.mesquita@epitech.eu
// Login   <vincy@epitech.net>
// 
// Started on  Thu Mar  2 15:30:34 2017 vincent.mesquita@epitech.eu
// Last update Mon Apr 17 17:43:35 2017 vincent.mesquita@epitech.eu
//

#ifndef COMPONENTMANAGEREXCEPTION_HPP_
# define COMPONENTMANAGEREXCEPTION_HPP_

#include <exception>
#include <string>

namespace nts
{
  namespace exception
  {
    class ComponentNotFoundException : public std::exception
    {
    public:
      ComponentNotFoundException(const std::string &name) throw();
      virtual ~ComponentNotFoundException() throw();
      virtual const char		*what(void) const throw();

    private:
      std::string		_msg;
    };
  }
}


#endif /* !COMPONENTMANAGEREXCEPTION_HPP_ */
