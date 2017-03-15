# FuzzyFramework
A fuzzy logic framework built in C++

## How to

You simply define your definition domain with graph shapes defined (Triangle...) then enter the rules with the operators defined (Aggregation, Then, Or, And, Is...).
Here we go ! just set the values for your entry expressions and let the magic begin !

This program is made to be use with a perfectly made GUI ;)

## Main test program

The rules that are implemented are the following :

* **IF** isolation **IS** poor **AND** heating **IS** weak **THEN** heat **IS** cold
* **IF** isolation **IS** poor **AND** heating **IS** strong **THEN** heat **IS** warm
* **IF** isolation **IS** medium **AND** heating **IS** strong **THEN** heat **IS** hot
* **IF** isolation **IS** medium **AND** heating **IS** weak **THEN** heat **IS** warm
* **IF** isolation **IS** high **AND** heating **IS** weak **THEN** heat **IS** hot
* **IF** isolation **IS** high **AND** heating **IS** strong **THEN** heat **IS** hot

You just have to chose a value for your isolation and your heating and then the program computes a value for your heat based on the rules defined earlier.
