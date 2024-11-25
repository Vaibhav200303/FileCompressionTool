#ifndef GUI_H
#define GUI_H

#include <QWidget>

class GUI : public QWidget {
    Q_OBJECT

public:
    GUI(QWidget* parent = nullptr);
    ~GUI();

private slots:
    void onCompressClicked();
    void onDecompressClicked();
};

#endif // GUI_H
