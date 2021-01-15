#ifndef __DMA_H__
#define __DMA_H__
#include <iostream>
class baseDMA
{
	private:
		char *label;
		int rate;
	public:
		baseDMA(const char *l = "null", int r = 0);
		baseDMA(const baseDMA &);
		virtual ~baseDMA();
		baseDMA & operator=(const baseDMA &);
		friend std::ostream & operator<<(std::ostream & o, const baseDMA &b);
};
class lacksDMA : public baseDMA
{
	private:
		enum {MAX_LEN = 40};
		char color[MAX_LEN];
	public:
		lacksDMA(const char *c = "black", const char *l = "null", int r = 0);
		lacksDMA(const char *c , const baseDMA & b);
		friend std::ostream & operator<<(std::ostream & o, const lacksDMA &l);
};
class hasDMA : public baseDMA
{
	private:
		char *style;
	public:
		hasDMA(const char *s = "none", const char *l = "null", int r = 0);
		hasDMA(const char *s , const baseDMA &b);
		hasDMA(const hasDMA &);
		virtual ~hasDMA();
		hasDMA & operator=(const hasDMA &);
		friend std::ostream & operator<<(std::ostream & o, const hasDMA & h);
};

#endif
