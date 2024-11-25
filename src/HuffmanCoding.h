#ifndef HUFFMANCODING_H
#define HUFFMANCODING_H

#include <unordered_map>
#include <queue>
#include <bitset>
#include <string>

struct HuffmanNode {
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return l->freq > r->freq;
    }
};

class HuffmanCoding {
public:
    HuffmanCoding();
    ~HuffmanCoding();
    void compressFile(const std::string& inputFile, const std::string& outputFile);
    void decompressFile(const std::string& inputFile, const std::string& outputFile);

private:
    HuffmanNode* root;
    std::unordered_map<char, std::string> huffmanCodes;

    void deleteTree(HuffmanNode* node);
    void buildHuffmanTree(const std::string& data);
    void generateCodes(HuffmanNode* node, const std::string& str);
};

#endif // HUFFMANCODING_H