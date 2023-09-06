#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<ctime>
#include<chrono>
#include<thread>

using namespace std;

struct MCQ {
    string question;
    string options[4];
    int correctOption;
};
void login();
void registr();
void forgot();
void takeExam();

int main() {

    int choice;
  
    cout << "-----------------------------------------------------------------------\n\n\n";
    cout << "                   ->   Welcome to EXAM PORTAL <-                        \n\n";
    cout << "--------------- Select the option from the given choices --------------\n\n";
    cout << "1.LOGIN TO YOUR ACCOUNT:" << endl;
    cout << "2.REGISTER NEW USER:" << endl;
    cout << "3.FORGOT YOUR PASSWORD/USERNAME:" << endl;
    cout << "4.START THE TEST:" << endl;
    cout << "5.LOGOUT FROTHE EXAM PORTAL:" << endl;
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
        takeExam();
        break;
    case 5:
        cout << "Thanks for using our Exam Portal.Session is closing and you are LOGGED OUT.Wishing you best for your future endeavours\n\n";
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

void takeExam() {
    string user;
    MCQ questions[5];
    questions[0] = { "The brain of any computer system is?", {"A.ALU","B.CPU","C.memory","D.control unit"}, 2 };
    questions[1] = { "Which of the following computer language is used for artificial intelligence?", {"A. COBOL", "B. VERILOG", "C. PROLOG", "D. HTML"}, 3 };
    questions[2] = { "Which of the following is the 1's complement of 10?", {"A. 10", "B. 01", "C. 001", "D.010"}, 2 };
    questions[3] = { "Which one among these is not a primitive datatype?", {"A. int", "B. float", "C. char", "D. array"}, 4 };
    questions[4] = { "Which one among these is not a keyword?", {"A. int", "B. typedef", "C. construct", "D. else"}, 3 };
    

    int score = 0;
    time_t start, end;
    time(&start);

    cout << "Welcome, " << user << "! You have 2 minutes to complete the exam." << endl;
    


    for (int i = 0; i < 5; i++) {
        cout << "Question " << i + 1 << ": " << questions[i].question << endl;
        for (int j = 0; j < 6; j++) {
            cout << questions[i].options[j] << endl;
        }

        int answer;
        cout << "Select your answer (1-4): ";
        cin >> answer;

        if (answer == questions[i].correctOption) {
            score++;
        }
    }
    

    time(&end);
    double elapsed = difftime(end, start);
    int examDurationInSeconds = 120; // 2 minutes
    time_t startTime = time(nullptr);
    time_t currentTime;
    while (true) {
        currentTime = time(nullptr);
        int elapsedSeconds = currentTime - startTime;
        if (elapsedSeconds >= examDurationInSeconds) {
            cout << "Time's up! Submitting the exam..." << endl;
            break;
        }

        cout << "Time remaining: " << (examDurationInSeconds - elapsedSeconds) << " seconds" << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "You scored :" << score << " out of 5." << endl;
    cout << "Time taken: " << elapsed << " seconds." << endl;

    ofstream src("scores.txt", ios::app);
    src << score << ' ' << user << endl;
    system("cls");
    cout << "\nYour username and the marks obtained by you has been uploaded to our databse\n";
    main();

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
        cout << "\nEnter your remembered username :";
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
            cout << "\n\nHurray, account found\n";
            cout << "\nYour password is " << sp;
            cin.get();
            cin.get();
            system("cls");
            main();
        }
        else
        {
            cout << "\nSorry, Your userID is not found in our database\n";
            cout << "\nPlease kindly contact your system administrator for more details \n";
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
        cout << "\nEnter the remembered password :";
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
            cout << "\nYour password is found in the database \n";
            cout << "\nYour Id is : " << su2;
            cin.get();
            cin.get();
            system("cls");
            main();
        }
        else
        {
            cout << "Sorry, We cannot found your password in our database \n";
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
        cout << "Sorry, You entered wrong choice. Kindly try again" << endl;
        forgot();
    }

}
