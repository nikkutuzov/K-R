/*================================================================================*/
/*    The C Programming Language by Brian W. Kernighan and Dennis M. Ritchie      */
/*================================================================================*/
/*  Tittle: Ex. 1.6                                                               */
/*  Start_time: 08.08.2022 17:44                                                  */
/*  End_time: 08.08.2022 17:46                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Проверьте, что выражение getchar() != EOF действительно равно 0 или 1.
 *
 */

/*<=====================================CODE=====================================>*/

#include <stdio.h>

int main() {
  int c, res;

  res = ((c = getchar()) != EOF);
  printf("res = %d\n", res);
}
