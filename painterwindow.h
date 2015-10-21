#ifndef PAINTERWINDOW_H
#define PAINTERWINDOW_H

#include <QMainWindow>

class QPaintEvent;
class CanvasDialog;

namespace Ui {
class PainterWindow;
}

class XPainter
{
public:
    enum Type {
        Simple,
        Gradient,
        Text,
        Path,
        Image,
    };
public:
    XPainter(Type type) : type(type) {}
    virtual ~XPainter() {}

    virtual void paint(QWidget *) {}

    Type getType() const { return type; }
private:
    Type type;
};

class XPainterFactory
{
private:
    typedef XPainter::Type Type;
public:
//    XPainterFactory() {}
    static XPainter* createPainter(Type type);
};

class PainterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PainterWindow(QWidget *parent = 0);
    ~PainterWindow();

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::PainterWindow *ui;

    CanvasDialog *canvasDlg = nullptr;

    typedef XPainter::Type Type;
    Type paintType = Type::Simple;
};

class XPainterSimple : public XPainter
{
public:
    XPainterSimple() : XPainter(Type::Simple) {}
    void paint(QWidget *widget);
};

class XPainterGradient : public XPainter
{
public:
    XPainterGradient() : XPainter(Type::Gradient) {}
    void paint(QWidget *widget);
};

class XPainterText : public XPainter
{
public:
    XPainterText() : XPainter(Type::Text) {}
    void paint(QWidget *widget);
};

class XPainterPath : public XPainter
{
public:
    XPainterPath() : XPainter(Type::Path) {}
    void paint(QWidget *widget);
};

class XPainterImage : public XPainter
{
public:
    XPainterImage() : XPainter(Type::Image) {}
    void paint(QWidget *widget);
private:
    QString filename = ":/images/images/add.png";
    bool isFileLoaded = false;
};

#endif // PAINTERWINDOW_H
