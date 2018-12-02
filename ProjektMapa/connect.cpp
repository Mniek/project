#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <random>
#include <sstream>



using namespace std;
// -----------------------------Silnik randomizujący miast ---------------------------------------------


//-------------------------------------Zaczynamy listę!!!!---------------------------------------------

struct koneksja
{
  string miastoPocz;
  string miastoKonc;
  int odleglosc;
  koneksja *nastepna;   // wskaźnik na następny element
  koneksja();         // Konstruktor
};
koneksja::koneksja()
{
  nastepna=0; // Konstruktor
}

struct lista
{
  koneksja *pierwsza;   //wskaźnik na początek listy
  void dodajMiasta(string miastoA,string miastoB, int dystans);
  void wyswietlListe();
  void dodajRandomMiasta();
  lista();
};
lista::lista()
{
  pierwsza =0;    //Konstruktor
}


    //Dodawanie elementu do listy miast!!!!!!!!!!!!!!!!!!!
    void lista::dodajMiasta(string miastoA, string miastoB, int dystans)
    {
      koneksja *nowa = new koneksja;

      nowa -> miastoPocz = miastoA;
      nowa -> miastoKonc = miastoB;
      nowa -> odleglosc = dystans;

      if(pierwsza == 0)
      {
        pierwsza = nowa;
      }
      else
      {
        koneksja *temp =  pierwsza;

        while(temp->nastepna)
        {
          temp = temp->nastepna;
        }
        temp -> nastepna = nowa;
        nowa -> nastepna = 0;
      }
    }



    //randomCityGenerator
    string randomCityMachineEngine( size_t length)
    {
      static const string alphabet = "abcd";
      static default_random_engine randomCity(time(nullptr));
      static uniform_int_distribution<size_t>distribution(0,alphabet.size()-1);
      string city;


      while(city.size()<length)
      {
        city += alphabet[distribution(randomCity)];
        return city;
      }
    }



//randomDistanceEngine
default_random_engine randomDistance;
uniform_int_distribution<int> distribution(1,893);

//Zrandomizowane generowanie miast
string newCity()
{
  string miastoPocz;
  stringstream mP;

  for(size_t i = 1 ; i < 6 ; i +=1  )
    mP << randomCityMachineEngine(i);


     mP>>miastoPocz;
     return miastoPocz;
}

void lista::dodajRandomMiasta()
{

  koneksja *random = new koneksja;





  random -> miastoPocz = newCity();
  random -> miastoKonc = newCity();
  random -> odleglosc = distribution(randomDistance) ;
  if(pierwsza == 0 )
  {
    pierwsza = random;
  }
  else
  {
    koneksja *temp = pierwsza;
    while(temp -> nastepna)
    {
      temp->nastepna;
    }
    temp ->nastepna = random;
    random -> nastepna =0;
  }
}


    //Wyświetlenie zasobów listy
    void lista::wyswietlListe()
  {
    koneksja*temp = pierwsza;
    while(temp)
    {
      cout<<"Miasto Początkowe: "<<temp->miastoPocz<<endl<<"Miasto Końcowe: "<< temp->miastoKonc<<endl<<"Odległość pomiędzy: "<< temp->odleglosc<<endl<<endl;
      temp = temp->nastepna;
    }
  }




int main()
{
  lista *miastaPolski = new lista;
  for(int i = 0; i<2; i++)
  {
      miastaPolski ->dodajRandomMiasta();
  }
   miastaPolski ->dodajMiasta("Gierałtowice","Wrocław", 178);
  // miastaPolski ->dodajMiasta("Gierałt","Suwałki", 1);
  // miastaPolski ->dodajMiasta("Gliwice","Katowice", 3238);
  // miastaPolski ->dodajMiasta("Zabrze","Wro", 14);
  // miastaPolski ->dodajMiasta("Gierał","Poznan", 78);
  miastaPolski->wyswietlListe();


}
