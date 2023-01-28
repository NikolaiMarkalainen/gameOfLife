#include <iostream>
#include <string>
#include <bits/stdc++.h>

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


int main (int argc, char* argv[]) {
 
 std::string word;

 if(argc >= 2 ){
  word = argv[1];
  std::string originalWord = word;
  reverseInput(word);
  std::cout << "Your argument reversed is: " << word << std::endl;
  isPalindrome(originalWord);
 }
return 0;
}
