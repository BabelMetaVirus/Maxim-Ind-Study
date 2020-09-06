#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <string>

class Character{
    // Character Class Specification:
    private: 
    // Constants:
    static const int min_stat;
    static const int max_stat;
    static const int start_gold;
    // Data Members:
    std::string name;          // Name as string  
    std::string race;          // Race as string
    std::string profession;    // Profession as string
    int str;    // Strength (str)
    int dex;    // Dexterity (dex)
    int con;    // Constitution (con)
    int inl;    // Intelligence (inl)
    int wis;    // Wisdom (wis)
    int cha;    // Charisma (cha)
    int gold;    // Gold (Starts at 10, integer)
    protected:
    public:
    // Accesors:
    std::string Name(void) const;
    std::string Race(void) const;
    std::string Profession(void) const;
    int Strength(void) const;
    int Dexterity(void) const;
    int Constitution(void) const;
    int Intelligence(void) const;
    int Wisdom(void) const;
    int Charisma(void) const;
    int Gold(void) const;
    // Mutators:
    void Name(std::string);
    void Race(std::string);
    void Profession(std::string);
    bool Strength(int);
};
#endif