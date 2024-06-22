# automated-complexity-analysis

I believe that before going any further, a quick disclaimer is in order. If you are a programmer and landed on this repo, then you should know that it has been proven in a variety of ways that automating time complexity analysis for any conceivable program is impossible, with that said, it is possible to automate it with somewhat decent results if the kind of programs analysed are bounded in respect to their structure and the subset of their programming language's standard used to create it.

As you may infer by the repository's name, this tool's purpose is to automate the time complexity analysis of C++ programs and it was created as a result of the fact that my university required me to create and document a graduation project and that throughout my college years i was fascinated by DS&A and compiler design. 

## Table of contents
1. [How do i run this tool?](##How-do-i-run-this-tool?)
2. [Which kind of programs can the tool analyse?](##Which-kind-of-programs-can-the-tool-analyse?)
3. [How does it work?](##How-does-it-work?)

## How do i run this tool?
Although this tool was made using C++, Flex and Bison. You only need to have the gcc 9.4.0 compiler and the code contained in the src directory in order to make an executable, this is possible because Flex and Bison were only used to generate the C++ source code of the lexical and syntactical analysis modules and you may only install these tools if you want to modify how this modules behave.

In order to compile an executable you may download the files inside the src directory and execute the following command

`g++ -o analizadors analizadorSintactico.cpp analizadorLexico.cpp`

This will generate an executable called analizador, which in turn should be moved to the same directory of the programs to be analyzed, once on the target directory you may analyze the time complexity of a C++ source code file by executing analizador passing as an argument the file name.

`analizador [file_name.cpp]`

As a final note, if you need to recompile the .lex and .y files, you should ensure that you have lex v.2.6.4 and bison v.3.5.1 and execute the following commands in order.

`bison -d -o analizadorSintactico.cpp analizadorSintactico.y`

`lex -o analizadorLexico.cpp analizadorLexico.l` 

`g++ -o analizadors analizadorSintactico.cpp analizadorLexico.cpp` 


## Which kind of programs can the tool analyse?

As I mentioned earlier, automating time complexity analysis for any conceivable program has been proven impossible in a number of ways, for that reason it was decided from the begining that this tool would only analyze programs that used a subset of the C++ standard and were structured in a particular way.

You may take into account the following considerations before analysing a source code file.

- Recursive functions are not allowed, unless they use tail recursion
- Function overriding is not allowed 
- The use of global variables is not allowed
- Compiler directives (except the include directive) are not supported
- All libraries should be included using quotation marks i.e. #include "library_name.hpp"
- Namespaces are not allowed, thus the use of a using namespace std is required 
- user defined data structures such as structs and classes, as well of access modifiers, user-defined templates and other related features are not supported 
- The use of pointers and related syntax is not supported 
- Loops and if-else structures should use braces {} to bound the code to be executed by them
- Circular dependencies between functions should be avoided. I.e. if a() makes a call to b(), then b() or any function called as a result of b() can't call a()


The following features of the C++ programming language are allowed.

- The use of any primitive data type, such as  bool, int, long long int, float, long double and double
- user-defined functions
- Loops, specifically while and for
- flow control structures and keywords such as if, else, break, continue and return
- the use of compile time arrays (data_type identifier[size0]..[sizen]
- The use of arithmetic operators 
- the use of logic operators, except and or 
- The use of the cin/cout as output routines
- The following functions are supported and assumed to be implemented by the programming language (overriding them is not advised): swap(), min(), max(), lower_bound(), upper_bound() and sort()
- the stack container and the following methods: push(), pop(), top(), size()
- the vector container and the following methods: push_back(),pop_back(), size(), [], front(), back(), swap(), clear(), shrink_to_fit(), at()
- the map/unordered_map container and the following methods: insert(), [], clear()
- the set/multiset container and the following methods: insert(), erase(), size(), clear(), lower_bound(), upper_bound(), find(), count()
- the queue container and the following methods: size(), push(), pop(), front(), back()
- the string container and the following methods: push_back(), pop_back(), size(), [], front(), back(), swap(), clear(), shrink_to_fit(), at(), =
## How does it work?

For a more in depth text about how does it work, you can refer to the document on the report directory, this document was written in Spanish as per my university's graduation project guidelines, if you speak the language or found a way to get a good enough translation you can read this document in order to find out more about some design and implemention decisions.

This tool is divided into four main modules: lexical analysis, syntactical analysis, precedence and hierarchy analysis and complexity analysis.

The lexical and syntactical analysis modules  receive the code as an input and build an abstract syntax tree(AST), such representation facilitates algorithmically obtaining characteristics about the code being analysed.

Once the lexical and syntactical analysis modules are done, the precedence and hierarchy analysis runs a modified tarjan algoritmh on the AST obtaining as a result wether or not the code contains circular dependencies between functions and a valid topological ordering of the function calls.

Finally, the complexity analysis module obtains an approximate time complexity by traversing the AST, keeping track of the growth rate of variables in each scope and every function's time complexity.