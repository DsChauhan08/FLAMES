#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

namespace Flames {

    string calculate(const string& name1, const string& name2) {
        // Convert names to lowercase and remove spaces
        string processedName1 = name1;
        string processedName2 = name2;

        transform(processedName1.begin(), processedName1.end(), processedName1.begin(), ::tolower);
        transform(processedName2.begin(), processedName2.end(), processedName2.begin(), ::tolower);

        processedName1.erase(remove_if(processedName1.begin(), processedName1.end(), ::isspace), processedName1.end());
        processedName2.erase(remove_if(processedName2.begin(), processedName2.end(), ::isspace), processedName2.end());

        // Create a map to count the occurrences of each letter in both names
        unordered_map<char, int> letterCount;
        for (char letter : processedName1 + processedName2) {
            letterCount[letter]++;
        }

        // Count the number of common letters
        int commonLetters = 0;
        for (const auto& entry : letterCount) {
            if (entry.second % 2 == 1) {
                commonLetters++;
            }
        }

        // Define the FLAMES relationship options
        vector<string> relationships = {"Friendship", "Love", "Affection", "Marriage", "Enmity", "Sister"};

        // Calculate the index to determine the relationship
        int index = commonLetters % relationships.size();

        // Output the result
        return relationships[index - 1];
    }
}

int main() {
    // Get user input for names
    string name1, name2;
    cout << "Enter the first name: ";
    getline(cin, name1);

    cout << "Enter the second name: ";
    getline(cin, name2);

    // Calculate and display the result using the Flames namespace
    string result = Flames::calculate(name1, name2);
    cout << "The relationship between " << name1 << " and " << name2 << " is: " << result << endl;

    // Wait for user input before exiting
    cout << "Press Enter to exit...";
    cin.get();

    return 0;
}
