#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int menu();
int main() {
    cout << "Hello, which conversion do you want to perform? " << endl;
    int menuChoice;
    while ( (menuChoice = menu()) != 5) {
        if (menuChoice==1) {
            //convert binary to others
            cout << "Enter a binary number (20 digits maximum): ";
            unsigned long long int binary;
            int dec=0,remainder,i=0;
            cin >> binary;
            //binary to decimal
            while (binary != 0) {
                remainder = binary % 10;
                dec += remainder * pow(2,i);
                i++;
                binary /= 10;
            }
            i=1;
            //binary to octal
            int temp = dec, octal = 0;
            while (temp != 0) {
                    octal += (temp % 8) * i;
                    temp /= 8;
                    i *= 10;
            }
            //binary to hexadecimal
            i=1;
            temp = dec;
            int hex[100];
            while (temp != 0) {
               hex[i] = temp % 16;
               temp /= 16;
               i++;
              }
            cout << "The decimal equivalent is: " << dec << endl;
            cout << "The octal equivalent is: " << octal << endl;
            cout << "The hexadecimal equivalent is: ";
            for (int j = i - 1; j > 0; j--) {
                if (hex[j] > 9)
                    cout << (char)(hex[j] + 55);
                else
                    cout << hex[j];
            }
            cout << endl << "\n";
        }
        //convert decimal to others
        else if (menuChoice==2) {
            int dec;
            cout << "Enter decimal number (positive): ";
            cin >> dec;
            long long int binary = 0;
            int remainder, i = 1,temp=dec,octal=0;
            //decimal to binary
            while (temp!=0) {
                remainder = temp % 2;
                temp /= 2;
                binary += remainder*i;
                i *= 10;
            }
            //decimal to octal
            temp = dec;
            i=1;
            while (temp !=0) {
                remainder = temp % 8;
                temp /= 8;
                octal += remainder * i;
                i *= 10;
            }
            //decimal to hexadecimal
            int hex[100];
            temp = dec;
            i=1;
            while (temp != 0) {
                hex[i] = temp % 16;
                temp /= 16;
                i++;
            }
            cout << "The binary equivalent of is: " << binary << endl;
            cout << "The octal equivalent of is: " << octal << endl;
            cout << "The hexadecimal equivalent is: ";
            for (int j = i - 1; j > 0; j--) {
                if (hex[j] > 9)
                    cout << (char)(hex[j] + 55);
                else
                    cout << hex[j];
            }
            cout << endl << "\n";
        }
        //convert octal to others
        else if (menuChoice==3) {
            int octal,dec=0,remainder,i=0,temp;
            int hex[100];
            long long int binary=0;
            cout << "Enter octal number: ";
            cin >> octal;
            //octal to decimal
            while (octal != 0) {
                remainder = octal % 10;
                dec += remainder * pow(8,i);
                i++;
                octal /= 10;
            }
            //octal to binary
            temp=dec;
            i=1;
            while (temp != 0) {
                remainder = temp % 2;
                temp /= 2;
                binary += remainder*i;
                i *= 10;
            }
            //octal to hexadecimal
            temp=dec;
            i=1;
            while (temp != 0) {
                hex[i] = temp % 16;
                temp /= 16;
                i++;
            }
            cout << "The binary equivalent of is: " << binary << endl;
            cout << "The decimal equivalent of is: " << dec << endl;
            cout << "The hexadecimal equivalent is: ";
            for (int j = i - 1; j > 0; j--) {
                if (hex[j] > 9)
                    cout << (char)(hex[j] + 55);
                else
                    cout << hex[j];
            }
            cout << endl << "\n";
        }
        //convert hexadecimal to others
        else if (menuChoice==4) {
            char hex[100];
            int dec=0,octal=0,b = 0;
            long long int binary=0;
            cout << "Enter Hexadecimal number: ";
            cin >> hex;
            //hexadecimal to decimal
            for (int i=strlen(hex)-1;i>=0;i--) {
                if (hex[i] >= '0' && hex[i]<='9') {
                    dec += (hex[i]-48) * pow(16,b);
                    b++;
                }
                else if (hex[i] >= 'A' && hex[i] <= 'F') {
                    dec += (hex[i]-55) * pow(16,b);
                    b++;
                }
            }
            //hexadecimal to binary
            int i=1,remainder,temp=dec;
            while (temp!=0) {
                remainder = temp % 2;
                temp /= 2;
                binary += remainder*i;
                i *= 10;
            }
            //hexadecimal to octal
            i=1;
            temp=dec;
            while (temp != 0) {
                octal += (temp % 8) * i;
                temp /= 8;
                i *= 10;
            }
            cout << "The binary equivalent of is: " << binary << endl;
            cout << "The octal equivalent of is: " << octal << endl;
            cout << "The decimal equivalent of is: " << dec << endl;
        }
        else if (menuChoice==5)
            break;
    }
    cout << "Thank you for using this program. Good Bye" << endl;
    return 0;
}
int menu() {
    int userOption;
    do {
        cout << "  Conversion Menu" << endl;
        cout << "=====================" << endl;
        cout << "1. Binary to Decimal, Octal and Hexadecimal" << endl;
        cout << "2. Decimal to Binary, Octal and Hexadecimal" << endl;
        cout << "3. Octal to Binary, Decimal and Hexadecimal" << endl;
        cout << "4. Hexadecimal to Binary, Octal and Decimal" << endl;
        cout << "5. Exit" << endl;
        cin >> userOption;
    //If the input is not valid, yield an error and a message
    if (cin.fail()){
            //Input must be a number
			cerr << "Invalid input, please try again, remember to input a number" << endl;
			cin.clear();
			cin.ignore(255, '\n');
			continue;
		}
		if (userOption > 0 && userOption <= 5)
			break;
		else
            //Input must be from 0 to 8
			cerr << "You made an incorrect choice, please input a valid option between 1 - 5" << endl;
	} while (true);
        return userOption;
}
