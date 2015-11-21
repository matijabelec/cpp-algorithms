# 02 - Branching

In c++ programming language we have a few options when our program needs to 
change its execution path depending on a condition.

For example: when user inputs an number bigger than 100 we want to print out 
an "OK" string. Otherwise we want to output "WRONG INPUT".
This can be done with simple use of if-else conditional branch:
```c++
int a;
cout << "a = ";
cin >> a;

if(a > 100) {
    cout << "OK" << endl;
} else {
    cout << "WRONG INPUT" << endl;
}
```

## if - else

The simple conditional branch. We check if an condition is true and if it is 
true the code inside "if block" is executed, otherwise the code inside 
"else block" is executed.

Example:
```c++
if(a > 100) {
    cout << "Number is bigger than 100." << endl;
} else {
    cout << "Number is not bigger than 100." << endl;
}
```

## if - else if - else

When we want to check multiple conditions and execute only one block depending 
on first condition which evaluates to true we can use if - else if - else.

Example:
```c++
if(a > 0) {
    cout << "Number is positive." << endl;
} else if(a < 0) {
    cout << "Number is negative." << endl;
} else {
    cout << "Number is zero." << endl;
}
```

## switch

When we need to check an value of some computation or variable against multiple 
values we can use switch branching.

Example:
```c++
switch(a) {
    case 1:
        cout << "Number is 1." << endl;
        break;
    case 2:
        cout << "Number is 2." << endl;
        break;
    case 3:
        cout << "Number is 3." << endl;
        break;
    case 4:
        cout << "Number is 4." << endl;
        break;
    default: 
        cout << "Number is not 1 or 2 or 3 or 4." << endl;
        break;
}
```
