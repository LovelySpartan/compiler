#include <iostream>
#include <string>
//#include "utils.h"
#include <fstream>
#include <map>
#include <vector>
using namespace std;


map<string, string> tokens {   {"while", "keywords"}, //{"int","keywords"},
                               { "=" ,"operator"}, {"<" , "operator"},//{"-" ,"operator"}, {"*","operator"} ,
                               { "," ,"separator"} , {"(", "separator"} ,{")","separator"} , {";", "separator"} ,
                               { "s" , "idenifier"} , {"upper","idenifier"} , {"t" , "idenifier"} ,
                               {"33.00" , "real"}
};
  string space = " ";
  string sum;
  char ch;
  string lexeme ="";
  string lexer(string lexeme){
    if (tokens.count(lexeme)>0){
      return tokens[lexeme];
    }
    else{
    return "lexeme not found";
        }
  }
int main()
{

    ifstream inFile("input_scode.txt");

    if (inFile.fail()) {
        cerr << "Unable to open file for reading." << endl;
        exit(1);
    }
    fstream fin("input_scode.txt", fstream::in);
    while (fin >> ch) {
      if(ch != ' '){
    lexeme += ch;
    if(lexer(lexeme) == "lexeme not found"){
      cout << " ";
    }
    else{

        /*ofstream output;
        output.open("output.txt" , ios::out);
        sum += lexeme += space += lexer(lexeme);
        lexeme = "";
        output << sum <<endl;*/
      //cout << "tokens"<< "        "<<"lexeme"<<endl;
      cout << lexeme <<"   "<<lexer(lexeme)<<endl;
      lexeme = "";


    }
    //output.close();    
  }
    }

    inFile.close();

    return 0;

}
