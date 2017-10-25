# Out of bound accesses

## Where can I replay this example ?

This example can be replayed with both **Newcomers** and **Open projects**
versions of the TrustInSoft Analyzer.

## Out of bound accesses

Whenever a program tries to evaluate an access to a pointer out of its allocated
memory bounds, TrustInSoft Analyzer locates a serious bug and emits an alarm.

The alarms appears in the function `main` as an assert:

`/*@ assert Value: mem_access: \valid_read(array+i);*/`.

This assertion has to be true for the code to be valid.

In this example, the condition of the loop lets the variable `i` reach the
value 5. Accessing an array of size 5 (defined by the malloc) at index 5 leads
to read out of the array upper bound.

## Understanding the origin

### Newcomers

Click on the link `An undefined behavior has been found.` on the left panel.
This will highlight the alarm TrustInSoft Analyzer has emitted as the assertion
`/*@ assert Value: mem_access: \valid_read(array+i);*/`.

Click on the variable `array` and look at the value displayed in the column
`Values before`. The displayed value `&__malloc_main_l10[0]` is the address of
an internal variable created by the call of `malloc`. Clicking on this
`__malloc_main_l10` shows that such variable has type `int[5]`.

Now that you have the information about the size of the array, click on the
variable `i` inside the loop, and inspect its possible values. You can see that
`i` takes the value 5 at least once during the loop.

### Open projects

After running the Value Anaysis, go to the `Exploration` mode, and chose the tab
`Evaluate ACSL Terms` in the bottom panel. If you don't see the tab, you can
change the template to the `Semantic Template` in the `Workspace` menu.

In an equivalent way to **Newcomers**, you can see that the variable `i` takes
the value 5 at least once during the loop.
