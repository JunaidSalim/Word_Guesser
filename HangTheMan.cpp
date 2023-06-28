//TASK 2: HANG THE MAN
//NAME: JUNAID SALEEM
//REG NO: 2022243
//SECTION: B
//INSTRUCTOR: SIR ZAHID HALEEM

/*NOTE: I have made this for pre-defined countries names;
If you want a change in names[] array then also change "total_names" and "max_name_length" in accordance with it*/

#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

int t_num(char a[]);           // Function to calculate no of characters in a string (cities/counties names)
void clrscr();                 //Function to clear screen
void hangman(int);             //Function to Hang the man
bool check(char[], char);      //Function to check that entered character should be entered at once and not repeated
const int total_names = 9;     // TOTAL NO OF NAMES IN LIST
const int max_name_length = 9; // LENGTH OF PESHAWAR(LONGEST STRING) + NULL CHARACTER
int total_chances = 8;		   //TOTAL CHANCES 

int main()
{
    //Countries/Cities Name List
    char names[total_names][max_name_length] = {"CHINA", "USA", "INDIA", "SINDH", "LAHORE", "PESHAWAR", "IRAN", "QATAR", "RUSSIA"};
    
    //Length of string written against its index
    int name_size[total_names];
    for (int i = 0; i < total_names; i++)
    {
        name_size[i] = t_num(names[i]);
    }
    
    //For Random Number Selection
    srand(time(0));

    // Storing Index of Computer Selected Index
    int sname_index = rand() % total_names; 

    //Storing name of country/city located at Index
    char *s_name = names[sname_index];
    char i_name[name_size[sname_index]];

    //Printing Dashes according to number of characters in country/city name
    cout << endl
         << "DASHES ACCORDING TO NUMBER OF CHARACTERS IN COUNTRY/CITY NAME:\n";
    for (int i = 0; i < name_size[sname_index]; i++)
    {
        i_name[i] = '_';
        cout << "_ ";
    }

    int i = 0;
    int count = 0, ch;
    char a, b[16];
    int mistakes = 0;

    /*REMEMBER: MISTAKES ARE DIFFERENT FROM CHANCES:
    IF YOU REPEAT CHARACTERS,IT WIll ONLY COUNTED AS MISTAKE AND CHANCES WILL NOT REDUCE,
    WHILE IF YOU INPUT CHARACTER DOESNOT MATCHES, IT WILL BE COUNTED AS BOTH MISTAKE AND WILL ASLO REDUCES CHANCES.*/

	//Whichever conditions meets first loop will terminate
	//If you want loop to continue until both conditions are met then change OR operator with AND operator in while condition bracket
    while(total_chances != 0 && mistakes < 12) //Chances will reduce if you entered value doesnot matched
    {
        cout <<endl<< "\nEnter a Character(in CAPITAL) present in Computer selected Country Name.Remeber not to Repeat Characters: \n";
        cin >> a;
        clrscr();      //Clearing screen for every input
        ch = check(b, a); //Making sure that character is not repeated
        if (ch == 1) //if character is not repeated
        {
            int ch1 = 0;
            for (int i = 0; i < name_size[sname_index]; i++)
            {
                if (a == s_name[i])
                {
                    i_name[i] = a;
                    cout << "\nCORRECT!\n";
                    for(int i=0;i<name_size[sname_index];i++)
                    {
                    	cout<<i_name[i]<<" ";
					}
                    count++;
                    ch1++;
                }
            }
            if (ch1 == 0)
            {
                total_chances--;
                mistakes++;
                cout << "WRONG\n";
                for(int i=0;i<name_size[sname_index];i++)
                    {
                    	cout<<i_name[i]<<" ";
					}
                cout << "\nCHANCES LEFT: " << total_chances << endl;
                cout << "MISTAKES DONE: " << mistakes << endl;
                hangman(mistakes);
                if (total_chances == 0)
                {
                    cout << "\nYOU HAVE NO CHANCE LEFT!!! YOU LOST!\n";
                    cout << "THE COUNTRY/CITY NAME WAS:\n"
                         << s_name;
                }
            }
            if (count == name_size[sname_index])
            {
                cout << "\nCONGRATULATIONS!!!.\nYOU WON\n";
                cout << "THE COUNTRY/CITY NAME WAS:\n";
                for (int i = 0; i < name_size[sname_index]; i++)
                {
                    cout << i_name[i];
                }
                break;
            }
        }
        else if (ch == 0) //if character is repeated
        {
            cout << "\nDONT REPEAT CHARACTERS!!!\n";
            mistakes++;
            cout << "MISTAKES DONE: " << mistakes << endl;
            hangman(mistakes);
        }
    }
    
    return 0;
}
int t_num(char a[])
{
    int i = 0, count = 0;
    while (a[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}
void clrscr()
{
    system("cls");
}

bool check(char b[], char a)
{
    static int z = 0;
    int count = 0;
    for (int k = 0; k < 16; k++)
    {
        if (a == b[k])
        {
            return 0;
        }
        else
        {
            count++;
        }
    }
    if (count == 16)
    {
        b[z] = a;
        z++;
        return 1;
    }
}

void hangman(int a)
{
    if (a == 11 || a > 11)
    {
        cout << "(  . .  )\n";
        cout << "    .	\n";
        cout << "/   |   \\  " << endl;
        cout << "    |	\n";
        cout << "   / \\	\n";
    }
    else if (a == 10)
    {
        cout << "(  .    )\n";
        cout << "    .	\n";
        cout << "/   |   \\  " << endl;
        cout << "    |	\n";
        cout << "   / \\	\n";
    }
    else if (a == 9)
    {
        cout << "(       )\n";
        cout << "    . 	\n";
        cout << "/   |   \\  " << endl;
        cout << "    |	\n";
        cout << "   / \\	\n";
    }
    else if (a == 8)
    {
        cout << "(       )\n";
        cout << "     	\n";
        cout << "/   |   \\  " << endl;
        cout << "    |	\n";
        cout << "   / \\	\n";
    }
    else if (a == 7)
    {
        cout << "(        \n";
        cout << "     	\n";
        cout << "/   |   \\  " << endl;
        cout << "    |	\n";
        cout << "   / \\	\n";
    }
    else if (a == 6)
    {
        cout << "         \n";
        cout << "     	\n";
        cout << "/   |   \\  " << endl;
        cout << "    |	\n";
        cout << "   / \\	\n";
    }
    else if (a == 5)
    {
        cout << "         \n";
        cout << "     	\n";
        cout << "    |   \\  " << endl;
        cout << "    |	\n";
        cout << "   / \\	\n";
    }
    else if (a == 4)
    {
        cout << "         \n";
        cout << "     	\n";
        cout << "    |    \n";
        cout << "    |	\n";
        cout << "   / \\	\n";
    }
    else if (a == 3)
    {
        cout << "         \n";
        cout << "     	\n";
        cout << "         \n";
        cout << "    |	\n";
        cout << "   / \\	\n";
    }
    else if (a == 2)
    {
        cout << "         \n";
        cout << "     	\n";
        cout << "         \n";
        cout << "     	\n";
        cout << "   / \\	\n";
    }
    else if (a == 1)
    {
        cout << "         \n";
        cout << "     	\n";
        cout << "         \n";
        cout << "     	\n";
        cout << "   /  	\n";
    }
}