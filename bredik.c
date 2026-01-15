#include <stdio.h>

int main(){
    // Вывод нечётных чисел от 1 до 10
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue; // Пропускаем чётные числа
        }
        printf("%d ", i); // Выводит: 1 3 5 7 9
    }   
}