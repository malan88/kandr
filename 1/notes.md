 - Somewhat unintuitively, getchar() reads an extra char for every line.
    - It is the newline
 - EOF in gcc is -1. This, as far as I am aware, is a legitimate value in char,
   contrary to what K&R say. char is signed, no?
 - I have always found the postfix increments and decrements (++, --) more
   intuitive where the difference between postfix and prefix are irrelevant.
 - I really want to ask on unix.stackexchange.com why exactly K&R did not choose
   to specify exact values for int, long, etc. It makes very little sense.
