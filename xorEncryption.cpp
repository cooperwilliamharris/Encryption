// xorEncryption.cpp
// 18-May-2017

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

int main()
{
    string input, output, normal, cipher;   //declares these vars upfront
    cout << "enter a word or phrase to encrypt: \n";
    getline(cin,input); //uses getline because we want it to accept non-letters & non-numbers like "space"
    
    //this will be used to xor the original string
    cout << "enter a cipher character or string: \n";
    getline(cin,cipher);
    int r = cipher.size();
    
//    cout << "a random number of the cipher characters will now build the key. \n";
//    int len = cipher.size();    //${string}.size() is a member function
//    srand(time(NULL));  //initialize random seed
//    int r = rand() % len; //generates random index value; min=0,max=len; uses cipher[0:r] to build master key
//    cout << "r= " << r << endl;
    
    int run = 0;
    for (int i = 0; i < r; i++){ //builds running sum of all cipher char ascii values up to index=r
        char var = cipher[i];
        run = run + int(var);
    }
//    int master = run / cipher.size(); //builds master as nearest into to mean of running ascii sum
    int master = sqrt (run); //builds master as nearest into to sqrt of running ascii sum
    
//    cout << "running total: " << run << ", master: " << master << endl;
    
    //now make the algorithm
    
    //xor operation done here
    for(int i = 0; i < input.size(); i++){
        output += input[i] ^ (master+i)%25;
        }
    
    cout << "\n here is the encrypted output: \n" << output << "\n";
    
    //deëncryption takes place here, xor is bidirectional by definition
    for(int i = 0; i < input.size(); i++){
        normal += output[i] ^ (master+i)%25;
    }
    
    cout << "\n here is that phrase deëncrypted: \n" << normal << "\n";
    
    cin.get();
    return 0;

}


