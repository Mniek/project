#include <iostream>
#include <fstream>
#include <string>

#include <stdlib.h>

using namespace std;



  void checkMap (string fileToRead, int sizeArray,string cityA[], string cityB[], int dista[], int loopDisplay)// plik możliwych tras
     {
             ifstream mapRead(fileToRead.c_str());
             if(mapRead)
             {
                 string tempWord;
                 int cellToFill = 0;
                     for(int word_Map = 0; (mapRead>>tempWord) && (word_Map<sizeArray); ++word_Map)
                     {
                         cout<<"WORD: " + tempWord<<" ";

                         if(word_Map%3 == 0 ||word_Map == 0) // Jeśli reszta z 3 wynosi 0 lub komórka 0 to dodaj do tablicy startowych miast
                         {
                             cityA[cellToFill] = tempWord;
                         }
                         else if(word_Map%3 == 1 ||word_Map == 1) // Jeśli reszta z 3 wynosi 1 lub komórka 1 to dodaj do tablicy końcowych miast
                         {
                             cityB[cellToFill] = tempWord;
                         }
                         else if(word_Map%3 == 2 ||word_Map == 2) // Jeśli reszta z 3 wynosi 2 lub komórka 2 to dodaj do tablicy odległości i iteruj komórkę
                         {
                             dista[cellToFill] = stoi(tempWord);
                             cellToFill++;
                         }



                         //wordsArray[word_Map] = tempWord;
                     }
                     mapRead.close();
             }
     }
  void checkPath(string fileToRead, int sizeArray,string cityA[], string cityB[] ) //Plik trasy użytkownika
  {
    ifstream mapRead(fileToRead.c_str());
    if(mapRead)
    {
        string tempWord;
        int cellToFill = 0;
            for(int word_Map = 0; (mapRead>>tempWord) && (word_Map<sizeArray); ++word_Map)
            {
                cout<<endl<<"END: " + tempWord<<" "<<endl;

                if(word_Map%2 == 0 ) // Jeśli reszta z 2 wynosi 0 lub komórka 0 to dodaj do tablicy startowych miast
                {
                    cityA[cellToFill] = tempWord;
                }
                else if(word_Map%2 == 1 || cellToFill == 1 ) // Jeśli reszta z 2 wynosi 1 lub komórka 1 to dodaj do tablicy końcowych miast
                {
                    cityB[cellToFill] = tempWord;
                }
            }
    }
  }
  void Dijkstra()
  {
    string startNode;
    string endNode;

  }
int main()
{
    string const mapsFile("mapa.txt");
    string const destinationFile("destiny");



    string tempWord;
    int const sizeArray_Map = 3;
    int const sizeArray_Dest = 4;

    //string wordsArray_Map[sizeArray_Map];

    string cityStart_Map[sizeArray_Map];
    string cityDest_Map[sizeArray_Map];
    int distBetween_Map[sizeArray_Map];

    string cityStart_Dest[sizeArray_Dest];
    string cityDest_Dest[sizeArray_Dest];



  checkMap(mapsFile,sizeArray_Map,cityStart_Map,cityDest_Map,distBetween_Map, 1);
  checkPath(destinationFile, sizeArray_Dest, cityStart_Dest, cityDest_Dest);
    //cout<< cityStart_Map[0]<<endl;
    return 0;
}



//ZAKOMENTOWANE PODOPOWIEDZI


       // Odczytanie po linijce

            //getline(mapRead,linijka);
            //cout<<linijka;

            //Przeszukanie pierwszej linijki MAPY z uwzględnieniem rozdzielenia na słowa;

 /*ostream readIt(mapsFile.c_str);
    stringstream vars;
    vars <<out.rdbuf();
    tempWord=vars.str();
    */


            //Otwarcie pliku z mapami

                // ofstream mapOpen(mapsFile.c_str(), ios::app);
