#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <array>

using namespace std;

auto cat_to_stdout(string const path) -> void {
	auto const in_fd = open(path.c_str(), O_RDONLY);
	if(in_fd == -1){
		return;
	}

	array<char, 4096> buf{0};
	auto flag = true;
	while(flag){
	
		auto const bytes_in = read(in_fd, buf.data(), buf.size());
		if(bytes_in == -1){
			break; 
		}
		if(bytes_in == 0){
			break; 
		}
		
		auto const bytes_out = write(1, buf.data(), bytes_in);
		while(bytes_out < bytes_in){
			
			if(bytes_out == -1){
				break;
			}
			if(bytes_out > bytes_in){
				break;
			}
		}
		flag = false;
	}
	close(in_fd);
}
auto main(int argc, char* argv[]) -> int {
	
		
	for(auto i = int{1}; i < argc; ++i) {
		cat_to_stdout(argv[i]);
	}
	
	cout << "\n";
		
	return 0;
}


