#pragma once

template <typename T1, typename T2>
class Pair {
private:
	T1 a;
	T2 b;
public:
	T1 & first() { return a; }
	T2 & second() { return b; }
	T1 first() const { return a; }
	T2 second() const { return b; }
	Pair(T1 const & x, T2 const & y) : a(x), b(y) {}
	Pair() {}
};