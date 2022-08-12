/*================================================================================*/
/*    The C Programming Language by Brian W. Kernighan and Dennis M. Ritchie      */
/*================================================================================*/
/*  Tittle: Ex. 1.16                                                              */
/*  Start_time: 12.08.2022 15:42                                                  */
/*  End_time:                                                                     */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Доработайте главный модуль программы опрелеления самой днинной строки так,
 * чтобы она выводила правильное значение для какой угодно длины строк входного
 * потока, насколько это позволяет текст.
 *
 * В российском издании перевод так себе, в английском:
 *
 * Revise the main routine of the longest-line program so it will correctly print 
 * the length of arbitrarily long input lines, and as much as possible of the text.
 *
 * Я бы перевел примерно так:
 *
 * Пересмотрите основную процедуру программы с самой длинной строкой, чтобы она
 * правильно печатала длину произвольно длинных входных строк и как можно больше
 * текста.
 *
 * Будем трогать только main, все что НЕ в блоке main, трогать НЕ будем!
 *
 * Вот по моему вольному переводу и будем делать.
 *
 */

/*<=====================================CODE=====================================>*/

#include <stdio.h>

// оригинальные строки буду комментировать
//#define MAXLINE 1000
#define MAXLINE 10 // для простоты тестирования укоротим строку

int Getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = Getline(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0) {
    printf("%s\n", longest);
    printf("%d\n", max);  // добавим распечатку длины самой длинной строки
  }

  return 0;
}

int Getline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while (( to[i] = from[i]) != '\0') {
    ++i;
  }
}
