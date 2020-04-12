#ifndef QPART_H
#define QPART_H

#include <QMetaObject>
#include <QMap>

class QPart
{
public:
    enum Share
    {
        any,
        shared,
        nonshared
    };

public:
    QPart(QMetaObject const * meta, QMetaObject const * type, char const * name, Share share = Share::any);

    class Type
    {
    public:
        Type(QMetaObject const * type) : type_(type) {}
        void apply(QPart & p) const
        {
            p.type_ = type_;
        }
    private:
        QMetaObject const * type_;
    };

    class Name
    {
    public:
        Name(char const * name) : name_(name) {}
        void apply(QPart & p) const
        {
            p.name_ = name_;
        }
    private:
        char const * name_;
    };

    class Shared
    {
    public:
        Shared(Share share) : share_(share) {}
        void apply(QPart & p) const
        {
            p.share_ = share_;
        }
    private:
        Share share_;
    };

    class Attribute
    {
    public:
        Attribute(char const * key, char const * value) : key_(key), value_(value) {}
        void apply(QPart & p) const
        {
            p.attrs_[key_] = value_;
        }
    private:
        char const * key_;
        char const * value_;
    };

protected:
    QPart(QMetaObject const * meta, bool isExport);

    template <typename Arg, typename ...Args>
    void config(Arg const & arg, Args const & ...args)
    {
        arg.apply(*this);
        config(args...);
    }

    void config()
    {
    }

    bool match(QPart const & o) const;

    bool attrMatch(QPart const & o) const;

    bool share(QPart const & o) const;

public:
    char const * name() const
    {
        return name_ == nullptr ? type_->className() : name_;
    }

    char const * attr(char const * key, char const * defalutValue = nullptr) const
    {
        return attrs_.value(key, defalutValue);
    }

protected:
    friend class QComponentRegistry;
    friend class QComponentContainer;
    QMetaObject const * meta_;
    QMetaObject const * type_;
    char const * name_;
    Share share_;
    QMap<char const *, char const *> attrs_;
};

#endif // QPART_H
