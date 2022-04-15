#ifndef CLASE_H
#define CLASE_H

#include<iostream>
#include<string>

class Angajat
{
protected:
	std::string nume;
	std::string functie;
	float salariu_baza;
	float procent_taxe_salariu;

public:

	Angajat(std::string, std::string, float,float);

	std::string get_nume();
	std::string get_functie();
	void marire_salariu(float);
	void afisare();
	virtual ~Angajat() {};

	virtual void setter_bonus_vechime(float a) {};
	virtual void setter_vechime_functie(int a) {};
	virtual void setter_procent_deducere_salariu_it(float) {};

	float get_salariu_baza();
	virtual float get_salariu_brut() { return this->salariu_baza; };
	virtual float get_salariu_net(float procent) { return this->salariu_baza - salariu_baza * (procent) / 100; };

};

class Analist : public Angajat
{
public:
	Analist(std::string, std::string, float);
	~Analist() {};


};

class Programator : public Analist
{
protected:
	float procent_deducere_salariu_it;

public:
	Programator(std::string, std::string, float, float);
	void setter_procent_deducere_salariu_it(float);
	float getter_procent_deducere_salariu_it();
	~Programator() {};
	float get_salariu_net(float);


};

class LiderEchipaProgramare : public Programator
{
protected:
	float bonus_vechime_functie;
	int vechime_functie;

public:
	LiderEchipaProgramare(std::string, std::string, float, int, float);
	~LiderEchipaProgramare() {};

	void setter_bonus_vechime(float);
	void setter_vechime_functie(int);
	int getter_vechime_functie();
	float getter_bonus_vechime();
	float get_salariu_brut();
	float get_salariu_net(float);

};

class FirmaProgramare
{
	Angajat** angajat;
	int n;

public:
	void afisare_angajati();
	void mareste_salarii(float, float, float);
	void prmoveaza(std::string);

	FirmaProgramare(Angajat**, int);
	void afisare();
	void calculare_salarii(float, float, float);
	void mariri_salarii();
	void promovari();
};

#endif