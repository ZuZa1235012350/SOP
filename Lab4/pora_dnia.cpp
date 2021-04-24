#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>


struct Czas{
int godzina;
int minuta;
int sekunda;

Czas(int godzina, int minuta, int sekunda);
std::string toString();
void next_hour();
void next_minute();
void next_second();
std::string time_of_day();
std::string to_string(std::string time_of_day);

};
Czas::Czas(int godz, int min, int sek){
godzina = godz;
minuta = min;
sekunda = sek;
}

auto main() -> int{

auto czas = Czas(23, 59, 59);
std::cout<<czas.toString();
czas.next_hour();
czas.next_minute();
czas.next_second();

std::cout<<czas.toString();
std::cout<<czas.to_string(czas.time_of_day())<<"\n";
return 0;
}

std::string Czas::toString(){
std::string godzina_string = std::to_string(godzina);
std::string minuta_string = std::to_string(minuta);
std::string sekundaa_string = std::to_string(sekunda);

if(godzina == 24)
godzina = 0;

if(minuta == 60)
minuta = 0;

if(sekunda == 60)
minuta = 0;


if(godzina < 10)
godzina_string = "0" + std::to_string(godzina);
if(minuta < 10)
minuta_string = "0" + std::to_string(minuta);
if(sekunda < 10)
sekundaa_string = "0" + std::to_string(sekunda);

return godzina_string + ":" + minuta_string + ":" + sekundaa_string + "\n";
}
void Czas::next_hour(){
godzina++;
if(godzina == 24)
std::cout<<"Nastepna godzina to 0\n";
else if(godzina > 24)
std::cout<<"Nastepna godzina to 1\n";
else
std::cout<<"Nastepna godzina to " + godzina;
}
void Czas::next_minute(){
minuta++;
if(minuta == 60)
std::cout<<"Nastepna minuta to 0\n";
else if(minuta > 60)
std::cout<<"Nastepna godzina to 1\n";
else
std::cout<<"Nastepna godzina to " + minuta;
}
void Czas::next_second(){
sekunda++;
if(sekunda == 60)
std::cout<<"Nastepna sekunda to 0\n";
else if(sekunda > 60)
std::cout<<"Nastepna sekunda to 1\n";
else
std::cout<<"Nastepna sekunda to " + sekunda;
}
std::string Czas::time_of_day(){
if(godzina >= 22 || godzina < 5)
return "noc";
else if(godzina >= 5 && godzina < 12)
return "rano";
else if(godzina >= 12 && godzina < 17)
return "dzien";
else
return "wieczor";
}
std::string Czas::to_string(std::string time_of_day){
return toString() + time_of_day;
} 
