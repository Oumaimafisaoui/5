#ifndef ASPELL_HPP
#define ASPELL_HPP
#include <iostream>

#include "ATarget.hpp"

class ATarget;


class ASpell
{
	private:
		std::string name;
		std::string effects;

	public:
		ASpell();
		virtual ~ASpell();
		std::string const &getName() const;
		std::string const &getEffects() const;
		ASpell(const ASpell &obj);
		ASpell &operator=(const ASpell &obj);
		ASpell(std::string const &name, std::string const &effects);
	   	virtual ASpell *clone() const  = 0;
		void launch(ATarget const &obj);

};




#endif
