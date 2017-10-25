# Oversized left-shift expressions

## Where can I replicate this example ?

This example can be replicated with both **Newcomers** and **Open projects**
versions of the **TrustInSoft Analyzer**.

## Oversized left-shift expressions

Generally speaking, a left-shift expression `E1 << E2` results into `E1`
left-shifted by `E2` bit positions, with vacated bits filled with zeros.
However, according to section 6.5.7 of the C11 Standard, if the value of `E2` is
negative or is greater than or equal to the width of `E1`, the behavior is
undefined. **TrustInSoft Analyzer** is able to catch such violations.

In the provided program example, **TrustInSoft Analyzer** emits an alarm
concerning the left-shift expression `2 << i`. In particular, the analyzer is
not able to guarantee `0 ≤ (int)(2<<i) < 32` valid (on x86 architecture). As
soon as the variable `i` takes the value 5, the left-shift expression `2 << i`
evaluates to 32. Hence, `1 << (2 << i)` reduces to `1 << 32`: on x86
architecture, since 32 is equal to the bit width of 1, the result is undefined.

## Understanding the origin

### Newcomers

Click on the link `An undefined behavior has been found.` on the left panel.
This will highlight the alarm **TrustInSoft Analyzer** has emitted as the
assertion `/*@ assert Value: shift: 0 ≤ (int)(2<<i) < 32;*/`.

Click on the expression `2 << i`, and look at the set of values displayed in the
column `Values before`. These are the possible values that the expression
evaluates to with respect to the value taken by `i`. (By clicking on the
variable `i`, the bottom panel displays all the values it takes during the
execution of the loop.)

Notice that, among the possible values of `2 << i`, there is also 32. It is
because of this latter that the assertion is violated.

### Open projects

Similar to the **Newcomers** version after running the `Value Analysis` with the
`Global slevel` set to 10.
