#pragma once

#include <iostream>
#include <stdexcept>

class BadHmean : public std::logic_error {
public:
    BadHmean (char const * str) : std::logic_error(str) {}
};

class BadGmean : public std::logic_error {
public:
    BadGmean (char const * str) : std::logic_error(str) {}
};
