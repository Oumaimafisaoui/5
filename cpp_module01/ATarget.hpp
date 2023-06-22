#ifndef ATarget_hpp
#define ATarget_hpp

#include <iostream>
#include "ASpell.hpp"


class ASpell;


class ATarget {
	private:
		std::string type;

	public:
		ATarget();
		virtual ~ATarget();
		ATarget &operator=(const ATarget &obj);
		ATarget(const ATarget &obj);
		std::string const &getType() const;
		virtual ATarget *clone() const = 0;
	   	void getHitBySpell(const ASpell &obj) const;
		ATarget(std::string const &type);
};



#endif
