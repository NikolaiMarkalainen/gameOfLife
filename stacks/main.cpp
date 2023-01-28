#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stack>


// function for basic string reversals
// reverses argv[1] input;
void reverseInput(std::string& word){
 std::reverse(word.begin(), word.end());
};

// Checks input for palindrome 
// if flag is not inheriting value then its a palindrome
// in other cases its a palindrome.

void isPalindrome(std::string input){
 int flag = 0;
 int len = input.length();
 for(int i = 0; i < len; i++){
  if(input[i] != input[len-i-1]){
   flag = 1;
   break;
  }
 }
 if(flag){
  std::cout<< input << " is not a palindrome " << std::endl;
 }
 else{
  std::cout << input << " is a palindrome" << std::endl;
 }
};

// function to realise stack idea
// display a character and pop it once its displayed
// to the console

void stackInput(std::string& input){

 std::stack<char> stack;
 for(char c : input ) {
  stack.push(c);
 }

 while (!stack.empty()) {
  std::cout << stack.top() << std::endl;
  stack.pop();
 }

};

void numberStack() {
int numberInput;
std::stack<int> numbers;
std::cout << "Enter a sequence of integers of increasing value: " << std::endl;

while( std::cin >> numberInput ) {
 if(numbers.size() > 0 && numberInput <= numbers.top()){
  break;
 }
 numbers.push(numberInput);
}

std::cout << "Integers in decreasing order: " << std::endl;

while(!numbers.empty()){
 std::cout << numbers.top() << std::endl;
 numbers.pop();
}

};

int main (int argc, char* argv[]) {
 
 std::string reversedWord;
 std::string word;
 if(argc >= 2 ){
  word = argv[1];
  reversedWord = word;
  reverseInput(reversedWord);
  std::cout << "Your argument reversed is: " << reversedWord << std::endl;
  isPalindrome(word);
  stackInput(word);
 }

numberStack();
}
