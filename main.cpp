#include <iostream>
#include <string>
#include <iomanip>
#include <memory.h>

using namespace std;


string formula[10000][10000];
int numb[10000][10000];

int solve(int i,int j){
    int r,c;
    numb[i][j] = r = c = 0;
    string str = formula[i][j];
    for (int k = 1; k <str.size()+1 ; k++) {
        if (isdigit(str.at(k))){
            r = r*10+str.at(k)-'0';
        } else if(str.at(k)>='A' and str.at(k) =='Z'){
            c =c*26+str.at(k)-'A'+1;
        }else if (str.at(k) == '+' or k == str.size()){
            numb[i][j] +=solve(r,c);
            r = c = 0;
        }
        return numb[i][j];
    }
    return 0;
}

int main(){
    int col,rows,spread;
    cin>>spread;
    for (int k= 0; k < spread; k++) {
        cin>>col>>rows;
        memset(numb,0, sizeof(numb));
        for (int i = 0; i <rows ; i++) {
            for (int j = 0; j < col; j++) {
                string dato;
                cin>>dato;
                if (dato.at(0) == '='){
                    formula[i][j] = dato;
                    numb[i][j] = -10000;
                } else{
                    numb[i][j] = atoi(dato.c_str());
                }
            }
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < col; ++j) {
                if (numb[i][j] == -10000)
                    solve(i, j);
            }
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < col; ++j) {
                cout<<setw(2)<<numb[i][j];
            }cout<<endl;
        }
    }
    return 0;
}