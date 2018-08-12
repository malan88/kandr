- Somewhat unintuitively, getchar() reads an extra char for every line.
   - It is the newline
- EOF in gcc is -1. This, as far as I am aware, is a legitimate value in char,
  contrary to what K&R say. char is signed, no?
- I have always found the postfix increments and decrements (++, --) more
  intuitive where the difference between postfix and prefix are irrelevant.
- I really want to ask on unix.stackexchange.com why exactly K&R did not choose
  to specify exact values for int, long, etc. It makes very little sense.
- The cntwd.c prog has strange behavior.
   1. By adding an extra space between two words the char count jumps by two.
   2. How does it not overincrement word count with extra spaces? Oh. nvm.
   - By making the `(state == OUT)` test an `else if` it's not immediately
     activated following a `state = OUT` declaration. Each subsequent space
     still trips the first part of the branch. (How does markdown implement
     nesting for bullets/numbers?)
- Fascinatingly, K&R take you through the language very slowly. It is not like
  most modern programming language where all operators are thrown at you at
  once (which is how *I* prefer it when I'm learning new languages because the
  concepts don't have to be explained to me anymore).
- I'm fascinated that K&R don't go more in to depth on the meaning of phrases
  like `c-'0'`. They explain it, but the concrete explanation does more. Because
  `'0'` has an ASCII value of `48`, `c-'0'` reverts the numbers to `int`.
  Similar logic applies to `c+'A'` and `c-'A'`, which is how you upper and lower
  case letters. IDK, I just always understood it better when it was explained
  that `'A'` represents 65.
- Ex 1-13's challenge of printing the histogram vertically is a doozy. I think I
  have the general conception, and it requires nested for loops in an
  interesting way
- Ch 1.7's function `power()` has a strange and useless definition of a for loop
  setting the counter to 1 and the comparator to `i <= n`. Why? `i = 0; i < n`
  would be equivalent. Most of the time it's also what programmers use.
- I do not know why K&R do not declare the return value for `main()` (I assume
  it was unnecessary and not typical practice in 1989/1990 when ANSI was
  declared). However, I will from here out declare it and provide a return value
  for the reasons that (a) gcc complains and (b) it's good practice.
