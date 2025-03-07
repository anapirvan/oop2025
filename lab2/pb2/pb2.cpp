
#include <iostream>
#include "Student.h"
#include "Comparatori.h"
using namespace std;

int main()
{
    Student s1, s2;

    s1.setNume("Ana");
    s1.setNotaMate(6);
    s1.setNotaIstorie(9.5);
    s1.setNotaEngleza(7);
    s1.setMedie(6.7);

    s2.setNume("Maria");
    s2.setNotaMate(9);
    s2.setNotaIstorie(6.5);
    s2.setNotaEngleza(8.7);
    s2.setMedie(6.5);

    cout << "Student: " << s1.getNume() <<endl;
    cout << "Nota mate: " << s1.getNotaMate() <<endl;
    cout << "Nota istorie: " << s1.getNotaIstorie() <<endl;
    cout << "Nota engleza: " << s1.getNotaEngleza() << endl;
    cout << "Medie: " << s1.getMedie() <<endl;
    cout << endl;


    cout << "Student: " << s2.getNume() << endl;
    cout << "Nota mate: " << s2.getNotaMate() << endl;
    cout << "Nota istorie: " << s2.getNotaIstorie() << endl;
    cout << "Nota engleza: " << s2.getNotaEngleza() << endl;
    cout << "Medie: " << s2.getMedie() << endl;
    cout << endl;


    if (comparaDupaMate(s1, s2) > 0)
        cout << s1.getNume() << " are nota mai mare la mate." << endl;
    else
        if (comparaDupaMate(s1, s2) < 0)
            cout << s2.getNume() << " are nota mai mare la mate." << endl;
        else
            cout << s1.getNume() << " si " << s2.getNume() << " au aceeasi nota la mate.";


    if (comparaDupaIstorie(s1, s2) > 0)
        cout << s1.getNume() << " are nota mai mare la istorie." << endl;
    else
        if (comparaDupaIstorie(s1, s2) < 0)
            cout << s2.getNume() << " are nota mai mare la istorie." << endl;
        else
            cout << s1.getNume() << " si " << s2.getNume() << " au aceeasi nota la istorie.";


    if (comparaDupaEngleza(s1, s2) > 0)
        cout << s1.getNume() << " are nota mai mare la engleza." << endl;
    else
        if (comparaDupaEngleza(s1, s2) < 0)
            cout << s2.getNume() << " are nota mai mare la engleza." << endl;
        else
            cout << s1.getNume() << " si " << s2.getNume() << " au aceeasi nota la engleza.";


    if (comparaDupaMedie(s1, s2) > 0)
        cout << s1.getNume() << " are medie mai mare." << endl;
    else
        if (comparaDupaMedie(s1, s2) < 0)
            cout << s2.getNume() << " are medie mai mare." << endl;
        else
            cout << s1.getNume() << " si " << s2.getNume() << " au aceeasi medie.";


    if (comparaDupaNume(s1, s2) > 0)
        cout <<"Numele studentilor in ordine lexicografica sunt: "<< s2.getNume()<<","<<s1.getNume()<< "." << endl;
    else
        if (comparaDupaNume(s1, s2) < 0)
            cout << "Numele studentilor in ordine lexicografica sunt: " << s1.getNume() << "," << s2.getNume() << "." << endl;

    


}

