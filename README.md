<div align="center" id="top">
    <h1 markdown="1">:fish_cake: Fibonacci :fish_cake:</h1>
</div>

<div align="center">
    <img alt="Language" src="https://img.shields.io/badge/language-C-blue?logo=c" />
    <img alt="Compilation" src="https://img.shields.io/badge/compilation-via_Makefile-blue" />
    <img alt="Development status" src="https://img.shields.io/badge/development-interrupted-red?logo=windows-terminal" />
    <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/QuentindiMeo/Fibonacci?color=blueviolet&logo=clarifai" />
</div>
<div align="center">
    <img alt="GitHub repository size" src="https://img.shields.io/github/repo-size/QuentindiMeo/Fibonacci?color=blue&logo=frontify" />
    <img alt="GitHub issues" src="https://img.shields.io/github/issues/QuentindiMeo/Fibonacci?color=green&logo=target" />
    <img alt="GitHub contributors" src="https://img.shields.io/github/contributors/QuentindiMeo/Fibonacci?color=red&logo=stackedit" />
    <img alt="Lines of code" src="https://tokei.rs/b1/github/QuentindiMeo/Fibonacci?category=code" />
</div>
&#xa0;

## :memo: Description

This C program computes the Fibonacci sequence from 0 to infinity.  
With or without parameters, you may enjoy reading the first values, find one, or simply unleash its computing power.

## :abacus: Usage

&#xa0;  
&nbsp;&nbsp; :checkered_flag:&nbsp; **Build/Compilation & Launch**

``` bash
make
./fibonacci [OPTIONS]
```

&#xa0;

&nbsp;&nbsp; :hammer_and_wrench:&nbsp; **Options**

``` bash
-d, --digits <int>  Compute the sequence until the result is *n* digits long
-u, --until  <int>  Compute the sequence until the *n*th Fibonacci number
-e, --end    <int>  Compute the sequence until the result is superior or equal to *n*
-F, --find   <int>  Find and print only F(*n*). Denies all other parameters
-S, --start  <int>  Start computing the sequence at *n* using the storage file (see --store)
--slow       <int>  Slow down the program by waiting *n* milliseconds after every iteration (max 100,000)

--silent            Make it so that the program does not print what it finds.
--store             Store the results in a file (calculations_fib.txt).

-h, --help          Display this help and exit
```

&#xa0;

&nbsp;&nbsp; :test_tube:&nbsp; **General**

The format for printing calculations is `$>  F(n)    =    value`.  
The exit status of the program is 0 if everything went well, 84 if an invalid argument was detected.  
The storage file ([calculations_fib.txt](./calculations_fib.txt)) was designed to make you able to inspect your calculations.

&#xa0;

**Work still in progress: -S (--start) has yet to be implemented.**  
*If you want new features to be included or found a malfunction, feel free to let me know by opening an issue.*

&#xa0;

[Back to top](#top)
