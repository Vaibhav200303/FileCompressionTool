#include "GUI.h"
#include "HuffmanCoding.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>

GUI::GUI(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QPushButton* compressButton = new QPushButton("Compress File", this);
    QPushButton* decompressButton = new QPushButton("Decompress File", this);

    mainLayout->addWidget(compressButton);
    mainLayout->addWidget(decompressButton);

    connect(compressButton, &QPushButton::clicked, this, &GUI::onCompressClicked);
    connect(decompressButton, &QPushButton::clicked, this, &GUI::onDecompressClicked);
}

GUI::~GUI() {}

void GUI::onCompressClicked() {
    QString inputFilePath = QFileDialog::getOpenFileName(this, "Select Input File");
    QString outputFilePath = QFileDialog::getSaveFileName(this, "Save Compressed File", "", "*.huff");

    if (inputFilePath.isEmpty() || outputFilePath.isEmpty()) {
        return;
    }

    HuffmanCoding huffmanCoder;
    huffmanCoder.compressFile(inputFilePath.toStdString(), outputFilePath.toStdString());
    QMessageBox::information(this, "Success", "File compressed successfully!");
}

void GUI::onDecompressClicked() {
    QString inputFilePath = QFileDialog::getOpenFileName(this, "Select Compressed File", "", "*.huff");
    QString outputFilePath = QFileDialog::getSaveFileName(this, "Save Decompressed File");

    if (inputFilePath.isEmpty() || outputFilePath.isEmpty()) {
        return;
    }

    HuffmanCoding huffmanCoder;
    huffmanCoder.decompressFile(inputFilePath.toStdString(), outputFilePath.toStdString());
    QMessageBox::information(this, "Success", "File decompressed successfully!");
}
