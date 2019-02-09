#include "client.h"
#include <cstdlib>

void Client::set(long when) {
	usage = std::rand() % 3 + 1;
	begin = when;
}