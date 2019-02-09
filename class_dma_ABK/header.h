#pragma once

#include <iostream>

class DMA {
	char * label;
	int rating;
public:
	DMA(const char * l="Null", int r=0);
	DMA(const DMA &);
	virtual ~DMA() { delete [] label; }
	DMA & operator=(const DMA &);
	virtual void view() const =0;
};

class BaseDMA : public DMA {
public:
	BaseDMA(const char * l="Null", int r=0) : DMA(l, r) {}
	BaseDMA(const DMA & bd) : DMA(bd) {}
	virtual void view() const;	
};

class LacksDMA : public BaseDMA {
	char * color;
public:
	LacksDMA(const char * c="Blank", const char * l="Null", int r=0);
	LacksDMA(const char * c, const DMA &);
	LacksDMA(const LacksDMA &);
	virtual ~LacksDMA() { delete [] color; }
	LacksDMA & operator=(const LacksDMA &);
	virtual void view() const;
};

class HasDMA : public DMA {
	char * style;
public:
	HasDMA(const char * s="None", const char * l="Null", int r=0);
	HasDMA(const char * s, const DMA &);
	HasDMA(const HasDMA &);
	virtual ~HasDMA() { delete [] style; }
	HasDMA & operator=(const HasDMA &);
	virtual void view() const;
};