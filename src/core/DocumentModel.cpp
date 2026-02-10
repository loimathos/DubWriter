#include "DocumentModel.h"
#include <QFile>
#include <QTextStream>

DocumentModel::DocumentModel(QObject *parent)
    : QObject(parent)
{
    // Initialize with 4 empty lines
    m_lines.reserve(4);
    for (int i = 0; i < 4; ++i) {
        m_lines.append(QString());
    }
}

QString DocumentModel::getLine(int index) const
{
    if (index >= 0 && index < m_lines.size()) {
        return m_lines.at(index);
    }
    return QString();
}

void DocumentModel::setLine(int index, const QString &text)
{
    if (index >= 0 && index < m_lines.size()) {
        m_lines[index] = text;
        emit lineChanged(index, text);
    }
}

int DocumentModel::lineCount() const
{
    return m_lines.size();
}

bool DocumentModel::saveToFile(const QString &filePath) const
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }
    
    QTextStream out(&file);
    for (int i = 0; i < m_lines.size(); ++i) {
        out << m_lines.at(i) << "\n";
    }
    
    file.close();
    return true;
}
