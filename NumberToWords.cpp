#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>

using namespace std;

void NumToWord(int);
int* SpilitNum(int,int);

string OnesWord[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string TensWord[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty"};
string TeenWord[] = {"Ten", "Eleven", "Tevlwe", "Thirtheen", "forteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Ninteen"};
string Unit[] = {"", "", "", "Hundrad", "Thousand", "Thousand", "Hundrad", "Million", "Million", "Hundrad", "Billion"};


int SIZE = 0;

int main(){
    NumToWord(12010078);
    NumToWord(157813);
    NumToWord(145);
    NumToWord(2115);
    NumToWord(754125);
    NumToWord(1);
    NumToWord(25);
}

void NumToWord(int num){
    printf("%d : ", num);
    int *digits;
    digits = SpilitNum(num,0);
    for(int i=SIZE-1;i>=0;i--){
        switch(i+1){
            case 1: // one digit 1-9
            case 3: // 3 digit number 100-999
            case 4: // 4 digit number 1000-9999
            case 6: // 6 digit number 100000-999999
            case 7: // 7 digit number 1000000-9999999
            case 9: // 9 digit number 10000000-99999999
            case 10: // 10 digit number 1000000000-9999999999
//                DisplayWord(digits[i],1); // display 1 digit number
//                DisplayUnit(i+1);
                cout << OnesWord[digits[i]] << " ";
                if (digits[i]) cout << Unit[i+1] << " ";
                break;
            case 2: // 7 digit number 10-99
            case 5: // 7 digit number 10000-99999
            case 8: // 7 digit number 10000000-99999999
            case 11: // 7 digit number 10000000000-99999999999
                //if(i == 2 )printf("And ");
                if(digits[i] > 1){ // if value > 19
//                    DisplayWord(digits[i],10); // display 2 digit number
                    cout << TensWord[digits[i]] << " ";
                } else if (digits[i] == 1) { // if value beteen 10-19
//                    DisplayTeen(digits[--i]); // pass last digit (0-9) from 10-19
//                    DisplayUnit(i+1);
                    cout << TeenWord[digits[--i]] << " ";
                    cout << Unit[i+1] << " ";
                } else {}
                break;
            default :
                break;
        }
    }
    printf("ONLY\n");
    free(digits);
}

int* SpilitNum(int num, int index){
    int* digits;
    if(!num){
        digits = (int*) calloc(index,sizeof(int));
        SIZE = index;

    } else {
        digits = SpilitNum(num/10,index+1);
        digits[index] = num%10;
    }
    return digits;
}
