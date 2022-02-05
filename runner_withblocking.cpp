#include <iostream>
#include "NetworkRouter.h"

int main() {
	NetworkRouter net;

	net.loadBlockedAddresses("blocked.txt");
	// std::cout << "started program" << std::endl;
	net.receiveRequests(std::cin);
	// std::cout << "receive request complete" << std::endl;
	net.processRequests();
	// std::cout << "process request complete" << std::endl;
	net.sendRequests(std::cout);
	// std::cout << "send request complete" << std::endl;

	return 0;
} 