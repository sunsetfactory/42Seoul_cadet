
# C++ Module 05

## Repetition and Exceptions

 반복과 예외

##### _Summary: This document contains the subject for Module 05 of the C++ modules._

 요약 : 이 문서에는 C ++ 모듈의 모듈 05에 대한 주제가 포함되어 있습니다.

##### _Version: 10.1_

 버전 : 10.1


<br>

## Contents

| Chapter | Contents | Page |
|:---:|:---|:---:|
| 1   | [**Introduction**](#Chapter-1) | 2 |
| 2   | [**General rules**](#Chapter-2) | 3 |
| 3   | [**Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!**](#Chapter-3) | 5 |
| 4   | [**Exercise 01: Form up, maggots!**](#Chapter-4) | 7 |
| 5   | [**Exercise 02: No, you need form 28B, not 28C...**](#Chapter-5) | 9 |
| 6   | [**Exercise 03: At least this beats coffee-making**](#Chapter-6) | 11 |
| 7   | [**Submission and peer evalutation**](#Chapter-7) | 13 |

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

## Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!

| **CPP Module** | Exercise 00 |
|:---:|:---|
||Mommy, when I grow up, I want to be a bureaucrat!|
|**제출할 폴더**|ex00/|
|**제출할 파일**|Makefile, main.cpp, Bureaucrat.{h, hpp}, Bureaucrat.cpp|
|**금지된 함수**|None|


>
> ℹ️ <br>
>
> ##### _Please note that exception classes don't have to be designed in Orthodox Canonical Form. But every other class has to._
>
> 예외 클래스는 Orthodox Canonical Form으로 디자인할 필요가 없습니다. 그러나 다른 모든 클래스는 그렇게 해야 합니다.
> <br><br>

##### _Let's design an artifical nightmare of offices, corridors, forms, and waiting queues. Sounds fun? No? Too bad._

 사무실, 복도, 양식, 대기열의 인공적인 악몽을 디자인해봅시다. 재미있어 보이지 않나요? 아니요? 아쉽네요.

##### _First, we start by the smallest cog in the vast bureaucratic machine: the `Bureaucrat`._

 먼저, 우리는 거대한 관료적 기계의 가장 작은 톱니바퀴인 `Bureaucrat`으로 시작합니다.

##### _A `Bureaucrat` must have:_

 `Bureaucrat`은 다음과 같아야 합니다:

- ##### _A constant name_

	상수 이름

- ##### _And a grade that ranges from `1` (highest possible grade) to `150` (lowest possible grade)._

	그리고 `1` (가능한 최고 등급)에서 `150` (가능한 최저 등급) 사이의 등급.

##### _Any attempt to instantiate a `Bureaucrat` with an invalid grade must throw an exception:_

 either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.

 잘못된 등급으로 `Bureaucrat`을 인스턴스화하려는 모든 시도는 예외를 throw해야 합니다:
 
 Bureaucrat::GradeTooHighException 또는 Bureaucrat::GradeTooLowException.

##### _You will provide getters for both these attributes: `getName()` and `getGrade()`. Implement also two member functions to increment or decrement the bureaucrat grade. If the grade is out of range, both of them will throw the same exceptions as the constructor._

 이러한 속성에 대한 getter를 제공합니다: `getName()`과 `getGrade()`. 또한 `Bureaucrat` 등급을 증가시키거나 감소시키는 두 멤버 함수를 구현합니다. 등급이 범위를 벗어나면, 두 함수 모두 생성자와 동일한 예외를 throw합니다.

>
> 💡 <br>
>
> ##### _Remember. Since grade 1 is the highest one and 150 the lowest, incrementing a grade 3 should give grade 2 the bureaucrat._
>
> 기억하세요. 등급 1이 가장 높고 150이 가장 낮기 때문에, 등급 3을 증가시키면 등급 2가 됩니다.
><br><br>

##### _The thrown exception must be catchable using try and catch blocks:_

 try와 catch 블록을 사용하여 throw된 예외를 catch할 수 있어야 합니다:

```cpp
try
{
	/* do some stuff with bureaucrats */
}
catch (std::exception & e)
{
	/* handle exception */
}
```

##### _You will implement an overload of the insertion (`<<`) operator to print something like(without the angle brackets):_

 다음과 같은 것을 출력하는 삽입(`<<`) 연산자의 오버로드를 구현해야 합니다(꺽쇠 괄호 없이):

`<name>, bureaucrat grade <grade>.`

##### _As usual, turn in some tests to prove everything works as expected._

 평소처럼, 모든 것이 예상대로 작동하는지 증명하기 위해 몇 가지 테스트를 제출하세요.


<br>

# **Chapter 4**

## Exercise 01: Form up, maggots!

| **CPP Module** | Exercise 01 |
|:---:|:---|
||Form up, maggots!|
|**제출할 폴더**|ex01/|
|**제출할 파일**|이전의 exercise 파일 + Form.{h, hpp}, Form.cpp|
|**금지된 함수**|None|

##### _Now that you have bureaucrats, let's give them something to do. What better activity could there be than the one of filling out a stack of forms?_

 이제 `Bureaucrat`들이 생겼으니 그들에게 할 일을 주자고요. 수북이 쌓인 양식을 작성하는 것보다 더 좋은 활동이 있을까요?

##### _Then let's make a `Form` class. It has:_

 그러면 `Form` 클래스를 만들어 봅시다. 다음과 같습니다:

- ##### _A constant name_

	상수 이름

- ##### _A boolean indicating whether it is signed (at construction, it's not)._

	서명되었는지 여부를 나타내는 boolean (생성 시에는 서명되지 않음).

- ##### _A constant grade required to sign it._

	서명하기 위해 필요한 상수 등급.

- ##### _A constant grade required to execute it._

	실행하기 위해 필요한 상수 등급.

##### _The grades of the `Form` follow the same rules that apply to the `Bureaucrat`. Thus, the following exceptions will be thrown if a form grade is out of bounds:_

Form::GradeTooHighException and Form::GradeTooLowException.

 `Form`의 등급은 `Bureaucrat`에 적용되는 규칙과 동일합니다. 따라서, 다음과 같은 예외가 throw됩니다:
 
 Form::GradeTooHighException 및 Form::GradeTooLowException.

##### _Same as before, write getters for all attributs and an overload of the insertion (`<<`) operator that prints all the form's informations._

 이전과 마찬가지로, 모든 속성에 대한 getter와 삽입(`<<`) 연산자의 오버로드를 작성하여 모든 양식 정보를 출력합니다.

##### _Add also a `beSigned()` member function to the Form that takes a Bureaucrat as parameter. It changes the form status to signed if the bureaucrat's grade is high enough (higher or egal to the required one). Remember, grade 1 is higher than grade2. If the grade is too low, throw a `Form::GradeTooLowException.`_

 또한 Form에 Bureaucrat을 매개변수로 사용하는 `beSigned()` 멤버 함수를 추가하세요. `Bureaucrat`의 등급이 충분히 높으면 (필요한 등급보다 높거나 같으면) 양식 상태를 서명된 것으로 변경합니다. 기억하세요, 등급 1은 등급 2보다 높습니다. 등급이 너무 낮으면 `Form::GradeTooLowException`을 throw하세요.

##### _Lastly, add a `signForm()` member function to the Bureaucrat. If the form got signed, it will print something like:_

 `<bureaucrat> signed <form>`

##### _Otherwise, it will print something like:_

 `<bureaucrat> couldn’t sign <form> because <reason>.`

 마지막으로, Bureaucrat에 `signForm()` 멤버 함수를 추가하세요. 양식이 서명되면 다음과 같이 출력됩니다:

 `<bureaucrat> signed <form>`

 그렇지 않으면 다음과 같이 출력됩니다:

 `<bureaucrat> couldn’t sign <form> because <reason>.`

##### _Implement and turn in some tests to ensure everything works as expected._

 모든 것이 예상대로 작동하는지 확인하기 위해 몇 가지 테스트를 구현하고 제출하세요.

<br>

# **Chapter 5**

## Exercise 02: No, you need form 28B, not 28C...

| **CPP Module** | Exercise 02 |
|:---:|:---|
||No, you need form 28B, not 28C...|
|**제출할 폴더**|ex02/|
|**제출할 파일**|Makefile, main.cpp, Bureaucrat.[{h, hpp},cpp], Bureaucrat.cpp + AForm.[{h, hpp},cpp], ShrubberyCreationForm.[{h, hpp},cpp] + RobotomyRequestForm.[{h, hpp},cpp], PresidentialPardonForm.[{h, hpp},cpp]|
|**금지된 함수**|None|

##### _Since you now have basic forms, it's time to make a few more that actually do something_

 이제 기본적인 양식이 있으므로 실제로 무언가를 하는 몇 가지 양식을 만들어 봅시다.

##### _In all cases, the base class Form must be an abstract class, and therefore should be renames AForm. Keep in mind the form's attributes need to remain private and that they are in the base class._

 모든 경우에, 기본 클래스 Form은 추상 클래스여야 하며, 따라서 AForm으로 이름을 바꿔야 합니다. 양식의 속성이 private로 유지되어야 하며, 기본 클래스에 있음을 기억하세요.

##### _Add the following concrete classes:_

 다음과 같은 concrete 클래스를 추가하세요:

- ##### _`ShrubberyCreationForm`: Required grades: sign 145, exec 137<br>Create a file `<target>_shrubbery` in the working directory, and writes ASCII trees inside it._

	`ShrubberyCreationForm`: 필요한 등급: sign 145, exec 137<br>작업 디렉토리에 `<target>_shrubbery` 파일을 생성하고, 그 안에 ASCII 트리를 작성합니다.

- ##### _`RobotomyRequestForm`: Required grades: sign 72, exec 45<br>Make some drilling noises, Then informs that <target> has been robotomized successfully 50% of the time. Otherwise, informs that the robotomy failed._

	`RobotomyRequestForm`: 필요한 등급: sign 72, exec 45<br>일부 드릴 소음을 내고, 그런 다음 <target>이 50%의 확률로 성공적으로 로보토마이즈되었음을 알립니다. 그렇지 않으면, 로보토미가 실패했음을 알립니다.

- ##### _`PresidentialPardonForm`: Required grades: sign 25, exec 5<br>Informs that <target> has been pardoned by Zaphod Beeblebrox._

	`PresidentialPardonForm`: 필요한 등급: sign 25, exec 5<br><target>이 Zaphod Beeblebrox에 의해 사면되었음을 알립니다.

##### _All of them take only one parameter in their constructor: the target of the form. For example, "home" if you want to plant shrubbery at home._

이들 모두는 생성자에서 양식의 대상인 매개변수를 하나만 받습니다. 예를 들어, 집에 관목을 심으려는 경우 "home"을 사용합니다.

##### _Now, add the `execute(Bureaucrat const & executor) const` member function to the base form and implement a function to execute the form’s action of the concrete classes. You have to check that the form is signed and that the grade of the bureaucrat attempting to execute the form is high enough. Otherwise, throw an appropriate exception._

 이제, 기본 양식에 `execute(Bureaucrat const & executor) const` 멤버 함수를 추가하고 concrete 클래스의 양식 작업을 실행하는 함수를 구현하세요. 양식이 서명되었는지, 양식을 실행하려는 `Bureaucrat`의 등급이 충분히 높은지 확인해야 합니다. 그렇지 않으면, 적절한 예외를 throw하세요.

##### _Whether you want to check the requirements in every concrete class or in the base class (then call another function to execute the form) is up to you. However, one way is prettier than the other one._

 모든 concrete 클래스에서 요구 사항을 확인할 것인지, 기본 클래스에서 확인한 다음 다른 함수를 호출하여 양식을 실행할 것인지는 여러분의 선택입니다. 그러나 한 가지 방법이 다른 방법보다 예쁩니다.

##### _Lastly, add the `executeForm(AForm const & form)` member function to the Bureaucrat. It must attempt to execute the form. If it’s successful, print something like:_

 `<bureaucrat> executed <form>`

##### _If not, print an explicit error message._

 마지막으로, Bureaucrat에 `executeForm(AForm const & form)` 멤버 함수를 추가하세요. 양식을 실행하려고 시도해야 합니다. 성공하면 다음과 같이 출력합니다:

 `<bureaucrat> executes <form>`

 그렇지 않으면, 명시적인 오류 메시지를 출력하세요.

##### _Implement and turn in some tests to ensure everything works as expected._

 모든 것이 예상대로 작동하는지 확인하기 위해 몇 가지 테스트를 구현하고 제출하세요.

<br>

# **Chapter 6**

## Exercise 03: At least this beats coffee-making

| **CPP Module** | Exercise 03 |
|:---:|:---|
||At least this beats coffee-making|
|**제출할 폴더**|ex03/|
|**제출할 파일**|이전 exercise들 파일 + Intern.{h, hpp}, Intern.cpp|
|**금지된 함수**|None|

##### _Because filling out forms is annoying enough, it would be cruel to ask our bureaucrats to do this all day long. Fortunately, interns exist. In this exercise, you have to implement the `Intern` class. The intern has no name, no grade, no unique characteristics. The only thing the bureaucrats care about is that they do their job._

 양식 작성은 이미 귀찮은 일이므로, 관료들에게 하루 종일 이 일을 하도록 요구하는 것은 잔인할 것입니다. 다행히도 인턴이 존재합니다. 이 연습에서는 `Intern` 클래스를 구현해야 합니다. 인턴은 이름도 없고 등급도 없고 독특한 특징도 없습니다. 관료들이 관심을 가지는 유일한 것은 그들이 일을 잘하는 것입니다.

##### _However, the intern has one important capacity: the `makeForm()` function. It takes two strings. The first one is the name of a form and the second one is the target of the form. It return a pointer to a `Form object` (whose name is the one passed as parameter) whose target will be initialized to the second parameter._

 그러나 인턴에게는 한 가지 중요한 능력이 있습니다: `makeForm()` 함수입니다. 두 개의 문자열을 사용합니다. 첫 번째는 양식의 이름이고 두 번째는 양식의 대상입니다. 두 번째 매개변수로 초기화된 `Form object` (이름이 매개변수로 전달된 것)에 대한 포인터를 반환합니다.

##### _It will print something like:_

 `<intern> creates <form>`

 다음과 같이 출력합니다:

 `<intern> creates <form>`

##### _If the form name passed as parameter doesn’t exist, print an explicit error message._

 매개변수로 전달된 양식 이름이 존재하지 않으면, 명시적인 오류 메시지를 출력합니다.

##### _You must avoid unreadable and ugly solutions like using a if/elseif/else forest. This kind of things won’t be accepted during the evaluation process. You’re not in Piscine (pool) anymore. As usual, you have to test that everything works as expected._

 if/elseif/else forest와 같은 읽기 어렵고 못생긴 솔루션을 피해야 합니다. 이러한 것들은 평가 과정에서 허용되지 않습니다. 여러분은 더 이상 Piscine(pool)에 있지 않습니다. 평소처럼 모든 것이 예상대로 작동하는지 테스트해야 합니다.

##### _For example, the code below creates a RobotomyRequestForm targeted on "Bender":_

 아래 코드는 "Bender"를 대상으로 한 RobotomyRequestForm을 생성합니다:

```cpp
{
	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}
```

<br>

# **Chapter 7**

## Submission and peer-evaluation

##### _Turn in your assignment in your Git repository as usual. Only the work inside your repository will be evaluated during the defense. Don't hesitate to double check the names of your folders and files to ensure they are correct._

 여러분의 과제를 평소와 같이 여러분의 깃 저장소에 제출하세요. 디펜스 동안 여러분의 저장소 안의 작업만 평가될 것입니다. 여러분의 폴더와 파일 이름이 올바른지 확인하는 것을 망설이지 마세요.

Powered by Wiki.js
