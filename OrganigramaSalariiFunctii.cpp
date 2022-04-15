#include "clase.h"

int main()
{
    std::string nume;
    std::string functie;
    float salariu_baza;
    int vechime_functie;
    int n;
    int x;
    std::cout << "Scrie numarul de angajati ai firmei tale:";
    std::cin >> n;
    std::cout << "\n";

    Angajat** angajat;

    angajat = new Angajat * [n];

    for (int i = 0; i < n; i++)
    {   
        std::cout << "Numele angajatului: ";
        std::getline(std::cin >> std::ws, nume);
        std::cout << "\nFunctia angajatului(Analist/Programator/LiderEchipaProgramare): ";
        std::cin >> functie;
        std::cout << "\n";
        while (functie != "Analist" && functie != "Programator" && functie != "LiderEchipaProgramare")
            {
            std::cout << "Nu avem aceasta functie in firma. Introdu una dintre functiile mentionate: ";
            std::cin >> functie;
            std::cout << "\n";
            };
            
        std::cout << "Salariul de baza al angajatului: ";
        std::cin >> salariu_baza;
        std::cout << "\n";
        
        if (functie == "Analist")
        {
            (*(angajat + i)) = new Analist(nume, functie, salariu_baza);
        }

        if (functie == "Programator")
        {
            (*(angajat + i)) = new Programator(nume, functie, salariu_baza, 0);
        }

        if (functie == "LiderEchipaProgramare")
        {
            std::cout << "Introdu vechimea in functie a angajatului:";
            std::cin >> vechime_functie;
            std::cout << "\n";

            (*(angajat + i)) = new LiderEchipaProgramare(nume, functie, salariu_baza, vechime_functie, 500);
        }
    }

    FirmaProgramare firmaprogramare(angajat, n);
    while(1)
        { 
        std::cout << "Alege dintre urmatoarele optiuni:\n1.Afisare angajati firma\n2.Calculare salarii angajati\n3.Marire salariu angajat\n4.Promovare angajat\n5.Iesire\n";

        std::cin >> x;
        std::cout << "\n";
        switch (x)
        {
        case 1:
            firmaprogramare.afisare();
            break;

        case 2:
            firmaprogramare.calculare_salarii(10, 500, 40);
            break;

        case 3:
            firmaprogramare.mariri_salarii();
            break;

        case 4:
            firmaprogramare.promovari();
            break;
        
        case 5:
            exit(1);
           }
        std::cout << "\n";
        }
    

    return 0;
}