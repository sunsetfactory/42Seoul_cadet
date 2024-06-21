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
  

    // 가장 중요하다 생각하는 서브젝트 명시 사항
  
    // In all of these member functions, you have to print a message to describe what happens.
    // - 모든 멤버 함수들은 모두 무슨 일이 일어났는지 설명하는 메시지를 출력해야 한다.
    // For example, the attack() function may display something like (of course, without the angle brackets):
    // - 예를 들어, attack() 함수는 다음과 같은 내용을 표시할 수 있다(물론, 꺽쇠 괄호 없이):
    // - ClapTrap <name> attacks <target>, causing <damage> points of damage! -

    // When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
    // - ClapTrap이 공격할 때, 공격 대상은 <공격력>의 체력을 잃게 된다.
    // When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing cost 1 energy point each.
    // - ClapTrap이 자신을 수리할 때, <수리량>의 체력을 회복한다. 공격과 수리는 각각 1 에너지 포인트가 소모된다.
    // Of course, ClapTrap can’t do anything if it has no hit points or energy points left.
    // - 물론, ClapTrap은 체력이나 에너지 포인트가 남아 있지 않은 경우 아무것도 할 수 없다.

    // hit points or energy points가 0이면 아무것도 할 수 없다는 점 잊지말고 구현할 것.
    // 그외 상세 구현은 코드 참고

    // 03 평가에서 중요한 요소 ( 아래 내용은 서브젝트를 설명하면서 미리 설명을 하고 평가지를 보면 좋음 )
    // 1. 상속, 오버라이딩
    // - 상속: 부모 클래스로부터 속성과 기능을 물려받아 새로운 클래스를 생성하는 것
    // - 오버라이딩: 부모 클래스로부터 상속받은 메서드를 자식 클래스에서 재정의하는 것

    // 1.1. 이번 과제에서 상속과 오버라이딩은 무엇인가?
    // - 이번 과제에서 상속은 ClapTrap 클래스를 상속받아 FragTrap 클래스를 생성하는 것이다.
    // - 이번 과제에서 오버라이딩은 attack() 메서드를 재정의하는 것이다.
    
    // 2. 생성자와 소멸자의 호출 순서
    // - 생성자: 부모 클래스의 생성자가 먼저 호출되고, 자식 클래스의 생성자가 호출된다.
    // - 소멸자: 자식 클래스의 소멸자가 먼저 호출되고, 부모 클래스의 소멸자가 호출된다.

    // 3. protected, private, public의 사용
    // - protected: 자식 클래스에서 접근 가능
    // - private: 자식 클래스에서 접근 불가능
    // - public: 모든 클래스에서 접근 가능

    void attack(const string &target);    // 공격
    void takeDamage(unsigned int amount); // 데미지 입기
    void beRepaired(unsigned int amount); // 수리
  
    string get_Name() const;              // 이름 반환
    unsigned int get_Damage(void) const;  // 공격력 반환
};

#endif