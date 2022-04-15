#include "clase.h"
#include<iostream>

//functii Angajat

Angajat::Angajat(std::string nume, std::string functie, float salariu_baza, float procent_taxe_salariu=0) :nume(nume), salariu_baza(salariu_baza), functie(functie), procent_taxe_salariu(procent_taxe_salariu) {};

std::string Angajat::get_nume() { return this->nume; }

std::string Angajat::get_functie() { return this->functie; }

void Angajat::afisare()
{
    std::cout << nume << "\n" << functie << "\n";
}

float Angajat::get_salariu_baza() { return salariu_baza; }

void Angajat::marire_salariu(float salariu_nou) { this->salariu_baza = salariu_nou; }


//functii Analist

Analist::Analist(std::string nume, std::string functie, float salariu_baza) :Angajat(nume, functie, salariu_baza) {};


//functii Programator

Programator::Programator(std::string nume, std::string functie, float salariu_baza, float procent_deducere_salariu_it = 0) :Analist(nume, functie, salariu_baza), procent_deducere_salariu_it(procent_deducere_salariu_it) {};

void Programator::setter_procent_deducere_salariu_it(float procent) { this->procent_deducere_salariu_it = procent; };

float Programator::getter_procent_deducere_salariu_it() { return procent_deducere_salariu_it; };

float Programator::get_salariu_net(float procent) { return salariu_baza - salariu_baza * (procent - procent_deducere_salariu_it) / 100; };


//functii LiderEchipaProgramare

LiderEchipaProgramare::LiderEchipaProgramare(std::string nume, std::string functie, float salariu_baza, int vechime_functie, float bonus_vechime_functie = 0) :Programator(nume, functie, salariu_baza), vechime_functie(vechime_functie), bonus_vechime_functie(bonus_vechime_functie) {};

void LiderEchipaProgramare::setter_vechime_functie(int vechime_functie) { this->vechime_functie = vechime_functie; }

int LiderEchipaProgramare::getter_vechime_functie() { return vechime_functie; }

void LiderEchipaProgramare::setter_bonus_vechime(float bonus_vechime) { this->bonus_vechime_functie = bonus_vechime; }

float LiderEchipaProgramare::getter_bonus_vechime() { return bonus_vechime_functie; }

float LiderEchipaProgramare::get_salariu_brut() { return salariu_baza + bonus_vechime_functie * vechime_functie; };

float LiderEchipaProgramare::get_salariu_net(float procent) { return (salariu_baza + bonus_vechime_functie * vechime_functie) - (salariu_baza + bonus_vechime_functie * vechime_functie) * (procent - procent_deducere_salariu_it) / 100; };


//functii FirmaProgramare

FirmaProgramare::FirmaProgramare(Angajat** angajat, int n) {

    this->angajat = new Angajat * [n];
    this->n = n;

    for (int i = 0; i < n; i++)
        (*(this->angajat + i)) = (*(angajat + i));

}

void FirmaProgramare::afisare()
{
    for (int i = 0; i < n; i++)
        (*(angajat + i))->afisare();
}

void FirmaProgramare::calculare_salarii(float bonus_it, float bonus_vechime, float procent_de_taxa)
{

    for (int i = 0; i < n; i++)
    {
        if ((*(angajat + i))->get_functie() == "Programator")
            (*(angajat + i))->setter_procent_deducere_salariu_it(bonus_it);

        else if ((*(angajat + i))->get_functie() == "LiderEchipaProgramare")
        {
            (*(angajat + i))->setter_procent_deducere_salariu_it(bonus_it);
            (*(angajat + i))->setter_bonus_vechime(bonus_vechime);
        }

        std::cout << (*(angajat + i))->get_nume() << "\n";
        std::cout << "Salariu brut: " << (*(angajat + i))->get_salariu_brut() << "\n";
        std::cout << "Salariu Net: " << (*(angajat + i))->get_salariu_net(procent_de_taxa) << "\n";
    }
}

void FirmaProgramare::mariri_salarii()
{
    float procent_marire;
    std::string nume;

    std::cout << "Introdu numele angajatului caruia vrei sa ii maresti salariul:";
    std::cin >> nume;
    std::cout << "\n";
    std::cout << "Introdu procentul cu care vrei sa maresti salariul:";
    std::cin >> procent_marire;
    std::cout << "\n";


    for (int j = 0; j < n; j++)
    {
        if ((*(angajat + j))->get_nume() == nume)
        {
            if ((*(angajat + j))->get_nume() == nume)
            {
                (*(angajat + j))->marire_salariu((*(angajat + j))->get_salariu_baza() + (*(angajat + j))->get_salariu_baza() * procent_marire / 100);
            }
        }
    }
}


void FirmaProgramare::promovari()
{
    std::string nume;
    std::string functie;

    std::cout << "Introdu numele angajatului pe care doresti sa il promovezi:";
    std::getline(std::cin >> std::ws, nume);


    std::cout << "Introdu functia la care vrei sa promovezi angajatul:";
    std::getline(std::cin >> std::ws, functie);



    while (functie != "Analist" && functie != "Programator" && functie != "LiderEchipaProgramare")
    {
        std::cout << "Nu avem aceasta functie in firma. Introdu una dintre functiile mentionate:\n";
        std::cin >> functie;
        std::cout << "\n";
    }



    Angajat* angajat_promovat;

    for (int i = 0; i < n; i++)
    {
        if ((*(angajat + i))->get_nume() == nume)
        {
            if ((*(angajat + i))->get_functie() == "LiderEchipaProgramare")
            {
             std::cout << "Angajatul are deja cea mai mare functie disponibila\n";
             break;
            }
            if (( * (angajat + i))->get_functie() == functie)
                {
                std::cout << "Angajatul are deja aceasta functie\n";
                std::cout << "Introdu o alta functie:";
                std::cin >> functie;
                std::cout << "\n";
                }

            if (( * (angajat + i))->get_functie() == "Programator" && functie == "Analist")
                {
                std::cout << "Angajatul nu poate sa fie promovat la o functie inferioara\n";
                std::cout << "Introdu o alta functie:";
                std::cin >> functie;
                std::cout << "\n";
                }

            if (( * (angajat + i))->get_functie() == "LiderEchipaProgramare" && functie == "Analist")
                {
                std::cout << "Angajatul nu poate sa fie promovat la o functie inferioara\n";
                std::cout << "Introdu o alta functie:";
                std::cin >> functie;
                std::cout << "\n";
                }
            if ((*(angajat + i))->get_functie() == "LiderEchipaProgramare" && functie == "Programator")
            {
                std::cout << "Angajatul nu poate sa fie promovat la o functie inferioara\n";
                std::cout << "Introdu o alta functie:";
                std::cin >> functie;
                std::cout << "\n";
            }

            if (functie == "Programator")
            {
                angajat_promovat = new Programator(nume, functie, (*(angajat + i))->get_salariu_baza());
                delete ((*(angajat + i)));
                (*(angajat + i)) = new Programator(nume, functie, angajat_promovat->get_salariu_baza());
            }
            if (functie == "LiderEchipaProgramare")
            {
                angajat_promovat = new LiderEchipaProgramare(nume, functie, (*(angajat + i))->get_salariu_baza(), 0);
                delete ((*(angajat + i)));
                (*(angajat + i)) = new LiderEchipaProgramare(nume, functie, angajat_promovat->get_salariu_baza(), 0);
            }
        }
    }

    afisare();

}