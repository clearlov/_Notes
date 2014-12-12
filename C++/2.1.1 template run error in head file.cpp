/* http://weibo.com/1651714954/BpJn5uCeG

it seems like that you can use template in head file  */


// echo.h
#pragma once
template <typename T>
void echo(const T &x);

// echo.cpp
#include <iostream>
#include "echo.h"
template <class T>
void echo(const T &x){
	std::cout << x << std::endl;
}

// Source.cpp
#include <iostream>
#include "echo.h"
int main(){
	echo("10");
	system("PAUSE");
	return 0;
}

/*
 it'll run error in VS
 Error	1	error LNK2019: unresolved external symbol "void __cdecl echo<char const [3]>(char const (&)[3])" (??$echo@$$BY02$$CBD@@YAXAAY02$$CBD@Z) referenced in function _main
 and 
 Error	2	error LNK1120: 1 unresolved externals


 and in  G++
 
Source.cpp:(.text+0x17): undefined reference to `void echo<int>(int const&)'
collect2: error: ld returned 1 exit status
 
 */