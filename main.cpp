#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>   // Для использования std::ostringstream
#include <iomanip>   // Для std::fixed и std::setprecision
using namespace std;

// Родительский класс
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
        } else {
            cout << "Итоговое уравнение: " << stream.str() << " = 0" << endl;
        }
    }
};


// 8 дочерних классов
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
        } else {
            double temp = static_cast<double>(C) / A;
            if (temp < 0) {
                areComplex = true;
            } else {
                x_1 = sqrt(temp);
                x_2 = -sqrt(temp);
            }
        }
    }

    void showAnswer() {
        if (areComplex) {
            cout << "Уравнение имеет комплексные корни." << endl;
        } else {
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
        } else if (discriminant == 0) {
            x_1 = x_2 = -B / (2 * A);
        } else {
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
        } else if (discriminant >= 0) {
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

int main() {
    int start = 0;
    bool readInstructions = false; // Флаг, указывающий, была ли показана инструкция
    vector<QuadraticEquation> history; // Вектор для хранения истории
    int historyIndex = 0; // Индекс для текущего запроса в истории

    while (true) {
        if (!readInstructions) {
            manual(); // Показываем инструкцию только если она еще не была показана
            readInstructions = true;
        }
        cin >> start;
        if (start == 1) {
            int choose = 0;
            while (choose != 3) {
                userChoose();
                cin >> choose;

                switch (choose) {
                    case 1: {
                        int secondChoose = 1; // Устанавливаем значение по умолчанию для продолжения цикла
                        while (secondChoose == 1) {
                            programLogic(history, historyIndex); // Решение уравнения
                            secondUserChoose(); // Меню после решения уравнения
                            cin >> secondChoose;
                        }
                        break;
                    }
                    case 2:
                        showHistory(history, historyIndex);
                        break;
                    case 3:
                        break;
                    default:
                        cout << "Данного пункта не существует, попробуйте еще раз" << endl;
                        break;
                }
            }
            break; // Выходим из бесконечного цикла после успешного запуска программы
        }
        else {
            cout << "Ознакомьтесь с инструкцией еще раз и введите цифру 1" << endl;
        }
    }

    return 0;
}


// Меню выбора
void userChoose() {
    cout << "----------------------------------------" << endl;
    cout << "|          Решатель квадратных         |" << endl;
    cout << "|            уравнений v3.3            |" << endl;
    cout << "----------------------------------------" << endl;
    cout << "|   Выберите действие:                 |" << endl;
    cout << "|   1. Решить квадратное уравнение     |" << endl;
    cout << "|   2. История запросов                |" << endl;
    cout << "|   3. Завершить программу             |" << endl;
    cout << "----------------------------------------" << endl;
}

// Ввод пользователем коэффиценты
void userValues(QuadraticEquation& equation) {
    double A, B, C;
    char nextChar;
    cout << "Введите коэффициенты A, B и C: " << endl;
    cout << "Коэффициент A: ";
    while (!(cin >> A)) {
        cout << "Ошибка: введите число для коэффициента A: ";
        cin.clear();
        while ((nextChar = cin.get()) != '\n' && nextChar != EOF);
    }
    cout << "Коэффициент B: ";
    while (!(cin >> B)) {
        cout << "Ошибка: введите число для коэффициента B: ";
        cin.clear();
        while ((nextChar = cin.get()) != '\n' && nextChar != EOF);
    }
    cout << "Коэффициент C: ";
    while (!(cin >> C)) {
        cout << "Ошибка: введите число для коэффициента C: ";
        cin.clear();
        while ((nextChar = cin.get()) != '\n' && nextChar != EOF);
    }
    equation = QuadraticEquation(A, B, C);
}


void programLogic(vector<QuadraticEquation>& history, int& historyIndex) {
    QuadraticEquation eq;
    userValues(eq); // Получаем значения от пользователя
    eq.showEquation(); // Показываем уравнение

    // Добавление запроса в историю
    if (history.size() < 20) {
        history.push_back(eq);
    } else {
        // Если история полна, удаляем самый старый элемент и добавляем новый
        history.erase(history.begin());
        history.push_back(eq);
    }

    historyIndex = (historyIndex + 1) % 20; // Обновляем индекс

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
    }
    else if (eq.A == 0 && eq.B != 0 && eq.C != 0) {
        FifthQuadraticEquation eq_5(eq.A, eq.B, eq.C);
        eq_5.showAnswer();
    }
    else if (eq.A != 0 && eq.B != 0 && eq.C != 0) {
        SixthQuadraticEquation eq_6(eq.A, eq.B, eq.C);
        eq_6.showAnswer();
    }
    else if (eq.A == 0 && eq.B != 0 && eq.C == 0) {
        SeventhQuadraticEquation eq_7(eq.A, eq.B, eq.C);
        eq_7.showAnswer();
    }
    else {
        EighthQuadraticEquation eq_8(eq.A, eq.B, eq.C);
        eq_8.showAnswer();
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
        history[i].showEquation(); // Показываем каждое уравнение в истории
    }
    cout << "----------------------------------------" << endl;
}


void manual() {
    cout << "----------------------------------------" << endl;
    cout << "|    Инструкция по эксплуатации        |" << endl;
    cout << "|      программы для решения           |" << endl;
    cout << "|        квадратных уравнений          |" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1. Выбор действия:" << endl;
    cout << "   - Главное меню предлагает три действия:" << endl;
    cout << "     - Решить квадратное уравнение." << endl;
    cout << "     - Посмотреть историю запросов." << endl;
    cout << "     - Завершить программу." << endl;
    cout << endl;
    cout << "2. Решение квадратного уравнения:" << endl;
    cout << "   - Выберите действие \"Решить квадратное уравнение\" (введите \"1\")." << endl;
    cout << "   - Введите значения коэффициентов квадратного уравнения: A, B и C." << endl;
    cout << "   - Ввод дробных коэффициентов производится через точку." << endl;
    cout << "   - Программа решит уравнение и выведет его на экран." << endl;
    cout << "   - Затем будет предложено выбрать следующее действие:" << endl;
    cout << "     - Ввести новые коэффициенты." << endl;
    cout << "     - Вернуться к главному меню." << endl;
    cout << endl;
    cout << "3. Просмотр истории запросов:" << endl;
    cout << "   - Выберите действие \"История запросов\" (введите \"2\")." << endl;
    cout << "   - Программа выведет на экран историю последних 20 запросов с коэффициентами квадратных уравнений." << endl;
    cout << endl;
    cout << "4. Завершение программы:" << endl;
    cout << "   - Если вы хотите завершить программу, выберите действие \"Завершить программу\" (введите \"3\")." << endl;
    cout << endl;
    cout << "5. Ошибки ввода:" << endl;
    cout << "   - В случае некорректного ввода (например, ввод буквы вместо числа) программа сообщит об ошибке и попросит ввести значение снова." << endl;
    cout << endl;
    cout << "6. Дополнительные функции:" << endl;
    cout << "   - При решении квадратного уравнения программа определяет тип уравнения и его корни." << endl;
    cout << "   - В истории запросов отображается последние 20 введенных уравнений." << endl;
    cout << endl;
    cout << "7. Повторный запуск:" << endl;
    cout << "   - После завершения программы вы можете повторно запустить ее для решения новых уравнений или просмотра истории запросов." << endl;
    cout << "----------------------------------------" << endl;
    cout << "Для продолжения введите цифру 1" << endl;
}
