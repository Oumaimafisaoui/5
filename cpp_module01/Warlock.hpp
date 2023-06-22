#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"

#include <map>

class Warlock
{
	private:
		std::string name;
		std::string title;
		std::map<std::string, ASpell *> array;
		Warlock(const Warlock &obj);
		Warlock();
		const Warlock &operator=(const Warlock& obj);
	public:
		~Warlock();
		const std::string &getName() const; 
		const std::string &getTitle() const;
		void setTitle(const std::string &title);	
		Warlock(const std::string &name,const std::string &title);
		void introduce() const;
		void learnSpell(ASpell *spell);
		void forgetSpell(std::string spell);
		void launchSpell(std::string spell, ATarget const  &target);
};


#endif
