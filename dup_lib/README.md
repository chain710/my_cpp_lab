# 多SO包含同名符号

##case1
 两个全局变量(global_my_string)处于同一地址，doublefree

##case2
 两个静态全局变量处于不同地址，正常

##case3
 libmidware静态链接libmy_string_static.a, case3.1.out动态链接libmidware.so，正常

 注意：调换-lmidware -lmy_string的顺序导致多了一个flag静态变量(case3.2.out)，在同一块内存构造两次，doublefree

##case4
 dlopen一个路径不同，但是内容一样的so，全局变量在不同的内存地址构造，但是static成员会在同一块地址构造，doublefree

##case5
 global_my_string全局变量用extern修饰，case5.out中之有一份，正常

##case6
 和case4类似，flag改为const static，依然在同一地址构造，doublefree

##case7
 引入midware，libmidware动态链接libmy_string，case7.out动态链接libmy_string

 dlopen libmidware，const static FLAG还是用一份，正常

##case8
 midware静态链接libmy_string，case8.out也静态链接libmy_string
 
 dlopen libmidware，有两份FLAG，但是不同地址，正常

##case9
 libmidware静态链接libmy_string，case9.1.out静态链接libmy_string，动态链接midware

 libmidware_plugin动态链接lib_mystring

 dlopen libmidware_plugin，有两个FLAG在同一块地址构造、析构，doublefree

 如果调换链接顺序，不用dlopen就有两个FLAG，在同一块地址构造、析构，doublefree
 