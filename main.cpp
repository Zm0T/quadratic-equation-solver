#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// Parent class
class QuadraticEquation {
public:
    double A, B, C;

    QuadraticEquation(double a = 0, double b = 0, double c = 0) : A(a), B(b), C(c) {}

    void showEquation() const {
        std::ostringstream stream;
        stream << std::fixed;

        if (A != 0) {
            stream << std::setprecision(A == floor(A) ? 0 : 2) << A << "x^2 ";
        }
        if (B != 0) {
            if (B > 0 && !stream.str().empty()) stream << "+ ";
            stream << std::setprecision(B == floor(B) ? 0 : 2) << B << "x ";
        }
        if (C != 0) {
            if (C > 0 && !stream.str().empty()) stream << "+ ";
            stream << std::setprecision(C == floor(C) ? 0 : 2) << C;
        }

        if (stream.str().empty()) {
            cout << "0 = 0" << endl;
        }
        else {
            cout << "Итоговое уравнение: " << stream.str() << " = 0" << endl;
        }
    }
};


// 8 child classes
class FirstQuadraticEquation : public QuadraticEquation {
public:
    FirstQuadraticEquation(double a, double b, double c) : QuadraticEquation(a, b, c) {}

    void showAnswer() {
        cout << "Уравнение верно при любом x" << endl;
    }
};

class SecondQuadraticEquation : public QuadraticEquation {
public:
    SecondQuadraticEquation(double a, double b, double c) : QuadraticEquation(a, b, c) {}

    void showAnswer() {
        cout << "Уравнение имеет единственный корень x, равный 0" << endl;
    }
};

class ThirdQuadraticEquation : public QuadraticEquation {
public:
    ThirdQuadraticEquation(double a, double b, double c) : QuadraticEquation(a, b, c) {}

    void showAnswer() {
        cout << "Уравнение не имеет корней" << endl;
    }
};

class FourthQuadraticEquation : public QuadraticEquation {
public:
    double x_1, x_2;
    bool areComplex;
    FourthQuadraticEquation(double a, double b, double c) : QuadraticEquation(a, b, c), areComplex(false) {
        if (A == 0) {
            cout << "Не квадратное уравнение." << endl;
        }
        else {
            double temp = static_cast<double>(C) / A;
            if (temp < 0) {
                areComplex = true;
            }
            else {
                x_1 = sqrt(temp);
                x_2 = -sqrt(temp);
            }
        }
    }

    void showAnswer() {
        if (areComplex) {
            cout << "Уравнение имеет комплексные корни." << endl;
        }
        else {
            cout << "Данное квадратное уравнение имеет 2 корня:" << endl;
            cout << "Первый корень: " << x_1 << endl;
            cout << "Второй корень: " << x_2 << endl;
        }
    }
};

class FifthQuadraticEquation : public QuadraticEquation {
public:
    double x_1;
    FifthQuadraticEquation(double a, double b, double c) : QuadraticEquation(a, b, c) {
        x_1 = (C / B);
    }

    void showAnswer() {
        cout << "Данное квадратное уравнение имеет один единственный корень:" << x_1 << endl;
    }
};

class SixthQuadraticEquation : public QuadraticEquation {
public:
    double discriminant, x_1, x_2;
    bool isComplex;

    SixthQuadraticEquation(double a, double b, double c) : QuadraticEquation(a, b, c), isComplex(false) {
        discriminant = B * B - 4 * A * C;
        if (discriminant > 0) {
            x_1 = (-B + sqrt(discriminant)) / (2 * A);
            x_2 = (-B - sqrt(discriminant)) / (2 * A);
        }
        else if (discriminant == 0) {
            x_1 = x_2 = -B / (2 * A);
        }
        else {
            isComplex = true;
            x_1 = -B / (2 * A);
            x_2 = sqrt(-discriminant) / (2 * A);
        }
    }

    void showAnswer() {
        if (isComplex) {
            cout << "Данное квадратное уравнение имеет комплексные корни:" << endl;
            cout << "x1 = " << x_1 << " + " << x_2 << "i" << endl;
            cout << "x2 = " << x_1 << " - " << x_2 << "i" << endl;
        }
        else if (discriminant >= 0) {
            cout << "Данное квадратное уравнение имеет следующие корни:" << endl;
            cout << "Первый корень: " << x_1 << endl;
            cout << "Второй корень: " << x_2 << endl;
        }
    }
};

class SeventhQuadraticEquation : public QuadraticEquation {
public:
    SeventhQuadraticEquation(double a, double b, double c) : QuadraticEquation(a, b, c) {}
    void showAnswer() {
        cout << "Данное квадратное уравнение имеет одно единственное решение при x = 0" << endl;
    }
};

class EighthQuadraticEquation : public QuadraticEquation {
public:
    int x_1 = 0;
    double x_2;
    EighthQuadraticEquation(double a, double b, double c) : QuadraticEquation(a, b, c) {
        x_2 = -B / A;
    }

    void showAnswer() {
        cout << "Данное квадратное уравнение имеет два корня:" << endl;
        cout << "Первый равен:" << x_1 << endl;
        cout << "Второй равен" << x_2 << endl;
    }
};

void userChoose();
void userValues(QuadraticEquation& equation);
void programLogic(vector<QuadraticEquation>& history, int& historyIndex);
void secondUserChoose();
void showHistory(const vector<QuadraticEquation>& history, int historyIndex);
void manual();
void about();

// Function to check if a string is a number
bool isNumber(const std::string& s) {
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) { // Check if each character is a digit
            return false;
        }
    }
    return true;
}

// Function to get a numeric value from the user
int getNumberFromUser() {
    std::string input;
    while (true) {
        getline(std::cin, input); // Read the line
        if (isNumber(input)) {
            int number = stoi(input); // Convert the string to an integer
            if (number >= 1) { // Additionally check that the number is not negative
                return number;
            }
        }
        cout << "Ошибка: Введено некорректное значение. Попробуйте еще раз.\n";
    }
}


int main() {
    setlocale(LC_ALL, "Russian");
    int start = 0;
    bool readInstructions = false; // Flag indicating whether the instruction was shown
    vector<QuadraticEquation> history; // Vector for storing history
    int historyIndex = 0; // Index for the current request in history

    while (true) {
        if (!readInstructions) {
            manual(); // Show the instruction only if it has not already been shown
            readInstructions = true;
        }
        start = getNumberFromUser(); // Request a number from the user
        if (start == 1) {
            system("cls");
            int choose = 0;
            while (choose != 4) {
                userChoose();
                choose = getNumberFromUser(); // Request a number from the user

                switch (choose) {
                case 1: {
                    int secondChoose = 1;
                    while (secondChoose == 1) {
                        programLogic(history, historyIndex); // Solving the equation
                        secondUserChoose(); // Menu after solving the equation
                        secondChoose = getNumberFromUser();
                        system("cls");
                    }
                    break;
                }
                case 2:
                    showHistory(history, historyIndex);
                    cout << "Введите 1, чтобы вернуться к начальному меню: ";
                    while (true) {
                        int returnToMenu = getNumberFromUser();
                        if (returnToMenu == 1) {
                            break;
                        }
                        else {
                            cout << "Ошибка: Введите 1, чтобы вернуться к начальному меню." << endl;
                        }
                    }
                    system("cls");
                    break;
                case 3:
                    about();
                    cout << "Введите 1, чтобы вернуться к начальному меню: ";
                    while (true) {
                        int returnToMainMenu = getNumberFromUser();
                        if (returnToMainMenu == 1) {
                            break;
                        }
                        else {
                            cout << "Ошибка: Введите 1, чтобы вернуться к начальному меню." << endl;
                        }
                    }
                    system("cls");
                    break;
                default:
                    cout << "Данного пункта не существует, попробуйте еще раз" << endl;
                    break;
                }
            }
            break; // Exit the endless loop after successfully running the program
        }
        else {
            cout << "Ознакомьтесь с инструкцией еще раз и введите цифру 1" << endl;
        }
    }

    return 0;
}




// Selection menu
void userChoose() {
    cout << "----------------------------------------" << endl;
    cout << "|          Решатель квадратных         |" << endl;
    cout << "|            уравнений v4.2            |" << endl;
    cout << "----------------------------------------" << endl;
    cout << "|   Выберите действие:                 |" << endl;
    cout << "|   1. Решить квадратное уравнение     |" << endl;
    cout << "|   2. История запросов                |" << endl;
    cout << "|   3. О приложении                    |" << endl;
    cout << "|   4. Завершить программу             |" << endl;
    cout << "----------------------------------------" << endl;
}

// User input coefficients
void userValues(QuadraticEquation& equation) {
    double A, B, C;
    char nextChar;
    string input;

    cout << "Введите коэффициенты A, B и C: " << endl;

    // Enter coefficient A
    cout << "Коэффициент A: ";
    while (true) {
        getline(cin, input); // Read the line
        size_t comma_pos = input.find(','); // Search for a comma in a string
        if (comma_pos != string::npos) {
            input[comma_pos] = '.'; // Replace comma with dot
        }
        stringstream ss(input);
        if (ss >> A && ss.eof()) { // Check if the input is a number
            equation.A = A;
            break;
        }
        cout << "Ошибка: введите корректное число для коэффициента A: ";
    }

    // Enter coefficient B
    cout << "Коэффициент B: ";
    while (true) {
        getline(cin, input); // Read the line
        size_t comma_pos = input.find(','); // Search for a comma in a string
        if (comma_pos != string::npos) {
            input[comma_pos] = '.'; // Replace comma with dot
        }
        stringstream ss(input);
        if (ss >> B && ss.eof()) { // Check if the input is a number
            equation.B = B;
            break;
        }
        cout << "Ошибка: введите корректное число для коэффициента B: ";
    }

    // Enter coefficient C
    cout << "Коэффициент C: ";
    while (true) {
        getline(cin, input); // Read the line
        size_t comma_pos = input.find(','); // Search for a comma in a string
        if (comma_pos != string::npos) {
            input[comma_pos] = '.'; // Replace comma with dot
        }
        stringstream ss(input);
        if (ss >> C && ss.eof()) { // Check if the input is a number
            equation.C = C;
            break;
        }
        cout << "Ошибка: введите корректное число для коэффициента C: ";
    }
}



void drawGraph(const QuadraticEquation& equation) {
    // Get coefficients from an object of the Quadratic Equation class
    double A = equation.A;
    double B = equation.B;
    double C = equation.C;

    // send data to python function
    std::string command = "python link/draw_graph.py " + std::to_string(A) + " " + std::to_string(B) + " " + std::to_string(C);

    // Call the Python script
    int result = std::system(command.c_str());

    // Check the result of the call
    if (result != 0) {
        std::cerr << "Ошибка: Не удалось вызвать скрипт для построения графика." << std::endl;
    }
}

void programLogic(vector<QuadraticEquation>& history, int& historyIndex) {
    QuadraticEquation eq;
    userValues(eq); // Get values from the user
    eq.showEquation(); // Show the equation

    // Adding a request to history
    if (history.size() < 20) {
        history.push_back(eq);
    }
    else {
        // If the history is full, remove the oldest element and add a new one
        history.erase(history.begin());
        history.push_back(eq);
    }

    historyIndex = (historyIndex + 1) % 20;

    if (eq.A == 0 && eq.B == 0 && eq.C == 0) {
        FirstQuadraticEquation eq_1(eq.A, eq.B, eq.C);
        eq_1.showAnswer();
    }
    else if (eq.A != 0 && eq.B == 0 && eq.C == 0) {
        SecondQuadraticEquation eq_2(eq.A, eq.B, eq.C);
        eq_2.showAnswer();
    }
    else if (eq.A == 0 && eq.B == 0 && eq.C != 0) {
        ThirdQuadraticEquation eq_3(eq.A, eq.B, eq.C);
        eq_3.showAnswer();
    }
    else if (eq.A != 0 && eq.B == 0 && eq.C != 0) {
        FourthQuadraticEquation eq_4(eq.A, eq.B, eq.C);
        eq_4.showAnswer();
        drawGraph(eq);
    }
    else if (eq.A == 0 && eq.B != 0 && eq.C != 0) {
        FifthQuadraticEquation eq_5(eq.A, eq.B, eq.C);
        eq_5.showAnswer();
        drawGraph(eq);
    }
    else if (eq.A != 0 && eq.B != 0 && eq.C != 0) {
        SixthQuadraticEquation eq_6(eq.A, eq.B, eq.C);
        eq_6.showAnswer();
        drawGraph(eq);
    }
    else if (eq.A == 0 && eq.B != 0 && eq.C == 0) {
        SeventhQuadraticEquation eq_7(eq.A, eq.B, eq.C);
        eq_7.showAnswer();
        drawGraph(eq);
    }
    else {
        EighthQuadraticEquation eq_8(eq.A, eq.B, eq.C);
        eq_8.showAnswer();
        drawGraph(eq);
    }
}


// Меню после решения квадратного уравнения
void secondUserChoose() {
    cout << "----------------------------------------" << endl;
    cout << "|    Выберите следующее действие:      |" << endl;
    cout << "|    1. Ввести новые коэффициенты      |" << endl;
    cout << "|    2. Вернуться к первоначальному    |" << endl;
    cout << "|       меню                           |" << endl;
    cout << "----------------------------------------" << endl;
}

void showHistory(const vector<QuadraticEquation>& history, int historyIndex) {
    cout << "----------------------------------------" << endl;
    cout << "|            История запросов:         |" << endl;
    for (int i = 0; i < history.size(); ++i) {
        cout << "|   Запрос " << (i + 1) << ": ";
        history[i].showEquation(); // Show each equation in history
    }
    cout << "----------------------------------------" << endl;
}


void manual() {
    cout << "----------------------------------------" << endl;
    cout << "|    Инструкция по эксплуатации        |" << endl;
    cout << "|      программы для решения           |" << endl;
    cout << "|        квадратных уравнений v4.3     |" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1. Выбор действия:" << endl;
    cout << "   - Главное меню предлагает три действия:" << endl;
    cout << "     1. Решить квадратное уравнение." << endl;
    cout << "     2. Посмотреть историю запросов." << endl;
    cout << "     3. Завершить программу." << endl;
    cout << endl;
    cout << "2. Решение квадратного уравнения:" << endl;
    cout << "   - Выберите действие \"Решить квадратное уравнение\" (введите '1')." << endl;
    cout << "   - Введите значения коэффициентов квадратного уравнения A, B, и C." << endl;
    cout << "   - Ввод дробных чисел должен производиться с использованием точки (например, 3.14)." << endl;
    cout << "   - После ввода коэффициентов программа рассчитает и выведет на экран результат." << endl;
    cout << "   - Затем будет предложено выбрать следующее действие:" << endl;
    cout << "     - Ввести новые коэффициенты (введите '1')." << endl;
    cout << "     - Вернуться к главному меню (введите '2')." << endl;
    cout << endl;
    cout << "3. Просмотр истории запросов:" << endl;
    cout << "   - Выберите действие \"История запросов\" (введите '2')." << endl;
    cout << "   - Программа выведет на экран историю последних 20 запросов с коэффициентами квадратных уравнений и результатами их решений." << endl;
    cout << endl;
    cout << "4. Завершение программы:" << endl;
    cout << "   - Если вы хотите завершить программу, выберите действие \"Завершить программу\" (введите '3')." << endl;
    cout << endl;
    cout << "5. Ошибки ввода:" << endl;
    cout << "   - В случае некорректного ввода (например, ввод буквы вместо числа) программа сообщит об ошибке и попросит ввести значение заново." << endl;
    cout << endl;
    cout << "6. Дополнительные функции:" << endl;
    cout << "   - При решении квадратного уравнения программа определяет тип уравнения и его корни, а также может отобразить график уравнения." << endl;
    cout << "   - В истории запросов отображаются последние 20 введенных уравнений с их корнями или указанием на их отсутствие." << endl;
    cout << endl;
    cout << "7. Повторный запуск:" << endl;
    cout << "   - После завершения программы вы можете повторно запустить ее для решения новых уравнений или просмотра истории запросов." << endl;
    cout << "----------------------------------------" << endl;
    cout << "Для продолжения введите цифру 1" << endl;
}

void about() {
    cout << "----------------------------------------" << endl;
    cout << "|           О программе                |" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Данное приложение разработано в рамках курсовой работы на тему:" << endl;
    cout << "\"Решатель квадратных уравнений\"." << endl;
    cout << endl;
    cout << "Основная функция программы заключается в возможности решения" << endl;
    cout << "квадратных уравнений, визуализации результатов и хранения истории запросов." << endl;
    cout << endl;
    cout << "Программа написана на языке C++ и имеет открытый исходный код." << endl;
    cout << "Исходный код доступен для просмотра и скачивания на GitHub по ссылке:" << endl;
    cout << "https://github.com/Zm0T/quadratic-equation-solver" << endl;
    cout << endl;
    cout << "Этот проект представляет собой отличный ресурс для обучения и" << endl;
    cout << "демонстрации принципов программирования и математических вычислений." << endl;
    cout << endl;
    cout << "Автор: ZmoT" << endl;
    cout << "----------------------------------------" << endl;
}
