#include<iostream>
#include<cstdio>
#include<cmath>
#define mod 1000000007
using namespace std;
class player
{
	private :
	char NamePrefix[][5] = {

    "", //who said we need to add a prefix?

    "bel", //lets say that means "the good"

    "nar", //"The not so good as Bel"

    "xan", //"The evil"

    "bell", //"the good"

    "natr", //"the neutral/natral"

    "ev", //Man am I original

};

    char NameSuffix[][5] = {

    "", "us", "ix", "ox", "ith",

    "ath", "um", "ator", "or", "axia",

    "imus", "ais", "itur", "orex", "o",

    "y"

};
const char NameStems[][10] = {

    "adur", "aes", "anim", "apoll", "imac",

    "educ", "equis", "extr", "guius", "hann",

    "equi", "amora", "hum", "iace", "ille",

    "inept", "iuv", "obe", "ocul", "orbis"

};

void NameGen(char *PlayerName);

char get_Char(void);
 char name[21]; 
 public :
void init()
{
	NameGen(name);

}
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
int main()
{

	int n;
	cout<<"robotic war";
	cout<<"------------";
	
	cin>>n;
	return 0;
}
