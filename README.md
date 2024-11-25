# <div align="center">File Compression Using Huffman's Algorithm</div>

## About
Huffman coding is a **lossless compression algorithm** that assigns variable-length codes to input characters, with shorter codes assigned to more frequent characters. This project implements Huffman's Algorithm for file compression and decompression with two different interfaces:
- **Command-Line Interface (CLI)** for direct terminal usage
- **Graphical User Interface (GUI)** built using Qt

The program calculates the frequency of characters from the input file, builds a binary tree based on these frequencies, generates corresponding Huffman codes, and compresses or decompresses the file.

## Features
- **Command-Line Interface (CLI)**: A simple terminal-based interface for file compression and decompression.
- **Graphical User Interface (GUI)**: An easy-to-use GUI to select files for compression and decompression with a couple of clicks.
- **Support for file padding** to ensure the file size is a whole number of bytes after compression.

## Usage

### CLI Usage
To use the **CLI**, follow these steps:

1. **Compression**:
Huffman Compression Tool
1. Compress File
2. Decompress File
3. Exit
Enter your choice: 1
Enter input file name: example.txt
Enter output file name (or press Enter for default): compressed.huff
Compression completed.

Huffman Compression Tool
1. Compress File
2. Decompress File
3. Exit
Enter your choice: 3
Exiting...

### GUI Usage
For a **Graphical User Interface (GUI)**, simply run the program:
You can then:
- Select a file to compress.
- Select a compressed file to decompress.

**Steps for GUI Compression**:
1. Click on "Compress File" to choose an input file.
2. Choose where to save the compressed file.
3. The program will display a success message after compression.

**Steps for GUI Decompression**:
1. Click on "Decompress File" to choose the compressed file.
2. Choose where to save the decompressed file.
3. The program will display a success message after decompression.

## File Structure

<table border="1">
    <tr>
        <td colspan="2"> N = total number of unique characters (1 byte) </td>
    </tr>
    <tr>
        <td> Character [1 byte] </td>
        <td> Binary codeword String Form [MAX bytes] </td>
    </tr>
    <tr>
        <td> Character [1 byte] </td>
        <td> Binary codeword String Form [MAX bytes] </td>
    </tr>
    <tr>
        <td colspan="2"> N times </td>
    </tr>
    <tr>
        <td> p (1 byte) </td>
        <td> p times 0's (p bits) </td>
    </tr>
    <tr>
        <td colspan="2"> DATA </td>
    </tr>
</table>

* `p` = Padding to ensure the file fits into a whole number of bytes.  
  For example, if a file is 4 bytes + 3 bits, it must be padded by 5 bits to make it 5 bytes.

## Example

### Input: `aabcbaab`

| Content                           | Comment                                  |
|-----------------------------------|------------------------------------------|
| 3                                 | N=3 (a, b, c)                            |
| a "1"                             | Character 'a' and corresponding code "1" |
| b "01"                            | Character 'b' and corresponding code "01"|
| c "00"                            | Character 'c' and corresponding code "00"|
| 4                                 | Padding count                            |
| [0000]                            | Padding 4 zeroes                         |
| [1] [1] [01] [00] [01] [1] [1] [01]| Actual data, code in place of char      |

## Algorithm

### (Pass 1) - Building the Huffman Tree
1. **Read input file** to get character frequencies.
2. Create a sorted linked list of characters based on their frequency:
3.for each character ch from the file if (ch exists in the linked list at node p) then { p.freq++; sort the linked list by frequency; }
else add a new node at the beginning with frequency=1;
4. **Construct the Huffman tree**:
- Combine the two nodes with the lowest frequencies into a new node.
- Insert this new node back into the list.
- Repeat until only one node remains, which will be the root of the Huffman tree.
4. Traverse the tree in preorder and assign codewords to each node.
5. Create a mapping table from characters to their Huffman codes.
6. Write the mapping table to the output file.

### (Pass 2) - Compressing the File
1. **Read the input file again**.
2. Replace each character with its corresponding codeword (from the mapping table) and write it to the output file.
3. **Handle padding** by adding extra bits (if necessary) to make the file size a multiple of 8 bits.

Contributing
============

Please feel free to submit issues and pull requests. I appreciate bug reports.
Testing on different platforms is especially appreciated. I only tested on Linux.

License
=======
[MIT](https://opensource.org/licenses/MIT)

Development
Planned Features
Support for Binary Files: Add support for compressing and decompressing binary files like images and audio.
Unicode Support: Enhance the program to handle files with special characters or multilingual text.
Python Version: Implement a Python version using neural networks for smarter compression.
Performance Optimization: Improve the algorithm for large files with multithreading or parallel processing.

