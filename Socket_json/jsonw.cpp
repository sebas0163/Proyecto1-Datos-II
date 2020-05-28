#include "jsoncpp/json/json.h"
#include <iostream>
#include <fstream>
using namespace std;



void bwrite(){

  Json::Value root; //dato del json a sobreescribir
  root["conexiones"][0]["Usuario"] = "Harold";
  Json::StyledWriter SW;
  ofstream OS;
  OS.open("LogServer.json");
  OS << SW.write(root);
  /*root["conexiones"][1]["Usuario2"] = "cliente 2" ;
  OS << SW.write(root);*/
  OS.close();
  cout<<"\n json escrito \n";

}

void bread(){

  ifstream ifs("LogServer.json");
  Json::Reader reader;
  Json::Value obj;
  reader.parse(ifs, obj); 
  const Json::Value& characters = obj["conexiones"]; // array of characters
  for (int i = 0; i < characters.size(); i++){
      cout << "\nNombre: " << characters[i]["Usuario"].asString();
      //cout << "\nIP: " << characters[i]["ip"].asString();
      cout << endl;
  }


}

int main() {

  
  bwrite();
  cout<<"\n";
  bread();
  return EXIT_SUCCESS;
}

