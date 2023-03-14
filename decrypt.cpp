#include <iostream>
#include <vector>
#include <cmath>
#include "decrypt.h"
#include "funcs.h"
using namespace std;

char reverseChar(char c, int rshift){
    char ret = c;
    if(!isalpha(c)){
        return c;
    }
    for(int i = 0;i < rshift;i++){
        if(ret == 'a'){
            ret = 'z';
        }else if(ret == 'A'){
            ret = 'Z';
        }else{
            ret--;
        }
    }
    return ret;
}

string decryptCaesar(string input, int shift){
    if(shift==0){
        return input;
    }
    if(input ==""){
        return "";
    }
    string ret = "";
    for(char x : input){
        if(!isalpha(x)){
            ret+=x;
        }else{
            ret+=reverseChar(x,shift);
        }
    }
    return ret;
}

string decryptVigenere(string word, string key){
    if(key == ""){
        return word;
    }
    if(word == ""){
        return "";
    }
    string ret = "";
    int z = 0;
    for(char x : word){
        if(!isalpha(x)){
            ret+=x;
            continue;
        }
        if(z > key.length()-1){ //resets the indexing for keyword
            z = 0;
        }
        int position = tolower(key[z]) - 'a';
        z++;
        ret+=reverseChar(x,position);
    }
    return ret;
}

//returns the position of a letter in the alphabet, from 0-25
int getLocation(char a){
    char alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int i = 0;
    for(char x : alpha){
        if(x == a){
            return i;
        }
        i++;
    }
    return -1;
}

//distance formula is  sqrt(  (PhraseFreqA - EngFreqA)^2 + (Phrase FreqB - EngFreB)^2... etc)
double dist(vector<double> count){
    vector<double> freq ={8.2,1.5,2.8,4.3,13,2.2,2,6.1,7,0.15,0.77,4,2.4,6.7,7.5,1.9,0.095,6,6.3,9.1,2.8,0.98,2.4,0.15,2,0.074};
    double sum = 0;
    int i = 0;
    for(double x : count){
        sum+=pow(count[i]-freq[i],2);
        i++;
    }
    return sqrt(sum);
}

//returns a vector with the frequency of each of the 26 letters of the alphabet in order
vector<double> letterFreq(string a){
    vector<double> count(26,0);
    for(char x : a){
        if(isalpha(x)){
            count[getLocation(tolower(x))] +=1;
        }
    }
    return count;
}

string rotate(string plaintext, int rshift){
    string ret = "";
    for(char x : plaintext){
        ret+=shiftChar(x,rshift);
    }
    return ret;
}

std::string solve(std::string encrypted_string){
    string ret = "";
    double sDistance = 100;
    for(int i =0;i <= 25;i++){
        string r = rotate(encrypted_string,i);
        vector<double> letterCount = letterFreq(r);
        double distance = dist(letterCount);
        if(distance < sDistance){
            sDistance = distance;
            ret = rotate(encrypted_string,i);
        }
    }
    return ret;
}