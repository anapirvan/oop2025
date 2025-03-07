#pragma once

class Student
{
private:
	char nume[20];
	float notaMate, notaIstorie, notaEngleza, medie;
public:
	void setNume(const char numeStudent[]);
	void setNotaMate(float value);
	void setNotaEngleza(float value);
	void setNotaIstorie(float value);
	void setMedie(float value);

	char* getNume();
	float getNotaMate();
	float getNotaEngleza();
	float getNotaIstorie();
	float getMedie();

	Student();
};

