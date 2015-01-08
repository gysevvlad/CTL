del iterator_example.exe iterator_example.obj point.obj
cl ..\example\*.c /I ..\include
if errorlevel 0 iterator_example
