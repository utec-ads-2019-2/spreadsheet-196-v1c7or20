#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int spread_sheets = 0, rows = 0, col = 0;
    string dato = "";
    map<string, string> maps;
    cin>>spread_sheets;
    for (int i = 0; i < spread_sheets ;i++) {
        cin>>col>>rows;
        for (int j = 0; j < rows; j++) {
            char name = 'A';
            for (int k = 0; k < col; k++) {
                cin>>dato;
                string namae = "";
                namae += name;
                maps.insert(pair<string,string>(namae, dato));
                name++;
            }
        }
    }
    cout<<"esta"<<endl;
    return 0;
}
