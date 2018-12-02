#include <iostream>
#include <ctime>
#include <random>
#include <string>

using namespace std;
string randomCity( size_t length)
{
  static const string alphabet = "abcdefghijklmnopqrstuvwxyz";
  static default_random_engine randomCity(time(nullptr));
  static uniform_int_distribution<size_t>distribution(0,alphabet.size()-1);
  string city;


  while(city.size()<length)
  {
    city += alphabet[distribution(randomCity)];
    return city;
  }
}

int main()
{
    for(size_t i = 10 ; i < 40 ; i += 3 ) cout << randomCity(i);
}
