/***************************************************************************************************
**      2018-06-19  HSingleton 单例模板。
***************************************************************************************************/

#ifndef HSINGLETON_H
#define HSINGLETON_H

#include "HCoreGlobal.h"
#include <memory>

HE_CORE_BEGIN_NAMESPACE

template <typename T>
class HSingleton
{
public:
    template <typename... Args>
    static T *instance(Args&&... args)
    {
        if(__instance == nullptr)
            __instance = new T(std::forward<Args>(args)...);
        return __instance;
    }

    static T *getInstance()
    {
        if (__instance == nullptr)
            throw std::logic_error("The instance is not init, Please initialize the instance first.");
        return __instance;
    }

    static void destroyInstance()
    {
        delete __instance;
        __instance = nullptr;
    }

protected:
    HSingleton() = default;
    ~HSingleton() = default;
    HSingleton(const HSingleton&) = delete;
    HSingleton &operator=(const HSingleton&) = delete;

protected:
    static T *__instance;
};

template <typename T>
T *HSingleton<T>::__instance = nullptr;

#define H_FRIEND_SINGLETON(theClass)    friend class HSingleton<theClass>;

HE_CORE_END_NAMESPACE

#endif // HSINGLETON_H
