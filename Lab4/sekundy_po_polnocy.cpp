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
Czas dodawanie(const Czas zeg);
Czas odejmowanie(const Czas zeg);
bool czy_wiekszy(const Czas zeg);
bool czy_mniejszy(const Czas zeg);
bool czy_rowne(const Czas zeg);
bool czy_nierowne(const Czas zeg);
int count_seconds();
int count_minutes();
Czas time_to_midnight();

};
Czas::Czas(int godz, int min, int sek){
godzina = godz;
minuta = min;
sekunda = sek;
}

auto main() -> int{

auto czas = Czas(20, 51, 59);
std::cout<<czas.toString();

auto czas2 = Czas(21, 55, 00);

std::cout<<czas2.toString();
std::cout << czas.count_seconds() << "\n";
std::cout << czas.count_minutes() << "\n";
auto czas3 = czas2.time_to_midnight();

std::cout<<czas3.toString();

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
return time_of_day;
}
Czas Czas::dodawanie(Czas zeg){
int g;
int m;
int s;

g = godzina + zeg.godzina;
m = minuta + zeg.minuta;
s = sekunda + zeg.sekunda;

if(s >= 60){
s -= 60;
m++;
}
if(m >= 60){
m -= 60;
g++;
}
if(g >= 24)
g -= 24;

Czas z = Czas(g,m,s);
return z;
}
Czas Czas::odejmowanie(Czas zeg){
int g;
int m;
int s;

g = godzina - zeg.godzina;
m = minuta - zeg.minuta;
s = sekunda - zeg.sekunda;

if(s < 0){
s += 60;
m--;
}
if(m < 0){
m += 60;
g--;
}
if(g < 0)
g += 24;

Czas z = Czas(g,m,s);
return z;
}
bool Czas::czy_wiekszy(Czas zeg){
if(godzina > zeg.godzina)
return true;
else if(godzina == zeg.godzina){
if(minuta > zeg.minuta)
return true;
else if(minuta == zeg.minuta){
if(sekunda > zeg.sekunda)
return true;
else
return false;
}else
return false;
return false;
}else
return false;
}
bool Czas::czy_mniejszy(Czas zeg){
if(godzina < zeg.godzina){
return true;
}else if(godzina == zeg.godzina){
if(minuta < zeg.minuta){
return true;
}else if(minuta == zeg.minuta){
if(sekunda < zeg.sekunda){
return true;
}else
return false;
}else
return false;

}else
return false;

}
bool Czas::czy_rowne(Czas zeg){
if(godzina != zeg.godzina)
return false;
return true;
}
bool Czas::czy_nierowne(Czas zeg){
if(godzina != zeg.godzina)
return true;
return false;
}
int Czas::count_seconds(){
int min = minuta * 60;
int g = godzina * 60 * 60;

return sekunda + min + g;
}
int Czas::count_minutes(){
int g = godzina * 60;

return g + minuta + 1;
}
Czas Czas::time_to_midnight(){
int g = 23 - godzina;
int m = 59 - minuta;
int s = 60 - sekunda;

if(minuta == 0)
m = 59;
if(sekunda == 0)
s = 59;
if(godzina == 24)
g = 0;
return Czas(g,m,s);
} 
