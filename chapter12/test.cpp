#include <iostream>
//#include <string>
#include <cstring>
//#include <cmath>
using namespace std;
/*************************Class StringBad***************************/
class StringBad {
	private:
		char *str;
		int len=0;
		static int num_strings;
	public:
		int length() const {return len;}
		StringBad(const char * s = "");
		StringBad(const StringBad &);
		~StringBad();
		StringBad & operator=(const StringBad &b);
		StringBad & operator=(const char *s);
		const StringBad operator+(const StringBad & b) const;
		friend ostream & operator<<(ostream & os, const StringBad & b);
		friend bool operator<(const StringBad & a, const StringBad & b);
		friend bool operator>(const StringBad & a, const StringBad & b);
		friend bool operator==(const StringBad & a, const StringBad & b);
		char & operator[](int n);
		const char & operator[](int n) const;
		static int howMany();
};
int StringBad::howMany() { return num_strings; }
const StringBad StringBad::operator+(const StringBad & b) const {
	char buf[1024] = "";
	strcpy(buf, this->str);
	strcpy(buf+this->len, b.str);
	return StringBad(buf);
}
#if 1
StringBad::StringBad(const char *s) {
	len = strlen(s);
	if (len == 0) str = 0;
	else {
		str = new char[len + 1];
		strcpy(str, s);
	}
	num_strings++;
	cout<<num_strings<<" : ("<<s<<") was created\n";
}
#endif
StringBad::StringBad(const StringBad &b) {
	len = b.len;
	str = new char[len + 1];
	strcpy(str, b.str);
	num_strings++;
	cout<<"copy constructor "<<num_strings<<" : "<<str<<" was created\n";
}
StringBad::~StringBad() {
//	cout<<str<<" was deleted. ["<<--num_strings<<"] string left\n";
	delete []str;
}
StringBad & StringBad::operator=(const StringBad &b) {
	cout<<"assign operator for StringBad &"<<endl;
	if (this == &b)
	return *this;
	if (str)
		delete [] str;
	len = b.len;
	str = new char[len + 1];
	strcpy(str, b.str);
	return *this;
}
#if 1
StringBad & StringBad::operator=(const char *s) {
	cout<<"assign operator for char *"<<endl;
	delete [] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	return *this;
}
#endif
char & StringBad::operator[](int i)
{
	return str[i];
}
const char & StringBad::operator[](int i) const
{
	return str[i];
}
ostream & operator<<(ostream & os, const StringBad & b) {
	os<<b.str;
	return os;
}
void callme1(StringBad & rsb) {
	cout<<"String passed by reference:\n";
	cout<<" \""<<rsb<<"\"\n";
}
void callme2(StringBad sb) {
	cout<<"String passed by value:\n";
	cout<<" \""<<sb<<"\"\n";
}
bool operator<(const StringBad & a, const StringBad & b) {
	return (strcmp(a.str, b.str)<0);
}
bool operator>(const StringBad & a, const StringBad & b) {
	return (strcmp(a.str, b.str)>0);
}
bool operator==(const StringBad & a, const StringBad & b) {
	return (strcmp(a.str, b.str)==0);
}
int StringBad::num_strings = 0;
int main()
{
	cout<<"Start of main()\n";
	StringBad s1;
	s1 = "asdasd";
	s1[2] = 'E';
//	callme1(s1);
	callme2(s1);
	cout<<s1<<endl;
	cout<<"************************\n";
	StringBad s5=s1;
	cout<<"************************\n";
	StringBad s2, s3;
	s2 = "AAAAAA";
	cout<<s2<<endl;
	s3 = s1+s2;
	const StringBad s4("const obj");
	cout<<s4<<endl;
	cout<<(s1+s2)<<endl;

	cout<<"End of main()\n";

	return 0;
}
