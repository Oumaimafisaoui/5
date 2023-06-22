#include "Fwoosh.hpp"


Fwoosh::Fwoosh() : ASpell("fwoosh", "fwooshed")
{

}
Fwoosh::~Fwoosh() {}

Fwoosh *Fwoosh::clone() const
{
    return (new Fwoosh());
}