#pragma once

#include <stdexcept>
#include <cstring>
#include <algorithm>

class Sales {
public:
    static int const MONTHS = 12;
    
    class BadIndex : public std::logic_error {
    public:
        explicit BadIndex(int bi, char const * str = "Wrong index in Sales") : std::logic_error(str), bi_(bi) {}
        int bi_val() const { return bi_; }

    private:
        int bi_;
    };

    explicit Sales(int year = 0) : year_(year) { for (int i = 0; i < MONTHS; ++i) gross_[i] = 0; }
    Sales(int year, double const * gross, int size) : year_(year) {
        int months = MONTHS;
        int inf = std::min(months, size);
        for (int i = 0; i < inf; ++i)
            gross_[i] = gross[i];
        for (int i = inf; i < MONTHS; ++i)
            gross_[i] = 0;
    }
    virtual ~Sales() {}
    int year() const { return year_; }
    virtual double operator[](int i) const throw (std::logic_error) {
        if (i < 0 || i >= MONTHS)
            throw BadIndex(i);

        return gross_[i];
    }
    virtual double & operator[](int i) throw (std::logic_error) {
        if (i < 0 || i >= MONTHS)
            throw BadIndex(i);

        return gross_[i];
    }

private:
    int year_;
    double gross_[MONTHS];
};

class LabeledSales : public Sales {
public:
    static const int STRLEN = 50;
    class LabeledBadIndex : public Sales::BadIndex {
    public:
        LabeledBadIndex(char const * label, int bi, char const * str = "Wrong index in LabeledSales") : Sales::BadIndex(bi, str) {
            std::strcpy(label_, label);   
        }
        char const * label() const { return label_; }

    private:
        char label_[STRLEN];
    };
    explicit LabeledSales(char const * label = "none", int year = 0) : Sales(year) {
        std::strcpy(label_, label);
    }
    LabeledSales(char const * label, int year, double const * gross, int size) : Sales(year, gross, size) {
        std::strcpy(label_, label);
    }
    virtual ~LabeledSales() {}
    char const * label() const { return label_; }
    virtual double operator[](int i) const throw (std::logic_error) {
        if (i < 0 || i >= MONTHS)
            throw LabeledBadIndex(label(), i);

        return Sales::operator[](i);
    }
    virtual double & operator[](int i) throw (std::logic_error) {
        if (i < 0 || i >= MONTHS)
            throw LabeledBadIndex(label(), i);

        return Sales::operator[](i);
    }

private:
    char label_[STRLEN];
};
