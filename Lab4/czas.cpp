#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

struct Czas{
int godzina;
int minuta;
int sekunda;

Czas(int godzina, int minuta, int sekunda);
std::string toString();
void next_hour();
void next_minute();
void next_second();

};
Czas::Czas(int godz, int min, int sek){
godzina = godz;
minuta = min;
sekunda = sek;
}

auto main() -> int{

auto czas = Czas(23, 59, 59);
std::cout<<czas.toString();
std::cout<<"\n";

czas.next_second();

std::cout<<czas.toString() <<"\n";

return 0;
}

std::string Czas::toString(){
std::ostringstream out;
out << std::setw(2) << std::setfill('0') << godzina << ":";
out << std::setw(2) << std::setfill('0') << minuta << ":";
out << std::setw(2) << std::setfill('0') << sekunda;

return out.str();

}
void Czas::next_hour(){
godzina++;
if(godzina == 24){
godzina = 0;
}
}
void Czas::next_minute(){
minuta++;
if(minuta == 60){
minuta = 0;
next_hour();
}
}
void Czas::next_second(){
sekunda++;
if(sekunda == 60){
sekunda = 0;
next_minute();
}

} 
