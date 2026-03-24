# cpp_modules
42 Vienna assigments.

Collection of all the C++ entry level projects designed to learn the foundations of the language

1. cpp00 - say hello to C++ and make your own phonebook (ex01)
2. cpp01 - use external files and learn how to allocate and delete objects in a C++ way
3. cpp02 - build your own first fixed point numbers, overlad operators
4. cpp03 - inheritance, multi inheritance and understandig of linkage at compilation or run time
5. cpp04 - polymorphism and how to manage classes via their super classes

### Useful command

nice and quick way to make all the builds once you are at the root of the repo :) :

```
for i in `find -maxdepth 2 -type d | grep /ex`; do make -C $i; done
```
and to clean them:
```
for i in `find -maxdepth 2 -type d | grep /ex`; do make -C $i fclean; done
```
