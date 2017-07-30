 Summary
A class template is a class that is implemented with one or more type parameters left open.
To use a class template, you pass the open types as template arguments. The class template is then
instantiated (and compiled) for these types.
For class templates, only those member functions that are called are instantiated.
You can specialize class templates for certain types.
You can partially specialize class templates for certain types.
You can define default values for class template parameters. These may refer to previous template
parameters