# Simple Version Control System (VCS) in C++

This is a simple version control system (VCS) implemented in C++. It supports basic operations such as initializing a repository, adding files to tracking, committing changes, and viewing commit history.

## Features

- **Initialize a repository**: Creates a new VCS repository.
- **Add files**: Adds files to the list of tracked files.
- **Commit changes**: Commits the current state of tracked files with a commit message.
- **View commit history**: Displays the history of commits.

## Requirements

- C++17 or higher
- A C++ compiler (e.g., g++)

## Usage

### 1. Compile the Code

Make sure you have a C++ compiler installed. Open your terminal and navigate to the directory containing `main.cpp`. Run the following command to compile the code with C++17 standard:

```sh
g++ -std=c++17 main.cpp -o myvcs
2. Initialize the Repository
To initialize a new repository, run:

sh
Copy code
./myvcs init
This command will create a .myvcs directory to store VCS data.

3. Add Files to Tracking
To add a file to the list of tracked files, run:

sh
Copy code
./myvcs add <filename>
For example:

sh
Copy code
echo "Hello World" > example.txt
./myvcs add example.txt
4. Commit Changes
To commit the current state of all tracked files with a commit message, run:

sh
Copy code
./myvcs commit <message>
For example:

sh
Copy code
./myvcs commit "Initial commit"
5. View Commit History
To view the commit history, run:

sh
Copy code
./myvcs log
This command will display a list of all commits with their timestamps and messages.