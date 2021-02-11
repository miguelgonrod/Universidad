#include <iostream>
using namespace std;
int main()
{
    float grade1, grade2, grade3, grade4, grade5, finalGrade;
    cout << "Ingresa la nota del parcial 1: \n";
    cin >> grade1;
    cout << "Ingresa la nota del parcial 2: \n";
    cin >> grade2;
    cout << "Ingresa la nota del parcial 3: \n";
    cin >> grade3;
    cout << "Ingresa la nota de quices y tareas: \n";
    cin >> grade4;
    cout << "Ingresa la nota de el proyecto final: \n";
    cin >> grade5;
    grade1 = grade1 * 0.2;
    grade2 = grade2 * 0.25;
    grade3 = grade3 * 0.25;
    grade4 = grade4 * 0.15;
    grade5 = grade5 * 0.15;
    finalGrade = grade1 + grade2 + grade3 + grade4 + grade5;
    cout << "Tu nota final es de: " << finalGrade;
    return 0;
}
