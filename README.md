# ESWE---Data-Processing-and-Storage
## Setup and Running the Code
1. Clone or download the repository locally.
2. Compile the code using your C++ compiler. Example command:
  g++ -o transaction transaction.cpp
3. Run the program:
  ./transaction
   
### Note: The main function is set up exactly like Fig.2 in the assignment documentation. To see the error handling functionality, uncomment the error you want to test, re-compile the executable, then run the executable.

## Future Modifications
To make this assignment an official part of the curriculum, consider clarifying edge cases, such as what happens if rollback() or commit() is called without any changes being made. Additionally, expanding the instructions to include multi-threaded scenarios would reflect real-world use cases and increase the challenge. Including automated test cases that validate functionality would standardize grading. Lastly, providing a basic example or skeleton implementation as a starting point could help students focus on the transactional logic without being overwhelmed by setup issues.

