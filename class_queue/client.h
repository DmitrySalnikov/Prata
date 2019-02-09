#pragma once

class Client {
	long begin;
	int usage;
public:
	Client() { begin=usage=0; }
	void set(long);
	long start() const { return begin; }
	int hold() const { return usage; }
};