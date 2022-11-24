#ifndef FONT_FRM_H
#define FONT_FRM_H

#include <QWidget>

namespace Ui {
class font_frm;
}

class font_frm : public QWidget
{
    Q_OBJECT

public:
    explicit font_frm(QWidget *parent = nullptr);
    ~font_frm();
    int show_font_num();

private slots:
    void on_pushButton_clicked();

private:
    Ui::font_frm *ui;
};

#endif // FONT_FRM_H
