# Compilation

A compiler translates C source code into machine redeable code that can be executed by the target microcontroller.
 
## Preprocessing (.i file is output of this process)
- The C processor handles directives that begin with # (e.g. #include, #define, #ifdef).
- This is the first phase through which source code is passed. This phase includes :
- Removal of Comments
- Expansion of Macros
- Expansion of the included files.
- Conditional compilation

## Compiler (.s)
- The compiler takes the preprocessed source code and translates it into assembly language specfic to the target architecture.
- The output is an assembly language file.

## Assembler (.o)
- The assembler converts the assembly language code into machine code, which is a sequence of binary instructions directly understandable by the CPU.
- This machine code is typically stored in an object file (e.g. .o or .obj extension)
- Object files may contain unresolved references to functions or variables defined in other files or libraries.

## Linking 
- The linker combines one or object files with necessary library files.
- It resolves all external references, ensuring that every function call and variable usuage points to its correct definition.
- The final output of the linking stage is and exectable file.
- This executable file can then be loaded into memory and run by operating system.


