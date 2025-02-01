# Custom `rm` Implementation in C

This project is a custom implementation of the `rm` command in C, designed to provide basic file deletion functionality with additional features and improvements.

## Features

- **File Deletion:** Delete files specified by the user.
- **File Information:** Use `FileData` structure to check file type before deletion.

## Getting Started

### Prerequisites

- GCC (GNU Compiler Collection) or any C compiler.
- Basic knowledge of terminal commands.

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/your-repo-name.git
   cd your-repo-name
   ```

2. Compile the program:
   ```bash
   make
   ```

3. Run the program:
   ```bash
   ./remof file1.txt file2.txt
   ```

### Usage

To delete files, provide the filenames as arguments:
```bash
./remof file1.txt file2.txt
```

### Example

```bash
$ ./custom_rm test.txt
File deleted successfully. (test.txt)

$ ./custom_rm non_existent.txt
Error: Unable to delete the file.
```


## Contributing

Contributions are welcome! If you'd like to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature/YourFeature`).
3. Commit your changes (`git commit -m 'Add some feature'`).
4. Push to the branch (`git push origin feature/YourFeature`).
5. Open a pull request.
