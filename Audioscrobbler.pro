# The name of your app.
# NOTICE: name defined in TARGET has a corresponding QML filename.
#         If name defined in TARGET is changed, following needs to be
#         done to match new name:
#         - corresponding QML filename must be changed
#         - desktop icon filename must be changed
#         - desktop filename must be changed
#         - icon definition filename in desktop file must be changed
TARGET = Audioscrobbler

QT += xml network
CONFIG += sailfishapp c++11

SOURCES += src/Audioscrobbler.cpp \
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
    src/WelcomePageViewModel.cpp \
    src/PageStackAdapter.cpp \
    src/ScrobblerPageViewModel.cpp \
    src/Track.cpp \
    src/QueryBuilder.cpp \
    src/Scrobbler.cpp \
    src/StatusParser.cpp \
    src/Status.cpp \
    src/ScrobblerViewModel.cpp \
    src/CoverPageViewModel.cpp \
    src/ConnectPageViewModel.cpp

OTHER_FILES += qml/Audioscrobbler.qml \
    qml/cover/CoverPage.qml \
    rpm/Audioscrobbler.spec \
    rpm/Audioscrobbler.yaml \
    Audioscrobbler.desktop \
    qml/pages/MainPage.qml \
    qml/pages/PlayerSelectionPage.qml \
    qml/pages/ConnectPage.qml

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
    src/WelcomePageViewModel.h \
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
