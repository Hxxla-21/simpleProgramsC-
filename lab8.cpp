/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
#include<stack>
using namespace std;
//Evaluation Method of Postfix expression
/*
  Evaluation Of postfix Expression in C++
  Input Postfix expression must be in a desired format.
  Operands must be integers and there should be space in between two operands.
  Only '+'  ,  '-'  , '*' and '/'  operators are expected.
*/

// Function to evaluate Postfix expression and return output
int EvaluatePostfix(string expression);

// Function to perform an operation and return output.
int PerformOperation(char operation, int operand1, int operand2);

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C);

// Function to verify whether a character is numeric digit.
bool IsNumericDigit(char C);

// Function to evaluate Postfix expression and return output
int EvaluatePostfix(string ex)
{

    stack<int> S;
    for (int i = 0; i < ex.length(); i++)
    {

        if (ex[i] == ' ' || ex[i] == ',')
            continue;

        else if (IsOperator(ex[i])) {

            int operand2 = S.top(); S.pop();
            int operand1 = S.top(); S.pop();

            int result = PerformOperation(ex[i], operand1, operand2);

            S.push(result);
        }
        else if (IsNumericDigit(ex[i])) {

            int operand = 0;
            while (i < ex.length() && IsNumericDigit(ex[i])) {

                operand = (operand * 10) + (ex[i] - '0');
                i++;
            }

            i--;

            S.push(operand);
        }
    }

    return S.top();
}

// Function to verify whether a character is numeric digit.
bool IsNumericDigit(char C)
{
    if (C >= '0' && C <= '9') return true;
    return false;
}

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/')
        return true;

    return false;
}

// Function to perform an operation and return output.
int PerformOperation(char operation, int operand1, int operand2)
{
    if (operation == '+') return operand1 + operand2;
    else if (operation == '-') return operand1 - operand2;
    else if (operation == '*') return operand1 * operand2;
    else if (operation == '/') return operand1 / operand2;

    else cout << "Unexpected Error \n";
    return -1;
}
//---------------------------------------------------------------------------------------------------
// get weight of operators as per precedence
// higher weight given to operators with higher precedence
// for non operators, return 0
int getWeight(char ch) {
    switch (ch) {
    case '/':
    case '*': return 2;
    case '+':
    case '-': return 1;
    default: return 0;
    }
}
//--------------------------------------------------------------------------------------------------

// convert infix expression to postfix using a stack
void infix2postfix(char infix[], char postfix[], int size) {
    stack<char> s;
    int weight;
    int i = 0;
    int k = 0;
    char ch;
    // iterate over the infix expression
    while (i < size) {
        ch = infix[i];
        if (ch == '(') {
            // simply push the opening parenthesis
            s.push(ch);
            i++;
            continue;
        }
        if (ch == ')') {
            // if we see a closing parenthesis,
            // pop of all the elements and append it to
            // the postfix expression till we encounter
            // a opening parenthesis
            while (!s.empty() && s.top() != '(') {
                postfix[k++] = s.top();
                s.pop();

            }
            // pop off the opening parenthesis also
            if (!s.empty()) {
                s.pop();
            }
            i++;
            continue;
        }
        weight = getWeight(ch);
        if (weight == 0) {
            // we saw an operand
            // simply append it to postfix expression
            postfix[k++] = ch;

        }
        else {
            // we saw an operator
            if (s.empty()) {
                // simply push the operator onto stack if
                // stack is empty
                s.push(ch);
            }
            else {
                // pop of all the operators from the stack and
                // append it to the postfix expression till we
                // see an operator with a lower precedence that
                // the current operator
                while (!s.empty() && s.top() != '(' &&
                    weight <= getWeight(s.top())) {
                    postfix[k++] = s.top();
                    s.pop();

                }
                // push the current operator onto stack
                s.push(ch);
            }
        }
        i++;
    }
    // pop of the remaining operators present in the stack
    // and append it to postfix expression
    while (!s.empty()) {
        postfix[k++] = s.top();
        s.pop();
    }
    postfix[k] = 0; // null terminate the postfix expression
}
//------------------------------------------------------------------------------------------------------
// main
int main() {
    cout << ">>>>>>>    Convert Infix to Postfix      <<<<<<<<<< \n";
    cout << ">> Enter the Infix Expression you wish to convert\n";
    cout << "type on one line \n";
    cout << "Example : 7 * 10 + 5 + 4 * 3 + 2 5 * 2 \n";
    cout << "Please enter the Infix expression: ";
    char infix[100];
    cin.get(infix, 100);
    int size = strlen(infix);
    char postfix[size];
    infix2postfix(infix, postfix, size);
    cout << "\nInfix Expression :: " << infix;
    cout << "\nPostfix Expression :: " << postfix;

    // method EvaluatePostfix
    string expression = postfix;
    int result = EvaluatePostfix(expression);
    cout << "\nPostFix Evaluated to : " << result << "\n";


    cout << endl;
    return 0;
}

