![banner_cpp_modules-13](https://github.com/diocode/42-cpp/assets/107859177/d3839718-5b51-4dd4-bb91-526e15ee5581)


<p align="center">
	<img src="https://img.shields.io/badge/status-finished-success?color=%2312bab9&style=flat-square"/>
	<img src="https://img.shields.io/badge/evaluated-00%20%2F%2000%20%2F%200000-success?color=%2312bab9&style=flat-square"/>
	<img src="https://img.shields.io/badge/score-000%20%2F%20000-success?color=%2312bab9&style=flat-square"/>
	<img src="https://img.shields.io/github/last-commit/diocode/42-Minishell?color=%2312bab9&style=flat-square"/>
	<a href='https://www.linkedin.com/in/diogo-gsilva' target="_blank"><img alt='Linkedin' src='https://img.shields.io/badge/LinkedIn-100000?style=flat-square&logo=Linkedin&logoColor=white&labelColor=0A66C2&color=0A66C2'/></a>
</p>

<p align="center">
	<a href="#about">About</a> •
	<a href="#how-to-use">How to use</a> •
	<a href="#norminette">Norminette</a>
</p>

## ABOUT

**C++ Object-Oriented Programming Course**

Welcome to my C++ Object-Oriented Programming (OOP) course repository! This project is designed to guide me through the fascinating journey of learning C++ with a strong foundation in OOP principles. The aim is to build on my existing programming knowledge, specifically if I'm already familiar with C, by extending it to C++. 

**Naming and Formatting Conventions**

- Exercise directories should follow the naming convention: `ex00`, `ex01`, ..., `exn`.
- Use Upper Camel Case format for class names. For example, class files should be named `ClassName.hpp` or `ClassName.cpp`.
- Header files must contain include guards to prevent double inclusion issues.
- All output messages should end with a newline character and be directed to the standard output.

**Coding Guidelines**

This course encourages exploration within the bounds of the C++ standard library, steering away from external libraries, including C++11 and later versions, as well as Boost libraries. Certain functions such as `*printf()`, `*alloc()`, and `free()` are prohibited to ensure you fully leverage C++'s capabilities.

**Key Concepts Covered**

- Namespaces, classes, member functions, std iostreams, and initialization lists.
- Memory management to prevent leaks.
- Designing classes in the Orthodox Canonical Form.
- Restriction on using the STL to specific modules (Module 08 and 09).

<br>

#### MAKEFILE COMMANDS
`make` or `make all` - Compile program **mandatory** files.

`make clean` - Delete all .o (object files) files.

`make fclean` - Delete all .o (object file) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.
