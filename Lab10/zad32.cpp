#include <iostream>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

char buff[64] = {0};

auto signal_handler(int x){
		auto pathname = "plik.txt";
		
		auto file = open(pathname, 0);
		
		
		
		auto readed_value = read(file, buff, 64);
		close(file);
}

auto main(int argc, char* argv[]) -> int {
		auto pathname = "plik.txt";
		
		auto file = open(pathname, 0);
		
		
		auto readed_value = read(file, buff, 64);
		close(file);
		signal()
		while(true){
			std::cout << buff << "\n";
			sleep(1);
		}
		
		
		
		return 0;
}
