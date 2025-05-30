#include <iostream>
#include"Catalog.h"
using namespace std;

int main()
{
	Student s1("Maria", "1234567678", en);
	s1.InserareMaterie(Informatica(), 5);
	s1.InserareMaterie(Romana(), 7);

	Student s2("Stefan", "83402823427", ro);
	s2.InserareMaterie(Engleza(), 9);
	s2.InserareMaterie(Spaniola(), 10);


	Student s3("Ana", "84322823427", ro);
	s3.InserareMaterie(Optional1(), 10);
	s3.InserareMaterie(Optional2(), 9);

	CatalogRo catalog;
	catalog.InserareStudent(s1);
	catalog.InserareStudent(s2);
	catalog.InserareStudent(s3);

	vector<Student> v = catalog.Filtrare([](Student& std)
		{
			return(std.Medie()> 5);
		});


}

