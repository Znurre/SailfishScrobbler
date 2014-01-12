# The name of your app.
# NOTICE: name defined in TARGET has a corresponding QML filename.
#         If name defined in TARGET is changed, following needs to be
#         done to match new name:
#         - corresponding QML filename must be changed
#         - desktop icon filename must be changed
#         - desktop filename must be changed
#         - icon definition filename in desktop file must be changed
TARGET = harbour-audioscrobbler

QT += xml network
CONFIG += sailfishapp c++11

SOURCES += \
    src/PulseAudioModel.cpp \
    src/PulseAudioThread.cpp \
    src/NetworkObject.cpp \
    src/QStringEx.cpp \
    src/UrlBuilder.cpp \
    src/Key.cpp \
    src/KeyValue.cpp \
    src/SignatureBuilder.cpp \
    src/Settings.cpp \
    src/MainPageViewModel.cpp \
    src/PageStackAdapter.cpp \
    src/ScrobblerPageViewModel.cpp \
    src/Track.cpp \
    src/QueryBuilder.cpp \
    src/Scrobbler.cpp \
    src/StatusParser.cpp \
    src/Status.cpp \
    src/ScrobblerViewModel.cpp \
    src/CoverPageViewModel.cpp \
    src/ConnectPageViewModel.cpp \
    src/main.cpp

OTHER_FILES += \
    qml/cover/CoverPage.qml \
    rpm/harbour-audioscrobbler.spec \
    rpm/harbour-audioscrobbler.yaml \
    qml/pages/MainPage.qml \
    qml/pages/ConnectPage.qml \
    qml/NowPlayingItemTemplate.qml \
    qml/HistoryItemTemplate.qml \
    qml/NowPlayingHeaderTemplate.qml \
    qml/HistoryHeaderTemplate.qml \
    qml/MediaListItem.qml \
    harbour-audioscrobbler.desktop \
    harbour-audioscrobbler.png \
    qml/harbour-audioscrobbler.qml

HEADERS += \
    src/PulseAudioModel.h \
    src/PulseAudioThread.h \
    src/NetworkObject.h \
    src/QStringEx.h \
    src/UrlBuilder.h \
    src/Key.h \
    src/KeyValue.h \
    src/SignatureBuilder.h \
    src/Settings.h \
    src/MainPageViewModel.h \
    src/AudioscrobblerAdapter.h \
    src/PageStackAdapter.h \
    src/ScrobblerPageViewModel.h \
    src/Track.h \
    src/QueryBuilder.h \
    src/Scrobbler.h \
    src/TimeProvider.h \
    src/StatusParser.h \
    src/Status.h \
    src/ScrobblerViewModel.h \
    src/CoverPageViewModel.h \
    src/ConnectPageViewModel.h

resources.files = icon-cover-heart.png
resources.path = /usr/share/$${TARGET}

INSTALLS += resources

LIBS += -lpulse
