//#include "stdafx.h"
#include"iostream"
using namespace std;

static int n;//要变换的数
static int m;//要变换成的数
static int k;//变换的次数
static bool found;//查找结果
static int result[100];//最多变换100次

bool search(int dep, int n);
void compute();
int fg(int n, int i);

void compute(){
    k = 1;
    found = false;
    while (!search(1, n)){
        k++;
        if (k > 100)
            break;
        if (found)
            break;
    }
}

bool search(int dep, int n){
//search实现回溯搜索
    if (dep>k){
        return false;
    }
    for (int i = 0; i<2; i++){
        int num = n;
        num = fg(num, i);
        result[dep] = i;
        if (num == m || search(dep + 1, num)){
            found = true;
            return true;
        }
    }
    return false;
}

int fg(int n, int i){
    if (i == 0)
        return n / 2;
    else
        return 3 * n;
}

int main(void){
    cout << "输入要变换的数： ";
    cin >> n ;
    cout << "输入要变换成的数： ";
    cin >> m ;
    for (int i = 0; i<99; i++){
        result[i] = 0;
    }
    compute();
    if (found){
        cout << "运算次数：" << k << "次" << endl;
        cout << "运算过程：";
        for (int i = k; i >= 1; i--){
            if (result[i] == 0)
                cout << "g";
            else if (result[i] == 1)
                cout << "f";
        }
        cout << endl;   
    }
    else{
        cout <<n<<"无法变换成"<<m <<endl;
    }
    //system("pause");
    return 0;
}
