#include "Warlock.hpp"


void Warlock::setTitle(const std::string &title)
{
	this->title = title;
}

const std::string &Warlock::getName() const
{
	return this->name;
}

const std::string &Warlock::getTitle() const
{
	return this->title;
}

Warlock::Warlock(const std::string &name, const std::string &title)
{
	this->name = name;
	this->title = title;
	std::cout << getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << getName() << ": My job here is done!" << std::endl;
	std::map<std::string, ASpell*>::iterator i = this->array.begin();
	std::map<std::string, ASpell*>::iterator j = this->array.end();
	while(i != j)
	{
		delete i->second;
		++i;
	}
	this->array.clear();

}

Warlock::Warlock(){}

Warlock::Warlock(const Warlock &obj)
{
	*this = obj;
}


const Warlock& Warlock::operator=(const Warlock &obj)
{
	this->name = obj.name;
	this->title = obj.title;
	return (*this);
}

void Warlock::introduce() const
{
	std::cout << getName() << ": I am " << getName() << ", " << getTitle() << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	if(spell)
		array.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}
void Warlock::forgetSpell(std::string spell)
{
	std::map<std::string, ASpell*>::iterator i = array.find(spell);
	if(i != array.end())
		delete (i->second);
	array.erase(spell);
}

void Warlock::launchSpell(std::string spell, ATarget const  &target)
{
	ASpell *spelly = array[spell];
	if(spelly)
		spelly->launch(target);
}