#pragma once
#include <QObject>
#include <QString>

class Player : public QObject {
    Q_OBJECT
    Q_PROPERTY(int id READ id CONSTANT)
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int rating READ rating CONSTANT)
    Q_PROPERTY(QString federation READ federation CONSTANT)

public:
    explicit Player(int id, QString name, int rating,
                     QString federation, QObject *parent = nullptr)
        : QObject(parent), m_id(id), m_name(std::move(name)),
          m_rating(rating), m_federation(std::move(federation)) {}

    int id() const { return m_id; }
    QString name() const { return m_name; }
    int rating() const { return m_rating; }
    QString federation() const { return m_federation; }

private:
    int m_id;
    QString m_name;
    int m_rating;
    QString m_federation;
};
