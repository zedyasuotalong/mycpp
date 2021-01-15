#ifndef __EXERCISE_H__
#define __EXERCISE_H__
class Cow
{
	private:
		char name[20];
		char * hobby;
		double weight;
	public:
		Cow();
		Cow(const char *nm, const char *hb, double wt);
		Cow(const Cow &);
		~Cow();
		Cow & operator=(const Cow &);
		void ShowCow() const;
};
#endif
