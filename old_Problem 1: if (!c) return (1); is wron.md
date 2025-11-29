❌ Problem 1: if (!c) return (1); is wrong

Splitting by '\0' is undefined nonsense.
If c == '\0', you are saying:

“Split the string by the end of the string.”

Which means:

You don’t truly have a delimiter.

The correct result should be: one big word = the whole string.

Your code kinda tries that, but only returns 1, so the rest of your logic misbehaves.

ft_split(str, 0) is invalid input according to 42’s spec.
Most testers will call it anyway. You need to handle it properly, otherwise behavior becomes unpredictable.

❌ Problem 2: No cleanup on allocation failure inside ft_make_word

If ft_substr fails for one of the words, you just return and leak memory.

Example:
If you have allocated words[0], words[1], but words[2] fails, you bail out without freeing words[0] or words[1].

That is a memory leak.
Francinette / Moulinette will flag this if your malloc fails.

You MUST free the previous strings.

⚠️ Problem 3: ft_count_words misbehaves with no delimiter (c == '\0')

You return 1, okay.
But then you do:

result_split = ft_calloc((word_count + 1), sizeof(char *));
ft_make_word(s, c, word_count, result_split);


Then ft_make_word tries to “skip delimiters," but your delimiter is '\0', so:

while (s[i] && s[i] == c) // never true
while (s[i + j] && s[i + j] != c) // this runs through the whole string


It accidentally forms the whole string as one word.
That actually works by accident, but it’s fragile and ugly.

Better to explicitly handle it.

⚠️ Problem 4: No NULL termination explicitly in error cases

If ft_make_word returns early, result_split is not guaranteed NULL-terminated.

⚠️ Problem 5: You’re not checking ft_make_word result

If it fails, you're returning a half-filled array with a leak.