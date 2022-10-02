#include <iostream>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
using namespace std;

//Create a class that handles the input of the user and determines if they should be granted access.
class loginManeger{
    public:
    string usernameAttempt;
    string passwordAttempt;
    bool access = false;
    
    //Create a constructor.
    loginManeger(){
        
    }
//    Create a login.
    void login(){
        
        //Get user input.
        cout << "Username: ";
        getline (cin, usernameAttempt);

        cout << "Password: ";
        getline (cin, passwordAttempt);
        
        //Loop through the list of passwords and usernames and compare it with input from the user.
        
        for (int i = 0; i < 13; i++) {
            
            if(usernameAttempt == username[i] && passwordAttempt == password[i]){

                access = true;
            }
        }

        if(access == true){
            cout << "Access granted \n";
        }

        if(access == false){
            cout << "Access denied \n";
        }
            
    }
    
    private:
        // A list of passwords and usernames.
    
        string username[13] = {
            "King Arthur",
            "Lancelot",
            "Sir Robin, the Not-Quite-So-Brave",
            "Black Knight",
            "Sir Bedivere",
            "Roger the Shrubber",
            "Brother Maynard",
            "Bridgekeeper",
            "French Soldier",
            "Knight of Ni",
            "Dead Collector",
            "Dennis",
            "King of Swamp Castle"};

        string password [13] = {
            "Run away!",
            "She turned me into a newt!",
            "That's enough singing for now",
            "None shall pass",
            "How do you know so much about swallows?",
            "Oh, what sad times are these when passing ruffians can say Ni at will to old ladies.",
            "Armaments, chapter two, verses nine through twenty-one",
            "What... is the air-speed velocity of an unladen swallow?",
            "I fart in your general direction",
            "You must cut down the mightiest tree in the forest... WITH... A HERRING!",
            "Bring out your dead!",
            "Help, I'm being oppressed",
            "Let's not bicker and argue over who killed who'"};
    
};

//Create a function that checks how strong a password is.
void printStrong(string& input)
{
    //Get the length of the input.
    int n = input.length();
    
    //Make boolean variables to keep track of the password and make sure it has the correct characters.
    bool hasLower = false;
    bool hasUpper = false;
    bool hasDigit = false;
    bool specialChar = false;
    
    //Make a variable that contains characters to compare with.
    string normalChars = "abcdefghijklmnopqrstu"
        "vwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
    
    //Make sure that the password has a uppercase, lowercase, digit, and a special character.
 
    for (int i = 0; i < n; i++) {
        if (islower(input[i]))
            hasLower = true;
        if (isupper(input[i]))
            hasUpper = true;
        if (isdigit(input[i]))
            hasDigit = true;
 
        size_t special = input.find_first_not_of(normalChars);
        if (special != string::npos)
            specialChar = true;
    }
 
    //Print how strong the password is by comparing inputs with built-in functions.
    cout << "Strength of password:-";
    if (hasLower && hasUpper && hasDigit &&
        specialChar && (n >= 8))
        cout << "Strong";
    else if ((hasLower || hasUpper) &&
             specialChar && (n >= 6))
        cout << "Moderate";
    else
        cout << "Weak";
}

int main() {
    
    loginManeger loginManagerObj;
    
    string choice;
    
    //Display choices to the user.
    cout << "Welcome \n";
    cout << "Please select one of the options. \n";
    
    cout << "1: Login \n2: Create new account \n3 Check password strenght \n";
    getline (cin, choice);
    
    if(choice == "1"){
        //Call the login method.
        loginManagerObj.login();
        
    }
    
    else if(choice == "2"){
        
    }
    
    else if(choice == "3"){
        string input;
        cout << "Input password: ";
        getline (cin, input);
        //Call strongPassword.
        printStrong(input);
    }
    
    return 0;
}
