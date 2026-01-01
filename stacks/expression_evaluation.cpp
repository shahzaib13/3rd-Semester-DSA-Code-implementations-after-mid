#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char val)
{
    if ((val >= 'A' && val <= 'Z') ||
        (val >= 'a' && val <= 'z') ||
        (val >= '0' && val <= '9'))
        return true;
    return false;
}

int inStackPriority(char val)
{
    if (val == '#')
        return -1;
    else if (val == '/' || val == '*' || val == '%')
        return 2;
    else if (val == '+' || val == '-')
        return 1;
    else if (val == '(')
        return 0;
    else
        return -1;
}

string infix_to_postfix_converter(string infix)
{
    stack<char> p_Stack;
    p_Stack.push('#');

    string output = "";
    char top = '\0';
    int i = 0;

    while (infix[i] != '\0')
    {
        char curr = infix[i++];

        if (curr == ' ')
            continue;

        else if (isOperand(curr))
            output.push_back(curr);

        else if (curr == '(')
            p_Stack.push(curr);

        else if (curr == ')')
        {
            while (p_Stack.top() != '#' && p_Stack.top() != '(')
            {
                top = p_Stack.top();
                output.push_back(top);
                p_Stack.pop();
            }
            p_Stack.pop();
        }
        else
        {
            while (inStackPriority(p_Stack.top()) >= inStackPriority(curr))
            {
                top = p_Stack.top();
                output.push_back(top);
                p_Stack.pop();
            }
            p_Stack.push(curr);
        }
    }

    while (!p_Stack.empty())
    {
        if (p_Stack.top() != '#')
        {
            top = p_Stack.top();
            output.push_back(top);
            p_Stack.pop();
        }
        else
            p_Stack.pop();
    }

    return output;
}

int char_to_int(char val)
{
    if (val >= '0' && val <= '9')
        return val - '0';
    else if (val >= 'A' && val <= 'Z')
        return val - 'A';
    else if (val >= 'a' && val <= 'z')
        return val - 'a';
    return -1;
}

int calculator(int a, int b, char op)
{
    if (op == '+')
        return b + a;
    else if (op == '-')
        return b - a;
    else if (op == '*')
        return b * a;
    else if (op == '/')
    {
        if (a == 0)
            throw runtime_error("Division by zero");
        return b / a;
    }
    else if (op == '%')
        return b % a;
    else
        return -1;
}

int postfix_expression_evaluator(string postfix)
{
    stack<int> st;
    int i = 0;
    int a, b;
    char curr;

    while (postfix[i] != '\0')
    {
        curr = postfix[i++];

        if (isOperand(curr))
            st.push(char_to_int(curr));
        else
        {
            a = st.top(); st.pop();
            b = st.top(); st.pop();
            st.push(calculator(a, b, curr));
        }
    }
    return st.top();
}

int main()
{
    string infix = "5 * (5 + 5)";
    string post = infix_to_postfix_converter(infix);

    cout << post << endl;
    // cout << postfix_expression_evaluator(post);

    return 0;
}
