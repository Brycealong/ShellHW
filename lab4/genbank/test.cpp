#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

char* copy_lines(char str[], int i1, int i2);
int find_key(char str1[], char str2[]);
string readFileIntoString(char* filename);

#define MAX 180000

class Info
{
public:
	char* LOCUS, * ORGANISM, * CDS, * ORIGIN;
};

int main()
{
    //read the file and convert it to a character string called 'geb'
	char* fn = "NM000207.gb";
	string str;
	str = readFileIntoString(fn);
	char geb[MAX];
	strcpy(geb, str.c_str());

	//create a struct called 'e' and assign value to each element
	Info e;
	e.LOCUS = copy_lines(geb, find_key(geb, "LOCUS"), find_key(geb, "DEFINITION"));
	e.ORGANISM = copy_lines(geb, find_key(geb, "ORGANISM"), find_key(geb, "REFERENCE"));
	e.CDS = copy_lines(geb, find_key(geb, "CDS"), find_key(geb, "sig_peptide"));
	e.ORIGIN = copy_lines(geb, find_key(geb, "ORIGIN"), strlen(geb));

	cout << "What type of info do you want to see?(LOCUS, ORGANISM, CDS, ORIGIN)(Please use uppercase letters)\n";
	char key[20];
	cin >> key;

	if (key == "LOCUS")
		cout << e.LOCUS << endl;
	else if (key == "ORGANISM")
		cout << e.ORGANISM << endl;
	else if (key == "CDS")
		cout << e.CDS << endl;
	else if (key == "ORIGIN")
		cout << e.ORIGIN << endl;
	else
		cout << "Wrong Prompt! Please check again." << endl;
	return 0;
}

char* copy_lines(char str[], int i1, int i2)
{

    char* info = new char[MAX];
    for (int i = i1; i < i2; i++)
        info[i - i1] = str[i];
    return info;

    delete[]info;


}

int find_key(char str1[], char str2[])
{

	int i = 0, j = 0;

	for (int i, j; str1[i]; i++) {
		for (j; str2[j]; j++)
			if (str1[i + j] != str2[j]) break;
		if (!str2[j]) {
			return i;
			break;
		}
	}
}

string readFileIntoString(char* filename)
{
	ifstream ifile(filename);
	ostringstream buf;
	char ch;
	while (buf && ifile.get(ch))
		buf.put(ch);
	return buf.str();
}
