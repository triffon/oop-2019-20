### Why do we include .h files rather than .cpp files (for instance in main).
While you can include .cpp files as you mentioned, this is a bad idea.

As you mentioned, declarations belong in header files. These cause no problems when included in multiple compilation units because they do not include implementations. Including a the definition of a function or class member multiple times will normally cause a problem (but not always) because the linker will get confused and throw an error.

What should happen is each .cpp file includes definitions for a subset of the program, such as a class, logically organized group of functions, global static variables (use sparingly if at all), etc.

Each compilation unit (.cpp file) then includes whatever declarations it needs to compile the definitions it contains. It keeps track of the functions and classes it references but does not contain, so the linker can resolve them later when it combines the object code into an executable or library.

Example

Foo.h -> contains declaration (interface) for class Foo.
Foo.cpp -> contains definition (implementation) for class Foo.
Main.cpp -> contains main method, program entry point. This code instantiates a Foo and uses it.
Both Foo.cpp and Main.cpp need to include Foo.h. Foo.cpp needs it because it is defining the code that backs the class interface, so it needs to know what that interface is. Main.cpp needs it because it is creating a Foo and invoking its behavior, so it has to know what that behavior is, the size of a Foo in memory and how to find its functions, etc. but it does not need the actual implementation just yet.

The compiler will generate Foo.o from Foo.cpp which contains all of the Foo class code in compiled form. It also generates Main.o which includes the main method and unresolved references to class Foo.

Now comes the linker, which combines the two object files Foo.o and Main.o into an executable file. It sees the unresolved Foo references in Main.o but sees that Foo.o contains the necessary symbols, so it "connects the dots" so to speak. A function call in Main.o is now connected to the actual location of the compiled code so at runtime, the program can jump to the correct location.

If you had included the Foo.cpp file in Main.cpp, there would be two definitions of class Foo. The linker would see this and say "I don't know which one to pick, so this is an error." The compiling step would succeed, but linking would not. (Unless you just do not compile Foo.cpp but then why is it in a separate .cpp file?)

Finally, the idea of different file types is irrelevant to a C/C++ compiler. It compiles "text files" which hopefully contain valid code for the desired language. Sometimes it may be able to tell the language based on the file extension. For example, compile a .c file with no compiler options and it will assume C, while a .cc or .cpp extension would tell it to assume C++. However, I can easily tell a compiler to compile a .h or even .docx file as C++, and it will emit an object (.o) file if it contains valid C++ code in plain text format. These extensions are more for the benefit of the programmer. If I see Foo.h and Foo.cpp, I immediately assume that the first contains the declaration of the class and the second contains the definition.

### What is linker 
I have found this article with explanation about Linker and some schemes how it works. 
https://www.learncpp.com/cpp-tutorial/introduction-to-the-compiler-linker-and-libraries/
