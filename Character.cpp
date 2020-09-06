#include "Character.h"
const int Character::min_stat = 1;
const int Character::max_stat = 25;
const int Character::start_gold = 10;
// Accessors:
std::string Character::Name(void) const{
    return this->name;
}

std::string Character::Race(void) const{
    return this->race;
}

std::string Character::Profession(void) const{
    return this->profession;
}
int Character::Strength(void) const{
    return this->str;
}
int Character::Dexterity(void) const{
    return this->dex;
}
int Character::Constitution(void) const{
    return this->con;
} 
int Character::Intelligence(void) const{
    return this->inl;
}
int Character::Wisdom(void) const{
    return this->wis;
}
int Character::Charisma(void) const{
    return this->cha;
}
int Character::Gold(void) const{
    return this->gold;
}

// Mutators:
void Character::Name(std::string _name){
    this->name = _name;
}
void Character::Race(std::string _race){
    this->race = _race;
}
void Character::Profession(std::string _profession){
    this->profession = _profession;
}


bool Character::Strength(int _str){
    bool flag = false;
    if(_str <= max_stat && _str >= min_stat){
        this->str = _str;
        flag = true;
    }
    return flag;
}