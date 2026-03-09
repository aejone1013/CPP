# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## 빌드

각 exercise는 독립적인 Makefile을 가지며, 해당 디렉토리에서 실행한다.

```bash
cd cpp05/ex02
make        # 빌드
make re     # 클린 빌드
make fclean # 바이너리 + 오브젝트 삭제
```

표준 플래그: `-Wall -Wextra -Werror -std=c++98` (전 모듈 공통)

## cpp05 — 예외 처리

**구조:** `Bureaucrat` ↔ `AForm(추상)` ← `ShrubberyCreationForm` / `RobotomyRequestForm` / `PresidentialPardonForm`

- `Bureaucrat`의 등급 범위는 1(최고)~150(최저). `validateGrade()`가 범위 위반 시 중첩 예외(`GradeTooHighException` / `GradeTooLowException`) throw.
- `AForm::execute()`는 서명 여부(`_signed`)와 실행 등급을 검증한 뒤 순수 가상 `executeAction()`을 호출.
- `ShrubberyCreationForm::executeAction()`은 `<target>_shrubbery` 파일을 생성한다 (`make clean`이 제거).
- `RobotomyRequestForm`은 50% 확률을 사용한다. `srand`는 `main()` 상단에서 한 번만 호출.
- ex00/ex01/ex02는 각각 독립된 디렉토리이며 소스를 공유하지 않는다.

## cpp06 — 타입 캐스팅

**구조:** `ScalarConverter` (static 메서드만, 인스턴스화 불가) / `Serializer` / 동적 타입 식별

- `ScalarConverter::convert()`는 입력 문자열을 `isPseudoLiteral` → `isChar` → `isInt` → `isFloat` → `isDouble` 순서로 판별한다.
- `isFloat`/`isDouble`는 공통 헬퍼 `isDecimalDigits(s, start, end)`를 사용 (substr 할당 없음).
- 정수 여부 판단은 `isWholeNumber(double)`로 통일 (`std::fmod` 사용, `static_cast<int>` UB 없음).
- ex01: `uintptr_t`를 통한 포인터 직렬화/역직렬화.
- ex02: `dynamic_cast`로 타입 식별, `try/catch` 패턴.

## cpp07 — 템플릿

- ex00: `swap`, `min`, `max` 함수 템플릿 (`whatever.hpp`).
- ex01: `iter(arr, len, func)` — 배열+길이+함수 포인터를 받는 템플릿 함수.
- ex02: `Array<T>` — 동적 배열 템플릿 클래스, 범위 초과 시 `std::exception` throw.

## cpp08 — STL 컨테이너 & 알고리즘

- ex00: `easyfind<T>(container, value)` — `std::find` 래퍼, 미발견 시 예외.
- ex01: `Span` — `std::vector<int>` 내부 보관. `shortestSpan()`은 정렬 후 인접 차이, `longestSpan()`은 단일 패스 min/max.
- ex02: `MutantStack<T>` — `std::stack`을 상속해 `begin()`/`end()` 등 iterator를 노출 (`this->c` 접근).

## cpp09 — STL 컨테이너 활용

- ex00 (`btc`): `std::map<string, double>`으로 CSV 데이터베이스 보관. `getRate()`는 `lower_bound` 단일 조회로 가장 가까운 과거 날짜 검색. 실행: `./btc input.csv` (data.csv 필요).
- ex01 (`RPN`): `std::stack<int>`을 `calculate()` 내부 지역 변수로 사용. 숫자는 0~9 한 자리만 허용.

## 공통 패턴

- **Orthodox Canonical Form**: 기본/복사 생성자, 대입 연산자, 소멸자 — 모든 클래스에 구현.
- **중첩 예외 클래스**: `std::exception` 상속, `what() const throw()` 오버라이드.
- 인스턴스화 방지 클래스(cpp06)는 생성자/소멸자를 모두 private으로 선언.
