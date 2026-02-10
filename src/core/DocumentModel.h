#ifndef DOCUMENTMODEL_H
#define DOCUMENTMODEL_H

#include <QObject>
#include <QString>
#include <QList>

class DocumentModel : public QObject
{
    Q_OBJECT

public:
    explicit DocumentModel(QObject *parent = nullptr);
    
    // Get line content
    QString getLine(int index) const;
    
    // Set line content
    void setLine(int index, const QString &text);
    
    // Get total number of lines
    int lineCount() const;
    
    // Save all lines to a text file
    bool saveToFile(const QString &filePath) const;

signals:
    void lineChanged(int index, const QString &text);

private:
    QList<QString> m_lines;
};

#endif // DOCUMENTMODEL_H
