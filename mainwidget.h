#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "nehewidget.h"
#include <QTime>
#include <QTimer>
#include <QList>
#include <QLabel>

namespace Ui {
class MainWidget;
}

struct RotateTask{
    NeHeWidget::LAYER layer;
    NeHeWidget::XYZ   xyz;
    NeHeWidget::ANGLE angle;
} ;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

    void initUI();

protected:
    void keyPressEvent( QKeyEvent *e );

public slots:
    //随机旋转操作
    void onRandBtn();
    //随机旋转定时器函数
    void onRandTimer();
private:
    Ui::MainWidget *ui;
    //opengl widget
    NeHeWidget   *cubeWidget;
    //随机旋转按钮
    QPushButton  *randBtn;
    //随机旋转时的定时器
    QTimer randTimer;
    //随机旋转的所有操作任务
    QList<RotateTask> listRotateTask;
};

#endif // MAINWIDGET_H