// caesarCipher.cpp
// 18-May-2017

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    int length;
    
    cout << "enter your phrase to be encrypted: \n";
    getline(cin,input);
    
    length = (int)input.length();
    int count = 0,
    
    for (count = 0; count < length; count++)
    {
       if (isalpha(input[count]))
       {
           input[count] = tolower(input[count]);
           for (int i =0; i<13;i++)
           {
               if (input[count] == 'z')
                   input[count] = 'a';
               else
                   input[count]++;
           }
       }
           
    }
    
    cout << "Results: \n" << input << endl;
    
}
