del map_test.exe map_test.obj CTL_string.obj point.obj
cl ..\test\map_test.c ..\sourse\CTL_string.c ..\support\point.c /I ..\include /I ..\support
map_test
