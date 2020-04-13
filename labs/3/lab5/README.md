# За какво ще си говорим днес:
- ще разгледаме миналото ви домашно
- ще разгледаме: ifstream, ofstream, fstream - кога се ползват, какви методи имат и ще напишем няколко примера


# Защо кастваме към (const char*)& при write и (char *)& при read (binary)
## Намерих това в една статия. Дано ви е полезно.

"Оnly write requires const char* because it ensures that resource buffer (s) will not be modified.

ostream& write (const char* s, streamsize n);

istream& read (char* s, streamsize n);

The reason of using char* is, a char is equivalent to a BYTE. So these function actually writes binary equivalent of data and thus mainly used for handling binary files."
