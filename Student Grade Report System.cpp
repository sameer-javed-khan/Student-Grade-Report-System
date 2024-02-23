#include <iostream>
using namespace std;

int main()
{
    int rollNum[5];
    int csMarks[5];
    int mathMarks[5];
    float percentages[5];
    char grades[5];
    int count = 0;
    char choice;
    int i = 1;

    do {
        cout << "Enter Roll Number of student " << i << ": ";
        cin >> rollNum[count];

        do {
            cout << "Enter Marks for Computer Science of student " << i << ": ";
            cin >> csMarks[count];
            if (csMarks[count] < 0 && csMarks[count] > 100)
            {
                cout << "Marks cannot be negative or greater than 100. Please enter a valid value." << endl;
            }
        } while (csMarks[count] < 0 && csMarks[count] > 100);

        do {
            cout << "Enter Marks for Mathematics of student " << i << ": ";
            cin >> mathMarks[count];
            if (mathMarks[count] < 0 && mathMarks[count] > 100)
            {
                cout << "Marks cannot be negative or greater than 100. Please enter a valid value." << endl;
            }
        } while (mathMarks[count] < 0 && mathMarks[count] > 100);

        percentages[count] = ((csMarks[count] + mathMarks[count]) / 200.0) * 100.0;

        if (percentages[count] >= 91 && percentages[count] <= 100)
        {
            grades[count] = 'A';
        }
        else if (percentages[count] >= 75 && percentages[count] <= 90)
        {
            grades[count] = 'B';
        }
        else if (percentages[count] >= 60 && percentages[count] < 75)
        {
            grades[count] = 'C';
        }
        else if (percentages[count] >= 50 && percentages[count] < 60)
        {
            grades[count] = 'D';
        }
        else
        {
            grades[count] = 'F';
        }

        cout << "Do you want to continue enrolling students? (Y/N): ";
        cin >> choice;
        i++;
        count++;
    } while ((choice == 'Y' || choice == 'y') && count < 5);

    if (choice == 'n' || choice == 'N')
    {
        char advChoice;
        cout << "Do you want to do advanced operations? (Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y')
        {
            do {
                cout << endl;
                cout << "Advanced Operations: " << endl;
                cout << "1. Press 1 to update the Roll Number of a particular Student." << endl;
                cout << "2. Press 2 to update the marks of a particular student for CS." << endl;
                cout << "3. Press 3 to update the marks of CS for all students who are already enrolled." << endl;
                cout << "4. Press 4 to update marks of a particular student for Mathematics." << endl;
                cout << "5. Press 5 to update marks in Mathematics for all students who are already enrolled." << endl;
                cout << "6. Press 6 to sort the data based on generated percentages." << endl;
                cout << "7. Press 7 to delete the record of a particular student." << endl;
                cout << endl;
                cout << "Enter your choice: ";
                cin >> advChoice;

                switch (advChoice)
                {
                case '1': {
                    int currRoll, newRoll;
                    cout << "Enter the previous Roll Number of the student: ";
                    cin >> currRoll;

                    if (currRoll < 0 || currRoll > 100)
                    {
                        cout << "Invalid Roll Number. Please enter a valid value." << endl;
                        break;
                    }

                    bool rollNumberExists = false;
                    for (int i = 0; i < count; i++)
                    {
                        if (rollNum[i] == currRoll)
                        {
                            rollNumberExists = true;
                            break;
                        }
                    }

                    if (!rollNumberExists)
                    {
                        cout << "Roll Number does not exist in the system. Unable to update." << endl;
                        break;
                    }

                    cout << "Enter the new Roll Number of the student: ";
                    cin >> newRoll;
                    for (int i = 0; i < count; i++)
                    {
                        if (rollNum[i] == currRoll)
                        {
                            rollNum[i] = newRoll;
                            break;
                        }
                    }
                    break;
                }
                case '2': {
                    int rollToUpdateCsMark, newCSMarks;
                    cout << "Enter the Roll Number of the student whose CS marks are to be updated: ";
                    cin >> rollToUpdateCsMark;

                    if (rollToUpdateCsMark < 0 || rollToUpdateCsMark > 100)
                    {
                        cout << "Invalid Roll Number. Please enter a valid value." << endl;
                        break;
                    }

                    bool rollNumberExists = false;
                    for (int i = 0; i < count; i++)
                    {
                        if (rollNum[i] == rollToUpdateCsMark)
                        {
                            rollNumberExists = true;
                            break;
                        }
                    }

                    if (!rollNumberExists)
                    {
                        cout << "Roll Number does not exist in the system. Unable to update CS marks." << endl;
                        break;
                    }

                    cout << "Enter the new marks for Computer Science: ";
                    cin >> newCSMarks;

                    if (newCSMarks < 0)
                    {
                        cout << "Marks cannot be negative. Please enter a valid value." << endl;
                        break;
                    }

                    for (int i = 0; i < count; i++)
                    {
                        if (rollNum[i] == rollToUpdateCsMark)
                        {
                            csMarks[i] = newCSMarks;
                            break;
                        }
                    }
                    break;
                }
                case '3': {
                    int newCSMarksAll;
                    cout << "Enter the new marks of Computer Science for all students: ";
                    cin >> newCSMarksAll;

                    if (newCSMarksAll < 0)
                    {
                        cout << "Marks cannot be negative. Please enter a valid value." << endl;
                        break;
                    }

                    for (int i = 0; i < count; i++)
                    {
                        csMarks[i] = newCSMarksAll;
                    }
                    break;
                }
                case '4': {
                    int rollToUpdateMathMark, newMathMarks;
                    cout << "Enter the Roll Number of the student whose Maths marks are to be updated: ";
                    cin >> rollToUpdateMathMark;

                    if (rollToUpdateMathMark < 0 || rollToUpdateMathMark > 100)
                    {
                        cout << "Invalid Roll Number. Please enter a valid value." << endl;
                        break;
                    }

                    bool rollNumberExists = false;
                    for (int i = 0; i < count; i++)
                    {
                        if (rollNum[i] == rollToUpdateMathMark)
                        {
                            rollNumberExists = true;
                            break;
                        }
                    }

                    if (!rollNumberExists) {
                        cout << "Roll Number does not exist in the system. Unable to update Math marks." << endl;
                        break;
                    }

                    cout << "Enter the new marks for Maths: ";
                    cin >> newMathMarks;

                    if (newMathMarks < 0)
                    {
                        cout << "Marks cannot be negative. Please enter a valid value." << endl;
                        break;
                    }

                    for (int i = 0; i < count; i++)
                    {
                        if (rollNum[i] == rollToUpdateMathMark)
                        {
                            mathMarks[i] = newMathMarks;
                            break;
                        }
                    }
                    break;
                }
                case '5': {
                    int newMathMarksAll;
                    cout << "Enter the new marks for Mathematics for all students: ";
                    cin >> newMathMarksAll;

                    if (newMathMarksAll < 0)
                    {
                        cout << "Marks cannot be negative. Please enter a valid value." << endl;
                        break;
                    }

                    for (int i = 0; i < count; i++)
                    {
                        mathMarks[i] = newMathMarksAll;
                    }
                    break;
                }
                case '6': {
                    for (int i = 0; i < count - 1; i++)
                    {
                        for (int j = 0; j < count - i - 1; j++)
                        {
                            if (percentages[j] > percentages[j + 1])
                            {
                                // To swap the rollNum
                                int tempRoll = rollNum[j];
                                rollNum[j] = rollNum[j + 1];
                                rollNum[j + 1] = tempRoll;

                                // To swap the csMarks
                                int tempCS = csMarks[j];
                                csMarks[j] = csMarks[j + 1];
                                csMarks[j + 1] = tempCS;

                                // To swap the mathMarks
                                int tempMath = mathMarks[j];
                                mathMarks[j] = mathMarks[j + 1];
                                mathMarks[j + 1] = tempMath;

                                // To swap the percentages
                                float tempPercentage = percentages[j];
                                percentages[j] = percentages[j + 1];
                                percentages[j + 1] = tempPercentage;

                                // To swap the grades
                                char tempGrade = grades[j];
                                grades[j] = grades[j + 1];
                                grades[j + 1] = tempGrade;
                            }
                        }
                    }
                    break;
                }
                case '7': {
                    int rollDel;
                    cout << "Enter the Roll Number of the student to delete: ";
                    cin >> rollDel;

                    if (rollDel < 0 || rollDel > 100)
                    {
                        cout << "Invalid Roll Number. Please enter a valid value." << endl;
                        break;
                    }

                    bool rollNumberExists = false;
                    for (int i = 0; i < count; i++)
                    {
                        if (rollNum[i] == rollDel)
                        {
                            rollNumberExists = true;
                            break;
                        }
                    }

                    if (!rollNumberExists) {
                        cout << "Roll Number does not exist in the system. Unable to delete." << endl;
                        break;
                    }

                    int j = 0;
                    for (int i = 0; i < count; i++) {
                        if (rollNum[i] != rollDel)
                        {
                            rollNum[j] = rollNum[i];
                            csMarks[j] = csMarks[i];
                            mathMarks[j] = mathMarks[i];
                            percentages[j] = percentages[i];
                            grades[j] = grades[i];
                            j++;
                        }
                    }
                    count = j;
                    break;
                }
                default:
                {
                    cout << "Invalid choice!";
                    break;
                }
                }
                cout << endl;
                cout << "Do you want to perform another advanced operation? (Y/N): ";
                cin >> choice;
            } while (choice == 'Y' || choice == 'y');

            if (choice == 'n' || choice == 'N')
            {
                cout << endl;
                cout << "Student Data:" << endl;
                cout << "Roll No.\tCS Marks\tMath Marks\tPercentage\tGrade" << endl;
                for (int i = 0; i < count; i++)
                {
                    cout << rollNum[i] << "\t\t" << csMarks[i] << "\t\t" << mathMarks[i] << "\t\t" << percentages[i] << "\t\t" << grades[i] << endl;
                }
            }
            else
            {
                cout << "You Entered the wrong choice." << endl;
            }
        }
        else
        {
            cout << endl;
            cout << "Student Data:" << endl;
            cout << "Roll No.\tCS Marks\tMath Marks\tPercentage\tGrade" << endl;
            for (int i = 0; i < count; i++)
            {
                cout << rollNum[i] << "\t\t" << csMarks[i] << "\t\t" << mathMarks[i] << "\t\t" << percentages[i] << "\t\t" << grades[i] << endl;
            }
        }
    }
    else
    {
        cout << "You Entered the wrong choice." << endl;
    }

    return 0;
}