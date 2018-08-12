 - Somewhat unintuitively, getchar() reads an extra char for every line.
    - It is the newline
 - EOF in gcc is -1. This, as far as I am aware, is a legitimate value in char,
   contrary to what K&R say. char is signed, no?
