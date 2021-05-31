#include <sys/socket.h>
#include <unistd.h>
#include <string>


auto main(int argc, char* argv[]) -> int{
	
	auto address = argv[1];
	auto port = static_cast<uint16_t>(std::stoi(argv[2]));
	
	auto sock = socket(AF_INET,SOCK_STREAM,0);
	
	shutdown(sock,SHUT_RDWR);
	close(sock);
	
    return 0;	
}
