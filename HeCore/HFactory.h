#ifndef HFACTORY_H
#define HFACTORY_H

#include "IInitializeable.h"
#include <functional>
#include <QVariant>

HE_CORE_BEGIN_NAMESPACE

class HE_CORE_EXPORT HFactory
{
public:
    template<typename T>
    static void registerClass(QString className);

    template<typename T>
    static T *createObject(QString className);

    template<typename T>
    static T *createObject(QString className, QVariantMap param);

protected:
    template<typename T>
    static void *constructorHelper();

protected:
    static QHash<QString, std::function<void *()>> __hashConstructor;
};

template<typename T>
void HFactory::registerClass(QString className)
{
    __hashConstructor.insert(className, &constructorHelper<T>);
}

template<typename T>
T *HFactory::createObject(QString className)
{
    if (!__hashConstructor.contains(className))
        return nullptr;
    return static_cast<T*>(__hashConstructor[className]());
}

template<typename T>
T *HFactory::createObject(QString className, QVariantMap param)
{
    static_assert(std::is_base_of<IInitializeable, T>::value, "T needs to be IInitializeable based.");
    auto t = createObject<T>(className);
    if (t != nullptr)
        t->initialize(param);
    return t;
}

template<typename T>
void *HFactory::constructorHelper()
{
    return new T();
}

HE_CORE_END_NAMESPACE

#endif // HFACTORY_H