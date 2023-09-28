/**
* file: driver-proj0
* author: Michael Mathews
* course: CSI 3334
* assignment: project 0
* due date: January 21, 2022
* version: 11.7
*
* This file uses stacks to type words, undo the typing, and redo the typing
* through commands
 */

#include <iostream>
#include <string>
#include <stack>
#include <cassert>

using namespace std;

/** main
 *  parameters:
 *      argc -- the number of arguments from the command line
 *      argv -- the command line argument values
 *  return value: 0 (indicating a successful run)
 *
 *  This function uses commands from the user to add and remove words from
 *  multiple stacks. The purpose of this function is to type a sentence while
 *  being able to undo and redo the typing of words
 */
int main(int argc, char **argv) {
    // these are the two stacks used to store the typed words and the undone
    // words
    stack<string> typing, undo, reverse;
    int n, tSize, uSize, cCount = 0;
    const int MIN_LINES = 0, MAX_LINES = 1001;
    char command;
    string word;
    
    //get the number of lines
    cin >> n;

    //make the amound of lines is between 0 and 1000
    assert(n > MIN_LINES);
    assert(n < MAX_LINES);
    
    for(int i = 0; i < n; i++){
        //get the command
        cin >> command;
        cCount++;
        
        //this decides what to do based on the command entered
        if(command == 't'){
            //put a new word at top of the typing stack
            cin >> word;
            typing.push(word);
        }
        else if(command == 'u'){
            //remove the top word from the typing stack and place it on
            //the undo stack if there is a word to remove
            if(typing.size() > 0){
                undo.push(typing.top());
                typing.pop();
            }
            else {
                cout << "nothing to undo on command " << cCount << endl;
            }
        }
        else if(command == 'r'){
            //remove the top word from the undo stack and place it on
            //the typing stack if there is a word to remove
            if(undo.size() > 0){
                typing.push(undo.top());
                undo.pop();
            }
            else {
                cout << "nothing to redo on command " << cCount << endl;
            }
        }
    }
   
    //set unchanging sizes
    tSize = typing.size();
    uSize = undo.size();
    
    //make sure that there are words on the typing stack
    if(tSize > 0){
        //reverse the order of typing stack
        for(int i = 0; i < tSize; i++){
            reverse.push(typing.top());
            typing.pop();
        }
        
        //print the typing stack in the correct order on first line
        for(int i = 0; i < tSize-1; i++){
            //get top word and move to next one
            cout << reverse.top() << " ";
            reverse.pop();
        }
        //leave no extra space at the end of the line
        cout << reverse.top();
        reverse.pop();
    }
    cout << endl;
    
    //make sure there are words on the undo stack
    if(uSize > 0){
        //reverse the order of the undo stack
        for(int i = 0; i < uSize; i++){
            reverse.push(undo.top());
            undo.pop();
        }
        
        //print the undo stack on the second line
        for(int i = 0; i < uSize-1; i++){
            cout << reverse.top() << " ";
            reverse.pop();
        }
        //leave no extra space at the end of the line
        cout << reverse.top();
        reverse.pop();
    }
    cout << endl;
    
    return 0;
}
