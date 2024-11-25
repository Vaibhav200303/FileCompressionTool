#include "HuffmanCoding.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <queue>
#include <bitset>

using namespace std;

HuffmanCoding::HuffmanCoding() : root(nullptr) {}

HuffmanCoding::~HuffmanCoding() {
    deleteTree(root);
}

void HuffmanCoding::deleteTree(HuffmanNode* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void HuffmanCoding::buildHuffmanTree(const string& data) {
    unordered_map<char, int> freqMap;
    for (char c : data) freqMap[c]++;

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    for (auto& pair : freqMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        HuffmanNode* merged = new HuffmanNode('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }
    root = pq.top();
    generateCodes(root, "");
}

void HuffmanCoding::generateCodes(HuffmanNode* node, const string& str) {
    if (!node) return;
    if (!node->left && !node->right) {
        huffmanCodes[node->data] = str;
    }
    generateCodes(node->left, str + "0");
    generateCodes(node->right, str + "1");
}

void HuffmanCoding::compressFile(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile, ios::binary);
    if (!in.is_open()) {
        cerr << "Error: Unable to open input file.\n";
        return;
    }
    ostringstream oss;
    oss << in.rdbuf();
    string data = oss.str();
    in.close();

    buildHuffmanTree(data);

    ofstream out(outputFile, ios::binary);
    if (!out.is_open()) {
        cerr << "Error: Unable to create output file.\n";
        return;
    }

    // Now, we will write the data in bits.
    string bitStream;
    for (char c : data) {
        bitStream += huffmanCodes[c];
    }

    // Write the bitStream into the output file byte by byte.
    size_t fullBytes = bitStream.size() / 8;
    size_t remainingBits = bitStream.size() % 8;

    for (size_t i = 0; i < fullBytes; ++i) {
        bitset<8> byte(bitStream.substr(i * 8, 8));
        out.put(static_cast<unsigned char>(byte.to_ulong()));
    }

    // Handle remaining bits that don't form a full byte
    if (remainingBits > 0) {
        bitset<8> byte(bitStream.substr(fullBytes * 8));
        out.put(static_cast<unsigned char>(byte.to_ulong()));
    }

    out.close();
    cout << "Compression completed.\n";
}

void HuffmanCoding::decompressFile(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile, ios::binary);
    if (!in.is_open()) {
        cerr << "Error: Unable to open input file.\n";
        return;
    }

    // Read the file byte by byte and reconstruct the bitstream
    ostringstream oss;
    char byte;
    while (in.get(byte)) {
        bitset<8> bits(static_cast<unsigned char>(byte));
        oss << bits.to_string();
    }
    string compressedData = oss.str();
    in.close();

    ofstream out(outputFile, ios::binary);
    if (!out.is_open()) {
        cerr << "Error: Unable to create output file.\n";
        return;
    }

    HuffmanNode* current = root;
    for (char bit : compressedData) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        // When we reach a leaf node, write the data
        if (!current->left && !current->right) {
            out.put(current->data);
            current = root;
        }
    }

    out.close();
    cout << "Decompression completed.\n";
}
