#include <iostream>
#include <string>

struct Student{
	std::string imie;
	std::string nazwisko;
	std::string indeks;
	int aktualny_semestr;
	float srednia_ocen;
	Student(std::string imie, std::string nazwisko, std::string indeks, int aktualny_semestr, float srednia_ocen);
	std::string toString();
};
std::string Student::toString(){
	return imie + " " + nazwisko; 
}

Student::Student(std::string im, std::string na, std::string in, int as, float so){
	imie= im;
	nazwisko =na;
	indeks=in;
	aktualny_semestr=as;
	srednia_ocen=so;		
}
auto main()-> int{
	auto student = Student("Zuzanna","Borkowska","s21243",4,3.0);
	std::cout << student.toString() << "\n";
	return 0;
}
