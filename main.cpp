/*********************
* Name: Ian Olsen
* Assignment: Challenge 2
* Date: 11/28/2022
* FIFO STACK
*********************/

#include "main.h"

int main() {

    //get srand time null
    srand(time(NULL));

    //create a new fifo stack
    Fifo fifo;

    //Create variables for random integers and strings
    int randomInt1;
    int randomInt2;
    int id;
    std::string randomString;
    Data getData;

    int fivePull = 5;
    int multiplier = 2;
    //Test stack isEmpty; Expect empty
    if (fifo.isEmpty()) {
        std::cout << "Stack is empty!\n" << std::endl;
    }
    else {
        std::cout << "Stack is not empty!\n" << std::endl;
    }
    //create a for loop to push 10 random integers and strings to the stack
    for (int i = 0; i < TESTSIZE; i++) {
        //Get random integer and string variables
        randomInt1 = rand();
        randomInt2 = rand();
        id = randomInt1 - randomInt2;

        //Testing string with stack int
        randomString = "Test String " + std::to_string(id);

        //Insert data
        if(id > 0) {
            if (fifo.push(id, randomString)) {
                std::cout << id << ": " << randomString << " has been inserted!" << std::endl;
            }

            //Overflow is stack is full
            else {
                std::cout << "Stack overflow error, element " << id << ": " << randomString << " was not inserted" << std::endl;
            }
        }
        //If id is negative, do not enter into the stack.
        else if(id < 0) {
            std::cout << "Element " << id << ": " << randomString << " was not inserted" << std::endl;
        }
    }
    //Test dumpStack
    fifo.dumpStack();
    //Test stack isEmpty; Expect not empty
    if (fifo.isEmpty()) {
        std::cout << "Stack is empty!\n" << std::endl;
    }
    else {
        std::cout << "Stack is not empty!\n" << std::endl;
    }
    //Test pull from Stack
    std::cout << "Pulling 1st element from the stack" << std::endl;
    fifo.pull(getData);
    //checking that first element previously added was removed
    fifo.dumpStack();
    //Pull second element from stack
    std::cout << "Pulling 2nd element from the stack" << std::endl;
    fifo.pull(getData);
    //Test dumpStack
    fifo.dumpStack();
    //peek at the current bottom element
    std::cout << "Testing peek" << std::endl;
        if(fifo.peek(getData)) {
            std::cout << "Element with ID: " << getData.id << " and string " << getData.information << " is next to be pulled off stack." << std::endl;
        }
        else {
            std::cout << "Stack underflow error" << std::endl;
        }
    //pull 5 elements from the stack
    std::cout << "Pulling 5 elements from the stack" << std::endl;
    for (int i = 0; i < fivePull; i++) {
        fifo.pull(getData);
    }
    //Test dumpStack
    fifo.dumpStack();
    //pull all data from stack
    std::cout << "Pulling all data from stack" << std::endl;
    while(!fifo.isEmpty()) {
        fifo.pull(getData);
    }
    //Test dumpStack
    fifo.dumpStack();

    /****************************
    ******RANDOM TESTS**********
    *****PUSH AND POP*********
    *****PEEK AND ISEMPTY ******
    ****************************/

    //Test Random Operations
    std::cout << "Testing random operations...\n" << std::endl;

    for (int i = 1; i <= pow(TESTSIZE, multiplier); i++) {
        srand(i * time(NULL));

        //test cases when integer is between 1 and 6, test pop and pull twice as often
        switch (rand() % 6 + 1) {

            //Test push
            case 1:
            case 2:
                std::cout << "Testing push!\n" << std::endl;
                //Get random integer and string variables
                for (int i = 0; i < STACKSIZE; i++) {
                    randomInt1 = rand();
                    randomInt2 = rand();
                    id = randomInt1 - randomInt2;

                    //Testing string with stack int
                    randomString = "Test String " + std::to_string(id);

                    //Insert data
                    if (id > 0) {
                        if (fifo.push(id, randomString)) {
                            std::cout << id << ": " << randomString << " has been inserted!" << std::endl;
                        }

                            //Overflow is stack is full
                        else {
                            std::cout << "Stack overflow error, element " << id << ": " << randomString
                                      << " was not inserted" << std::endl;
                        }
                    }
                }//END CASE 1 & 2
            case 3:
            case 4:
                //Test peek
                std::cout << "Testing peek!\n" << std::endl;
                for (int i = 0; i < peekSize; i++) {
                    if (fifo.peek(getData)) {
                        std::cout << "Element with ID: " << getData.id << " and string " << getData.information << " on top of stack." << std::endl;
                    }
                    else {
                        std::cout << "Stack underflow error" << std::endl;
                    }
                } //End CASE 3 & 4
            case 5:
                std::cout << "Testing pull!\n" << std::endl;
                for (int i = 0; i < STACKSIZE; i++) {
                    if (fifo.pull(getData)) {
                        std::cout << "Element id: " << getData.id << " and string " << getData.information << " removed." << std::endl;
                    }
                    else {
                        std::cout << "Stack underflow error" << std::endl;
                    }
                } //End Case 5
            // Test isEmpty
            case 6:
                //Test isEmpty
                std::cout << "Testing isEmpty!\n" << std::endl;
                if (fifo.isEmpty()) {
                    std::cout << "Stack is empty!\n" << std::endl;
                }
                else {
                    std::cout << "Stack is not empty!\n" << std::endl;
                }//End Case 6
        }//END SWITCH
    }//END FOR LOOP


}//END MAIN