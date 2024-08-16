## 가장 중요하다 생각하는 서브젝트 명시 사항

### Member Function Descriptions

- In all of these member functions, you have to print a message to describe what happens.
  - 모든 멤버 함수들은 모두 무슨 일이 일어났는지 설명하는 메시지를 출력해야 한다.
- For example, the `attack()` function may display something like (of course, without the angle brackets):
  - 예를 들어, `attack()` 함수는 다음과 같은 내용을 표시할 수 있다(물론, 꺽쇠 괄호 없이):
  - ClapTrap `<name>` attacks `<target>`, causing `<damage>` points of damage!

- When ClapTrap attacks, it causes its target to lose `<attack damage>` hit points.
  - ClapTrap이 공격할 때, 공격 대상은 `<공격력>`의 체력을 잃게 된다.
- When ClapTrap repairs itself, it gets `<amount>` hit points back. Attacking and repairing cost 1 energy point each.
  - ClapTrap이 자신을 수리할 때, `<수리량>`의 체력을 회복한다. 공격과 수리는 각각 1 에너지 포인트가 소모된다.
- Of course, ClapTrap can’t do anything if it has no hit points or energy points left.
  - 물론, ClapTrap은 체력이나 에너지 포인트가 남아 있지 않은 경우 아무것도 할 수 없다.

### Important Notes

- Implement the logic to ensure that if `hit points` or `energy points` are 0, ClapTrap cannot perform any actions.
- Refer to the code for further implementation details.

## 03 평가에서 중요한 요소

### 1. 상속, 오버라이딩

- 상속: 부모 클래스로부터 속성과 기능을 물려받아 새로운 클래스를 생성하는 것
- 오버라이딩: 부모 클래스로부터 상속받은 메서드를 자식 클래스에서 재정의하는 것

#### 1.1 이번 과제에서 상속과 오버라이딩은 무엇인가?

- 이번 과제에서 상속은 ClapTrap 클래스를 상속받아 FragTrap 클래스를 생성하는 것이다.
- 이번 과제에서 오버라이딩은 `attack()` 메서드를 재정의하는 것이다.

### 2. 생성자와 소멸자의 호출 순서

- 생성자: 부모 클래스의 생성자가 먼저 호출되고, 자식 클래스의 생성자가 호출된다.
- 소멸자: 자식 클래스의 소멸자가 먼저 호출되고, 부모 클래스의 소멸자가 호출된다.

### 3. protected, private, public의 사용

- `protected`: 자식 클래스에서 접근 가능
- `private`: 자식 클래스에서 접근 불가능
- `public`: 모든 클래스에서 접근 가능
