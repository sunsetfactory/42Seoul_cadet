#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

#define string std::string
#define cout std::cout
#define cin std::cin
#define endl std::endl

class ClapTrap
{
  private:
    string _Name;
    unsigned int _Hit_point;      // 체력
    unsigned int _Max_hit_point;  // 최대 체력
    unsigned int _Energy_point;   // 에너지
    unsigned int _Attack_damage;  // 공격력

  public:
    ClapTrap();
    ClapTrap(string Name);
    ClapTrap(const ClapTrap &claptrap);  // 복사 생성자
    ClapTrap &operator=(const ClapTrap &claptrap);// 대입 연산자
    ~ClapTrap();

    void attack(const string &target);    // 공격
    void takeDamage(unsigned int amount); // 데미지 입기
    void beRepaired(unsigned int amount); // 수리
  
    string get_Name() const;              // 이름 반환
    unsigned int get_Damage(void) const;  // 공격력 반환
};

#endif