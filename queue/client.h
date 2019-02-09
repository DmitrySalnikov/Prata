#pragma once

#include <cstdlib>
#include <ctime>

class Client {
public:
	Client() { begin = usage = 0; }
	
    void set(long when) {
    	usage = std::rand() % 3 + 1;
	    begin = when;
    }
	
    long start() const { return begin; }

	int hold() const { return usage; }

private:
	long begin;
	int usage;

};
