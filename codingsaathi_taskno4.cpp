
#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<chrono>
#include<thread>
#include <ctime>

using namespace std;
using namespace chrono_literals;

void login();
void registr();
void forgot();
void clearScreen();
void runQuiz();

int main() {

    int choice;
 #pragma warning(disable : 4996)

    cout << "-----------------------------------------------------------------------\n\n";
    cout << "                   ->   Welcome to EXAM PORTAL <-                        \n\n";
    cout << "-------------------------------------------------------------------------\n\n";
    time_t now = time(0);
    const char* date_time = ctime(&now);
    cout << date_time << endl;
    cout << "--------------- Select the option from the given choices --------------\n\n";


    cout << "1.LOGIN TO YOUR ACCOUNT:" << endl;
    cout << "2.REGISTER NEW USER:" << endl;
    cout << "3.FORGOT YOUR PASSWORD/USERNAME:" << endl;
    cout << "4.START THE TEST:" << endl;
    cout << "5.LOGOUT FROM THE EXAM PORTAL:" << endl;
    cout << "\n Kindly Enter your choice :";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        registr();
        break;
    case 3:
        forgot();
        break;
    case 4:
        runQuiz();
        break;
    case 5:
        cout << "Thanks for using our Exam Portal.Session is closing and you are LOGGED OUT.Wishing you best of luck for your future endeavours\n\n";
        break;
    default:
        system("cls");
        cout << "Sorry wrong choice, Try again..\n" << endl;
        main();
    }
    return 0;

}

void login()
{
    int count = 0;
    string user, pass, u, p;
    system("cls");
    cout << "please enter the following details" << endl;
    cout << "USERNAME :";
    cin >> user;
    cout << "PASSWORD :";
    cin >> pass;

    ifstream input("database.txt");
    while (input >> u >> p)
    {
        if (u == user && p == pass)

        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << "\nHello" << user << "\n<LOGIN SUCCESSFUL>\nThanks for logging in..\n";
        cin.get();
        cin.get();
        main();
    }
    else
    {
        cout << "\nLOGIN ERROR\nPlease check your username and password\n";
        main();
    }
}

bool askQuestion(const string& question, const string& optionA, const string& optionB, const string& optionC, const string& correctAnswer)
{
    cout << question << endl;
    cout << "A) " << optionA << endl;
    cout << "B) " << optionB << endl;
    cout << "C) " << optionC << endl;

    cout << "Your answer (A/B/C): ";
    string userAnswer;
    cin >> userAnswer;

    return (userAnswer == correctAnswer);
}

void runQuiz()
{
    int score = 0;
    const int totalTimeInSeconds = 80;
    const int numberOfQuestions = 10;


    string questions[numberOfQuestions] = {
        "A technique used by codes to convert an analog signal into a digital bit stream is known as?",
        "An optical input device that interprets pencil marks on paper media is?",
        "The brain of any computer system is?",
        "Which of the following computer language is used for artificial intelligence ?",
        "What is the chemical symbol for gold?",
        "The nucleus of an atom consists of?",
        "The most electronegative element among the following is?",
        "Movement of cell against concentration gradient is called?",
        "Plants synthesis protein from?",
        "Which of the following is known as powerhouse of the cell?",
    };

    string optionsA[numberOfQuestions] = {
        "Pulse code modulation",
        "Punch card reader",
        "Memory",
        "COBOL",
        "Au",
        "neutrons and electrons",
        "Fluorine",
        "Osmosis",
        "Amino Acids",
        "Lysosome"
    };

    string optionsB[numberOfQuestions] = {
        "Pulse stretcher",
        "O.M.R",
        "CPU",
        "PROLOG",
        "Ag",
        "electrons only",
        "Chlorine",
        "Diffusion",
        "Starch",
        "Mitochondria"
    };

    string optionsC[numberOfQuestions] = {
        "Query processing",
        "Magnetic tape",
        "ALU",
        "FORTRAN",
        "Ge",
        "neutrons and protons",
        "Silicon",
        "Active Transport",
        "Glucose",
        "Golgi apparatus",
    };

    string correctAnswers[numberOfQuestions] = {
        "A",
        "B",
        "B",
        "B",
        "A",
        "C",
        "A",
        "C",
        "A",
        "B"
    };

    auto startTime = chrono::high_resolution_clock::now();
    auto endTime = startTime + chrono::seconds(totalTimeInSeconds);

    while (chrono::high_resolution_clock::now() < endTime)
    {
        clearScreen();
        int questionIndex = rand() % numberOfQuestions;

        if (askQuestion(questions[questionIndex], optionsA[questionIndex], optionsB[questionIndex], optionsC[questionIndex], correctAnswers[questionIndex]))
        {
            cout << "Correct! You earn 1 point." << endl;
            score++;
        }
        else
        {
            cout << "Incorrect. The correct answer was " << correctAnswers[questionIndex] << "." << endl;
        }

        
        this_thread::sleep_for(2s);
    }

    clearScreen();
    cout << "Time's up! Your final score is: " << score << " out of " << totalTimeInSeconds / 2 << " points." << endl;

    main();


}


void clearScreen()
{
    cout << "\033[2J\033[H";
}

void registr()
{

    string reguser, regpass, ru, rp;
    system("cls");
    cout << "Enter the username :";
    cin >> reguser;
    cout << "\nEnter the password :";
    cin >> regpass;

    ofstream reg("database.txt", ios::app);
    reg << reguser << ' ' << regpass << endl;
    system("cls");
    cout << "\nRegistration Sucessful\n";
    main();


}


void forgot()
{
    int ch;
    system("cls");
    cout << "Forgotten your username or password?Don't worry we're here to assist you\n";
    cout << "1.Search your id by username" << endl;
    cout << "2.Search your id by password" << endl;
    cout << "3.Main menu" << endl;
    cout << "Enter your choice :";
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        int count = 0;
        string searchuser, su, sp; 
        cout << "\nEnter the username that you remember :";
        cin >> searchuser;

        ifstream searchu("database.txt");
        while (searchu >> su >> sp)
        {
            if (su == searchuser)
            {
                count = 1;
            }
        }
        searchu.close();
        if (count == 1)
        {
            cout << "\n\nYour account has been identified:\n";
            cout << "\nYour password is :" << sp;
            cin.get();
            cin.get();
            system("cls");
            main();
        }
        else
        {
            cout << "\nSorry the username which you entered is invalid and it is not available in our database \n";
            cout << "\nContact the system administrator for more information\n";
            cin.get();
            cin.get();
            main();
        }
        break;
    }
    case 2:
    {
        int count = 0;
        string searchpass, su2, sp2;
        cout << "\nEnter the password that you remember:";
        cin >> searchpass;

        ifstream searchp("database.txt");
        while (searchp >> su2 >> sp2)
        {
            if (sp2 == searchpass)
            {
                count = 1;
            }
        }
        searchp.close();
        if (count == 1)
        {
            cout << "\nYour password is found in our database: \n";
            cout << "\nYour Id is : " << su2;
            cout << "Kindly note it down for future use";
            cin.get();
            cin.get();
            system("cls");
            main();
        }
        else
        {
            cout << "Sorry, We are unable to find the password in our database \n";
            cout << "\nkindly contact your administrator for more information\n";
            cin.get();
            cin.get();
            main();
        }

        break;
    }

    case 3:
    {
        cin.get();
        main();
    }
    default:
        cout << "Sorry, The choice you entered doesn't exit.Please try again" << endl;
        forgot();
    }

}
