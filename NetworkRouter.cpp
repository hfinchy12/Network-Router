#include "NetworkRouter.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>


void NetworkRouter::loadBlockedAddresses(std::string filename){
	std::string line;
	std::ifstream fin(filename);
	while(getline(fin, line)){
		blocked_addresses.push_back(line);
	}
}


// receiveRequests:
//   - "receives" network requests by reading from the standard input
void NetworkRouter::receiveRequests(std::istream &is) {
	std::string line; // get one line at a time
	std::stringstream ss; // setup stringstream as an easy way to parse a line
	std::string src; 
	std::string dst; 
	std::string cks; 
	std::string dat; 
	// as long as new data is being received, do:
	while (getline(is,line)) {
		ss << line; // put the entire line into a string stream
		// use the space separations to get the first few packet values
		getline(ss, src, ' ');
		getline(ss, dst, ' ');
		getline(ss, cks, ' ');
		getline(ss, dat); // whatever remains is data
		// queue the request
		received_requests.push_back(NetworkPacket(src,dst,cks,dat)); 
		ss.clear();
	}
}

// processRequests:
//   - function checks received requests and determines if internal or external traffic
void NetworkRouter::processRequests() {
	NetworkPacket req;
	// process all received requests
	while (!received_requests.empty()) {
		bool blocked = false;
		req = received_requests.pop_front(); // Question: What does this do?
		for(size_t i = 0; i < blocked_addresses.size(); i++){
			// std::cout << "src: " << req.source << "   blocked: " << blocked_addresses.at(i) << std::endl;
			if(req.source == blocked_addresses.at(i)){
				// std::cout << "[MATCH FOUND]" << std::endl;
				blocked = true;
			}
		}
		size_t foundA = (req.data).find(";");
		size_t foundB = (req.data).find("POST");
		if(foundA != std::string::npos && foundB != std::string::npos){
			// Invalid character detected. Invalidating request.
			continue;
		}
		if(blocked){
			continue;
		}
		if (req.destination.compare(0,4,"10.0") == 0) { // Internal traffic starts with 10.0
			internal_requests.push_back(req);
		} else { // Everything else is external and will be sent to another node
			external_requests.push_back(req);
		}
	}
}

// sendRequests:
//   - member function to "send" requests to standard output
void NetworkRouter::sendRequests(std::ostream &os) {
	// "send" internal ones first
	os << "Internal Requests:\n";
	while (!internal_requests.empty()) {
		os << internal_requests.pop_front();
	}
	// "send" external ones
	os << "\nExternal Requests:\n";
	while (!external_requests.empty()) {
		os << external_requests.pop_front();
	}
}