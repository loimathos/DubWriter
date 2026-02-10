#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QLabel>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_documentModel(new DocumentModel(this))
{
    setupUI();
    connectSignals();
    
    setWindowTitle("DubWriter");
    resize(800, 300);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUI()
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    
    // Add application title at the top
    QLabel *titleLabel = new QLabel("DubWriter", centralWidget);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);
    
    // Add spacing after title
    mainLayout->addSpacing(15);
    
    // Create 4 line edits
    for (int i = 0; i < 4; ++i) {
        QHBoxLayout *lineLayout = new QHBoxLayout();
        
        // Add line label
        QLabel *label = new QLabel(QString("Line %1:").arg(i + 1), centralWidget);
        label->setMinimumWidth(60);
        lineLayout->addWidget(label);
        
        // Create line edit with horizontal scrolling
        QLineEdit *lineEdit = new QLineEdit(centralWidget);
        lineEdit->setText(m_documentModel->getLine(i));
        lineEdit->setProperty("lineIndex", i);
        
        // Disable word wrap and enable horizontal scrolling
        lineEdit->setCursorPosition(0);
        
        lineLayout->addWidget(lineEdit);
        mainLayout->addLayout(lineLayout);
        
        m_lineEdits.append(lineEdit);
    }
    
    // Add some spacing
    mainLayout->addSpacing(20);
    
    // Create save button
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    
    m_saveButton = new QPushButton("Save", centralWidget);
    m_saveButton->setMinimumWidth(100);
    buttonLayout->addWidget(m_saveButton);
    
    buttonLayout->addStretch();
    mainLayout->addLayout(buttonLayout);
    
    // Add stretch to push everything to the top
    mainLayout->addStretch();
    
    setCentralWidget(centralWidget);
}

void MainWindow::connectSignals()
{
    // Connect line edits to model
    for (int i = 0; i < m_lineEdits.size(); ++i) {
        QLineEdit *lineEdit = m_lineEdits[i];
        connect(lineEdit, &QLineEdit::textChanged, this, [this, i]() {
            onLineEdited(i);
        });
    }
    
    // Connect save button
    connect(m_saveButton, &QPushButton::clicked, this, &MainWindow::onSaveClicked);
}

void MainWindow::onLineEdited(int lineIndex)
{
    if (lineIndex >= 0 && lineIndex < m_lineEdits.size()) {
        QString text = m_lineEdits[lineIndex]->text();
        m_documentModel->setLine(lineIndex, text);
    }
}

void MainWindow::onSaveClicked()
{
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Save Document",
        QString(),
        "Text Files (*.txt);;All Files (*)"
    );
    
    if (filePath.isEmpty()) {
        return;
    }
    
    // Add .txt extension if not present
    if (!filePath.endsWith(".txt", Qt::CaseInsensitive)) {
        filePath += ".txt";
    }
    
    if (m_documentModel->saveToFile(filePath)) {
        QMessageBox::information(this, "Success", "File saved successfully!");
    } else {
        QMessageBox::critical(this, "Error", "Failed to save file!");
    }
}
