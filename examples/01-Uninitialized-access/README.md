# Uninitialized variable ![Badge](https://img.shields.io/badge/TrustInSoft-Verified-green.svg)

## Where can I replay this example?

This example can be replayed with both **Newcomers** and **Open projects**
versions of the **TrustInSoft Analyzer**.

## Uninitialized variable

Whenever a program tries to read the value of a local variable that has not been
previously initialized, TrustInSoft Analyzer locates a serious bug and emits an
alarm.

The alarm appears in the analyzer as an assertion:

`/*@ assert Value: initialization: \initialized(&n);*/`.

This assertion has to be true for the code to be valid.

## Understanding the origin

### Newcomers

Click on the link `An undefined behavior has been found.` on the left panel.
This will highlight the alarm TrustInSoft Analyzer has emitted as the assertion
`/*@ assert Value: initialization: \initialized(&n);*/`.

Click on the variable `n` inside the loop. You can see that the bottom panel now
displays the value of this variable, before and after the statement. In the
column `Values before`, you can see that the variable `n` has the value
`UNINITIALIZED`.

The variable `n` has been declared at line 4, but is never initialized before
its usage in the loop.

### Open projects

After running the `Value Analysis`, go to `Exploration` mode and chose the tab
`Evaluate ACSL Terms` in the bottom panel. If you don't see the tab, you can
change the template to the `Semantic Template` in the `Workspace` menu.

In an equivalent way to **Newcomers**, you can click the variable `n` and see
that the value of `n` displayed in the tab `Values before` is set to
`UNINITIALIZED`.
