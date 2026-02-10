#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include "DocumentModel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSaveClicked();
    void onLineEdited(int lineIndex);

private:
    void setupUI();
    void connectSignals();
    
    DocumentModel *m_documentModel;
    QList<QLineEdit*> m_lineEdits;
    QPushButton *m_saveButton;
};

#endif // MAINWINDOW_H
