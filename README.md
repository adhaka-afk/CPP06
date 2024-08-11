# CPP06


## Description:

This module focuses on type conversion, serialization, and type identification in C++. Through a series of exercises, it aims to reinforce understanding of C++ casting, type conversion between scalar types, pointer manipulation, and dynamic type identification without using the typeinfo header.
## Overview:

The module consists of three exercises:

## Exercise 00: Conversion of Scalar Types
- Objective: Implementing a ScalarConverter class to convert string representations of C++ literals into various scalar types.
  
**Key Features:**
- The class contains a single static method convert that takes a string as input and converts it to the following types:
  
  char
  
  int
  
  float
  
  double
- Handles special floating-point values like -inff, +inff, and nanf for float, and -inf, +inf, and nan for double.
- Provides informative output when a conversion is impossible or results in a non-displayable char.
- The class is non-instantiable, as it doesn’t need to store any data.

## Exercise 01: Serialization
- Objective: Implementing a Serializer class to convert a pointer to a scalar type and back, facilitating serialization.
  
**Key Features:**
- Contains two static methods:
    - uintptr_t serialize(Data* ptr);
    - Data* deserialize(uintptr_t raw);
- The serialize method converts a pointer to an unsigned integer (uintptr_t).
- The deserialize method converts an unsigned integer back to a pointer of type Data*.
- Ensures that the deserialize() result matches the original pointer passed to serialize().

## Exercise 02: Identify Real Type
- Objective: Implementing a base class and derived classes to identify the real type of an object at runtime.

**Key Features:**
- Implements a Base class with a virtual destructor and three derived classes: A, B, and C.
- Provides the following functions:
- Base* generate(void); - Randomly generates an instance of A, B, or C and returns it as a Base*.
- void identify(Base* p); - Identifies and prints the real type of the object pointed to by p.
- void identify(Base& p); - Identifies and prints the real type of the object referred to by p, without using pointers.
- Dynamic type identification is performed without relying on std::typeinfo, enforcing a deeper understanding of polymorphism and casting.

## File Structure: 
- ex00/: Contains the implementation of the ScalarConverter class.
- ex01/: Implements the Serializer class and the Data structure.
- ex02/: Contains the Base class, derived classes A, B, C, and functions for type identification.
- Makefile: Provided in each directory for compiling the respective exercises.
- main.cpp: Each directory contains a main.cpp file with test cases to demonstrate the functionality.

## Compilation and Execution:

Navigate to the Exercise Directory: Open a terminal and change to the directory of the exercise you want to run.
 ```bash
cd ex00  # Replace 'ex00' with the exercise directory you want to run
```
Compile the Code: Use the provided Makefile to compile the code.
 ```bash
make
```
Run the Executable: After successful compilation, run the generated executable.
```bash
./scalar_converter_test  # Replace 'scalar_converter_test' with the name of the executable for the exercise
```
Verify Output: Check the output in the terminal to verify the correctness of the program.
   
Clean Up (Optional): To clean up the compiled files, you can use the clean/fclean target in the Makefile.
 ```bash
make clean
```
or 
 ```bash
make fclean
```

## Exercise Specifics:

- Type Conversion: Exercise 00 focuses on converting between different scalar types, handling edge cases like non-displayable characters and special floating-point values.
- Serialization: Exercise 01 emphasizes pointer manipulation and serialization, demonstrating how to safely convert pointers to scalar types and back.
- Type Identification: Exercise 02 showcases polymorphism and dynamic type identification without relying on RTTI (typeinfo), reinforcing the use of C++ casting techniques.

## 🚀 Next Project

[CPP07](https://github.com/adhaka-afk/CPP07)

## ⏳ Previous Project

[CPP05](https://github.com/adhaka-afk/CPP05)


