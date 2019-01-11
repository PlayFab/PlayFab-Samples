//--------------------------------------------------------------------------------------
// BatchRemovalCollection.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

template<class T>
class BatchRemovalCollection
{
public:
    inline void QueuePendingRemoval(const typename std::vector<T>::value_type &item)
    {
        pendingRemovals.push_back(item);
    }

    void ApplyPendingRemovals()
    {
        activeObjects.insert(activeObjects.end(), pendingAdds.begin(), pendingAdds.end());
        pendingAdds.clear();

        for (size_t i = 0; i < pendingRemovals.size(); i++)
        {
            auto itr = std::find(std::begin(activeObjects), std::end(activeObjects), pendingRemovals[i]);
            activeObjects.erase(itr);
        }
        pendingRemovals.clear();
    }

    inline void clear()
    {
        pendingAdds.clear();
        pendingRemovals.clear();
        activeObjects.clear();
    }

    inline void push_back(const typename std::vector<T>::value_type &item)
    {
        pendingAdds.push_back(item);
    }

    inline typename std::vector<T>::iterator begin()
    {
        return activeObjects.begin();
    }

    inline typename std::vector<T>::const_iterator cbegin() const
    {
        return activeObjects.cbegin();
    }

    inline typename std::vector<T>::iterator end()
    {
        return activeObjects.end();
    }

    inline typename std::vector<T>::const_iterator cend() const
    {
        return activeObjects.cend();
    }

    inline typename std::vector<T>::size_type size() const
    {
        return activeObjects.size();
    }

    inline typename std::vector<T>::size_type total_size() const
    {
        return activeObjects.size() + pendingAdds.size();
    }

    inline typename std::vector<T>::reference operator[](typename std::vector<T>::size_type index)
    {
        return activeObjects[index];
    }

    inline typename std::vector<T>::const_reference operator[](typename std::vector<T>::size_type index) const
    {
        return activeObjects[index];
    }

    inline typename std::vector<T>::const_iterator erase(typename std::vector<T>::const_iterator itr)
    {
        return activeObjects.erase(itr);
    }

private:
    std::vector<T> pendingAdds;
    std::vector<T> pendingRemovals;
    std::vector<T> activeObjects;
};