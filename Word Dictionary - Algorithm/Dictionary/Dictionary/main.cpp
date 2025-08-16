#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

// Node structure for BST
struct Node {
    string word;
    string meaning;
    string partOfSpeech;  // New: Part of speech
    Node* left;
    Node* right;

    Node(string w, string m, string pos) {
        word = w;
        meaning = m;
        partOfSpeech = pos;
        left = nullptr;
        right = nullptr;
    }
};



// Function to insert a new word with meaning and part of speech into the BST
Node* insert(Node* root, string word, string meaning, string pos) {
    if (!root) {
        return new Node(word, meaning, pos);
    }

    if (word < root->word) {
        root->left = insert(root->left, word, meaning, pos);
    } else if (word > root->word) {
        root->right = insert(root->right, word, meaning, pos);
    }

    return root;
}

// Function to search for a word in the BST
Node* search(Node* root, string word) {
    if (!root || root->word == word) {
        return root;
    }

    if (word < root->word) {
        return search(root->left, word);
    } else {
        return search(root->right, word);
    }
}

// Function to find suggestions for similar words based on letter similarity
void findSuggestions(Node* node, string word, vector<string>& suggestions) {
    if (!node) return;
    findSuggestions(node->left, word, suggestions);

    int matchCount = 0;
    for (int i = 0; i < min(word.size(), node->word.size()); i++) {
        if (word[i] == node->word[i]) {
            matchCount++;
        }
    }
    if (matchCount >= 2) {  // Suggest words with at least 2 matching letters
        suggestions.push_back(node->word);
    }

    findSuggestions(node->right, word, suggestions);
}

// Function to delete a word from the BST
Node* deleteWord(Node* root, string word) {
    if (!root) return nullptr;

    if (word < root->word) {
        root->left = deleteWord(root->left, word);
    } else if (word > root->word) {
        root->right = deleteWord(root->right, word);
    } else {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        } else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* successor = root->right;
            while (successor->left) {
                successor = successor->left;
            }
            root->word = successor->word;
            root->meaning = successor->meaning;
            root->partOfSpeech = successor->partOfSpeech;
            root->right = deleteWord(root->right, successor->word);
        }
    }
    return root;
}

// Function to display all words in the dictionary (in-order traversal)
void displayAllWords(Node* root) {
    if (!root) return;
    displayAllWords(root->left);
    cout << root->word << " (" << root->partOfSpeech << "): " << root->meaning << endl;
    displayAllWords(root->right);
}

// Function to load words and meanings from a text file
Node* loadFromFile(string filename, Node* root) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);

            if (pos1 != string::npos && pos2 != string::npos) {
                string word = line.substr(0, pos1);
                string meaning = line.substr(pos1 + 1, pos2 - pos1 - 1);
                string pos = line.substr(pos2 + 1);
                root = insert(root, word, meaning, pos);
            }
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
    return root;
}

int main() {
    Node* root = nullptr;

    // Load words and meanings from a text file
    root = loadFromFile("dictionary.txt", root);

    int choice;
    string word;

    while (true) {
        cout << "\nDictionary Menu:" << endl;
        cout << "1. Add a new word" << endl;
        cout << "2. Search for a word" << endl;
        cout << "3. Delete a word" << endl;
        cout << "4. Display all words" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    string newWord, newMeaning, pos;
                    cout << "Enter a new word to add: ";
                    cin >> newWord;
                    cout << "Enter the meaning: ";
                    cin.ignore();
                    getline(cin, newMeaning);
                    cout << "Enter the part of speech (e.g., noun, verb): ";
                    cin >> pos;
                    root = insert(root, newWord, newMeaning, pos);
                }
                break;

            case 2:
                cout << "Enter a word to search (or 'q' to go back): ";
                cin >> word;
                if (word == "q") {
                    break;
                } {
                    Node* result = search(root, word);
                    if (result) {
                        cout << word << " (" << result->partOfSpeech << "): " << result->meaning << endl;
                    } else {
                        cout << "The word \"" << word << "\" was not found." << endl;
                        vector<string> suggestions;
                        findSuggestions(root, word, suggestions);
                        if (!suggestions.empty()) {
                            cout << "Did you mean: ";
                            for (const string& suggestion : suggestions) {
                                cout << suggestion << " ";
                            }
                            cout << "?" << endl;
                        }
                    }
                }
                break;

            case 3:
                cout << "Enter a word to delete: ";
                cin >> word;
                if (search(root, word)) {
                    root = deleteWord(root, word);
                    cout << word << " deleted successfully." << endl;
                } else {
                    cout << "Word not found in the dictionary." << endl;
                }
                break;

            case 4:
                displayAllWords(root);
                break;

            case 5:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
