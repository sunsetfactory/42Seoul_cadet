# page 0

## C++ - Module 07
## C++ - 모듈 07

### c++ Templates
### c++ 템플릿

Summary: This document contains the subject for Module 07 of the C++ modules.  
요약: 이 문서에는 C ++ 모듈의 모듈 07에 대한 주제가 포함되어 있습니다.  

# page 1

## Contents

| Chapter | Contents | Page |
|:---:|:---|:---:|
| I | [__General rules__]() | 2 |
| II | [__Exercise 00: A few functions__]() | 4 |
| III | [__Exercise 01: Iter__]() |  6 |
| IV | [__Exercise 02: Array__]() |  7 |

# page 2

## Chapter I
## 챕터 I
## General rules
## 일반적인 규칙

- Any function implemented in a header (except in the case of templates), and any unprotected header, means 0 to the exercise.

- 헤더에 구현된 어떤 기능 (템플릿의 경우 제외) 및 보호되지 않은 헤더는 평가 과정에서 0을 의미합니다.

- Every output goes to the standard output, and will be ended by a newline, unless specified otherwise.

- 모든 출력은 표준 출력으로 전달되며 달리 지정하지 않는 한 개행으로 끝납니다.

- The imposed filenames must be followed to the letter, as well as class names, function names and method names.

- 부과된 파일 이름 뒤에는 클래스 이름, 함수 이름 및 메소드 이름뿐만 아니라 문자가 와야합니다.

- Remember: You are coding in C++ now, not in C anymore. Therefore:
  - The following functions are FORBIDDEN, and their use will be punished by a 0, no questions asked: *alloc, *printf and free.
  - You are allowed to use basically everything in the standard library. HOWEVER, it would be smart to try and use the C++-ish versions of the functions you are used to in C, instead of just keeping to what you know, this is a new language after all. And NO, you are not allowed to use the STL until you actually are supposed to (that is, until module 08). That means no vectors/lists/maps/etc... or anything that requires an include \<algorithm> until then.

- 기억하세요: 이제 당신은 더 이상 C가 아닌 C++로 코딩하고 있습니다. 따라서:
  - \*alloc, \*printf 및 free와 같은 함수는 금지되어 있으며 사용시 0으로 처벌됩니다.
  - 기본적으로 표준 라이브러리의 모든 것을 사용할 수 있습니다. 그러나 알고 있는 내용을 그대로 유지하는 대신 이것은 결국 새로운 언어이기 때문에, C에서 익숙한 함수의 C++ 버전을 사용하는 것이 현명할 것입니다. STL을 사용하기로 되어있는 모듈(cpp module 08) 전 까지는 STL 을 사용하실 수 없습니다. 즉, 그때까지 벡터/리스트/맵/등등 또는 \<algorithm> 헤더에 포함된 어떤 것도 쓸 수 없음을 의미합니다.

- Actually, the use of any explicitly forbidden function or mechanic will be punished by a 0, no questions asked.

- 실제로, 명시적으로 금지된 기능이나 방법은 가차없이 0점으로 처벌됩니다.

- Also note that unless otherwise stated, the C++ keywords "using namespace" and "friend" are forbidden. Their use will be punished by a -42, no questions asked.

- 또한 달리 명시되지 않는 한 C++ 키워드 "using namespace" 및 "friend"는 금지됩니다. 그들의 사용은 가차없이 -42로 처벌될 것입니다.

- Files associated with a class will always be ClassName.hpp and ClassName.cpp, unless specified otherwise.

- 클래스와 연관된 파일은 달리 지정하지 않는 한 항상 ClassName.hpp 및 ClassName.cpp입니다.

- Turn-in directories are ex00/, ex01/, . . . , exn/.

- 제출 디렉토리는 ex00 /, ex01 /,. . . , exn/ 입니다.

- You must read the examples thoroughly. They can contain requirements that are not obvious in the exercise’s description. If something seems ambiguous, you don’t understand C++ enough.

- 예제를 철저히 읽어야합니다. 여기에는 연습 설명에서 명확하지 않은 요구 사항이 포함될 수 있습니다. 모호해 보이는 것이 있으면 C++를 충분히 이해하지 못하는 것입니다.

- Since you are allowed to use the C++ tools you learned about since the beginning, you are not allowed to use any external library. And before you ask, that also means no C++11 and derivates, nor Boost or anything your awesomely skilled friend told you C++ can’t exist without.

- 처음부터 배운 C++ 도구를 사용할 수 있으므로 외부 라이브러리를 사용할 수 없습니다. 미리 말씀드리지만, C++11, Boost, 프로그래밍을 잘하는 친구가 c++은 이거 없으면 시체라고 추천한 툴들을 포함한 그 어떤 외부 라이브러리도 사용할 수 없습니다

# page 3

- You may be required to turn in an important number of classes. This can seem tedious, unless you’re able to script your favorite text editor.

- 상당한 수의 클라스들을 제출해야 할 수도 있습니다. 좋아하는 텍스트 편집기를 스크립팅 할 수 없다면 지루해 보일 수 있습니다.

- Read each exercise FULLY before starting it! Really, do it.

- 시작하기 전에 각 연습 문제를 완전히 읽으십시오! 정말로, 하세요.

- The compiler to use is clang++.

- 사용할 컴파일러는 clang ++입니다.

-  Your code has to be compiled with the following flags : -Wall -Wextra -Werror.

- 다음 플래그를 사용하여 코드를 컴파일해야합니다: -Wall -Wextra -Werror.

- Each of your includes must be able to be included independently from others. Includes must contains every other includes they are depending on, obviously.

- 각 includes는 다른 것들과 독립적으로 포함될 수 있어야합니다. Includes는 분명히 그들이 의존하는 다른 모든 include를 포함해야합니다.

- In case you’re wondering, no coding style is enforced during in C++. You can use any style you like, no restrictions. But remember that a code your peer-evaluator can’t read is a code she or he can’t grade.

- 혹시 궁굼할까봐 말씀드리지만, C++에서는 코딩 스타일이 강제되지 않습니다. 제한없이 원하는 스타일을 사용할 수 있습니다. 하지만 동료 평가자가 읽을 수 없는 코드는 점수를 매길 수 없는 코드라는 점을 기억하세요.

- Important stuff now : You will NOT be graded by a program, unless explictly stated in the subject. Therefore, you are afforded a certain amount of freedom in how you choose to do the exercises. However, be mindful of the constraints of each exercise, and DO NOT be lazy, you would miss a LOT of what they have to offer !

- 지금 중요한 사항 : 서브젝트에 명시적으로 언급되지 않는 한 프로그램에 의해 평가되지 않습니다. 따라서 연습 문제를 선택하는 방법에 있어 어느 정도의 자유가 주어집니다. 그러나 각 연습 문제의 제약을 염두에 두고 게을러지지 마세요, 그들이 제공해야하는 많은 것을 놓칠 것입니다 !

- It’s not a problem to have some extraneous files in what you turn in, you may choose to separate your code in more files than what’s asked of you. Feel free, as long as the result is not graded by a program.

- 제출한 파일에 관련없는 파일이 있는 것은 문제가 되지 않습니다. 요청한 것보다 더 많은 파일에서 코드를 분리하도록 선택할 수 있습니다. 결과가 프로그램에 의해 평가되지 않는한 자유롭게 평가하시면 됩니다.

- Even if the subject of an exercise is short, it’s worth spending some time on it to be absolutely sure you understand what’s expected of you, and that you did it in the best possible way.

- 연습 문제의 주제가 짧더라도 자신에게 기대되는 바를 이해하고 가능한 최선의 방법으로 수행했는지 확인하기 위해 시간을 할애 할 가치가 있습니다.

- By Odin, by Thor! Use your brain!!!

- 오딘, 토르! 머리를 써라!!!

# page 4

## Chapter II
## 챕터 II
## Exercise 00: A few functions
## 연습 문제 00: 몇 가지 함수들

```
Exercise : 00
Exercise 00: A few functions
Turn-in directory : ex00/
Files to turn in : whatever.hpp, main.cpp and a Makefile
Allowed functions : None
```

```
연습 문제 : 00
연습 문제 00: 몇 가지 함수들
제출 디렉터리 : ex00/
제출할 파일 : whatever.hpp, main.cpp and a Makefile
허용 함수 : 없음
```

Write the following function templates:  

다음 함수 템플릿을 작성합니다:  

- swap: Swaps the values of two arguments. Does not return anything.
- min: Compares the two arguments and returns the smallest one. If the two arguments are equal, then it returns the second one.
- max: Compares the two arguments and returns the biggest one. If the two arguments
are equal, then it returns the second one.

- swap : 두 인수의 값을 바꿉니다. 아무것도 반환하지 않습니다.
- min : 두 인수를 비교하여 가장 작은 인수를 반환합니다. 두 인수가 같으면 두 번째 인수를 반환합니다.
- max : 두 인수를 비교하여 가장 큰 인수를 반환합니다. 두 인수가 같으면 두 번째 인수를 반환합니다.

Templates must be defined in header files. You must turn in a main.cpp containing tests
for your program. This file can and will be changed during evaluation. These functions
can be called with any type of argument, with the condition that the two arguments have
the same type and supports all comparison operators. Provide enough code to compile
an executable that proves that everything works as intended.  

템플릿은 반드시 헤더 파일에 정의되어야합니다. 프로그램은 반드시 테스트가 포함된 main.cpp를 제출해야합니다. 이 파일은 평가 중에 변경되거나 변경될 수 있습니다. 이러한 함수들은 두 인수들이 동일한 타입이며 모든 비교 연산자를 지원하는 조건 하에서 모든 타입의 인수를 호출 할 수 있어야 합니다. 모든 것이 의도한대로 작동함을 증명하는 실행 파일을 컴파일하기에 충분한 코드로 제공할 수 있어야 합니다.  

# page 5

The following code:  
다음 코드 :  

```c++
int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}
```

Should output the following if you did well:  
잘 해냈다면 다음을 출력해야합니다:  

```sh
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
```

# page 6

## Chapter III
## 챕터 III
## Exercise 01: Iter
## 연습 문제 01: Iter

```
Exercise : 01
Exercise 01: Iter
Turn-in directory : ex01/
Files to turn in : iter.hpp, main.cpp and a Makefile
Allowed functions : None
```

```
연습 문제 : 01
연습 문제 01: Iter
제출 디렉터리 : ex01/
제출할 파일 : iter.hpp, main.cpp and a Makefile
허용 함수 : 없음
```

Write a function template iter that take 3 parameters and returns nothing. The first
parameter is the address of an array, the second one is the length of the array and the
third one is a function that is called on each element of the array.  

3개의 매개 변수를 사용하고 아무것도 반환하지 않는 `function template iter`를 작성하세요. 첫번째 매개 변수는 배열의 주소이고, 두번째는 배열의 길이이며 세 번째는 배열의 각 요소에서 호출되는 함수입니다.  

Wrap your work in an executable that proves that your function template iter works with any type of array and/or with an instantiated function template as a third parameter.  

당신의 `function template iter`가 모든 유형의 배열 및/또는 인스턴스화된 함수 템플릿을 세 번째 매개변수로서 작동함을 보여주는 실행 파일을 만들어 마무리 하세요.  

# page 7

## Chapter IV
## 챕터 IV
## Exercise 02: Array
## 연습 문제 02: 배열

```
Exercise 02: Array
Turn-in directory : ex02/
Files to turn in : Array.hpp, or Array.tpp, or Array.h, or anything that makes sens, plus anything necessary to build an executable, and a Makefile
Allowed functions : None
```

```
연습 문제 02: 배열
제출 디렉터리 : ex02/
제출할 파일 : Array.hpp, or Array.tpp, or Array.h, or anything that makes sens, plus anything necessary to build an executable, and a Makefile
허용 함수 : 없음
```

Write a class template Array that contains elements of type T and that allows the
following behavior:  

T 타입의 요소를 포함하고 다음 동작을 만족하는 `class template Array`를 작성해봅시다:  

- Construction with no parameter: creates an empty array.

- 매개변수가 없는 생성자: 빈 배열을 생성합니다.

- Construction with an unsigned int n as a parameter: creates an array of n elements, initialized by default. (Tip: try to compile int * a = new int();, then display *a.)

- `unsigned int n`을 매개 변수로 사용하는 생성자: 기본적으로 초기화되는 n 요소의 배열을 생성합니다. (팁 : `int * a = new int ();`로 컴파일 한 다음 `*a`를 출력해보세요.)

- Construction by copy and assignment operator. In both cases, modifying one of the two arrays after copy/assignment won’t affect anything in the other array.

- 복사 및 할당 연산자에 의한 생성자. 두 경우 모두 복사/할당 후 두 배열 중 하나를 수정해도 다른 배열에는 영향을 주지 않습니다.

- You MUST use the operator new[] for your allocation. You must not do preventive allocation. Your code must never access non allocated memory.

- 할당에 `new[]` 연산자를 반드시 사용해야합니다. 예방 할당을 해서는 안됩니다. 코드는 할당되지 않은 메모리에 액세스해서는 안됩니다.

- Elements are accessible through the operator[].

- `operator[]`를 통해 요소에 접근 가능 할 수 있어야 합니다.

- When accessing an element with the operator[], if this element is out of the limits, a std::exception is thrown.

- `operator[]`로 요소에 접근 할 때 이 요소가 제한을 밖에 있으면 `std::exception`이 발생합니다.

- A member function size that returns the number of elements in the array. This member function takes no parameter and does not modify the current instance in any way.

- `member function size`는 배열의 요소 수를 반환합니다. 이 멤버 함수는 매개 변수를 갖지 않으며 어떤 식으로든 현재 인스턴스를 수정하지 않습니다.

Wrap your work into an executable that proves that your class template works as intended.  

당신의 `class template`이 의도한대로 작동함을 보여주는 실행 파일을 만들어 마무리 하세요.  