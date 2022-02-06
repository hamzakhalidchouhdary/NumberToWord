#include<iostream>
#include<string>

using namespace std;

void NumToWord(int);
int* SpilitNum(int,int);

int SIZE = 0;
int FiguresMap [] = {1,2,1,1,2,1,1,2,1,1,2};
string Unit[] = {"\b", "\b", "\b", "Hundrad", "Thousand", "\b", "Hundrad", "\b", "Million", "Hundrad", "Billion"};
string Words[3][10] = {
    {"Ten", "Eleven", "Tevlwe", "Thirtheen", "forteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Ninteen"},
    {"\b", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"},
    {"\b", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty"}
};

int main(){
    NumToWord(12010078);
    NumToWord(150813);
    NumToWord(145);
    NumToWord(2115);
    NumToWord(754125);
    NumToWord(1);
    NumToWord(25);
}

void NumToWord(int num){
    cout << num << " : ";
    int *digits;
    bool isTeen, isTens;
    digits = SpilitNum(num,0);
    for(int i=SIZE-1;i>=0;){
        FiguresMap[i] == 2 ? isTens = true : isTens = false;
        isTens && digits[i] == 1 ? isTeen = true : isTeen = false;
        isTeen ? cout << Words[0][digits[i-1]]  << " " : cout << Words[FiguresMap[i]][digits[i]] << " ";
        if (digits[i] || FiguresMap[i] == 2) cout << Unit[i+1] << " ";
        isTeen ? i-=2 : i-=1;
    }
    cout << "ONLY\n";
    delete digits;
}

int* SpilitNum(int num, int index){
    int* digits;
    if(!num){
        digits = new int[index];
        SIZE = index;

    } else {
        digits = SpilitNum(num/10,index+1);
        digits[index] = num%10;
    }
    return digits;
}
