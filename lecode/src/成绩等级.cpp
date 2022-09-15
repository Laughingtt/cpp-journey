//
// Created by tian on 2022/4/11.
//
#include "iostream"
#include "string"

using namespace std;

class Student {
public:
    /**
     * Declare two public attributes name(string) and score(int).
     */
    string name;
    int score;

    /**
     * Declare a constructor expect a name as a parameter.
     */
    Student(string name) {
        this->name = name;
    };

    /**
     * Declare a public method `getLevel` to get the level(char) of this student.
     */
    char getLevel() {
        if (score >= 90) {
            return 'A';
        } else if (score < 90 && score >= 80) {
            return 'B';
        } else if (score < 80 && score >= 60) {
            return 'C';
        } else {
            return 'D';
        }
    }
};

int main() {
    Student s = Student("zhangsan");
    s.score = 85;
    char r = s.getLevel();
    cout << r << endl;

    return 0;
}