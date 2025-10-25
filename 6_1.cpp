#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

struct Grade
{
    string subject;
    int score;
};

struct Student
{
    string name;
    int age;
    int course;
    bool sex; // 0 = М, 1 = Ж
    vector<Grade> grades;
};

string getRandomName()
{
    const vector<string> firstNames = {
        "Иван", "Алексей", "Матвей", "Дмитрий", "Николай", "Сергей", "Андрей",
        "Кирилл", "Егор", "Владислав", "Степан", "Артем", "Роман", "Максим",
        "Григорий", "Павел", "Виктор", "Лев", "Федор", "Константин",
        "Михаил", "Олег", "Анатолий", "Евгений", "Ярослав", "Борис",
        "Илья", "Тимофей", "Руслан", "Владимир"
    };

    const vector<string> lastNames = {
        "Иванов", "Смирнов", "Кузнецов", "Попов", "Соколов", "Лебедев",
        "Козлов", "Новиков", "Морозов", "Петров", "Волков", "Соловьёв",
        "Васильев", "Зайцев", "Павлов", "Семенов", "Голубев", "Виноградов",
        "Богданов", "Воробьёв", "Фёдоров", "Михайлов", "Беляев", "Тарасов",
        "Белов", "Комаров", "Орлов", "Киселёв", "Макаров", "Никитин"
    };

    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> firstNameDist(0, firstNames.size() - 1);
    uniform_int_distribution<> lastNameDist(0, lastNames.size() - 1);

    return lastNames[lastNameDist(gen)] + " " + firstNames[firstNameDist(gen)];
}

vector<Student> generateStudents(const int n, const vector<string>& subjects)
{
    vector<Student> students(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> ageDist(17, 25);
    uniform_int_distribution<> courseDist(1, 4);
    uniform_int_distribution<> gradeDist(1, 10);
    uniform_int_distribution<> sexDist(0, 1);

    for (auto& student : students)
    {
        student.name = getRandomName();
        student.age = ageDist(gen);
        student.course = courseDist(gen);
        student.sex = sexDist(gen);

        for (auto& subj : subjects)
        {
            student.grades.push_back({subj, gradeDist(gen)});
        }
    }
    return students;
}

void displayStudents(const vector<Student>& students)
{
    for (const auto& student : students)
    {
        cout << "Имя студента: " << student.name << endl;
        cout << "Возраст: " << student.age << endl;
        cout << "Курс: " << student.course << endl;
        cout << "Пол: " << (student.sex ? "женский" : "мужской") << endl;
        cout << "Успеваемость:" << endl;
        for (const auto& g : student.grades)
            cout << "  " << g.subject << " — " << g.score << endl;
        cout << endl;
    }
}

vector<int> getGradesForSubject(const vector<Student>& students, int course, const string& subject)
{
    vector<int> grades;
    for (const auto& student : students)
    {
        if (student.course != course) continue;

        auto it = find_if(student.grades.begin(), student.grades.end(),
                          [&](const Grade& g) { return g.subject == subject; });
        if (it != student.grades.end())
            grades.push_back(it->score);
    }
    return grades;
}

float calculateAverage(const vector<int>& grades)
{
    if (grades.empty()) return 0;
    int sum = 0;
    for (int g : grades) sum += g;
    return static_cast<float>(sum) / grades.size();
}

int inputInt(const string& prompt, int min, int max)
{
    int x;
    while (true)
    {
        cout << prompt;
        if (cin >> x && x >= min && x <= max)
            break;
        cin.clear();
        cout << "Ошибка! Введите число от " << min << " до " << max << ".\n";
    }
    return x;
}

int main()
{
    const vector<string> subjects = {
        "Математический анализ",
        "Аналитическая геометрия",
        "Наношитьё",
        "Тевтонская борьба в пакетах",
        "Программирование"
    };

    auto students = generateStudents(1000, subjects);

    bool display_students = false;
    if (display_students) displayStudents(students);

    cout << "Просмотр оценок для предмета на определённом курсе\n";
    int chosen_course = inputInt("Выберите курс (1-4): ", 1, 4);

    cout << "Выберите предмет:\n";
    for (int i = 0; i < subjects.size(); ++i)
        cout << " " << i << " — " << subjects[i] << endl;

    int chosen_subject = inputInt("Номер предмета: ", 0, subjects.size() - 1);

    auto grades = getGradesForSubject(students, chosen_course, subjects[chosen_subject]);

    cout << "\nОценки по предмету \"" << subjects[chosen_subject] << "\" на "
        << chosen_course << " курсе: ";
    if (grades.empty())
    {
        cout << "нет данных.\n";
    }
    else
    {
        for (int g : grades) cout << g << " ";
        cout << "\nСреднее значение — " << calculateAverage(grades) << endl;
    }

    return 0;
}
