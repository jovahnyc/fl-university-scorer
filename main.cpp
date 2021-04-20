#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void filedata (vector<string> & major, vector<string>& school) {
    ifstream fin;
    string temp_major;
    string temp_school;
    
    fin.open("majors.txt");      // majors.txt is the name of the file of popular majors
    if(fin.is_open()) {
        
        while(!fin.eof()) {
            getline(fin, temp_major);
            getline(fin, temp_school);
            
            major.push_back(temp_major);
            school.push_back(temp_school);
        }
    fin.close();
    } else {
        cout << "Error while loading the data." << endl;
        }
}

int scoreTracker1 = 0, scoreTracker2 = 0, scoreTracker3 = 0;
int totalScore;

void printWelcome() {
    
    cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
    cout << "Florida University Admissions Probability Calculator" << endl;
    cout << "By entering your current stats, you can see what your chances are to being accepted into one of the major Florida universities!" << endl;
    cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
}

void printMenu () {
    cout << "Press [G] to enter your GPA." << endl;
    cout << "Press [A] to enter ACT score." << endl;
    cout << "Press [S] to enter SAT score." << endl;
    cout << "Press [D] when you are done entering your stats." << endl;
    cout << "Press [P] to see the list of popular majors for each schools" <<endl;
    cout << "Press [Q] to quit." << endl;
}

void gpaReq () {
    double gpa;
    cout << "Please enter weighted GPA using 2 decimal places (ex: if GPA is 4.4, enter 4.40): ";
    cin >> gpa;
        if (gpa >= 4.60) {
            scoreTracker1 += 5;
        }
        else if (gpa >= 4.30) {
            scoreTracker1 += 4;
        }
        else if (gpa >= 4.00) {
            scoreTracker1 += 2;
        }
        else {
            scoreTracker1 += 0;
        }
}

void actReq () {
    int act;
    cout << "Please enter ACT score: ";
    cin >> act;
        if (act >= 30) {
            scoreTracker2 += 3;
        }
        else if (act >= 27) {
            scoreTracker2 += 2;
        }
        else if (act >= 25) {
            scoreTracker2 += 1;
        }
        else {
            scoreTracker2 += 0;
        }
}

void satReq () {
    int sat;
    
    cout << "Please enter SAT score: ";
    cin >> sat;
        if (sat >= 1350) {
            scoreTracker3 += 3;
        }
        else if (sat >= 1250) {
            scoreTracker3 += 2;
        }
        else if (sat >= 1150) {
            scoreTracker3 += 1;
        }
        else {
            scoreTracker3 += 0;
        }
}

void customPlan() {
    vector <char> yes_no(1);
    int user_input;
    
    totalScore = scoreTracker1 + scoreTracker2 + scoreTracker3;
    
    cout << "This is your custom university admissions plan!" << endl;
    cout << "Do any of these majors sound interesting to you? Please enter " << endl;
    cout << "[Y]es or [N]o" << endl;
    cout << "STEM, Business, Psychology, Social Sciences, Pre-Health/Med, Pre-Law" << endl;\
    
    cin >> yes_no.at(0);
    
        if (yes_no.at(0) == 'Y' || yes_no.at(0) == 'y' ) {
            cout << "Choose a major/pathway:" << endl;
            cout << "[1] STEM" << endl;
            cout << "[2] Business" << endl;
            cout << "[3] Social Sciences" << endl;
            cout << "[4] Pre-Health/Med" << endl;
            cout << "[5] Pre-Law" << endl;
            cin >> user_input;
            if (user_input == 1 || user_input == 4) {
                if (totalScore >= 10) {
                    cout << "The best school that you should apply to is UF, UCF, or USF! They have prestigious STEM and Pre-Health/Med program." << endl;
                }
                else if (totalScore >= 6) {
                    cout << "The best place that you should apply to is USF or UCF! They have a well-known STEM and Pre-Health/Med program." << endl;
                }
                else if (totalScore >= 3){
                    cout << "You should apply to FIU." << endl;
                }
                else if (totalScore <= 2) {
                    cout << "You didn't score high enough." << endl;
                }
            }
            else if (user_input == 2 || user_input == 3 || user_input == 5) {
                if (totalScore >= 10) {
                    cout << "The best place to apply is FSU and UF! " << endl;
                }
                else if (totalScore >= 6) {
                    cout << "The best place to apply to FIU! They have a well-known business/social science program." << endl;
                }
                else if (totalScore >= 3) {
                    cout << "You should apply to FIU. They have a well-known business/social science program." << endl;
                }
                else if (totalScore <= 2) {
                    cout << "You didn't score high enough." << endl;
                }

            }
        }
        else if (yes_no.at(0) == 'N' || yes_no.at(0) == 'n') {
            if (totalScore >= 10) {
                cout << "Congratulations on all your hard work! You can apply to UF, FSU, FIU, UCF, or USF and have a pretty good chances of being admitted!" << endl;
            }
            else if (totalScore >= 6) {
                cout << "Good job on working hard. You can apply to FIU, UCF." << endl;
            }
            else if (totalScore >= 3){
                cout << "You can apply to FIU." << endl;
            }
            else if (totalScore <= 2) {
                cout << "You didn't score high enough." << endl;
            }
        }
}

void popular_majors( const vector <string> & major, const vector <string>& school){
    
    for ( int i = 0; i < major.size(); ++i){
        cout << major.at(i) << school.at(i) << endl;
        cout << endl;
      }
}



int main () {
vector<string> major;
 vector<string> school;
    char user_input;

filedata(major, school);

    printWelcome();
    
    do {
        printMenu();
        
        cin >> user_input;
        
        switch (user_input) {
        case 'G':
        case 'g':
            gpaReq();
        break;
                
        case 'A':
        case 'a':
            actReq();
        break;
                
        case 'S':
        case 's':
            satReq();
        break;
                
        case 'D':
        case 'd':
            customPlan();
        break;
               
       case 'P':
        case 'p':
                popular_majors(major, school);
        break;
                
        case 'Q':
        case 'q':
                cout << " Goodbye!" << endl;
        break;

        default:
        cout << "Please enter a valid option." << endl;
        }
    } while (user_input != 'Q' && user_input != 'q');

    return 0;
}

