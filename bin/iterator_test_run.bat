del iterator_test.exe iterator_test.obj point.obj
cl ..\test\iterator_test.c ..\support\point.c /I ..\include /I ..\support
iterator_test
