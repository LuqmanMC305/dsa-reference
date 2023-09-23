#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void ceasarCipher(int i, string &str)
{
    //Right shift of 3

    if(i >= str.length())
    {
        return;
    }

    if(str[i] != ' '&& str[i] != 'A' && str[i] != 'B' && str[i] != 'C')
    {
        str[i] = str[i] - 3;
        ceasarCipher(i+1, str);
    }
    else if (str[i] != ' ' && (str[i] == 'A' || str[i] == 'B' || str[i] == 'C'))
    {
        str[i] = str[i] + 23;
        ceasarCipher(i+1, str);
    }
    else
    {
       ceasarCipher(i+1, str);
    }


}

int main()
{
    string str;
    int index = 0;

    cout << "Enter the sentence or letter to convert:" << endl;
    getline(cin, str);

    for(int i=0; i<str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }

    ceasarCipher(index, str);
    cout << str << endl;


}