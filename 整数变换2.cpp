//#include "stdafx.h"
#include"iostream"
using namespace std;

static int n;//Ҫ�任����
static int m;//Ҫ�任�ɵ���
static int k;//�任�Ĵ���
static bool found;//���ҽ��
static int result[100];//���任100��

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
//searchʵ�ֻ�������
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
    cout << "����Ҫ�任������ ";
    cin >> n ;
    cout << "����Ҫ�任�ɵ����� ";
    cin >> m ;
    for (int i = 0; i<99; i++){
        result[i] = 0;
    }
    compute();
    if (found){
        cout << "���������" << k << "��" << endl;
        cout << "������̣�";
        for (int i = k; i >= 1; i--){
            if (result[i] == 0)
                cout << "g";
            else if (result[i] == 1)
                cout << "f";
        }
        cout << endl;   
    }
    else{
        cout <<n<<"�޷��任��"<<m <<endl;
    }
    //system("pause");
    return 0;
}
