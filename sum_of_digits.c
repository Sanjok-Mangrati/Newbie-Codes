#include <stdio.h>

int main() {
	
    int n;
    int sum =0;
    scanf("%d", &n);
    while (n>0) {
        sum += (n%10);
        n=n/10;
    }
    printf("%d", sum);
    return 0;
}

//Logic
/** In divison, the number when divided by 10 will give a remainder which is equal to the last digit of that number,
 * and the quotient remains, the quotient is again divided by 10 and the remainder is the last digit.
 * 
 * Example:
 * Let the number be 25678, the sum of all the digits of this number is 2+5+6+7+8 = 28.
 * To solve this we take the number and divide by 10, 25678/10 = 2567 (quotient) and 25678 % 10 = 8(remainder).
 * We again take the quotient and divide by 10, 2567/10 = 256(quotient) and 2567 % 10 = 7(remainder).
 * As we can see we can obtain last digit of the given number by dividing the quotient and remainder gives last digit. 
 * We repeat till the quotient is 0.
 * 
 **/
