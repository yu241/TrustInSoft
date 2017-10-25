# Division by zero

## Where can I replay this example?

This example can be replayed with the **Newcomers** version of the **TrustInSoft
Analyzer**.

## Division by zero

Whenever a program tries to evaluate a division or a modulo operation that have
the second operand set to zero, **TrustInSoft Analyzer** locates a serious bug
and emits an alarm.

The alarm appears in the function `modulo` as an assertion:

`/*@ assert Value: division_by_zero: b ≢ 0;*/`.

This assertion has to be true for the code to be valid.

## Understanding the origin

### Newcomers

Click on the link `An undefined behavior has been found.` on the left panel.
This will highlight the alarm TrustInSoft Analyzer has emitted as the assertion
`/*@ assert Value: division_by_zero: b ≢ 0;*/` in the function `modulo`.

Click on the variable `b`, and look at the set of values displayed in the column
`Values before`. These are the different values that `b` takes due to the
different calls of the function `modulo`.

Do a right click on the variable `b`, and choose `Show Defs`. A new panel shows
up at the left showing the different statements where the variable `b` has been
defined. Click on the statement `tmp = modulo(100, array[i])`. It redirects you
to the main function, highlighting the clicked statement.

Since you know that the parameter `b` of the function `modulo` is the second
one, click on the variable `array`, and look at the tab `Values before`. It
displays the values of every array element. You can see that the one at index 3
is set to zero.

Right click on the variable `array`, and then on `Show Defs`. You can see where
the array has been initialized, and see the call that sets `b` to zero when `i`
takes the value 3.
