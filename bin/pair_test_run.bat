del pair_test.exe pair_test.obj point.obj
cl ..\test\pair_test.c ..\support\point.c /I ..\include /I ..\support
pair_test
