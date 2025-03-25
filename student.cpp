#include <iostream>
#include <fstream>

class Student
{
private:
    int studentID = 1;
    std::string firstName = "Gulraiz";
    std::string lastName = "Bari";
    int age = 22;

public:
    Student() {};
    Student(int ID, std::string first, std::string last, int age)
        : studentID(ID), firstName(first), lastName(last), age(age)
    {
    }

    int getID() const
    {
        return studentID;
    }

    std::string getFirstName() const
    {
        return firstName;
    }

    std::string getLastName() const
    {
        return lastName;
    }

    int getAge() const
    {
        return age;
    }

    void printInfo() const
    {
        std::cout << getFirstName() << " " << getLastName() << " " << getAge() << " " << getID() << " " << std::endl;
    }
};

class Course
{
    std::string name = "Course";
    std::vector<Student> students;

public:
    Course() {};
    Course(const std::string &courseName) : name(courseName) {};

    void AddStudent(const Student &std)
    {
        students.push_back(std);
    }

    const std::vector<Student> &getStudents() const
    {
        return students;
    }

    void ReadFromFile(const std::string &fileName)
    {
        std::ifstream InputFile(fileName);
        if (!InputFile)
        {
            std::cout << "No Input File exists by the given name!" << std::endl;
            return;
        }
        std::string firstName;
        std::string lastName;
        int id;
        int age;

        while (InputFile >> firstName)
        {
            InputFile >> lastName >> id >> age;
            AddStudent(Student(id, firstName, lastName, age));
        }
    }

    void printCourse() const
    {
        for (const auto &student : students)
        {
            student.printInfo();
        }
        std::cout << "" << std::endl;
    }
};

//  ****** const Correctness ******
// const std::vector<Student> &getStudents() const
// -> The const in the start represents that the returned value from the function cannot be changed.
// -> The const at the end represents that the function won't change the actual class variables.

int main(int argc, char *argv[])
{
    Student s1;
    const Student s2(15, "Gulraiz", "Bari", 22);
    Student s3(2, "John", "Smith", 25);

    // s1.printInfo();
    // s3.printInfo();

    // Course c1;
    Course c2;
    c2.AddStudent(s1);
    c2.AddStudent(s2);
    c2.AddStudent(s3);
    c2.printCourse();

    Course c3("COMP 450");
    c3.ReadFromFile("./students.txt");
    c3.printCourse();

    return 0;
};
