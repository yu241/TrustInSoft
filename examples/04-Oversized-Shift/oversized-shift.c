
int main(void)
{
    int i, sum;

    sum = 2;
    for (i = 0; i <= 4; i++)
        /* TrustInSoft Analyzer emits an alarm concerning the left-shift
           expression '2 << i'. In particular, the analyzer is not able to
           guarantee '0 ≤ (int)(2<<i) < 32' valid (on x86 architecture).

           Note that, as soon as the variable 'i' takes the value 5, the
           left-shift expression '2 << i' evaluates to 32. Hence, '1 << (2 <<
           i)' reduces to '1 << 32'.

           According to section 6.5.7 of the C11 Standard, the behavior of '1 <<
           32' is undefined. This is because, on x86 architecture, the right
           operand 32 is greater than or equal to the width (in bits) of the
           left operand 1.
        */
      sum += 1 << (2 << i);

    return 0;
}
