#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    int ans = -1;

    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // push onto the stack
            Bracket *b = new Bracket(next, position + 1);
            opening_brackets_stack.push(*b);
        }
        if (next == ')' || next == ']' || next == '}') {
            if(opening_brackets_stack.size() == 0){
              ans = position + 1;
              break;
            }
            // closing should pop off the stack
              // if stack is null, then everything is balanced
            if(opening_brackets_stack.top().Matchc(next)){
              opening_brackets_stack.pop();
              }
            else{
              ans = position + 1;
              break;
            }
        }
    }
    
    // Printing answer, write your code here
    // Balanced - Print Success
    if(opening_brackets_stack.size() == 0 && ans == -1){
      cout << "Success" << endl;
    }
    // Unbalanced - Print Position
    else{
      if(opening_brackets_stack.size() > 0 && ans == -1){
        cout << opening_brackets_stack.top().position << endl;
      } else{
        cout << ans << endl;
      }
    }

    return 0;
}
