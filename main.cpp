#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

vector<std::string> split(string stringToBeSplitted, string delimeter)
{
    std::vector<std::string> splittedString;
    int startIndex = 1;
    int  endIndex = 0;
    while( (endIndex = stringToBeSplitted.find(delimeter, startIndex)) < stringToBeSplitted.size() )
    {
        std::string val = stringToBeSplitted.substr(startIndex, endIndex - startIndex);
        splittedString.push_back(val);
        startIndex = endIndex + delimeter.size();
    }
    if(startIndex < stringToBeSplitted.size())
    {
        std::string val = stringToBeSplitted.substr(startIndex);
        splittedString.push_back(val);
    }
    return splittedString;
}

void armar_nombre(string &namae, char letra){
    char temp = letra;
    char lul ;
    do{
        lul = ((temp-64 )%27)+64;
        namae+=lul;
        temp-=27;
    }while (temp>64);
}

void solve(map<string,string> &mapa){
    bool control = true;
        while (control){
            control = false;
            for (auto &map : mapa) {
                if ((*map.second.begin()) == '=') {
                    vector<string> splited = split(map.second, "+");
                    int valor = 0;
                    for (auto &str : splited) {
                        string palabra = mapa[str];
                        if (palabra.size()>1 and isalpha(palabra.at(1))){
                            control = true;
                            break;
                        }else{
                            valor += atoi(mapa[str].c_str());
                            control = false;
                        }
                    }
                    if (!control){
                        map.second = to_string(valor);
                        control = true;
                    }
                }
            }
        }
}

int main() {
    int spread_sheets = 0, rows = 0, col = 0;
    map<string, string> maps;
    string dato = "";
    cin>>spread_sheets;
    for (int i = 0; i < spread_sheets ;i++) {
        cin >> col >> rows;
        for (int j = 0; j < rows; j++) {
            char name = 65;
            for (int k = 0; k < col; k++) {
                cin >> dato;
                string namae = "";
                armar_nombre(namae, name);
                namae += to_string(j + 1);
                maps.insert(pair<string, string>(namae, dato));
                name++;
            }
        }
        solve(maps);

        for (int j = 0; j < rows; j++) {
            char name = 65;
            for (int k = 0; k < col; k++) {
                string namae = "";
                armar_nombre(namae, name);
                namae += to_string(j + 1);
                cout << setw(2) << maps[namae] << " ";
                name++;
            }cout << endl;
        }
        maps.clear();
    }
    return 0;
}
