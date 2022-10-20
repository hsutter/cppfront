#!/bin/fish

cp ../*.cpp2 .
set count 0
for f in mixed-*.cpp2
    echo Starting cppfront $f
    cppfront $f > $f.output 2>&1
    rm $f
    set count (math $count + 1)
end

for f in pure2-*.cpp2
    echo Starting cppfront $f -p
    cppfront $f -p > $f.output 2>&1
    rm $f
    set count (math $count + 1)
end

echo Done: $count tests
