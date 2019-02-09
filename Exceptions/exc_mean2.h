#pragma once

#include <iostream>
#include <stdexcept>

class BadMean : public std::logic_error {
public:
    BadMean (char const * str, double x, double y) : std::logic_error(str), x_(x), y_(y) {}
    virtual void description () const = 0;
protected:
    double x_;
    double y_;
};

class BadHmean : public BadMean {
public:
    BadHmean (double x, double y, char const * str = "Error in hmean(x, y): x = -y") : BadMean(str, x, y) {}
    virtual void description () const override final {
        std::cout << "Error in hmean(" << x_ << ", " << y_ << "): x = -y" << std::endl;
    }
};

class BadGmean : public BadMean {
public:
    BadGmean (double x, double y, char const * str = "Error in gmean(x, y): x or y is negative") : BadMean(str, x, y) {}
    virtual void description () const override final {
        using std::cout;
        std::cout << "Error in gmean(" << x_ << ", " << y_ << "): ";       
        if ((x_ < 0) && (y_ < 0))
            cout << "x < 0 and y < 0";
        else if (x_ < 0)
            cout << "x < 0";
        else 
            cout << "y < 0";
        cout << std::endl;
    }
};
