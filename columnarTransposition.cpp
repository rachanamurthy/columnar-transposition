//Multiple Columnar Transposition
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
using namespace std;

void encrypt()
{
  char str[100];
  cout << "\nEnter plain text ";
  cin >> str;
  char key[100],backup[100];
  cout << "\nEnter key ";
  cin >> key;
  strcpy(backup, key);
  int s = strlen(str);
  int k = strlen(key);
  cout << "Length of plain text = " << s << endl << "Length of key = " << k;
  int offset = s%k;

  //adding fillers
  if (offset)
  {
    for (int i = 0; i<k-offset; i++)
    {
      strcat(str,"x");
    }
  }
  cout << endl << str << endl;
  s = strlen(str);

  //calculating number of rows
  int row = s / k;
  char temp[100][100];
  int z = 0;
  //writing into temporary character array row-wise
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < k; j++)
    {
      temp[i][j] = str[z++];
      cout << temp[i][j];
    }
  }

  //sorting key
  char t;
  for (int i = 0; i < k; i++)
  {
    for (int j = 0; j < k - 1; j++)
    {
      if (key[i] < key[j])
      {
        t = key[i];
        key[i] = key[j];
        key[j] = t;
      }
    }
  }

  //finding the pattern of decryption
  int pattern[10];
  for (int i = 0; i<k; i++)
  {
    int j = 0;
    while (j != k)
    {
      if (backup[i] == key[j])
      {
        pattern[j] = i;
        break;
      }
      else
        j = j + 1;
    }
  }

  cout << "\nThe pattern in which the text has to be encrypted is as follows: ";
  for (int i = 0; i<k; i++)
    cout << pattern[i] << " ";
  cout << "\n";

  char cipher[100][100];

  for (int i = 0; i < k; i++)
  {
    for (int j = 0; j < row; j++)
    {
      cipher[i][j] = temp[j][pattern[i]];
    }
  }
  cout << endl << "Encrypted Text\n";
  for (int i = 0; i <k; i++)
  {
    for (int j = 0; j < row; j++)
      cout << cipher[i][j];
  }
  cout << endl;
}

void decrypt()
{
  char key[10], cipher[10][10], backup[10], cback[10][10];
  int k, c, m;
  //key
  cout << "\nEnter the key length ";
  cin >> k;
  cout << "\nEnter the key ";
  for (int i = 0; i<k; i++)
    cin >> key[i];
  for (int i = 0; i<k; i++)
    backup[i] = key[i];

  //cipher
  cout << "\nEnter the cipher text length ";
  cin >> c;
  m = c / k;
  cout << "\nEnter the cipher text without spaces ";
  for (int j = 0; j<k; j++)
    for (int i = 0; i<m; i++)
      cin >> cipher[i][j];

  cout << "\nThe cipher text entered is as follows : ";
  for (int i = 0; i<m; i++)
  {
    cout << "\n";
    for (int j = 0; j<k; j++)
    {
      cout << cipher[i][j] << " ";
    }
  }

  //sorting key
  char t;
  int i, j;
  for (i = 0; i<k; i++)
  {
    for (j = 0; j<k - 1; j++)
    {
      if (key[i]<key[j])
      {
        t = key[i];
        key[i] = key[j];
        key[j] = t;
      }
    }
  }

  cout << "\nThe sorted key is: ";
  for (int i = 0; i<k; i++)
    cout << key[i];
  cout << "\n";

  //finding the pattern of decryption
  int pattern[10];
  for (int i = 0; i<k; i++)
  {
    int j = 0;
    while (j != k)
    {
      if (backup[i] == key[j])
      {
        pattern[i] = j;
        break;
      }
      else
        j = j + 1;
    }
  }

  cout << "\nThe pattern in which the text has to be decrypted is as follows: ";
  for (i = 0; i<k; i++)
    cout << pattern[i] << " ";
  cout << "\n";
  //rearranging the cipher matrix according to pattern

  for (i = 0; i<m; i++)
  {
    for (j = 0; j<k; j++)
    {
      cback[i][j] = cipher[i][pattern[j]];
    }
  }

  cout << "\nThe plain text without spaces is as follows:\n ";
  for (i = 0; i<m; i++)
    for (j = 0; j<k; j++)
      cout << cback[i][j];
}

int main()
{
  int x;
  int s;
lbl:
  cout << "\nMultiple Columnar Transposition";
  cout << "\nPlease enter your choice ";
  cout << "\n1.Encrpyt\n2.Decrypt\n3.Exit\n";
  cin >> x;
  switch (x)
  {
  case 1: encrypt();
    break;
  case 2: decrypt();
    break;
  case 3:
      return 0;
  default: cout << "\nInvalid input!";
  }
  goto lbl;
  return 0;
}
