del iterator_example.exe iterator_example.obj point.obj
cl ..\examples\iterator_example.c ..\support\point.c /I ..\include /I ..\support
if errorlevel 0 iterator_example
