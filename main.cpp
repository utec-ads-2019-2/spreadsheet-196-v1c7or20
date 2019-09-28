#include<string>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include <iomanip>

using namespace std;


string formula[1000][1000];
int numb[1000][1000];

int solve(int i,int j){
    if (numb[i][j] != -10000)
        return numb[i][j];
    int r=0,c=0;
    numb[i][j] = 0;
    string str = formula[i][j];
    for (int k = 1; k <=str.size()+1 ; k++) {
        if (str[k] >='0' and str[k]<='9'){
            r = r*10+str[k]-'0';
        } else if(str[k]>= 'A' and str[k] <='Z'){
            c =c*26+str[k]-'A'+1;
        }else if (str[k] == '+' or k == str.size()){
            numb[i][j] +=solve(r,c);
            r = c = 0;
        }
    }
    return numb[i][j];
}

int main(){
    int col,rows,spread;
    cin>>spread;
    for (int k= 0; k < spread; k++) {
        cin>>col>>rows;
        for (int i =1; i <=rows ; i++) {
            for (int j = 1; j <= col; j++) {
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
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= col; ++j) {
                if (numb[i][j] == -10000)
                    solve(i, j);
            }
        }
        int i,j;
        for ( i = 1; i <= rows; ++i) {
            for ( j = 1; j < col; ++j) {
                printf("%d ",numb[i][j]);
            }
                printf("%d\n",numb[i][j]);
        }
    }
    return 0;
}