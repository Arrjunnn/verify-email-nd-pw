#include <stdio.h> 
#include <string.h> 
#include <stdbool.h> 
#include<ctype.h> 
 
bool validateEmail(const char *email) 
{    
    int emailLength = strlen(email); 
    int atIndex = -1; 
    int dotIndex = -1; 
 
    // Check for minimum length 
    if (emailLength < 5)
    { 
        return false; 
    } 
 
    // Check for '@' symbol 
    for (int i = 0; i < emailLength; i++) 
    { 
        if (email[i] == '@') 
        { 
            atIndex = i;            
            break; 
        } 
    } 
 
    if (atIndex == -1)
    {        
        return false; // No '@' symbol found 
    } 
 
    // Check for '.' after '@' symbol 
    for (int i = atIndex; i < emailLength; i++)
    { 
        if (email[i] == '.')
        {            
            dotIndex = i;         
            break; 
        } 
    } 
 
    if (dotIndex == -1)
    {        
        return false; // No '.' symbol found after '@' 
    } 
 
    // Check for invalid characters    
    for (int i = 0; i < emailLength; i++) 
    {      
        if (isalpha(email[i]) || isdigit(email[i]) || email[i] == '@' || email[i] == '.' || email[i] == '-' || email[i] == '_') 
        {            
            continue; 
        } 
        return false; // Invalid character found 
    } 
 
    // Check for consecutive dots    
    for (int i = 0; i < emailLength - 1; i++)
    {        
        if (email[i] == '.' && email[i + 1] == '.') 
        { 
            return false; // Consecutive dots found 
        } 
    } 
 
    return true; // All checks passed, email is valid 
} 
bool confirmPassword(const char* password1, const char* password2)
{
    // Compare the two passwords    
    if (strcmp(password1, password2) == 0) 
    {       
        return true;   
    } 
    else
    {        
        return false; 
    } 
} 
int checkStrength(char password2[])
{
    int length = strlen(password2);
    int hasUpperCase = 0;
    int hasLowerCase = 0;
    int hasDigit = 0;
    int hasSpecialChar = 0;

    // Checking each character of the password
    for (int i = 0; i < length; i++) 
    {
        if (password2[i] >= 'A' && password2[i] <= 'Z')
            hasUpperCase = 1;
        else if (password2[i] >= 'a' && password2[i] <= 'z')
            hasLowerCase = 1;
        else if (password2[i] >= '0' && password2[i] <= '9')
            hasDigit = 1;
        else
            hasSpecialChar = 1;
    }3
    // Determining the password strength
    if (length < 8 || length > 20)
    {
        return 0; // Weak password (length less than 8 or greater than 20)
    } 
    else if (hasUpperCase && hasLowerCase && hasDigit && hasSpecialChar) 
    {
        return 3; // Strong password (contains uppercase, lowercase, digit, and special character)
    }
    else if ((hasUpperCase || hasLowerCase) && hasDigit)
    {
        return 2; // Medium password (contains either uppercase or lowercase and a digit)
    } 
    else 
    {
        return 1; // Weak password (does not meet the criteria for strong or medium)
    }
}

int main()
{    
    char email[100];   
    char password1[100];  
    char password2[100]; 
 
    printf("Enter your email address: ");  
    scanf("%s", email); 
    
    //char password[50];
    //printf("Enter a password: ");
    fgets(password2, sizeof(password2), stdin);
    password2[strcspn(password2, "\n")] = '\0';
    // Remove the trailing newline character from fgets

 
    if (validateEmail(email)) 
    { 
        printf("Email address is valid.\n"); 
 
        printf("Enter your password: "); 
        scanf("%s", password1); 
 
        printf("Confirm your password: ");       
        scanf("%s", password2); 
 
        if (confirmPassword(password1, password2))
        {             
            printf("Password confirmed.\n"); 
 
            // Check if email and password match             
            if (strcmp(email, password1) == 0)
            { 
                printf("Email and password match.\n"); 
            } 
            else
            { 
                printf("Email and password do not match.\n"); 
            } 
        } 
        else
        { 
            printf("Password does not match.\n"); 
        } 
    } 
    else 
    { 
        printf("Invalid email address.\n"); 
    } 
    
    int strength = checkStrength(password2);

    // Displaying the password strength
    switch (strength)
    {
        case 0:printf("Weak password! Length should be between 8 and 20 characters.\n");
            break;
        case 1:printf("Weak password! It should contain either uppercase or lowercase characters and a digit.\n");
            break;
        case 2:printf("Medium password! It contains either uppercase or lowercase characters and a digit.\n");
            break;
        case 3:printf("Strong password! It contains uppercase, lowercase, digit, and special character.\n");
            break;
    }
 
    return 0; 
}
