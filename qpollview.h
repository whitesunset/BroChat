#ifndef QPOLLVIEW
#define QPOLLVIEW

#include <QWebView>

class QPollView: public QWebView
{
    Q_OBJECT
public:
    explicit    QPollView( QWidget * parent = nullptr );
    virtual     ~QPollView();
protected:
    //virtual void timerEvent( QTimerEvent * event );
private:
};

#endif // QPOLLVIEW

