\ That's a comment; it ends at the end of the line
( Another comment; it ends here: ) .s

: squared ( n -- n^2 )
    dup * ;

17 squared .
cr

: cubed ( n -- n^3 )
    dup squared * ;

-5 cubed .
cr

: fourth-power ( n -- n^4 )
    squared squared ;

3 fourth-power .
cr

: swap { a b -- b a}
    b a ;

1 42 swap .s
cr

see squared
cr
see cubed
cr
see fourth-power
cr

: abs ( n1 -- +n2)
    dup 0 < if
        negate
    endif ;
5 abs .
cr
-5 abs .
cr

1 2 < .
cr
2 1 < .
cr
1 1 < .
cr

: foo ( n1 -- n2)
    0= if
        14
    else
        0
    endif ;

0 foo .
cr
1 foo .
cr

: foo ( n1 -- n2)
    0= 14 and ;

0 foo .
cr
1 foo .
cr

\ : endless ( -- )
\     0 begin
\         dup . 1+
\     again ;
\ endless


: log2 ( +n1 -- n2 )
\ logarithmus dualis of n1>0, rounded down to the next integer
  assert( dup 0> )
  2/ 0 begin
    over 0> while
      1+ swap 2/ swap
  repeat
  nip ;
7 log2 .
cr
8 log2 .
cr

: ^ ( n1 u -- n)
\ n = the uth power of u1
    1 swap 0 u+do
        over *
    loop
    nip ;

3 2 ^ .
cr
4 3 ^ .
cr

: fac ( u -- u! )
    1 swap 1+ 1 u+do
        i *
    loop ;

5 fac .
cr
7 fac .
cr

: up2 ( n1 n2 -- )
    +do
        i .
    2 +loop ;
10 0 up2
cr

: down2 ( n1 n2 -- )
    -do
        i .
    2 -loop ;
0 10 down2
cr

cr 