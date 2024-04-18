#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Родительский класс
class QuadraticEquation {
public:
    double A;
    double B;
    double C;

    // Конструктор родительского класса
    QuadraticEquation(double a = 0, double b = 0, double c = 0) : A(a), B(b), C(c) {}

    void showEquation() {
        string equation = "";

        if (A != 0) {
            equation += to_string(A) + "x^2 ";
        }
        if (B != 0) {
            if (B > 0 && !equation.empty()) {
                equation += "+ ";
            }
            equation += to_string(B) + "x ";
        }
        if (C != 0) {
            if (C > 0 && !equation.empty()) {
                equation += "+ ";
            }
            equation += to_string(C);
        }

        if (equation.empty()) {
            cout << "0 = 0" << endl;
        }
        else {
            cout << "Итоговое уравнение: " << equation << " = 0" << endl;
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
    FourthQuadraticEquation(double a, double b, double c) : QuadraticEquation(a, b, c) {
        x_1 = sqrt(static_cast<double>(C) / A);
        x_2 = -sqrt(static_cast<double>(C) / A);
    }

    void showAnswer() {
        cout << "Данное квадратное уравнение имеет 2 корня:" << endl;
        cout << "Первый корень: " << x_1 << endl;
        cout << "Второй корень: " << x_2 << endl;
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
    SixthQuadraticEquation(double a, double b, double c) : QuadraticEquation(a, b, c) {
        discriminant = B * B - 4 * A * C;
        if (discriminant > 0) {
            x_1 = (-B + sqrt(discriminant)) / (2 * A);
            x_2 = (-B - sqrt(discriminant)) / (2 * A);
        }
        else if (discriminant == 0) {
            x_1 = (-B) / (2 * A);
        }
    }

    void showAnswer() {
        if (discriminant > 0) {
            cout << "Данное квадратное уравнение имеет следующие корни" << endl;
            cout << "Первый корень: " << x_1 << endl;
            cout << "Второй корень: " << x_2 << endl;
        }
        else if (discriminant == 0) {
            cout << "Данное квадратное уравнение имеет одно единственное решение при x = " << x_1 << endl;
        }
        else if (discriminant < 0) {
            cout << "Данное квадратное уравнение не имеет корней" << endl;
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
    char nextChar; // Для проверки на букву после числа
    cout << "----------------------------------------" << endl;
    cout << "Введите коэффициенты A, B и C: " << endl;
    cout << "Коэффициент A: ";
    while (!(cin >> A)) {
        cout << "Ошибка: введите целое число для коэффициента A: ";
        cin.clear(); // Сбросить ошибку ввода
        while ((nextChar = cin.get()) != '\n' && nextChar != EOF); // Проигнорировать оставшуюся часть ввода до символа новой строки
    }
    cout << "Коэффициент B: ";
    while (!(cin >> B)) {
        cout << "Ошибка: введите целое число для коэффициента B: ";
        cin.clear();
        while ((nextChar = cin.get()) != '\n' && nextChar != EOF);
    }
    cout << "Коэффициент C: ";
    while (!(cin >> C)) {
        cout << "Ошибка: введите целое число для коэффициента C: ";
        cin.clear();
        while ((nextChar = cin.get()) != '\n' && nextChar != EOF);
    }
    cout << "----------------------------------------" << endl;
    equation = QuadraticEquation(A, B, C);
}

void programLogic(QuadraticEquation history[], int& historyIndex) {

    const int historySize = 20;

    int secondChoose = 0;

    QuadraticEquation eq; // Создаем объект класса QuadraticEquation

    userValues(eq); // Вызываем функцию для ввода коэффициентов

    eq.showEquation();

    // Добавление запроса в историю
    history[historyIndex] = eq;
    if (++historyIndex >= historySize) {
        historyIndex = 0; // Сбрасываем индекс, если достигли конца истории
    }

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

void showHistory(QuadraticEquation history[], int historyIndex) {
    const int historySize = 20;
    int startIndex = (historyIndex >= historySize) ? (historyIndex % historySize) : 0;

    cout << "----------------------------------------" << endl;
    cout << "|            История запросов:         |" << endl;
    for (int i = 0; i < historySize; ++i) {
        int index = (startIndex + i) % historySize;
        cout << "|   Запрос " << (i + 1) << ": ";
        history[index].showEquation();
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

int main() {
    int start = 0;
    bool readInstructions = false; // Флаг, указывающий, была ли показана инструкция

    while (true) {
        if (!readInstructions) {
            manual(); // Показываем инструкцию только если она еще не была показана
            readInstructions = true;
        }
        cin >> start;
        if (start == 1) {
            int choose = 0;
            const int historySize = 20;
            QuadraticEquation history[historySize];
            int historyIndex = 0;

            // Первичный вывод меню
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
