#include "HuffmanCoding.h"
#include "GUI.h"
#include <iostream>
#include <QApplication>

using namespace std;

void showMenu() {
    cout << "Huffman Compression Tool\n";
    cout << "1. Compress File\n";
    cout << "2. Decompress File\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

int runCLI() {
    HuffmanCoding huffmanTool;
    int choice;
    string inputFileName, outputFileName;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter input file name: ";
                cin >> inputFileName;
                cout << "Enter output file name (or press Enter for default): ";
                cin.ignore();
                getline(cin, outputFileName);
                if (outputFileName.empty()) outputFileName = "compressed.huff";
                huffmanTool.compressFile(inputFileName, outputFileName);
                break;
            case 2:
                cout << "Enter compressed file name: ";
                cin >> inputFileName;
                cout << "Enter output file name (or press Enter for default): ";
                cin.ignore();
                getline(cin, outputFileName);
                if (outputFileName.empty()) outputFileName = "decompressed.txt";
                huffmanTool.decompressFile(inputFileName, outputFileName);
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main(int argc, char* argv[]) {
    cout << "Select mode: \n";
    cout << "1. Command-Line Interface (CLI)\n";
    cout << "2. Graphical User Interface (GUI)\n";
    cout << "Enter your choice: ";
    int mode;
    cin >> mode;

    if (mode == 1) {
        return runCLI();
    } else if (mode == 2) {
        QApplication app(argc, argv);
        GUI gui;
        gui.setWindowTitle("Huffman Compression Tool");
        gui.resize(400, 200);
        gui.show();
        return app.exec();
    } else {
        cout << "Invalid choice. Exiting...\n";
        return 0;
    }
}
