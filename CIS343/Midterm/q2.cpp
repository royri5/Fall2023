#include <vector>
#include <iterator>
#include <iostream>

//function that takes a reference to a vector<int> and returns the sum total of all the odd numbers in the vector.
//Note I don't mean the odd indices, but the odd values. Loop with an iterator. You may use the auto keyword.
int oddTotal(std::vector<int>& vector) {
        //sum
        int sum = 0;
        //iterator
        std::vector<int>::iterator iterator;
        iterator = vector.begin();
        //loop through vector
        while (iterator != vector.end()) {
            //element is odd
            if (*iterator % 2 != 0) {
                //add to sum
                sum += *iterator;
            }
            //increment iterator
            iterator++;
        }
        
        return sum;
}

int main() {
    //vector
    std::vector<int> vector;
    //add elements
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);
    vector.push_back(4);
    vector.push_back(5);
    //call function
    int sum = oddTotal(vector);
    //print sum
    std::cout << sum << std::endl;

    

}