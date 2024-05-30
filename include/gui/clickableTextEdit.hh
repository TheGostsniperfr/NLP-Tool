#ifndef CLICKABLE_TEXT_EDIT_HH
#define CLICKABLE_TEXT_EDIT_HH

#include <QTextEdit>
#include <QMouseEvent>
#include <QTextCursor>
#include <QDebug>

class ClickableTextEdit : public QTextEdit {
    Q_OBJECT

public:
    ClickableTextEdit(QWidget *parent = nullptr) : QTextEdit(parent) {}

signals:
    void wordClicked(const QString &word);

protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            QTextCursor cursor = cursorForPosition(event->pos());
            cursor.select(QTextCursor::WordUnderCursor);
            QString word = cursor.selectedText();
            emit wordClicked(word);
            QTextEdit::mousePressEvent(event);
        }
    }
};

#endif // CLICKABLE_TEXT_EDIT_HH
