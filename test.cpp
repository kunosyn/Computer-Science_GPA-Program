/*
Made by: Andrew Bordis
Date made: 9/7/2021
Project name:
Project description:
*/
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// Checks if given grade is an accepted grade, returns true if grade is, else returns false.
bool accepted_grade(char grade)
{
    char accepted_grades[7] = {'a', 'b', 'c', 'd', 'f'}; // Char array of accepted grades.

    for (int i; i < sizeof(accepted_grades); i++) // Iterates through accepted_grades array.
    {
        if (accepted_grades[i] == grade)
        {
            return true;
        }
        else
        {
            continue;
        }
    }

    return false;
}

bool on_honor_role(char grades[7])
{
    for (int i; i < sizeof(grades); i++) // Iterates through grades.
    {
        if (grades[i] == 'd' || grades[i] == 'f')
        {
            return false; // There is a D or F in the student's grades, meaning they cannot be on the honor role.
        }
    }

    return true; // Didn't already return false, meaning that there are no D's or F's in the Student's grades.
}

string honor_role_type(double gpa)
{
    if (gpa >= 3.8)
    {
        return "High Honor Role";
    }
    else if (gpa >= 3.5)
    {
        return "A Honor Role";
    }
    else if (gpa >= 3.0)
    {
        return "B Honor Role";
    }
}

int main()
{
    // Defining Variables.
    const int NUM_CLASSES = 7;
    char grades[NUM_CLASSES];
    double total_points;

    // Starts grade collection iterations.
    for (int i; i < sizeof(grades); i++) // Iterates for each grade.
    {
        while(true)
        {
           if (i == 0)
            {
                cout << "Enter your grade for class 1" << endl;
            }
            else if (i == 1)
            {
                cout << "Enter your grade for class 2" << endl;
            }
            else if (i == 2)
            {
                cout << "Enter your grade for class 3" << endl;
            }
            else
            {

                cout << "Enter your grade for class " << i << endl;
            }

            cout << "(A/B/C/D/F): ";
            cin >> grades[i];
            cout << endl;

            if (accepted_grade(::tolower(grades[i]))) // If given grade is an accepted grade value, break while true loop, continuing iterations for class grade entering.
            {
                break; // Breaks while true loop.
            }
            else // Given grade was not an accepted grade value.
            {
                system("CLS");
                cout << "The grade you entered is invalid, please try again!" << endl;
                usleep(1000000);
                system("CLS");
                continue;
            }
        }
        system("CLS");
    }

    // Computes total points.
    for (int i; i < sizeof(grades); i++)
    {
        const int A_POINTS = 4;
        const int B_POINTS = 3;
        const int C_POINTS = 2;
        const int D_POINTS = 1;
        const int F_POINTS = 0;

        char selected_grade = ::tolower(grades[i]);
        if (selected_grade == 'a')
        {
            total_points += A_POINTS;
        }
        else if (selected_grade == 'b')
        {
            total_points += B_POINTS;
        }
        else if (selected_grade == 'c')
        {
            total_points += C_POINTS;
        }
        else if (selected_grade == 'd')
        {
            total_points += D_POINTS;
        }
        else
        {
            total_points += F_POINTS;
        }
    }

    double gpa = total_points / NUM_CLASSES; // Computes GPA.

    //
    system("CLS");
    cout << "Your GPA for this grading period is: " << gpa << endl;

    if (on_honor_role(grades))
    {
        cout << "You are on the " << honor_role_type(gpa) << " honor role." << endl;
    }
    else
    {
        cout << "You are not on the honor role." << endl;
    }
}
