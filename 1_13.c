/*================================================================================*/
/*    The C Programming Language by Brian W. Kernighan and Dennis M. Ritchie      */
/*================================================================================*/
/*  Tittle: Ex. 1.13                                                              */
/*  Start_time: 10.08.2022 14:48                                                  */
/*  End_time: 10.08.2022 18:16                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Напишите программу для вывода гистограммы длин слов во входном потоке. Построить
 * гистограмму с горизонтальными рядами довольно легко, а вот с вертикальными
 * столбцами труднее.
 *
 */

/*<=====================================CODE=====================================>*/

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXWORDLENGTH 15 // максимальная длина слова

int main() {
  int c, state; // c - знакб state - состояние (внутри или снаружи слова)
  int counter; // счетик слов
  int maxcounter; // максимальное количество слов одной длины
  int length[MAXWORDLENGTH]; // массив длин слов

  // занулим массив
  for (int i = 0; i < MAXWORDLENGTH; ++i) {
    length[i] = 0;
  }

  // занулим счетчики
  counter = maxcounter = 0;
  // стивим положение: снаружи слова
  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') { // если встречаем пробел, табуляцию
                                              // или снак новую строку
      if (state == IN) {                      // и при этом мы внутри слова
        state = OUT;                          // ставим положение - снаружи
        ++length[counter];                    // + одно слово определенной длинны
        counter = 0;                          // обнуляем счеткич символов в слове
      }
    } else if (state == OUT) {                // иначе если положение снаружи
      state = IN;                             // ставим положение внутри
      ++counter;                              // начинаем считать количество знаков
    } else {                                  // иначе (то есть если внутри слова)
      ++counter;                              // тоже считаем количество знаков
    }
  }
  printf("\n");

  // горизонтальная гистограмма
  for (int i = 1; i <= MAXWORDLENGTH; ++i) { // пока проходим по всем длинам
    if (maxcounter < length[i]) {            // заодно выясним, какой длины слов
      maxcounter = length[i];                // больше всего
    }
    for (int j = 0; j < length[i]; ++j) {    // какая цифра в яцейке массива
      printf("#");                           // столько раз и напечатаем # то есть
    }                                        // отобразим кол-во слов опред. длины
    printf("\n");
  }
  printf("\n");

  // вертикальная гистограмма
  for (int i = maxcounter; i > 0; --i) {   // вот и пригодился maxcounter
    for (int j = 1; j <= MAXWORDLENGTH; ++j) {
      if (length[j] < i) { // если значение в ячейке меньше текуще рассматриваемой
        printf("  ");      // просто печатаем пробел
      } else {             // в противном случае
        printf("[]");      // печатаем какой-то знак
      }
    }
    printf("\n");
  }
}
