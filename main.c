#include <stdio.h>   // Подключение библиотеки для ввода/вывода
#include <stdlib.h>  // Подключение стандартной библиотеки (например, для работы с памятью)
#include <time.h>    // Подключение библиотеки для работы с датой и временем

// Функция для вычисления возраста на основе даты рождения
int calculateAge(int birthYear, int birthMonth, int birthDay) {

    time_t t = time(NULL);  // Получение текущего времени в формате time_t (секунды с 1 января 1970 года)

    // Преобразование времени в структуру tm, содержащую дату и время в развернутом виде
    struct tm currentTime = *localtime(&t);  // Получаем локальное время (переобразуем time_t в tm)

    // Вычисление возраста как разница между текущим годом и годом рождения
    int age = currentTime.tm_year + 1900 - birthYear;  // tm_year хранит количество лет с 1900 года, поэтому прибавляем 1900

    // Если день рождения еще не наступил в текущем году, уменьшаем возраст на 1
    if (currentTime.tm_mon + 1 < birthMonth || (currentTime.tm_mon + 1 == birthMonth && currentTime.tm_mday < birthDay)) {
        age--;  // День рождения еще не был в текущем году
    }

    return age;  // Возвращаем вычисленный возраст
}

int main() {

    char firstName[50], lastName[50];  // Массивы для хранения имени и фамилии (до 49 символов)

    int birthYear, birthMonth, birthDay;  // Переменные для хранения года, месяца и дня рождения

    // Запрашиваем у пользователя имя
    printf("Please enter your first name: ");

    // Считываем имя с безопасной проверкой длины (не более 49 символов)
    scanf_s("%49s", firstName, sizeof(firstName));  // Используется scanf_s для безопасного ввода

    // Запрашиваем у пользователя фамилию
    printf("Please enter your last name: ");

    // Считываем фамилию с безопасной проверкой длины (не более 49 символов)
    scanf_s("%49s", lastName, sizeof(lastName));  // Используется scanf_s для безопасного ввода

    // Запрашиваем год рождения
    printf("Please enter your birth year: ");

    // Считываем год рождения
    scanf_s("%d", &birthYear);  // Используется scanf_s для безопасного ввода целого числа

    // Запрашиваем месяц рождения
    printf("Please enter your birth month: ");

    // Считываем месяц рождения
    scanf_s("%d", &birthMonth);  // Используется scanf_s для безопасного ввода целого числа

    // Запрашиваем день рождения
    printf("Please enter your birth day: ");

    // Считываем день рождения
    scanf_s("%d", &birthDay);  // Используется scanf_s для безопасного ввода целого числа

    // Вычисляем возраст на основе введенной даты рождения
    int age = calculateAge(birthYear, birthMonth, birthDay);

    // Выводим приветствие с именем, фамилией и возрастом
    printf("Hello, %s %s! You are %d years old.\n", firstName, lastName, age);

    return 0;  // Завершаем программу, возвращая 0
}


