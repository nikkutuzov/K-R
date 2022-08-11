/*================================================================================*/
/*    The C Programming Language by Brian W. Kernighan and Dennis M. Ritchie      */
/*================================================================================*/
/*  Tittle: Ex. 1.15                                                              */
/*  Start_time: 11.08.2022 22:26                                                  */
/*  End_time: 11.08.2022 22:31                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Перепишите программу преобразования температур из раздела 1.2 так,
 * чтобы само преобразование выполнялось функцией.
 *
 */

/*<=====================================CODE=====================================>*/

#include <stdio.h>

float Fahr(float celsius);

int main() {
  float celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;
  while (celsius <= upper) {
    printf("%3.0f %7.2f\n", celsius, Fahr(celsius));
    celsius = celsius + step;
  }
}

float Fahr(float celsius) {
  return celsius * (9.0 / 5.0) + 32.0;
}
