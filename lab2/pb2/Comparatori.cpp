#include"Comparatori.h"
#include<cstring>

int comparaDupaMate(Student s1, Student s2)
{
	float nota1 = s1.getNotaMate();
	float nota2 = s2.getNotaMate();

	if (nota1 == nota2)
		return 0;
	if (nota1 > nota2)
		return 1;
	return -1;
}
int comparaDupaIstorie(Student s1, Student s2)
{
	float nota1 = s1.getNotaIstorie();
	float nota2 = s2.getNotaIstorie();

	if (nota1 == nota2)
		return 0;
	if (nota1 > nota2)
		return 1;
	return -1;
}
int comparaDupaEngleza(Student s1, Student s2)
{
	float nota1 = s1.getNotaEngleza();
	float nota2 = s2.getNotaEngleza();

	if (nota1 == nota2)
		return 0;
	if (nota1 > nota2)
		return 1;
	return -1;
}
int comparaDupaNume(Student s1, Student s2)
{
	char *nume1 = s1.getNume();
	char *nume2 = s2.getNume();

	if (strcmp(nume1,nume2)==0)
		return 0;
	if (strcmp(nume1, nume2) > 0)
		return 1;
	return -1;
}
int comparaDupaMedie(Student s1, Student s2)
{
	float medie1 = s1.getMedie();
	float medie2 = s2.getMedie();

	if (medie1 == medie2)
		return 0;
	if (medie1 > medie2)
		return 1;
	return -1;
}