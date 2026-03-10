#!/bin/bash
# Run this script on your server: bash make_tests.sh
# Creates all Lab 7 test files in ~/test7/
# KEY: in this lang grammar, functions are declared INSIDE the program block

mkdir -p ~/test7

# test01: print integer literals
cat > ~/test7/test01.lang << 'LANG'
// Benjamin Kerr - test01: print integer literals (basic sanity check)
program
{
    print(1);
    print(2);
    print(42);
}
LANG
printf "1\n2\n42\n" > ~/test7/test01.correct

# test02: int variable declare, assign, print
cat > ~/test7/test02.lang << 'LANG'
// Benjamin Kerr - test02: int variable declaration, assignment, and print
program
{
    int x;
    int y;
    x = 7;
    y = 13;
    print(x);
    print(y);
}
LANG
printf "7\n13\n" > ~/test7/test02.correct

# test03: char variable declare and assign
cat > ~/test7/test03.lang << 'LANG'
// Benjamin Kerr - test03: char variable declaration and assignment (byte ops)
program
{
    char c;
    c = 65;
    print(c);
}
LANG
printf "65\n" > ~/test7/test03.correct

# test04: char uses byte ops, not word ops
cat > ~/test7/test04.lang << 'LANG'
// Benjamin Kerr - test04: char byte store/load distinct from int word store/load
program
{
    char a;
    char b;
    int  n;
    a = 10;
    b = 20;
    n = 300;
    print(a);
    print(b);
    print(n);
}
LANG
printf "10\n20\n300\n" > ~/test7/test04.correct

# test05: arithmetic operators
cat > ~/test7/test05.lang << 'LANG'
// Benjamin Kerr - test05: all arithmetic operators (+, -, *, /, %)
program
{
    int a;
    int b;
    a = 10;
    b = 3;
    print(a + b);
    print(a - b);
    print(a * b);
    print(a / b);
    print(a % b);
}
LANG
printf "13\n7\n30\n3\n1\n" > ~/test7/test05.correct

# test06: relational operators
cat > ~/test7/test06.lang << 'LANG'
// Benjamin Kerr - test06: relational operators (==, !=, <, >, <=, >=)
program
{
    int a;
    int b;
    a = 5;
    b = 10;
    print(a == b);
    print(a != b);
    print(a < b);
    print(a > b);
    print(a <= b);
    print(a >= b);
}
LANG
printf "0\n1\n1\n0\n1\n0\n" > ~/test7/test06.correct

# test07: operator precedence and associativity
cat > ~/test7/test07.lang << 'LANG'
// Benjamin Kerr - test07: precedence (* before +) and left-associativity
program
{
    int x;
    x = 2 + 3 * 4;
    print(x);
    x = 10 - 3 - 2;
    print(x);
    x = 2 * 3 + 4 * 5;
    print(x);
    x = 20 / 4 / 2;
    print(x);
}
LANG
printf "14\n5\n26\n2\n" > ~/test7/test07.correct

# test08: array as lval and rval
cat > ~/test7/test08.lang << 'LANG'
// Benjamin Kerr - test08: array element as lval (store) and rval (load)
program
{
    array int[3] arr;
    arr[0] = 11;
    arr[1] = 22;
    arr[2] = 33;
    print(arr[0]);
    print(arr[1]);
    print(arr[2]);
}
LANG
printf "11\n22\n33\n" > ~/test7/test08.correct

# test09: function call without params
cat > ~/test7/test09.lang << 'LANG'
// Benjamin Kerr - test09: function declaration and call with no parameters
program
{
    int getVal()
    {
        return 99;
    }
    int v;
    v = getVal();
    print(v);
}
LANG
printf "99\n" > ~/test7/test09.correct

# test10: function call with params
cat > ~/test7/test10.lang << 'LANG'
// Benjamin Kerr - test10: function call with integer parameters
program
{
    int add(int a, int b)
    {
        return a + b;
    }
    int result;
    result = add(3, 4);
    print(result);
    print(add(10, 20));
}
LANG
printf "7\n30\n" > ~/test7/test10.correct

# test11: int return values used in expressions
cat > ~/test7/test11.lang << 'LANG'
// Benjamin Kerr - test11: function return values used in expressions and nested calls
program
{
    int double(int x)
    {
        return x * 2;
    }
    int square(int x)
    {
        return x * x;
    }
    print(double(5));
    print(square(4));
    print(double(square(3)));
}
LANG
printf "10\n16\n18\n" > ~/test7/test11.correct

# test12: stack preservation across calls
cat > ~/test7/test12.lang << 'LANG'
// Benjamin Kerr - test12: locals survive across function calls (stack preservation)
program
{
    int inc(int x)
    {
        return x + 1;
    }
    int a;
    int b;
    a = 10;
    b = 20;
    print(inc(a));
    print(a);
    print(b);
}
LANG
printf "11\n10\n20\n" > ~/test7/test12.correct

# test13: if statement
cat > ~/test7/test13.lang << 'LANG'
// Benjamin Kerr - test13: if statement with condition true and condition false
program
{
    int x;
    x = 5;
    if (x > 3)
        print(1);
    endif;
    if (x > 10)
        print(2);
    endif;
    print(3);
}
LANG
printf "1\n3\n" > ~/test7/test13.correct

# test14: if-else statement
cat > ~/test7/test14.lang << 'LANG'
// Benjamin Kerr - test14: if-else with both branches exercised
program
{
    int x;
    x = 7;
    if (x > 5)
        print(1);
    else
        print(2);
    endif;
    x = 3;
    if (x > 5)
        print(3);
    else
        print(4);
    endif;
}
LANG
printf "1\n4\n" > ~/test7/test14.correct

# test15: while loop
cat > ~/test7/test15.lang << 'LANG'
// Benjamin Kerr - test15: while loop counting from 1 to 5
program
{
    int i;
    i = 1;
    while (i <= 5)
    {
        print(i);
        i = i + 1;
    }
}
LANG
printf "1\n2\n3\n4\n5\n" > ~/test7/test15.correct

echo "Done. Test files:"
ls ~/test7/*.lang | wc -l
