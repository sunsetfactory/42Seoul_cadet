# **CPP Module 06**

## C++ casts

 C++ 캐스트

##### _<center>Summary:<br>This document contains the exercises of Module 06 from C++ modules</center>_

 <center>요약:<br>이 문서에는 C++ 모듈의 모듈 06 연습 문제가 포함되어 있습니다.</center>

##### _Version: 6.2_

 버전: 6.2

<br>

## Contents

| Chapter | Contents | Page |
|:---:|:---|:---:|
| 1   | [**Introduction**](#Chapter-1) | 2 |
| 2   | [**General rules**](#Chapter-2) | 3 |
| 3   | [**Additional rule**](#Chapter-3) | 5 |
| 4   | [**Exercise 00: Conversion of scalar types**](#Chapter-4) | 6 |
| 5   | [**Exercise 01: Serialization**](#Chapter-5) | 9 |
| 6   | [**Exercise 02: Identify real type**](#Chapter-6) | 10 |
| 7   | [**Submission and peer evalutation**](#Chapter-7) | 11 |

<br>

# **Chapter 1**

## Introduction

##### _C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language, or "C with Classes" (source: [Wikipedia](https://en.wikipedia.org/wiki/C++))._

 C++은 Bjarne Stroustrup이 C 프로그래밍 언어를 확장한 범용 프로그래밍 언어입니다. "C with Classes"라고도 불립니다. (출처 : [위키백과](https://en.wikipedia.org/wiki/C++))

##### _The goal of these module is to introduce you to Object-Oriented Programming.This will be starting point of your C++ journey. Many languages are recommended to learn OOP. We decided to choose C++ since it's derived from your old friend C. Because this is a comoplex language, and in order to keep things simple, your code will comply with the c++98 standard._

 이 모듈의 목표는 여러분을 객체 지향 프로그래밍에 소개하는 것입니다. 이것이 여러분의 C++ 여행의 시작점이 될 것입니다. 많은 언어들이 OOP를 배우기에 적합하다고 추천합니다. 우리는 여러분의 친구인 C에서 파생된 C++를 선택했습니다. 이 언어는 복잡하기 때문에, 간단하게 하기 위해 여러분의 코드는 c++98 표준을 준수할 것입니다.


##### _We are aware modern C++ is way different in a lot of aspects. So if you want to become proficient C++ developer, it's up to you to go further after 42 Comman Core!_

 우리는 현대의 C++가 많은 측면에서 매우 다르다는 것을 알고 있습니다. 따라서 여러분이 숙련된 C++ 개발자가 되고 싶다면, 42 Common Core 이후에 더 나아가는 것은 여러분에게 달려 있습니다!

<br>

# **Chapter 2**

## General rules

##### _Compiling_

  컴파일

- ##### _Compile your code with c++ and the flags `-Wall -Wextra -Werror`_

  여러분의 코드를 c++과 `-Wall -Wextra -Werror` 플래그와 함께 컴파일하세요.

- ##### _Your code should still complie if you add the flag `-std=c++98`_

  여러분의 코드는 `-std=c++98` 플래그를 추가해도 여전히 컴파일되어야 합니다.

##### _Formatting and naming conventions_

  포맷팅과 네이밍 규칙

- ##### _The exercise directories will be named this way: `ex00, ex01, ... , exn`_

  연습문제 디렉토리는 다음과 같이 이름이 지어집니다: `ex00, ex01, ... , exn`

- ##### _Name your files, classes, functions, variables, etc. according to the standard naming conventions and the C++ naming conventions._

  표준 네이밍 규칙과 C++ 네이밍 규칙에 따라 파일, 클래스, 함수, 변수 등의 이름을 지으세요.

- ##### _Write class names in `UpperCamelCase` format. Files containg class code will always be named according to the class naem. For instance: ClassName.hpp/ClassName.h, ClassName.cpp, or ClassName.tpp. Then, if you have a header file containing the definition of a class "BrickWall" standing for a brick wall, its name will be BrickWall.hpp._

  클래스 이름은 `UpperCamelCase` 형식으로 작성하세요. 클래스 코드를 포함하는 파일은 항상 클래스 이름에 따라 이름이 지어집니다. (클래스이름.hpp/클래스이름.h, 클래스이름.cpp, 클래스이름.tpp) 예를 들어, 벽돌 벽을 나타내는 "BrickWall" 클래스의 정의를 포함하는 헤더 파일의 이름은 BrickWall.hpp가 됩니다.

- ##### _Unless specified otherwise, every output message must be ended by a new-line character and displayed to the standard output._

  명시되지 않은 이상, 모든 출력 메시지는 개행 문자로 끝나야 하며 표준 출력으로 표시되어야 합니다.

- ##### _Goodbye Norminette! No coding style is enforced in the C++ modules. You can follow your favorite one. But keep in mind that a code your peer-evaluators can't understand is a code they can't grade. Do your best to write a clean and readable code._

  안녕, Norminette! C++ 모듈에서는 코딩 스타일이 강제되지 않습니다. 여러분이 좋아하는 스타일을 따라가세요. 하지만 동료 평가자가 이해할 수 없는 코드는 평가할 수 없는 코드입니다. 깨끗하고 읽기 쉬운 코드를 작성하기 위해 최선을 다하세요.

##### _Allowed/Forbidden_

  허용/금지

##### _You are not coding in C anymore. Time to C++! Therefore:_

  여러분은 더 이상 C를 코딩하지 않습니다. C++로 넘어가는 시간입니다! 그러므로:

- ##### _You are allowed to use almost everything from the standard library. Thus, instead of sticking to what you already know, it would be smart to use as much as possible the C++-ish version of the C functions you are used to._

  여러분은 표준 라이브러리에 있는 거의 모든 것들을 사용할 수 있습니다. 따라서 여러분이 이미 알고 있는 것에 고수하는 대신, C 함수의 C++ 스러운 버전을 최대한 사용하는 것이 현명할 것입니다.

- ##### _However, you can't use any other external library. It means C++11 (and derived forms) and Boost libraries are forbidden. The following functions are forbidden too: `*printf()`, `*alloc()`, `free()`. If you use them, your grade will be 0 and that's it._

  하지만 다른 외부 라이브러리는 사용할 수 없습니다. C++11 (그리고 파생된 형태)와 Boost 라이브러리는 금지입니다. 다음 함수들도 금지입니다: `*printf()`, `*alloc()`, `free()`. 사용 시에는 0점이 부여됩니다.

- ##### _Note that unless explicitly stated otehrwise, the using namespce `<ns_name> and friend are forbidden`. Otherwise, your grade will be -42._

  명시되지 않은 이상, using namespace `<ns_name>과 friend는 금지`입니다. 그렇지 않으면, 여러분의 점수는 -42점이 됩니다.

- ##### _`You are allowed to use STL in the Module 08 andn 09 only`. That means: `no` `Containers` (vector/list/map/and so forth) and no `Algorithms`(anything that requires to include the <algorithm> header) until then. Otherwisee, your grade will be -42._

  `Module 08과 09에서만 STL을 사용할 수 있습니다.` 즉, 그 전까지는 `컨테이너`(vector/list/map/그 외)와 `알고리즘`(algorithm 헤더를 포함해야 하는 것들)을 `사용할 수 없습니다`. 그렇지 않으면, 여러분의 점수는 -42점이 됩니다.

##### _A few design requirements_

  몇 가지 디자인 요구사항

- ##### _Memory leakage occurs in C++ too. When you allocate memory (by using the new keyword), you must avoid memory leaks._

  메모리 누수는 C++에서도 발생합니다. (new 키워드를 사용하여) 메모리를 할당할 때, 메모리 누수를 피해야 합니다.

- ##### _From Module 02 to Module 09, your classes must be designed in the `Orthodox Canonical Form`, except when explicitely stated otherwise._

  Module 02부터 Module 09까지, 여러분의 클래스는 명시되지 않은 이상 `Orthodox Canonical Form`으로 디자인되어야 합니다.

- ##### _Any function implementation put in a header file (except for function templates) means 0 to the exercise._

  (템플릿 함수를 제외한) 헤더 파일에 함수 구현이 포함되어 있으면 과제는 0점 처리됩니다.

- ##### _You should be able to use each of your headers independently from others. Thus, they must include all the dependencies they need. However, you must avoid the problem of double inclusion by adding `include guards`. Otherwise, your grade will be 0._

  여러분은 각 헤더를 다른 헤더와 독립적으로 사용할 수 있어야 합니다. 따라서, 헤더가 필요한 모든 의존성을 포함해야 합니다. 그러나, `include guards`를 추가하여 중복 포함 문제를 피해야 합니다. 그렇지 않으면, 여러분의 점수는 0점이 됩니다.

##### _Read me_

  읽어주세요

- ##### _You can add some additional files if you need to (i.e., to split your code). As these assignments are nnot verified by a program, feel free to do so as long as you turn in the mandatory files._

  코드를 분할해야 하는 경우, 필요한 경우에는 추가 파일을 추가할 수 있습니다. 이 과제는 프로그램에 의해 검증되지 않으므로, 필수 파일만 제출한다면 자유롭게 추가할 수 있습니다.

- ##### _Sometimes, the guidelines of an exercise look short but the examples can show requirements that are not explicitly written in the instructions._

  때로는 연습문제의 지침이 짧아 보이지만, 예시에서는 지침에 명시되지 않은 요구사항을 보여줄 수 있습니다.

- ##### _Read each module completely before starting! Really, do it._

  각 모듈을 시작하기 전에 전부 읽으세요! 진짜, 제발요.

- ##### _By Odin, by Thor! Use your brain!!!_

  오딘의 힘으로, 토르의 힘으로! 머리를 굴려보세요!!!

>
> 💡 <br>
>
> ##### _You will have to implement a lot of classes. It can seem tedious, unless you are able to script your favorite text editor._
>
> 꽤 많은 클래스들을 제출해야 할 지도 몰라요. 여러분의 취향에 맞는 텍스트 편집기를 사용하지 않으면 좀 지루한 작업이 될 겁니다.
> <br><br>

>
> ℹ️ <br>
>
> ##### _You are given a certain amount of freedom to complete the exercises. However, follow the mandatory rules and don't be lazy. You would miss a lot of useful information! Do not hesitate to read about theoretical concepts._
>
> 과제를 완료하기 위해 일정한 자유도가 주어집니다. 그러나 필수 규칙을 따르고 게으르지 마세요. 여러분은 많은 유용한 정보를 놓칠 것입니다! 이론적인 개념에 대해 읽어보는 것을 주저하지 마세요.
> <br><br>

<br>

# **Chapter 3**

## Additional rule

##### _The following rule applies to the entire module and is not optional._

 이 규칙은 모듈 전체에 적용되며 선택 사항이 아닙니다.

##### _For each exercise, the type conversion must be solved using specific type of casting. Your choice will be checked during defense._

 각 연습문제마다 타입 변환은 특정 타입의 캐스팅을 사용하여 해결해야 합니다. 여러분의 선택은 평가 과정에서 확인될 것입니다.

<br>

# **Chapter 4**

## Exercise 00: Conversion of scalar types

| **CPP Module** | Exercise 00 |
|:---:|:---|
||Conversion of scalar types|
| **제출할 폴더** | ex00/ |
| **제출할 파일** | Makefile, *.cpp, *.{h, hpp} |
| **허용된 함수** | 문자열을 정수, 실수 또는 이중으로 변환하는 모든 함수. 이것은 도움이 되긴 하겠지만 모든 작업을 수행하지는 않습니다. |

##### _Write a class `ScalarConverter` that will contain only one static methods `"convert"` that will takes as parameter a string representation of a C++ literal in its most common form and output its value in the following serie of scalar types :_

 클래스 `ScalarConverter`를 작성하십시오. 이 클래스는 `"convert"`라는 하나의 정적 메소드만 포함하며, 이 메소드는 가장 일반적인 형태의 C++ 리터럴의 문자열 표현을 매개변수로 받아 다음 스칼라 유형 시리즈에 해당하는 값을 출력합니다:

- ##### _char_

- ##### _int_

- ##### _float_

- ##### _double_

##### _As this class doesn’t need to store anything at all, this class must not be instanciable by users._

 이 클래스는 아무것도 저장할 필요가 없으므로, 이 클래스는 사용자가 인스턴스화 할 수 없어야 합니다.

##### _Except for char parameters, only the decimal notation will be used._

 char 매개 변수를 제외하고는 십진수 표기법만 사용됩니다.

##### _Examples of char literals: ’c’, ’a’, ...<br>To make things simple, please note that non displayable characters shouldn’t be used as inputs. If a conversion to char is not displayable, prints an informative message.

 char 리터럴의 예: 'c', 'a', ...<br>간단하게 하기 위해, 표시할 수 없는 문자는 입력으로 사용하지 마세요. char로 변환할 수 없는 경우, 정보 메시지를 출력하세요.

##### _Examples of int literals: 0, -42, 42..._

 int 리터럴의 예: 0, -42, 42...

##### _Examples of float literals: 0.0f, -4.2f, 4.2f..._

 float 리터럴의 예: 0.0f, -4.2f, 4.2f...

##### _You have to handle these pseudo literals as well (you know, for science): -inff, +inff and nanf._

 이러한 의사 리터럴도 처리해야 합니다 (과학을 위해): -inff, +inff 그리고 nanf

##### _Examples of double literals: 0.0, -4.2, 4.2..._

 double 리터럴의 예: 0.0, -4.2, 4.2...

##### _You have to handle these pseudo literals as well (you know, for fun): -inf, +inf and nan._

 이러한 의사 리터럴도 처리해야 합니다 (재미를 위해): -inf, +inf 그리고 nan

##### _Write a program to test that your class works as expected._

 여러분의 클래스가 예상대로 작동하는지 테스트하는 프로그램을 작성하세요.

##### _You have to first detect the type of the literal passed as parameter, convert it from string to its actual type, then convert it `explicitly` to the three other data types. Lastly, display the results as shown below._

 먼저 매개 변수로 전달된 리터럴의 유형을 감지한 다음, 문자열에서 실제 유형으로 변환한 다음, 나머지 세 가지 데이터 유형으로 `명시적으로` 변환하세요. 마지막으로 아래와 같이 결과를 표시하세요.

##### _If a conversion does not make any sense or overflows, display a message to inform the user that the type conversion is impossible. Include any header you need in order to handle numeric limits and special values._

 변환이 의미가 없거나 `overflow`하는 경우, 타입 변환을 할 수 없음을 사용자에게 알리는 메시지를 표시하세요. 숫자 제한 및 특수 값 처리에 필요한 헤더를 포함하세요.


```
$> ./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
$> ./convert nan
char: impossible
int: impossible
float: nanf
double: nan
$> ./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```

<br>

# **Chapter 5**

## Exercise 01: Serialization

| **CPP Module** | Exercise 01 |
|:---:|:---|
||Serialization|
| **제출할 폴더** | ex01/ |
| **제출할 파일** | Makefile, *.cpp, *.{h, hpp} |
| **금지된 함수** | 없음 |

##### _Implement a class Serializer, who will not be initializable by the user by any way, with the following static methods:_

 사용자가 아무런 방법으로도 초기화할 수 없는 다음 정적 메소드를 가진 Serializer 클래스를 구현하세요.

##### _`uintptr_t serialize(Data* ptr);`<br>It takes a pointer and converts it to the unsigned integer type `uintptr_t`._

 `uintptr_t serialize(Data* ptr);`<br>포인터를 가져와서 부호 없는 정수 형태인 `uintptr_t`로 변환합니다.

##### _`Data* deserialize(uintptr_t raw);`<br>It takes an unsigned integer parameter and converts it to a pointer to Data._

 `Data* deserialize(uintptr_t raw);`<br>부호 없는 정수 매개 변수를 가져와서 Data의 포인터로 변환합니다.

##### _Write a program to test that your class works as expected._

 여러분의 클래스가 예상대로 작동하는지 테스트하는 프로그램을 작성하세요.

##### _You must create a non-empty (it means it has data members) Data structure._

 비어 있지 않은 (데이터 멤버가 있는) Data 구조를 만들어야 합니다.

##### _Use `serialize()` on the address of the Data object and pass its return value to `deserialize()`. Then, ensure the return value of `deserialize()` compares equal to the original pointer._

 Data 객체의 주소에 `serialize()`를 사용하고 그 반환 값을 `deserialize()`에 전달하세요. 그런 다음 `deserialize()`의 반환 값이 원래 포인터와 같은지 확인하세요.

##### _Do not forget to turn in the files of your Data structure._

 Data 구조의 파일을 제출하는 것을 잊지 마세요.

<br>

# **Chapter 6**

## Exercise 02: Identify real type

| **CPP Module** | Exercise 02 |
|:---:|:---|
||Identify real type|
| **제출할 폴더** | ex02/ |
| **제출할 파일** | Makefile, *.cpp, *.{h, hpp} |
| **금지된 함수** | std::typeinfo |

##### _Implement a `Base` class that has a public virtual destructor only. Create three empty classes `A`, `B` and `C`, that publicly inherit from Base._

 오직 public virtual 소멸자만을 가진 `Base` 클래스를 구현하세요. `A`, `B` 그리고 `C`라는 세 개의 빈 클래스를 만들고, 이들은 모두 Base를 상속합니다.

>
> ℹ️ <br>
>
> ##### _These four classes don’t have to be designed in the Orthodox Canonical Form._
>
> 이 네 개의 클래스는 Orthodox Canonical Form으로 디자인할 필요가 없습니다.
> <br><br>

##### _Implement the following functions:_

 다음 함수들을 구현하세요.

- ##### _`Base * generate(void);`<br>It randomly instanciates `A`, `B` or `C` and returns the instance as a Base pointer. Feel free to use anything you like for the random choice implementation._

	`Base * generate(void);`<br>`A`, `B` 또는 `C`를 무작위로 인스턴스화하고 인스턴스를 Base 포인터로 반환합니다. 무작위 선택 구현에 필요한 것은 자유롭게 사용하세요.

- ##### _`void identify(Base* p);`<br>It prints the actual type of the object pointed to by p: `"A"`, `"B"` or `"C"`._

	`void identify(Base* p);`<br>p가 가리키는 객체의 실제 유형을 출력합니다: `"A"`, `"B"` 또는 `"C"`.

- ##### _`void identify(Base& p);`<br>It prints the actual type of the object pointed to by p: `"A"`, `"B"` or `"C"`. Using a pointer inside this function is forbidden._

	`void identify(Base& p);`<br>p가 가리키는 객체의 실제 유형을 출력합니다: `"A"`, `"B"` 또는 `"C"`. 이 함수 내에서 포인터를 사용하는 것은 금지됩니다.

##### _Including the `typeinfo` header is forbidden._

 `typeinfo` 헤더를 포함하는 것은 금지됩니다.

##### _Write a program to test that everything works as expected._

 모든 것이 예상대로 작동하는지 테스트하는 프로그램을 작성하세요.

<br>

# **Chapter 7**

## Submission and peer evaluation

##### _Turn in your assignment in your Git repository as usual. Only the work inside your repository will be evaluated during the defense. Don't hesitate to double check the names of your folders and files to ensure they are correct._

 여러분의 과제를 평소와 같이 여러분의 깃 저장소에 제출하세요. 디펜스 동안 여러분의 저장소 안의 작업만 평가될 것입니다. 여러분의 폴더와 파일 이름이 올바른지 확인하는 것을 망설이지 마세요.

Powered by Wiki.js
