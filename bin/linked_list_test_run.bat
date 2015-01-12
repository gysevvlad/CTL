del linked_list_test.exe linked_list_test.obj point.obj
cl ..\test\linked_list_test.c ..\support\point.c /I ..\include /I ..\support
linked_list_test
