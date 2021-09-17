#include "ClientHash.hpp"
#include <list>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

HashTable::HashTable(int hashTableSize)//
{
  this->hashTableSize = hashTableSize;
  hashTable = new client*[hashTableSize];
  for(int i = 0; i<hashTableSize; i++)
  {
      hashTable[i] = NULL;
  }
  numCollisions = 0;
  numItems = 0;
}

HashTable::~HashTable()
{
  for(int i = 0; i < hashTableSize; i++)
  {
    client* newNode = hashTable[i];
    while (newNode != NULL)
    {
      newNode = newNode->next;
      delete newNode;
    }
  }
}

void HashTable::incrementCount(string word)
{
  searchTableName(word)->count++;
}

void HashTable::addClient(string _IDNumber, string _name, string _password, string _passengerNum, string _orgin)
{
  int _IDNumber1 =stoi(_IDNumber);
  int _passengerNum1 = stoi(_passengerNum);

  int hashName = getHash(_name);
  client* pointTemp = hashTable[hashName];
  if(pointTemp == NULL)
  {
      hashTable[hashName] = new client;
      hashTable[hashName]->IDNumber = _IDNumber1;
      hashTable[hashName]->name = _name;
      hashTable[hashName]->passWord = _password;
      hashTable[hashName]->passengerNum = _passengerNum1;
      hashTable[hashName]->orgin = _orgin;
      hashTable[hashName]->next = NULL;
  }
  else
  {
      client* temp = new client;
      temp->IDNumber = _IDNumber1;
      temp->name = _name;
      temp->passWord = _password;
      temp->passengerNum = _passengerNum1;
      temp->orgin = _orgin;
      temp->next = hashTable[hashName];
      hashTable[hashName] = temp;
      numCollisions++;
  }
  numItems++;
}

int HashTable::getTotalNumWords()
{
  int sum = 0;
  for (int i = 0; i < hashTableSize; i++)
  {
    client* newNode = hashTable[i];//head of the table
    if(newNode != NULL)
    {
      while(newNode != NULL)
      {
          sum = sum + newNode->count;
          newNode = newNode->next;
      }
    }
  }
  return sum;
}

unsigned int HashTable::getHash(string word)
{
  unsigned int hashValue = 5381;
  int length = word.length();
  for(int i = 0; i < length; i++)
  {
    hashValue = ((hashValue<<5)+hashValue) + word[i];
  }
  hashValue %= hashTableSize;
  return hashValue;
}

///////////////////////////Search for Name/////////////////////////////////////
client* HashTable::searchTableName(string word)
{
  client* temp = hashTable[getHash(word)];
  while(temp != NULL && temp->name != word)
  {
    temp = temp->next;
  }
  return temp;
}

bool HashTable::isInTableName(string word)
{
  client* result = searchTableName(word);

  if(result == NULL)
  {
    return false;
  }
  else
  {
    return true;
  }
}

///////////////////////////Search for passWord/////////////////////////////////////
client* HashTable::searchTablePassWord(string name, string passWord)
{
  client* temp = hashTable[getHash(name)];
  while(temp != NULL && temp->passWord != passWord)
  {
    temp = temp->next;
  }
  return temp;
}

bool HashTable::isInTablePassWord(string name, string passWord)
{
  client* result = searchTablePassWord(name, passWord);

  if(result == NULL)
  {
    return false;
  }
  else
  {
    return true;
  }
}

int HashTable::getNumCollisions()
{
  return numCollisions;
}

int HashTable::getNumItems()
{
  return numItems;
}


void HashTable::getClient(HashTable &clientTable)
{
  ifstream myfile("ClientList.csv");
  string line;
  if(myfile.is_open())
  {
    while(getline(myfile, line))
    {
      string IDNumber, name, password, passengerNum, orgin;
      stringstream ss(line);
      getline(ss, IDNumber, ',');
      getline(ss, name, ',');
      getline(ss, password, ',');
      getline(ss, passengerNum, ',');
      getline(ss, orgin);
      clientTable.addClient(IDNumber, name, password, passengerNum, orgin);
    }
  }
  else
  {
    cout<<"File not open"<<endl;
  }
  myfile.close();
}

bool HashTable::loginDisplay()
{
    string userName = " ";
    string userPassword = " ";
    bool result1 = false;
    bool result2 = false;
    int loginAttempt = 1;//Keep track of attempts loggin in
    cout<< "Welcome to Ufly"<<endl;
    while(loginAttempt !=  6)
    {
      cout<<"Login attempts: "<<loginAttempt<<endl;
      cout<<"Please Enter userName: ";
      getline(cin,userName);
      cout<<"Please Enter password: ";
      getline(cin,userPassword);
      result1 = isInTableName(userName);
      result2 = isInTablePassWord(userName, userPassword);
      if (result1 == true && result2 == true)
      {
        return true;
      }
      else
      {
          cout << "Invalid login attempt. Please try again.\n" << '\n';
          loginAttempt++;
      }
      if (loginAttempt == 6)
      {
          cout << "Too many login attempts! The program will now terminate."<<endl;
          return false;//if its false terminate the program in main
      }
    }
    return false;
}

