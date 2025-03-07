#include "Student.h"
#include<cstring>

Student::Student()
{
	notaMate = 0;
	notaIstorie = 0;
	notaEngleza = 0;
	medie = 0;
}

void Student::setNume(const char numeStudent[])
{
	strcpy(nume, numeStudent);
}

char* Student::getNume()
{
	return nume;
}

void Student::setNotaMate(float value)
{
	if(value>=0 and value<=10)
		notaMate = value;
}

void Student::setNotaEngleza(float value)
{
	if(value>=0 and value<=10)
		notaEngleza = value;
}

void Student::setNotaIstorie(float value)
{
	if (value >= 0 and value <= 10)
		notaIstorie = value;
}

void Student::setMedie(float value)
{
	if (value >= 0 and value <= 10)
		medie = value;
}

float Student::getNotaMate()
{
	return notaMate;
}

float Student::getNotaEngleza()
{
	return notaEngleza;
}

float Student::getNotaIstorie()
{
	return notaIstorie;
}

float Student::getMedie()
{
	return medie;
}