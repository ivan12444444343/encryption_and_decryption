#include <iostream>
#include <array>
#include <iomanip>
#include <string>

using namespace std;

class Substitute

{

public:

    

    static int findIndex(char code[], char indexToFind)

    {

        for (int i = 0; i < 26; i++)

        {

            if (code[i] == indexToFind)

            {

                return i;

            }

        }

        return -1;

    }

    

    static char* getEncryptS(char* text, char code[])

    {

        int len = strlen(text);

        char* encryptedTextSub = (char*)malloc(sizeof(char) * len + 1);



        for (int i = 0; i < len; i++)

        {

            int encryptionIndexSub = tolower(text[i]) - 'a';

            

            if (encryptionIndexSub >= 0 && encryptionIndexSub < 26)

            {

                encryptedTextSub[i] = code[encryptionIndexSub];

            }

            else

            {

                encryptedTextSub[i] = text[i];

            }

        }

        encryptedTextSub[len] = '\0';

        

        return encryptedTextSub;

    }

    

    static char* getDecryptS(char* text, char code[])

    {

        int len = strlen(text);

        char* decryptedTextSub = (char*)malloc(sizeof(char) * len + 1);

        for (int i = 0; i < len; i++)

        {

            int decryptionIndexSub = tolower(text[i]) - 'a';

            

            if (decryptionIndexSub >= 0 && decryptionIndexSub < 26)

            {

                int codeIndexS = findIndex(code, tolower(text[i]));

                decryptedTextSub[i] = 'a' + codeIndexS;

            }

            else

            {

                decryptedTextSub[i] = text[i];

            }

        }

        decryptedTextSub[len] = '\0';

        

        return decryptedTextSub;

    }

};

class CaesarCipher

{

public:

    

    static string getEncryptC(string input, int s)

    {

        string encryptedTextC = "";

        int lenC = input.length();

        

        for (int i = 0; i < lenC; i++)

        {

            

            if (isalpha(input[i]) == 0)

                encryptedTextC += input[i];

            else if (isupper(input[i]))

                encryptedTextC += char(int(input[i] + s - 65) % 26 + 65);

            else if (islower(input[i]))

                encryptedTextC += char(int(input[i] + s - 97) % 26 + 97);

            else

                encryptedTextC = encryptedTextC;

        }

        

        return encryptedTextC;

    }

    static string getDecryptC(string input, int s)

    {

        string decryptedTextC = "";

        int lenC = input.length();

        

        s = 26 - s;

        for (int i = 0; i < lenC; i++)

        {

            

            if (isalpha(input[i]) == 0)

                decryptedTextC += input[i];

            else if (isupper(input[i]))

                decryptedTextC += char(int(input[i] + s - 65) % 26 + 65);

            else if (islower(input[i]))

                decryptedTextC += char(int(input[i] + s - 97) % 26 + 97);

            else

                decryptedTextC = decryptedTextC;

        }

        

        return decryptedTextC;

    }

};

int main()

{

    

    cout << "Welcome! This is then Encryption and Decryption Machine" << endl;

    cout << "Would you like to Encrypt or Decrypt text? Encrypt(1) Decrypt(2) Both(3) : " << endl;

    int tool;

    cin >> tool;

    

    if (tool == 1)

    {

        cout << "Encrypt text selected" << endl;

    }

    else if (tool == 2)

    {

        cout << "Decrypt text selected" << endl;

    }

    else if (tool == 3)

    {

        cout << "Both options selected" << endl;

    }

    cout << "Which Cipher option would be preferable? Substitution(1) Caesar(2) Both(3) : " << endl;

    int option;

    cin >> option;

    

    if (option == 1)

    {

        cout << "Substitution cipher has been selected" << endl;

    }

    else if (option == 2)

    {

        cout << "Caesar cipher has been selected" << endl;

    }

    else if (option == 3)

    {

        cout << "Both ciphers have been selected" << endl;

    }

    

    cout << "Enter your text: ";

    cin.ignore();

    string input;

    getline(cin, input);

    char* text = const_cast<char*>(input.c_str());

    char code[26] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm' };

    int s = 3;



    

    if (tool == 1)

    {

        

        if (option == 1)

        {

            cout << "Text: " << text << endl;

            cout << "Text encrypted with Substitution: " << Substitute::getEncryptS(text, code) << endl;

        }

        

        else if (option == 2)

        {

            cout << "Text: " << text << endl;

            cout << "Text encrpyted with Caesar: " << CaesarCipher::getEncryptC(input, s) << endl;

        }

        

        else if (option == 3)

        {

            cout << "Text: " << text << endl;

            cout << "Text encrypted with Substitution: " << Substitute::getEncryptS(text, code) << endl;

            cout << "Text encrpyted with Caesar: " << CaesarCipher::getEncryptC(input, s) << endl;

        }

    }

    

    else if (tool == 2)

    {

        

        if (option == 1)

        {

            cout << "Text: " << text << endl;

            cout << "Text decrypted with Substitution: " << Substitute::getDecryptS(Substitute::getEncryptS(text, code), code) << endl;



        }

        

        else if (option == 2)

        {

            cout << "Text: " << text << endl;

            cout << "Text decrpyted with Caesar: " << CaesarCipher::getDecryptC(CaesarCipher::getEncryptC(input, s), s) << endl;

        }

        

        else if (option == 3)

        {

            cout << "Text: " << text << endl;

            cout << "Text decrypted with Substitution: " << Substitute::getDecryptS(Substitute::getEncryptS(text, code), code) << endl;

            cout << "Text decrpyted with Caesar: " << CaesarCipher::getDecryptC(CaesarCipher::getEncryptC(input, s), s) << endl;

        }

    }

    

    else if (tool == 3)

    {

        

        if (option == 1)

        {

            cout << "Text: " << text << endl;

            cout << "Text encrypted with Substitution: " << Substitute::getEncryptS(text, code) << endl;

            cout << "Text decrypted with Substitution Cipher: " << Substitute::getDecryptS(Substitute::getEncryptS(text, code), code) << endl;



        }

        

        else if (option == 2)

        {

            cout << "Text: " << text << endl;

            cout << "Text encrpyted with Caesar: " << CaesarCipher::getEncryptC(input, s) << endl;

            cout << "Text decrpyted with Caesar: " << CaesarCipher::getDecryptC(CaesarCipher::getEncryptC(input, s), s) << endl;

        }

        

        else if (option == 3)

        {

            cout << "Text: " << text << endl;

            cout << "Text encrypted with Substitution: " << Substitute::getEncryptS(text, code) << endl;

            cout << "Text decrypted with Substitution: " << Substitute::getDecryptS(Substitute::getEncryptS(text, code), code) << endl;

            cout << "Text encrpyted with Caesar: " << CaesarCipher::getEncryptC(input, s) << endl;

            cout << "Text decrpyted with Caesar: " << CaesarCipher::getDecryptC(CaesarCipher::getEncryptC(input, s), s) << endl;

        }

    }

    return 0;

}