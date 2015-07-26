/*
HH:MM\n

*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream> 

using namespace std;

FILE *ulaz;
int pocetak, kraj;
ofstream a, b, c, d, e;

string osnovni("Osnovni polaci.txt");
string spec1("Specijalni polasci 1.txt");
string spec2("Specijalni polasci 2.txt");
string spec3("Specijalni polasci 3.txt");
string spec4("Specijalni polasci 4.txt");

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

	//cout << "UNOS POLAZAKA" << endl;
	
	for (int cas = pocetak; cas <= kraj; cas++) {

		char niz[200];
		fgets(niz, 200, ulaz);

		if (strcmp(niz, " \n") == 0) {
			//cout << "Preskocena linija" << endl;
			--cas;
		} 
		else {

			int i = 0;
			while (i < strlen(niz)) {

				if (isdigit(niz[i])) {

					char temp[10];
					int t = 0;
					while (isdigit(niz[i]) && niz[i] != NULL)
						temp[t++] = niz[i++];
					temp[t] = '\0';

					if (strlen(temp) == 0 || strcmp(temp, "99") == 0)
						break;

					if (niz[i] == '\0' || niz[i] == ',' || niz[i] == '.' || niz[i] == '\n')
						if (cas < 10)
							a << "0" << cas << ":" << temp << endl;
						else
							a << cas << ":" << temp << endl;
					else if (niz[i + 1] != '\0' && niz[i + 2] != '\0' && niz[i + 3] != '\0' && niz[i] == '*' && niz[i + 1] == '*' && niz[i + 2] == '*' && niz[i + 3] == '*')
						if (cas < 10)
							e << "0" << cas << ":" << temp << endl;
						else
							e << cas << ":" << temp << endl;
					else if (niz[i + 1] != '\0' && niz[i + 2] != '\0' && niz[i] == '*' && niz[i + 1] == '*' && niz[i + 2] == '*')
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

void radniDan() {

	//cout << "Unos: RADNI DAN" << endl;

	if (a.is_open())
		a << "RADNI DAN:" << endl;
	if (b.is_open())
		b << "RADNI DAN:" << endl;
	if (c.is_open())
		c << "RADNI DAN:" << endl;
	if (d.is_open())
		d << "RADNI DAN:" << endl;
	if (e.is_open())
		e << "RADNI DAN:" << endl;

	unos();

	//cout << "Unos zavrsen: RADNI DAN" << endl;

}

void subota() {

	//cout << "Unos: SUBOTA" << endl;

	if (a.is_open())
		a << "SUBOTA:" << endl;
	if (b.is_open())
		b << "SUBOTA:" << endl;
	if (c.is_open())
		c << "SUBOTA:" << endl;
	if (d.is_open())
		d << "SUBOTA:" << endl;
	if (e.is_open())
		e << "SUBOTA:" << endl;

	unos();

	//cout << "Unos zavrsen: SUBOTA" << endl;

}

void nedelja() {

	//cout << "Unos: NEDELJA" << endl;

	if (a.is_open())
		a << "NEDELJA:" << endl;
	if (b.is_open())
		b << "NEDELJA:" << endl;
	if (c.is_open())
		c << "NEDELJA:" << endl;
	if (d.is_open())
		d << "NEDELJA:" << endl;
	if (e.is_open())
		e << "NEDELJA:" << endl;

	unos();

	//cout << "Unos zavrsen: NEDELJA" << endl;

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
	
	cout << "*** JGPScraper - laxsrbija***";
	char ans;


	do {

		cout << endl;

		char naziv[50];
		cout << endl << "Unesi naziv datoteke: ";
		cin >> naziv;

		ulaz = fopen(naziv, "r");

		char linija[10];
		int linijaB;
		fscanf(ulaz, "%d", &linijaB);
		cout << "Unos linije " << linijaB << ":" << endl;
		_itoa(linijaB, linija, 10);
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
			cout << "Specijalni polasci postavljeni na 4." << endl;
		}
		else if (spec < 0) {
			spec = 0;
			cout << "Specijalni polasci postavljeni na 0." << endl;
		}
		else
			cout << "Specijalni polasci postavljeni na " << spec << "." << endl;

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
		cout << "Pocetni polazak postavljen na: " << pocetak << endl;
		fscanf(ulaz, "%d", &kraj);
		cout << "Poslednji polazak postavljen na: " << kraj << endl;

		radniDan();
		rastavi(spec);
		subota();
		rastavi(spec);
		nedelja();

		zatvori();

		cout << "OK!" << endl;

		cout << endl << "Nastaviti sa unosom (y/n)? ";
		cin >> ans;

	} while (ans == 'y');

}