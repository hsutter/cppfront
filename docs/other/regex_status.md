# Supported regular expression features

The listings are taken from [perl regex docs](https://perldoc.perl.org/perlre). Regular expressions are applied via [metafunctions](../cpp2/metafunctions.md#regex)

## Current status and planned on doing

### Modifiers
```
 - [x] i                Do case-insensitive pattern matching. For example, "A" will match "a" under /i.
 - [x] m                Treat the string being matched against as multiple lines. That is, change "^" and "$" from matching the start of the string's first line and the end of its last line to matching the start and end of each line within the string.
 - [x] s                Treat the string as single line. That is, change "." to match any character whatsoever, even a newline, which normally it would not match.
 - [x] x and xx         Extend your pattern's legibility by permitting whitespace and comments. Details in "/x and /xx"
 - [x] n                Prevent the grouping metacharacters () from capturing. This modifier will stop $1, $2, etc... from being filled in.
 - [ ] c                keep the current position during repeated matching
```

### Escape sequences __(Complete)__
```
 - [x] \t          tab                   (HT, TAB)
 - [x] \n          newline               (LF, NL)
 - [x] \r          return                (CR)
 - [x] \f          form feed             (FF)
 - [x] \a          alarm (bell)          (BEL)
 - [x] \e          escape (think troff)  (ESC)
 - [x] \x{}, \x00  character whose ordinal is the given hexadecimal number
 - [x] \o{}, \000  character whose ordinal is the given octal number

```

### Quantifiers __(Complete)__
```
 - [x] *           Match 0 or more times
 - [x] +           Match 1 or more times
 - [x] ?           Match 1 or 0 times
 - [x] {n}         Match exactly n times
 - [x] {n,}        Match at least n times
 - [x] {,n}        Match at most n times
 - [x] {n,m}       Match at least n but not more than m times
 - [x] *?        Match 0 or more times, not greedily
 - [x] +?        Match 1 or more times, not greedily
 - [x] ??        Match 0 or 1 time, not greedily
 - [x] {n}?      Match exactly n times, not greedily (redundant)
 - [x] {n,}?     Match at least n times, not greedily
 - [x] {,n}?     Match at most n times, not greedily
 - [x] {n,m}?    Match at least n but not more than m times, not greedily
 - [x] *+     Match 0 or more times and give nothing back
 - [x] ++     Match 1 or more times and give nothing back
 - [x] ?+     Match 0 or 1 time and give nothing back
 - [x] {n}+   Match exactly n times and give nothing back (redundant)
 - [x] {n,}+  Match at least n times and give nothing back
 - [x] {,n}+  Match at most n times and give nothing back
 - [x] {n,m}+ Match at least n but not more than m times and give nothing back
```

### Character Classes and other Special Escapes __(Complete)__
```
 - [x] [...]        Match a character according to the rules of the
                    bracketed character class defined by the "...".
                    Example: [a-z] matches "a" or "b" or "c" ... or "z"
 - [x] [[:...:]]    Match a character according to the rules of the POSIX
                    character class "..." within the outer bracketed
                    character class.  Example: [[:upper:]] matches any
                    uppercase character.
 - [x] \g1          Backreference to a specific or previous group,
 - [x] \g{-1}       The number may be negative indicating a relative
                    previous group and may optionally be wrapped in
                    curly brackets for safer parsing.
 - [x] \g{name}     Named backreference
 - [x] \k<name>     Named backreference
 - [x] \k'name'     Named backreference
 - [x] \k{name}     Named backreference
 - [x] \w           Match a "word" character (alphanumeric plus "_", plus
                    other connector punctuation chars plus Unicode
                    marks)
 - [x] \W           Match a non-"word" character
 - [x] \s           Match a whitespace character
 - [x] \S           Match a non-whitespace character
 - [x] \d           Match a decimal digit character
 - [x] \D           Match a non-digit character
 - [x] \v           Vertical whitespace
 - [x] \V           Not vertical whitespace
 - [x] \h           Horizontal whitespace
 - [x] \H           Not horizontal whitespace
 - [x] \1           Backreference to a specific capture group or buffer.
                    '1' may actually be any positive integer.
 - [x] \N           Any character but \n.  Not affected by /s modifier
 - [x] \K           Keep the stuff left of the \K, don't include it in $&
```

### Assertions
```
 - [x] \b     Match a \w\W or \W\w boundary
 - [x] \B     Match except at a \w\W or \W\w boundary
 - [x] \A     Match only at beginning of string
 - [x] \Z     Match only at end of string, or before newline at the end
 - [x] \z     Match only at end of string
 - [ ] \G     Match only at pos() (e.g. at the end-of-match position
              of prior m//g)
```

### Capture groups __(Complete)__
```
 - [x] (...)
```

### Quoting metacharacters __(Complete)__
```
 - [x] For ^.[]$()*{}?+|\
```

### Extended Patterns
```
 - [x] (?<NAME>pattern)            Named capture group
 - [x] (?#text)                    Comments
 - [x] (?adlupimnsx-imnsx)         Modification for surrounding context
 - [x] (?^alupimnsx)               Modification for surrounding context
 - [x] (?:pattern)                 Clustering, does not generate a group index.
 - [x] (?adluimnsx-imnsx:pattern)  Clustering, does not generate a group index and modifications for the cluster.
 - [x] (?^aluimnsx:pattern)        Clustering, does not generate a group index and modifications for the cluster.
 - [x] (?|pattern)                 Branch reset
 - [x] (?'NAME'pattern)            Named capture group
 - [ ] (?(condition)yes-pattern|no-pattern)  Conditional patterns.
 - [ ] (?(condition)yes-pattern)             Conditional patterns.
 - [ ] (?>pattern)                 Atomic patterns. (Disable backtrack.)
 - [ ] (*atomic:pattern)           Atomic patterns. (Disable backtrack.)
```

### Lookaround Assertions
```
 - [x] (?=pattern)                     Positive look ahead.
 - [x] (*pla:pattern)                  Positive look ahead.
 - [x] (*positive_lookahead:pattern)   Positive look ahead.
 - [x] (?!pattern)                     Negative look ahead.
 - [x] (*nla:pattern)                  Negative look ahead.
 - [x] (*negative_lookahead:pattern)   Negative look ahead.
 - [ ] (?<=pattern)                    Positive look behind.
 - [ ] (*plb:pattern)                  Positive look behind.
 - [ ] (*positive_lookbehind:pattern)  Positive look behind.
 - [ ] (?<!pattern)                    Negative look behind.
 - [ ] (*nlb:pattern)                  Negative look behind.
 - [ ] (*negative_lookbehind:pattern)  Negative look behind.
```

### Special Backtracking Control Verbs
```
 - [ ] (*PRUNE) (*PRUNE:NAME)   No backtracking over this point.
 - [ ] (*SKIP) (*SKIP:NAME)     Start next search here.
 - [ ] (*MARK:NAME) (*:NAME)    Place a named mark.
 - [ ] (*THEN) (*THEN:NAME)     Like PRUNE.
 - [ ] (*COMMIT) (*COMMIT:arg)  Stop searching.
 - [ ] (*FAIL) (*F) (*FAIL:arg) Fail the pattern/branch.
 - [ ] (*ACCEPT) (*ACCEPT:arg)  Accept the pattern/subpattern.
```

## Not planned (Mainly because of Unicode or perl specifics)

### Modifiers
```
 - [ ] p                Preserve the string matched such that ${^PREMATCH}, ${^MATCH}, and ${^POSTMATCH} are available for use after matching.
 - [ ] a, d, l, and u   These modifiers affect which character-set rules (Unicode, etc.) are used, as described below in "Character set modifiers".
 - [ ] g                globally match the pattern repeatedly in the string
 - [ ] e                evaluate the right-hand side as an expression
 - [ ] ee               evaluate the right side as a string then eval the result
 - [ ] o                pretend to optimize your code, but actually introduce bugs
 - [ ] r                perform non-destructive substitution and return the new value
```

### Escape sequences
```
 - [ ] \cK         control char          (example: VT)
 - [ ] \N{name}    named Unicode character or character sequence
 - [ ] \N{U+263D}  Unicode character     (example: FIRST QUARTER MOON)
 - [ ] \l          lowercase next char (think vi)
 - [ ] \u          uppercase next char (think vi)
 - [ ] \L          lowercase until \E (think vi)
 - [ ] \U          uppercase until \E (think vi)
 - [ ] \Q          quote (disable) pattern metacharacters until \E
 - [ ] \E          end either case modification or quoted section, think vi
```

### Character Classes and other Special Escapes
```
 - [ ]  (?[...])  Extended bracketed character class
 - [ ] \pP        Match P, named property.  Use \p{Prop} for longer names
 - [ ] \PP        Match non-P
 - [ ] \X         Match Unicode "eXtended grapheme cluster"
 - [ ] \R         Linebreak
```

### Assertions
```
 - [ ] \b{}   Match at Unicode boundary of specified type
 - [ ] \B{}   Match where corresponding \b{} doesn't match
```

### Extended Patterns
```
 - [ ] (?{ code })                 Perl code execution.
 - [ ] (*{ code })                 Perl code execution.
 - [ ] (??{ code })                Perl code execution.
 - [ ] (?PARNO) (?-PARNO) (?+PARNO) (?R) (?0)       Recursive subpattern.
 - [ ] (?&NAME)                   Recursive subpattern.
```

### Script runs
```
 - [ ] (*script_run:pattern)         All chars in pattern need to be of the same script.
 - [ ] (*sr:pattern)                 All chars in pattern need to be of the same script.
 - [ ] (*atomic_script_run:pattern)  Without backtracking.
 - [ ] (*asr:pattern)                Without backtracking.
```
