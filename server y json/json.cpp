#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h> // or jsoncpp/json.h , or json/json.h etc.

using namespace std;

int main() {
    ifstream ifs("camaras.json");
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj); 
    const Json::Value& characters = obj["camaras"]; // array of characters
    for (int i = 0; i < characters.size(); i++){
        cout << "\nNombre: " << characters[i]["nombre"].asString();
        cout << "\nIP: " << characters[i]["ip"].asString();
        cout << endl;
    }
}