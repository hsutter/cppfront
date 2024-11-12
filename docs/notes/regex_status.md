# Supported regular expression features

The listings are taken from the [Perl regex docs](https://perldoc.perl.org/perlre). Regular expressions are applied via the [`regex` metafunction](../cpp2/metafunctions.md#regex).


## Currently supported or planned features


### Modifiers

| Modifier | Notes | Status |
| --- | --- | --- |
| **`i`** | Do case-insensitive pattern matching. For example, "A" will match "a" under `/i`. | <span style="color:green">Supported</span> | 
| **`m`** | Treat the string being matched against as multiple lines. That is, change `^` and `$` from matching the start of the string's first line and the end of its last line to matching the start and end of each line within the string. | <span style="color:green">Supported</span> |
| **`s`** | Treat the string as single line. That is, change `.` to match any character whatsoever, even a newline, which normally it would not match. | <span style="color:green">Supported</span> |
| ***`x` and `xx`** | Extend your pattern's legibility by permitting whitespace and comments. For details see: [Perl regex docs: `/x` and `/xx`](https://perldoc.perl.org/perlre#/x-and-/xx). | <span style="color:green">Supported</span> |
| **`n`** | Prevent the grouping metacharacters `(` and `)` from capturing. This modifier will stop `$1`, `$2`, etc. from being filled in. | <span style="color:green">Supported</span> |
| **`c`** | Keep the current position during repeated matching. | <span style="color:green">Supported</span> |


### Escape sequences __(Complete)__

| Escape sequence  | Notes | Status |
| --- | --- | --- |
| **`\t`** | Tab (HT, TAB)X | <span style="color:green">Supported</span> | 
| **`\n`** | Newline (LF, NL) | <span style="color:green">Supported</span> | 
| **`\r`** | Return (CR) | <span style="color:green">Supported</span> | 
| **`\f`** | Form feed (FF) | <span style="color:green">Supported</span> | 
| **`\a`** | Alarm (bell) (BEL) | <span style="color:green">Supported</span> | 
| **`\e`** | Escape (think troff) (ESC) | <span style="color:green">Supported</span> |
| **`\x{}`, `\x00`** | Character whose ordinal is the given hexadecimal number | <span style="color:green">Supported</span> | 
| **`\o{}`, `\000`** | Character whose ordinal is the given octal number | <span style="color:green">Supported</span> | 


### Quantifiers __(Complete)__

| Quantifier  | Notes | Status |
| --- | --- | --- |
| **`*`** |        Match 0 or more times | <span style="color:green">Supported</span> | 
| **`+`** |        Match 1 or more times | <span style="color:green">Supported</span> | 
| **`?`** |        Match 1 or 0 times | <span style="color:green">Supported</span> | 
| **`{n}`** |      Match exactly n times | <span style="color:green">Supported</span> | 
| **`{n,}`** |     Match at least n times | <span style="color:green">Supported</span> | 
| **`{,n}`** |     Match at most n times | <span style="color:green">Supported</span> | 
| **`{n,m}`** |    Match at least n but not more than m times | <span style="color:green">Supported</span> | 
| |  | |
| **`*?`** |       Match 0 or more times, not greedily | <span style="color:green">Supported</span> | 
| **`+?`** |       Match 1 or more times, not greedily | <span style="color:green">Supported</span> | 
| **`??`** |       Match 0 or 1 time, not greedily | <span style="color:green">Supported</span> | 
| **`{n}?`** |     Match exactly n times, not greedily (redundant) | <span style="color:green">Supported</span> | 
| **`{n,}?`** |    Match at least n times, not greedily | <span style="color:green">Supported</span> | 
| **`{,n}?`** |    Match at most n times, not greedily | <span style="color:green">Supported</span> | 
| **`{n,m}?`** |   Match at least n but not more than m times, not greedily | <span style="color:green">Supported</span> | 
| |  | |
| **`*+`** |       Match 0 or more times and give nothing back | <span style="color:green">Supported</span> | 
| **`++`** |       Match 1 or more times and give nothing back | <span style="color:green">Supported</span> | 
| **`?+`** |       Match 0 or 1 time and give nothing back | <span style="color:green">Supported</span> | 
| **`{n}+`** |     Match exactly n times and give nothing back (redundant) | <span style="color:green">Supported</span> | 
| **`{n,}+`** |    Match at least n times and give nothing back | <span style="color:green">Supported</span> | 
| **`{,n}+`** |    Match at most n times and give nothing back | <span style="color:green">Supported</span> | 
| **`{n,m}+`** |   Match at least n but not more than m times and give nothing back | <span style="color:green">Supported</span> | 


### Character Classes and other Special Escapes __(Complete)__

| Feature  | Notes | Status |
| --- | --- | --- |
| **`[`...`]`** | Match a character according to the rules of the bracketed character class defined by the "...". Example: `[a-z]` matches "a" or "b" or "c" ... or "z" | <span style="color:green">Supported</span> | 
| **`[[:`...`:]]`** |    Match a character according to the rules of the POSIX character class "..." within the outer bracketed character class.  Example: `[[:upper:]]` matches any uppercase character. | <span style="color:green">Supported</span> | 
| **`\g1`** or **`\g{-1}`**  |          Backreference to a specific or previous group. The number may be negative indicating a relative previous group and may optionally be wrapped in curly brackets for safer parsing. | <span style="color:green">Supported</span> | 
| **`\g{name}`** |     Named backreference | <span style="color:green">Supported</span> | 
| **`\k<name>`** |     Named backreference | <span style="color:green">Supported</span> | 
| **`\k'name'`** |     Named backreference | <span style="color:green">Supported</span> | 
| **`\k{name}`** |     Named backreference | <span style="color:green">Supported</span> | 
| **`\w`** |           Match a "word" character (alphanumeric plus "_", plus other connector punctuation chars plus Unicode marks) | <span style="color:green">Supported</span> | 
| **`\W`** |           Match a non-"word" character | <span style="color:green">Supported</span> | 
| **`\s`** |           Match a whitespace character | <span style="color:green">Supported</span> | 
| **`\S`** |           Match a non-whitespace character | <span style="color:green">Supported</span> | 
| **`\d`** |           Match a decimal digit character | <span style="color:green">Supported</span> | 
| **`\D`** |           Match a non-digit character | <span style="color:green">Supported</span> | 
| **`\v`** |           Vertical whitespace | <span style="color:green">Supported</span> | 
| **`\V`** |           Not vertical whitespace | <span style="color:green">Supported</span> | 
| **`\h`** |           Horizontal whitespace | <span style="color:green">Supported</span> | 
| **`\H`** |           Not horizontal whitespace | <span style="color:green">Supported</span> | 
| **`\1`** |           Backreference to a specific capture group or buffer. '1' may actually be any positive integer. | <span style="color:green">Supported</span> | 
| **`\N`** |           Any character but \n.  Not affected by /s modifier | <span style="color:green">Supported</span> | 
| **`\K`** |           Keep the stuff left of the \K, don't include it in $& | <span style="color:green">Supported</span> | 


### Assertions

| Assertion  | Notes | Status |
| --- | --- | --- |
| **`\b`** |     Match a \w\W or \W\w boundary | <span style="color:green">Supported</span> | 
| **`\B`** |     Match except at a \w\W or \W\w boundary | <span style="color:green">Supported</span> | 
| **`\A`** |     Match only at beginning of string | <span style="color:green">Supported</span> | 
| **`\Z`** |     Match only at end of string, or before newline at the end | <span style="color:green">Supported</span> | 
| **`\z`** |     Match only at end of string | <span style="color:green">Supported</span> | 
| **`\G`** |     Match only at pos() (e.g. at the end-of-match position of prior m//g) | <span style="color:green">Supported</span> |


### Capture groups __(Complete)__

| Feature  | Status |
| --- | --- |
| **`(`...`)`** | <span style="color:green">Supported</span> | 


### Quoting metacharacters __(Complete)__

| Feature | Status |
| --- | --- |
| **For `^.[]$()*{}?+|\`** | <span style="color:green">Supported</span> | 


### Extended Patterns

| Extended pattern  | Notes | Status |
| --- | --- | --- |
| **`(?<NAME>pattern)`** |            Named capture group | <span style="color:green">Supported</span> | 
| **`(?#text)`** |                    Comments | <span style="color:green">Supported</span> | 
| **`(?adlupimnsx-imnsx)`** |         Modification for surrounding context | <span style="color:green">Supported</span> | 
| **`(?^alupimnsx)`** |               Modification for surrounding context | <span style="color:green">Supported</span> | 
| **`(?:pattern)`** |                 Clustering, does not generate a group index. | <span style="color:green">Supported</span> | 
| **`(?adluimnsx-imnsx:pattern)`** |  Clustering, does not generate a group index and modifications for the cluster. | <span style="color:green">Supported</span> | 
| **`(?^aluimnsx:pattern)`** |        Clustering, does not generate a group index and modifications for the cluster. | <span style="color:green">Supported</span> | 
| **`(?`<code>&#124;</code>`pattern)`** |                 Branch reset | <span style="color:green">Supported</span> | 
| **`(?'NAME'pattern)`** |            Named capture group | <span style="color:green">Supported</span> | 
| **`(?(condition)yes-pattern`<code>&#124;</code>`no-pattern)`** |  Conditional patterns. | <span style="color:gray">Planned</span> | 
| **`(?(condition)yes-pattern)`** |             Conditional patterns. | <span style="color:gray">Planned</span> | 
| **`(?>pattern)`** |                 Atomic patterns. (Disable backtrack.) | <span style="color:green">Supported</span> |
| **`(*atomic:pattern)`** |           Atomic patterns. (Disable backtrack.) | <span style="color:green">Supported</span> |


### Lookaround Assertions

| Lookaround assertion  | Notes | Status |
| --- | --- | --- |
| **`(?=pattern)`**                     | Positive look ahead. | <span style="color:green">Supported</span> | 
| **`(*pla:pattern)`**                  | Positive look ahead. | <span style="color:green">Supported</span> | 
| **`(*positive_lookahead:pattern)`**   | Positive look ahead. | <span style="color:green">Supported</span> | 
| **`(?!pattern)`**                     | Negative look ahead. | <span style="color:green">Supported</span> | 
| **`(*nla:pattern)`**                  | Negative look ahead. | <span style="color:green">Supported</span> | 
| **`(*negative_lookahead:pattern)`**   | Negative look ahead. | <span style="color:green">Supported</span> | 
| **`(?<=pattern)`**                    | Positive look behind. | <span style="color:green">Supported</span> |
| **`(*plb:pattern)`**                  | Positive look behind. | <span style="color:green">Supported</span> |
| **`(*positive_lookbehind:pattern)`**  | Positive look behind. | <span style="color:green">Supported</span> |
| **`(?<!pattern)`**                    | Negative look behind. | <span style="color:green">Supported</span> |
| **`(*nlb:pattern)`**                  | Negative look behind. | <span style="color:green">Supported</span> |
| **`(*negative_lookbehind:pattern)`**  | Negative look behind. | <span style="color:green">Supported</span> |


### Special Backtracking Control Verbs

| Backtracking control verb  | Notes | Status |
| --- | --- | --- |
| **`(*SKIP) (*SKIP:NAME)`**     | Start next search here. | <span style="color:gray">Planned</span> | 
| **`(*PRUNE) (*PRUNE:NAME)`**   | No backtracking over this point. | <span style="color:gray">Planned</span> | 
| **`(*MARK:NAME) (*:NAME)`**    | Place a named mark. | <span style="color:gray">Planned</span> | 
| **`(*THEN) (*THEN:NAME)`**     | Like PRUNE. | <span style="color:gray">Planned</span> | 
| **`(*COMMIT) (*COMMIT:arg)`**  | Stop searching. | <span style="color:gray">Planned</span> | 
| **`(*FAIL) (*F) (*FAIL:arg)`** | Fail the pattern/branch. | <span style="color:gray">Planned</span> | 
| **`(*ACCEPT) (*ACCEPT:arg)`**  | Accept the pattern/subpattern. | <span style="color:gray">Planned</span> | 


## Not planned (Mainly because of Unicode or perl specifics)

### Modifiers

| Modifier   | Notes | Status |
| --- | --- | --- |
| `p`                | Preserve the string matched such that ${^PREMATCH}, ${^MATCH}, and ${^POSTMATCH} are available for use after matching. | <span style="color:darkred">Not planned</span> | 
| `a`, `d`, `l`, and `u`   | These modifiers affect which character-set rules (Unicode, etc.) are used, as described below in "Character set modifiers". | <span style="color:darkred">Not planned</span> | 
| `g`                | globally match the pattern repeatedly in the string | <span style="color:darkred">Not planned</span> | 
| `e`                | evaluate the right-hand side as an expression | <span style="color:darkred">Not planned</span> | 
| `ee`               | evaluate the right side as a string then eval the result | <span style="color:darkred">Not planned</span> | 
| `o`                | pretend to optimize your code, but actually introduce bugs | <span style="color:darkred">Not planned</span> | 
| `r`                | perform non-destructive substitution and return the new value | <span style="color:darkred">Not planned</span> | 


### Escape sequences

| Escape sequence   | Notes | Status |
| --- | --- | --- |
| `\cK`         | control char          (example: VT) | <span style="color:darkred">Not planned</span> | 
| `\N{name}`    | named Unicode character or character sequence | <span style="color:darkred">Not planned</span> | 
| `\N{U+263D}`  | Unicode character     (example: FIRST QUARTER MOON) | <span style="color:darkred">Not planned</span> | 
| `\l`          | lowercase next char (think vi) | <span style="color:darkred">Not planned</span> | 
| `\u`          | uppercase next char (think vi) | <span style="color:darkred">Not planned</span> | 
| `\L`          | lowercase until \E (think vi) | <span style="color:darkred">Not planned</span> | 
| `\U`          | uppercase until \E (think vi) | <span style="color:darkred">Not planned</span> | 
| `\Q`          | quote (disable) pattern metacharacters until \E | <span style="color:darkred">Not planned</span> | 
| `\E`          | end either case modification or quoted section, think vi | <span style="color:darkred">Not planned</span> | 


### Character Classes and other Special Escapes

| Character class or escape   | Notes | Status |
| --- | --- | --- |
| `(?[...])`  | Extended bracketed character class | <span style="color:darkred">Not planned</span> | 
| `\pP`       | Match P, named property.  Use \p{Prop} for longer names | <span style="color:darkred">Not planned</span> | 
| `\PP`       | Match non-P | <span style="color:darkred">Not planned</span> | 
| `\X`        | Match Unicode "eXtended grapheme cluster" | <span style="color:darkred">Not planned</span> | 
| `\R`        | Linebreak | <span style="color:darkred">Not planned</span> | 


### Assertions

| Assertion   | Notes | Status |
| --- | --- | --- |
| `\b{}`   | Match at Unicode boundary of specified type | <span style="color:darkred">Not planned</span> | 
| `\B{}`   | Match where corresponding \b{} doesn't match | <span style="color:darkred">Not planned</span> | 

### Extended Patterns


| Extended pattern   | Notes | Status |
| --- | --- | --- |
| `(?{ code })`                 | Perl code execution. | <span style="color:darkred">Not planned</span> | 
| `(*{ code })`                 | Perl code execution. | <span style="color:darkred">Not planned</span> | 
| `(??{ code })`                | Perl code execution. | <span style="color:darkred">Not planned</span> | 
| `(?PARNO)` `(?-PARNO)` `(?+PARNO)` `(?R)` `(?0)`       | Recursive subpattern. | <span style="color:darkred">Not planned</span> | 
| `(?&NAME)`                   | Recursive subpattern. | <span style="color:darkred">Not planned</span> | 


### Script runs

| Script runs   | Notes | Status |
| --- | --- | --- |
| `(*script_run:pattern)`         | All chars in pattern need to be of the same script. | <span style="color:darkred">Not planned</span> | 
| `(*sr:pattern)`                 | All chars in pattern need to be of the same script. | <span style="color:darkred">Not planned</span> | 
| `(*atomic_script_run:pattern)`  | Without backtracking. | <span style="color:darkred">Not planned</span> | 
| `(*asr:pattern)`                | Without backtracking. | <span style="color:darkred">Not planned</span> | 
