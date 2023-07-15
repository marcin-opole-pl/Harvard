// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool u_c = false;
    bool l_c = false;
    bool dig = false;
    bool symbol = false;
    for (int i = 0; i < strlen(password); i++)
    {
        if (u_c == false)
        {
            u_c = isupper(password[i]);
        }
        if (l_c == false)
        {
            l_c = islower(password[i]);
        }
        if (dig == false)
        {
            dig = isdigit(password[i]);
        }
        if (symbol == false)
        {
            if (password[i] == '!' || password[i] =='#' || password[i] =='$')
            {
                symbol = true;
            }
        }
    }
    if (u_c == true && l_c == true && dig == true && symbol == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}