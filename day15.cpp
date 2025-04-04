#include <iostream>
#include <string>
using namespace std;

class University {
public:
    static string universityName;

    final void getUniversityDetails() const {
        cout << "University Name: " << universityName << endl;
    }

    static void changeUniversityName(const string& name) {
        universityName = name;
    }
};

string University::universityName = "XYZ University";

class Student {
private:
    int studentID;
    string studentName;
    string course;
    const int admissionYear; // Final attribute, can't be modified after assignment

public:
    // Static attribute to track total number of students
    static int totalStudents;

    // Constructor to initialize student details and increment totalStudents
    Student(int id, const string& name, const string& course, int admissionYear)
        : studentID(id), studentName(name), course(course), admissionYear(admissionYear) {
        totalStudents++;
    }

    // Function to display student details
    void displayStudentDetails() const {
        cout << "Student ID: " << studentID << endl;
        cout << "Student Name: " << studentName << endl;
        cout << "Course: " << course << endl;
        cout << "Admission Year: " << admissionYear << endl;
    }

    // Function to get total number of students
    static int getTotalStudents() {
        return totalStudents;
    }
};

int Student::totalStudents = 0;

int main() {
    cout << "Initial University Details:" << endl;
    University u1;
    u1.getUniversityDetails();

    // Change the university name
    cout << "\nChanging University Name..." << endl;
    University::changeUniversityName("ABC University");

    cout << "\nUpdated University Details:" << endl;
    u1.getUniversityDetails();

    cout << "\nCreating Students..." << endl;
    Student s1(1, "John Doe", "Computer Science", 2021);
    Student s2(2, "Jane Smith", "Electrical Engineering", 2020);

    cout << "\nStudent Details:" << endl;
    s1.displayStudentDetails();
    cout << endl;
    s2.displayStudentDetails();

    cout << "\nTotal Students Enrolled: " << Student::getTotalStudents() << endl;

    return 0;
}
