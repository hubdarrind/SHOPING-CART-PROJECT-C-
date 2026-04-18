#include "../includes/auth.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool authSystem()
{
    int choice;
    while (true)
    {
        cout << "\n========= AUTHENTICATION =========\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. Forgot Password\n";
        cout << "4. Exit\n";

        cout << "==================================\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (loginUser())
                return true;
        }
        else if (choice == 2)
        {
            registerUser();
        }
        else if (choice == 3)
        {
            forgotPassword();
        }
        else if(choice == 4){
          return false;
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }
}

void registerUser()
{
  string username, email, password;
  cout << "\n--- REGISTER ---\n";
  cout << "Enter new username: ";
  cin.ignore();
  getline(cin, username);

  cout << "Enter your email: ";
  getline(cin, email);


  ifstream inFile("users.txt");
  string u, e, p;
  bool emailExists = false;
  if (inFile.is_open())
  {
      while (getline(inFile, u) && getline(inFile, e) && getline(inFile, p))
      {
          if (e == email)
          {
              emailExists = true;
              break;
          }
      }
      inFile.close();
  }

  if (emailExists)
  {
      cout << "Error: A user with this email already exists! Registration failed.\n";
      return;
  }

  cout << "Enter new password: ";
  getline(cin, password);

  ofstream file("users.txt", ios::app);
  if (file.is_open())
  {
    file << username << endl;
    file << email << endl;
    file << password << endl;
    file.close();
    cout << "Registration Successful! Please Login.\n";
  }
  else
  {
    cout << "Error opening users file.\n";
  }
}

bool loginUser()
{
  string username, password, u, e, p;
  cout << "\n--- LOGIN ---\n";
  cout << "Username: ";
  cin.ignore();
  getline(cin, username);
  cout << "Password: ";
  getline(cin, password);

  ifstream file("users.txt");
  bool found = false;

  if (!file)
  {
    cout << "No users registered yet.\n";
    return false;
  }

  while (getline(file, u) && getline(file, e) && getline(file, p))
  {
    if (u == username && p == password)
    {
      found = true;
      break;
    }
  }
  file.close();

  if (found)
  {
    cout << "Login Successful! Welcome " << username << ".\n";
    return true;
  }
  else
  {
    cout << "Invalid credentials. Try again.\n";
    return false;
  }
}

void forgotPassword()
{
  string targetUser, targetEmail, newPass;
  cout << "\n--- FORGOT PASSWORD ---\n";
  cout << "Enter your username: ";
  cin.ignore();
  getline(cin, targetUser);
  cout << "Enter your email: ";
  getline(cin, targetEmail);

  string storedUsers[100];
  string storedEmails[100];
  string storedPass[100];
  int count = 0;

  ifstream inFile("users.txt");
  if (!inFile)
  {
    cout << "No users registered yet.\n";
    return;
  }

  string user, email, password;

  while (count < 100 && getline(inFile, user) && getline(inFile, email) && getline(inFile, password))
  {
    storedUsers[count] = user;
    storedEmails[count] = email;
    storedPass[count] = password;
    count++;
  }
  inFile.close();

  bool found = false;
  for (int i = 0; i < count; i++)
  {
    if (storedUsers[i] == targetUser && storedEmails[i] == targetEmail)
    {
      cout << "Identity Verified.\n";
      cout << "Enter new password: ";
      getline(cin, newPass);
      storedPass[i] = newPass;
      found = true;
      break;
    }
  }

  if (found)
  {
    ofstream outFile("users.txt");
    if (outFile.is_open())
    {
      for (int i = 0; i < count; i++)
      {
        outFile << storedUsers[i] << endl;
        outFile << storedEmails[i] << endl;
        outFile << storedPass[i] << endl;
      }
      outFile.close();
      cout << "Password updated successfully! Please Login.\n";
    }
    else
    {
      cout << "Error saving changes.\n";
    }
  }
  else
  {
    cout << "Invalid Username or Email. Cannot reset password.\n";
  }
}