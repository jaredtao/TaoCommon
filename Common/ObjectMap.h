#pragma once
#include <map>
#include <memory>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <functional>
#include <unordered_map>
namespace TaoCommon
{
    template <typename Key, typename Value>
    class ObjectMap
    {
    public:
        virtual ~ObjectMap()
        {
            clear();
        }
        void setObj(const Key &key, const Value &obj)
        {
            m_objMap[key] = obj;
        }
        Value getObj(const Key &key) const
        {
            auto itor = m_objMap.find(key);
            if (itor == m_objMap.end())
            {
                return nullptr;
            }
            else
            {
                return itor->second;
            }
        }
        void clear()
        {
            m_objMap.clear();
        }

    protected:
        std::unordered_map<Key, Value> m_objMap;
    };

    template <typename ObjectType>
    class CObjectMap : public ObjectMap<std::type_index, std::shared_ptr<ObjectType>>
    {
    public:
        template <typename DeriveObjectType>
        DeriveObjectType *getObject() const
        {
            static_assert(std::is_base_of<ObjectType, DeriveObjectType>::value, "DeriveObjectType must be derive from ObjectType");
            auto objPtr = getObj(std::type_index(typeid(std::shared_ptr<DeriveObjectType>)));
            return std::static_pointer_cast<DeriveObjectType>(objPtr).get();
        }
        template <typename DeriveObjectType, typename... Args>
        inline void setObject(Args &&... args)
        {
            static_assert(std::is_base_of<ObjectType, DeriveObjectType>::value, "DeriveObjectType must be derive from ObjectType");
            auto obj = std::make_shared<DeriveObjectType>(args...);
            setObj(std::type_index(typeid(obj)), std::static_pointer_cast<ObjectType>(obj));
        }
        void forEach(const std::function<void(ObjectType *)> &callback) const
        {
            for (const auto &pair : m_objMap)
            {
                callback(pair.second.get());
            }
        }
    };

    template <typename ObjectType>
    class CLevelObjectMap
    {
    public:
        template <typename DeriveObjectType>
        DeriveObjectType *getObject() const 
        {
            static_assert(std::is_base_of<ObjectType, DeriveObjectType>::value, "DeriveObjectType must be derive from ObjectType");
            auto index = std::type_index(typeid(std::shared_ptr<DeriveObjectType>));

            for (const auto &mainPair : m_map)
            {
                const std::unordered_map<std::type_index, std::shared_ptr<ObjectType>> &subMap = mainPair.second;
                auto itor = subMap.find(index);
                if (itor != subMap.end())
                {
                    return std::static_pointer_cast<DeriveObjectType>(itor->second).get();
                }
            }
            return nullptr;
        }
        template <typename DeriveObjectType, typename... Args>
        inline void setObject(uint8_t level, Args &&... args)
        {
            static_assert(std::is_base_of<ObjectType, DeriveObjectType>::value, "DeriveObjectType must be derive from ObjectType");
            auto obj = std::make_shared<DeriveObjectType>(args...);
            m_map[level][std::type_index(typeid(obj))] = std::static_pointer_cast<ObjectType>(obj);
        }
        void forEach(const std::function<void(ObjectType *)> &callback) const
        {
            for (const auto &mainPair : m_map)
            {
                const std::unordered_map<std::type_index, std::shared_ptr<ObjectType>> &subMap = mainPair.second;
                for (const auto &subPair : subMap)
                {
                    callback(subPair.second.get());
                }
            }
        }
        void clear()
        {
            m_map.clear();
        }

    private:
        std::map<uint8_t, std::unordered_map<std::type_index, std::shared_ptr<ObjectType>>> m_map;
    };
} // namespace TaoCommon
