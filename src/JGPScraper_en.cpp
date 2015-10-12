#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream> 

using namespace std;

FILE *ulaz;
int pocetak, kraj;
ofstream a, b, c, d, e;

string osnovni("Departures.txt");
string spec1("Special departures 1.txt");
string spec2("Special departures 2.txt");
string spec3("Special departures 3.txt");
string spec4("Special departures 4.txt");

void rastavi(int br) {

	a << endl;
	if (br >= 1)
		b << endl;
	if (br >= 2)
		c << endl;
	if (br >= 3)
		d << endl;
	if (br == 4)
		e << endl;

}

void unos() {

	for (int cas = pocetak; cas <= kraj; cas++) {

		char niz[200];
		fgets(niz, 200, ulaz);

		if (strcmp(niz, "\n") == 0)
			--cas;
		else {

			int i = 0;
			while (i < strlen(niz)) {

				if (isdigit(niz[i])) {

					char temp[10];
					int t = 0;
					while (isdigit(niz[i]) && niz[i] != NULL)
						temp[t++] = niz[i++];
					temp[t] = '\0';
					if (strlen(temp) == 0 || strcmp(temp, "q") == 0)
						break;


					if (niz[i] != '*')
						if (cas < 10)
							a << "0" << cas << ":" << temp << endl;
						else
							a << cas << ":" << temp << endl;
					else if (niz[i + 1] != '\0' && niz[i + 2] != '\0'
						&& niz[i + 3] != '\0' && niz[i] == '*'
						&& niz[i + 1] == '*' && niz[i + 2] == '*' && niz[i + 3] == '*')
						if (cas < 10)
							e << "0" << cas << ":" << temp << endl;
						else
							e << cas << ":" << temp << endl;
					else if (niz[i + 1] != '\0' && niz[i + 2] != '\0'
						&& niz[i] == '*' && niz[i + 1] == '*' && niz[i + 2] == '*')
						if (cas < 10)
							d << "0" << cas << ":" << temp << endl;
						else
							d << cas << ":" << temp << endl;
					else if (niz[i + 1] != '\0' && niz[i] == '*' && niz[i + 1] == '*')
						if (cas < 10)
							c << "0" << cas << ":" << temp << endl;
						else
							c << cas << ":" << temp << endl;
					else if (niz[i] == '*')
						if (cas < 10)
							b << "0" << cas << ":" << temp << endl;
						else
							b << cas << ":" << temp << endl;

				}

				++i;
			}

		}

	}
}

void dan(char k[]) {

	if (a.is_open())
		a << k << ":" << endl;
	if (b.is_open())
		b << k << ":" << endl;
	if (c.is_open())
		c << k << ":" << endl;
	if (d.is_open())
		d << k << ":" << endl;
	if (e.is_open())
		e << k << ":" << endl;

	unos();

}

void zatvori() {

	fclose(ulaz);

	if (a.is_open())
		a.close();
	if (b.is_open())
		b.close();
	if (c.is_open())
		c.close();
	if (d.is_open())
		d.close();
	if (e.is_open())
		e.close();

}

void main() {

	cout << "*** JGPScraper - laxsrbija ***";

	char ans;

	do {

		cout << endl;

		char naziv[50];
		cout << endl << "Enter file name: ";
		cin >> naziv;

		ulaz = fopen(naziv, "r");

		char linija[10];
		fscanf(ulaz, "%s", linija);
		cout << "Processing line " << linija << ":" << endl;

		strcat(linija, " - ");

		string osnovniA(linija);
		osnovniA += osnovni;
		string spec1A(linija);
		spec1A += spec1;
		string spec2A(linija);
		spec2A += spec2;
		string spec3A(linija);
		spec3A += spec3;
		string spec4A(linija);
		spec4A += spec4;

		int spec;
		fscanf(ulaz, "%d", &spec);

		if (spec > 4) {
			spec = 4;
			cout << "Special departures set to 4." << endl;
		}
		else if (spec < 0) {
			spec = 0;
			cout << "Special departures set to 0." << endl;
		}
		else
			cout << "Special departures set to " << spec << "." << endl;

		a.open(osnovniA, ofstream::out);
		if (spec >= 1)
			b.open(spec1A, ofstream::out);
		if (spec >= 2)
			c.open(spec2A, ofstream::out);
		if (spec >= 3)
			d.open(spec3A, ofstream::out);
		if (spec == 4)
			e.open(spec4A, ofstream::out);

		fscanf(ulaz, "%d", &pocetak);
		cout << "First departure set to: " << pocetak << endl;
		fscanf(ulaz, "%d", &kraj);
		cout << "Last departure set to: " << kraj << endl;

		dan("WEEKDAY");
		rastavi(spec);
		dan("SATURDAY");
		rastavi(spec);
		dan("SUNDAY");

		zatvori();

		cout << "OK!" << endl;

		cout << endl << "Process more lines (y/n)? ";
		cin >> ans;

	} while (ans == 'y');

}