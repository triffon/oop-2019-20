OOP week7 exercise
Are we recording?


Questions?


Recap
What are streams?
Data with some order. Could be of different types.
How do streams work in C++?
With internal buffers containing parts of the file opened and index to the position we have gotten to. This allows us to continue reading/writing where we left.
Demos:
Ofstream
Ifstream
Binary vs Text files


Binary files
* Allow random access because everything is fixed size
* Sometimes waste more space because everything is fixed size
* Cannot be read easily(from a text editor)


Text files
* We have to read everything in sequence because we don’t know what ends where
* Can save space
* Everyone can read them


More to show if we have time left:
* Stringstream
* interfaces as contracts
* Diamond problem (Virtual inheritance to solve it)
* Move semantics