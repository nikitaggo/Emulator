#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "businterface.h"
#include "emulation/CPU/Z80.h"
#include <QTimer>
#include <QFileDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void load_sna(const QString& filename);

    void keyPressed(int sc);

    void keyReleased(int sc);

public slots:
    void upPressed(bool secPlayer = false);

    void leftPressed(bool secPlayer = false);

    void rightPressed(bool secPlayer = false);

    void firePressed(bool secPlayer = false);

    void downPressed(bool secPlayer = false);

    void upReleased(bool secPlayer = false);

    void leftReleased(bool secPlayer = false);

    void downReleased(bool secPlayer = false);

    void rightReleased(bool secPlayer = false);

    void fireReleased(bool secPlayer = false);





protected:
    virtual bool eventFilter(QObject *object, QEvent *event) override;


private slots:
    void frameRefresh();
    void on_cbShowControls_stateChanged(int state);

    void reset();

    void on_key_pressed(int row, int col);
    void on_key_released(int row, int col);

    void on_cbCaptureKeyboard_stateChanged(int state);

    void on_btnTest_clicked();    
    void on_actionSpectrum_48k_triggered();

    void on_actionSpectrum_128k_triggered();

    void on_cbPaletteCh_currentIndexChanged(int index);

    void on_actionSave_screensot_triggered();

    void on_action_Load_screenshot_triggered();

    void on_actionE_xit_triggered();

    void on_actionReset_triggered();

    void on_actionNMI_triggered();

private:
    Ui::MainWindow *ui;

    BusInterface * bus { nullptr };

    // redcode/Z80
    Z80 cpustate {};
    QTimer *frame_timer;
    QTimer *flash_timer;
};
#endif // MAINWINDOW_H
