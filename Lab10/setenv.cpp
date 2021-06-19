#include <iostream>
#include <stdlib.h>
#include <unistd.h>

auto main(int argc, char* argv[]) -> int {
		auto name = argv[1];
		auto value = argv[2];
		auto oldShell = getenv("SHELL");
		
		if(name[0] != '-'){
			setenv(name, value, 1);
		}else{
			unsetenv(name + 1);
		}
		char* pointers[] = {oldShell, nullptr};
		
		execvp(oldShell, pointers);
		
		return 0;
}
