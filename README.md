# FuzzyFramework
A fuzzy logic framework built in C++

## Main test program

The rules that are implemented are the following :

* **IF** isolation **IS** poor **AND** heating **IS** weak **THEN** heat **IS** cold
* **IF** isolation **IS** poor **AND** heating **IS** strong **THEN** heat **IS** warm
* **IF** isolation **IS** medium **AND** heating **IS** strong **THEN** heat **IS** hot
* **IF** isolation **IS** medium **AND** heating **IS** weak **THEN** heat **IS** warm
* **IF** isolation **IS** high **AND** heating **IS** weak **THEN** heat **IS** hot
* **IF** isolation **IS** high **AND** heating **IS** strong **THEN** heat **IS** hot

You just have to chose a value for your isolation and your heating and then the program computes a value for your heat based on the rules defined earlier.
