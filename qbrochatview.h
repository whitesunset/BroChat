#ifndef QBROCHATVIEW
#define QBROCHATVIEW

#include <QSettings>

#include <QWebView>

#include "qmessagesmanager.h"

class QChatMessage;
class QChatStatistic;

class QChatUpdateServer;

class QAcesChat;
class QCyberGameChat;
class QFunStreamChat;
class QGamersTvChat;
class QGipsyTeamChat;
class QGoodGameChat;
class QHitBoxChat;
class QLivecodingChat;
class QReallTvChat;
class QSc2tvChat;
class QStreamBoxChat;
class QTwitchChat;
class QYoutubeChat;

class QIgdcChat;



class QBroChatView: public QWebView
{
    Q_OBJECT
public:
    explicit QBroChatView( QWidget *parent = 0 );
    virtual ~QBroChatView();

    void addMessage( const QString &service, const QString &nickName, const QString &message, const QString &type );
protected:
    virtual void mousePressEvent( QMouseEvent *event );
    virtual void mouseMoveEvent( QMouseEvent *event );
    virtual void mouseReleaseEvent( QMouseEvent *event );

    /*
    virtual void keyPressEvent( QKeyEvent *event );
    virtual void keyReleaseEvent( QKeyEvent * event );
    */

    virtual void closeEvent( QCloseEvent *event );

    virtual void timerEvent( QTimerEvent *event );
private:
    void loadSettings();
    bool isLink( const QString& str );
public slots:
    void slotNewMessage( QChatMessage *message );
    void onNewStatistic( QChatStatistic *statistic );
    void saveSettings();
    void showSettings();

    void loadFlagsAndAttributes();

    void changeStyle( const QString& styleName );

    void changeShowSystemMessagesState();
    void changeShowImagesState();
    void changeUseServerState();
    void changeSaveToFileState();
    void changeSaveMessagesToLogState();

private slots:
    void changeStyle();
    void changeOpacity();
    void onLinkClicked( const QUrl &url );

    void showPollSettings();
signals:
    void closeWindow();
private:
    QAcesChat *acesChat_;
    QCyberGameChat *cybergameChat_;
    QFunStreamChat *funstreamChat_;
    QGamersTvChat *gamerstvChat_;
    QGipsyTeamChat *gipsyteamChat_;
    QGoodGameChat *goodgameChat_;
    QHitBoxChat *hitboxChat_;
    QLivecodingChat * livecodingChat_;
    QReallTvChat *realltvChat_;
    QSc2tvChat *sc2tvChat_;
    QStreamBoxChat *streamboxChat_;
    QTwitchChat *twitchChat_;    
    QYoutubeChat * youtubeChat_;


    QIgdcChat * igdcChat_;

    QChatUpdateServer *chatUpdateServer_;

    QSettings settings_;

    bool moveState_;
    QPoint mouseStartPos_;

    int updatePictureId_;
    int updatePictureInterval_;


    bool showSystemMessages_;
    bool showImages_;
    bool saveToFile_;

    QMessagesManager messagesManager_;
    bool saveMessagesToLog_;
};

#endif // QBROCHATVIEW

