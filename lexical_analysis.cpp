#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>
using namespace std;

// Predefined keywords in our language
unordered_set<string> keywords = {"if", "else", "while", "for", "return", "int", "float", "double", "char"};
unordered_set<string> parenthesis = {"(", ")", "{", "}", "[", "]"};
unordered_set<string> punctuation = {",", ";", ":"};
unordered_set<string> arithmetic_operators = {"+", "-", "*", "/", "%"};
unordered_set<string> relational_operators = {"==", "!=", ">", "<", ">=", "<="};

// Function to check if a token is an identifier
bool isIdentifier(const string &token)
{
    if (isalpha(token[0]) || token[0] == '_')
    {
        for (char c : token)
        {
            if (!isalnum(c) && c != '_')
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

// Function to check if a token is a constant
bool isConstant(const string &token)
{
    for (char c : token)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

// Function to tokenize keywords from a source code input
vector<vector<string>> tokenize_keywords(const string &code)
{
    vector<string> tokens;
    vector<string> keyword_tokens;
    vector<string> parenthesis_tokens;
    vector<string> punctuation_tokens;
    vector<string> arithmetic_operators_tokens;
    vector<string> relational_operators_tokens;
    vector<string> identifier_tokens;
    vector<string> constant_tokens;
    stringstream ss(code); // To split code by spaces
    string token;

    // Tokenize based on whitespace
    while (ss >> token)
    {
        tokens.push_back(token);
    }

    // Check each token to see if it's a keyword
    for (const string &token : tokens)
    {
        if (keywords.find(token) != keywords.end())
        {
            keyword_tokens.push_back(token);
        }
        else if (parenthesis.find(token) != parenthesis.end())
        {
            parenthesis_tokens.push_back(token);
        }
        else if (punctuation.find(token) != punctuation.end())
        {
            punctuation_tokens.push_back(token);
        }
        else if (arithmetic_operators.find(token) != arithmetic_operators.end())
        {
            arithmetic_operators_tokens.push_back(token);
        }
        else if (relational_operators.find(token) != relational_operators.end())
        {
            relational_operators_tokens.push_back(token);
        }
        else if (isIdentifier(token))
        {
            identifier_tokens.push_back(token);
        }
        else if (isConstant(token))
        {
            constant_tokens.push_back(token);
        }
    }
    vector<vector<string>> all_tokens = {keyword_tokens, parenthesis_tokens, punctuation_tokens, arithmetic_operators_tokens, relational_operators_tokens, identifier_tokens, constant_tokens};
    return all_tokens;
}

int main()
{
    // Example input code
    string source_code = "int x = 10 ; if ( x > 0 ) { return x ; } else { x = 0 ; }";

    // Tokenize keywords in the source code
    vector<vector<string>> result = tokenize_keywords(source_code);

    // Print the keywords found
    cout << "Keywords found: ";
    for (const vector<string> &tokenize_keywords : result)
    {
        // Print the type name of tokens
        if (&tokenize_keywords == &result[0])
            cout << "Keywords (" << tokenize_keywords.size() << "): ";
        else if (&tokenize_keywords == &result[1])
            cout << "Parenthesis: (" << tokenize_keywords.size() << "): ";
        else if (&tokenize_keywords == &result[2])
            cout << "Punctuation: (" << tokenize_keywords.size() << "): ";
        else if (&tokenize_keywords == &result[3])
            cout << "Arithmetic Operators: (" << tokenize_keywords.size() << "): ";
        else if (&tokenize_keywords == &result[4])
            cout << "Relational Operators: (" << tokenize_keywords.size() << "): ";
        else if (&tokenize_keywords == &result[5])
            cout << "Identifiers: (" << tokenize_keywords.size() << "): ";
        else if (&tokenize_keywords == &result[6])
            cout << "Constants: (" << tokenize_keywords.size() << "): ";

        for (const string &token : tokenize_keywords)
        {
            // Print the tokens
            cout << token << " ";
        }

        // Print a newline after each set of tokens
        cout << endl;
    }
    cout << "" << endl;

    return 0;
}