RLANG DEVELOPMENT STOPPED FOR UNDETERMINED PERIOD OF TIME
# RLang-Language
**RLang Language is an interpreted language.**<br>
RLang is a simple procedural language run on a interpreter.<br>
But in future Object oriented programming feature might be added<br>
Syntax of RLang if influenced by C++<br>

But RLang focuses on :<br>
Reducing complexity of syntax <br>
Enchancing Readability of code<br>

It supports below data types <br>
1.bool<br>
2.int<br>
3.float<br>
4.string <br>
5.void<br>

**Proposed syntax** <br>

Variable declaration<br>

```
int identifier ;
float identifier ;
bool identifier;
string indetifier;
```

Variable initialization<br>
```
int identifier = constant | identifier;
float identifier = constant | identifier ;
bool identifier = constant | identifier;
string indetifier = constant | identifier;
```
or
```
int identifier(constant | identifier);
float identifier(constant | identifier) ;
bool identifier(constant | identifier);
string indetifier(constant | identifier);
```

Scope<br>

Temporary scopes<br>
How to declare temporary scopes<br>

```
scope
{
}
```
 or <br>
 
```
scope temporary
{
}
```

Permanent scopes<br>
How to declare permanent scopes<br>

```
scope scope-name 
{
}
```

Accessing variables from peramanent scope from  outside<br>

```
scope scope-name 
{
  int identifier; 
}
print(scope-name.identifier);
```

Control structures<br>

*Note: temporary scopes and if and else blocks have similarity*<br>

```
if()
{
 
}
else if()
{

}
else
{
}
```


**Basic system functions**<br>

print();<br>
input();<br>
return();<br>
pause();<br>
exit();<br>

**Currently Interpreter is able to do Lexical Analysis**<br>

*NOTE: PARSER AND INTERPRETER ARE NOT COMPLETE MEANING THEY DONOT MAKE ANY ABSTRACT SYNTAX TREE THEY HAVE RIGID.
SYNTAX SO PARSER IS BEING MADE SEPARATELY ON OTHER REPOSITORY<br>
THOUGH INTERPReTER PART HAS MADE PROGRESS BUT IT IS TEMPORARY ARRANGEMENT FOR NOW<br>
Recursive descent parser is being planned to made*<br>

![](https://github.com/raviverma2791747/RLang-Language/blob/master/RLang/Assests/Program%20structure.png)

The language doesnt have any intermediate representation like pythons bytecode to keep simplicity for now<br>
